### Two Minute Tutorial

#### Parsing
The following code causes RapidXml to parse a zero-terminated string named text:
<code>
using namespace rapidxml;
xml_document<> doc;    // character type defaults to char
doc.parse<0>(text);    // 0 means default parse flags
<\code>
doc object is now a root of DOM tree containing representation of the parsed XML. Because all RapidXml interface is contained inside namespace rapidxml, users must either bring contents of this namespace into scope, or fully qualify all the names. Class xml_document represents a root of the DOM hierarchy. By means of public inheritance, it is also an xml_node and a memory_pool. Template parameter of xml_document::parse() function is used to specify parsing flags, with which you can fine-tune behaviour of the parser. Note that flags must be a compile-time constant.

#### Accessing The DOM Tree
To access the DOM tree, use methods of xml_node and xml_attribute classes:
<code>
cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
xml_node<> *node = doc.first_node("foobar");
cout << "Node foobar has value " << node->value() << "\n";
for (xml_attribute<> *attr = node->first_attribute();
     attr; attr = attr->next_attribute())
{
    cout << "Node foobar has attribute " << attr->name() << " ";
    cout << "with value " << attr->value() << "\n";
}
<\code>

#### Modifying The DOM Tree
DOM tree produced by the parser is fully modifiable. Nodes and attributes can be added/removed, and their contents changed. The below example creates a HTML document, whose sole contents is a link to google.com website:
<code>
xml_document<> doc;
xml_node<> *node = doc.allocate_node(node_element, "a", "Google");
doc.append_node(node);
xml_attribute<> *attr = doc.allocate_attribute("href", "google.com");
node->append_attribute(attr);
<\code>
One quirk is that nodes and attributes do not own the text of their names and values. This is because normally they only store pointers to the source text. So, when assigning a new name or value to the node, care must be taken to ensure proper lifetime of the string. The easiest way to achieve it is to allocate the string from the xml_document memory pool. In the above example this is not necessary, because we are only assigning character constants. But the code below uses memory_pool::allocate_string() function to allocate node name (which will have the same lifetime as the document), and assigns it to a new node:
<code>
xml_document<> doc;
char *node_name = doc.allocate_string(name);        // Allocate string and copy name into it
xml_node<> *node = doc.allocate_node(node_element, node_name);  // Set node name to node_name
<\code>

#### Printing XML
You can print xml_document and xml_node objects into an XML string. Use print() function or operator <<, which are defined in rapidxml_print.hpp header.
<code>
using namespace rapidxml;
xml_document<> doc;    // character type defaults to char
// ... some code to fill the document

// Print to stream using operator <<
std::cout << doc;   

// Print to stream using print function, specifying printing flags
print(std::cout, doc, 0);   // 0 means default printing flags

// Print to string using output iterator
std::string s;
print(std::back_inserter(s), doc, 0);

// Print to memory buffer using output iterator
char buffer[4096];                      // You are responsible for making the buffer large enough!
char *end = print(buffer, doc, 0);      // end contains pointer to character after last printed character
*end = 0;                               // Add string terminator after XML
<\code>