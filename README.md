# Honey's daily technical learnings
- This repository is to keep track of my continuous technical learning efforts. 
- This repo consists of example codes, links to articles / tech videos, podcasts, readme etc.
- As and when required, this repo would be organized into sub-folders for easy access. 

- *Start date : 25 - Sep - 2023* ; *End date : Infinite*

- Deeply inspired by [@amitness](https://github.com/amitness)

## Contributors

<a href="https://github.com/honey-speaks-tech/daily-tech-learnings-of-honey/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=honey-speaks-tech/daily-tech-learnings-of-honey"  alt="daily-tech-learnings-of-honey contributors"/>
</a>

## Daily learning log
<details>
<summary>Day 1</summary>

<a name="refactoring"></a>

- [OpportunisticRefactoring article by @martinfowler](https://martinfowler.com/bliki/OpportunisticRefactoring.html)
<a name="software_craftsmanship"></a>

<a name="tech_quotes"></a>

- > “Any fool can write code that a computer can understand. Good programmers write code that humans can understand.”
  > ― Martin Fowler'

<a name="cheatsheets"></a>

- Github's Markdown cheatsheet 
  - Added under `cheatsheets/markdown-cheatsheet.pdf`

<a name="libraries"></a>
- Rapidxml library
  - [Two minute learning](https://rapidxml.sourceforge.net/manual.html#namespacerapidxml_1two_minute_tutorial)
  - Added under `Libraries/rapid-json-2-minute-learning.md`

<a name="dev_ecosystem"></a>

- Cmake wisdom nugget
<a name="cmake"></a>
  - cmake module directive to parse documentation
    - [Documentation in .cmake](https://github.com/honey-speaks-tech/daily-tech-learnings-of-honey/blob/main/developer_ecosystem/learn_cmake/cmake_tips.md#wisdom-nugget-1)
    - Added under `developer_ecosystem/learn_cmake/cmake_tips.md`
- Cmake useful references
  - [ ] [Reusable cmake-modules github](https://github.com/bilke/cmake-modules)
</details>

<details>
<summary>Day 2</summary>

<a name="cheatsheets"></a>

- hackingcpp cheatsheets 
  - std::string interfaces added under `cheatsheets/hackingcpp_cheatsheets/string_interfaces.png`

<a name="cppcoreguidelines"></a>

- cppcoreguidelines about lambda
  - [Use an unnamed lambda if you need a simple function object in one place only](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f11-use-an-unnamed-lambda-if-you-need-a-simple-function-object-in-one-place-only)

</details>

<details>
<summary>Day 3</summary>

<a name="cppcoreguidelines"></a>

- cppcoreguidelines about template meta programming
  - [T.120: Use template metaprogramming only when you really need to](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#t120-use-template-metaprogramming-only-when-you-really-need-to)
  - [T.121: Use template metaprogramming primarily to emulate concepts](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#t121-use-template-metaprogramming-primarily-to-emulate-concepts)

</details>

<details>
<summary>Day 4</summary>

<a name="lucid_suite"></a>

- LucidChart webinar
  - [LucidChart playground and presentation](https://lucid.app/lucidchart/2625a20c-74aa-4986-ab4a-9241c4529952/edit?viewport_loc=-802%2C120%2C3706%2C2104%2CMtuiO7oqJjT3&invitationId=inv_ecac68d4-d9a7-4125-a339-db8bf08777e7)

</details>

<details>
<summary>Day 5</summary>

<a name="json_schema"></a>

- JSON schema
  - [JSON Schema](https://json-schema.org/)
    - While JSON is probably the most popular format for exchanging data, JSON Schema is the vocabulary that enables JSON data consistency, validity, and interoperability at scale.
    - [JSON schema docs](https://json-schema.org/overview/what-is-jsonschema)

</details>

<details>
<summary>Day 6</summary>

<a name="dev_ecosystem"></a>
- run-clang-tidy.py
  - [Parallel clang-tidy runner](https://github.com/llvm/llvm-project/blob/main/clang-tools-extra/clang-tidy/tool/run-clang-tidy.py)

</details>

<details>
<summary>Day 7</summary>

<a name="qnx"></a>

- QNX binary debugging commands
  - `uname -m`
  - `readelf -a /proc/self/exe | grep -q -c Tag_ABI_VFP_args && echo "armhf" || echo "armel"`
  - qemu-$arch-static file is just an interpreter to run the architecture speicfic binary. Below is an example to run aarch64 specifc binary bin/hello-aarch64 on qemu-aarch64-static.
  ```
  $ uname -m
  x86_64

  $ file bin/hello-aarch64
  bin/hello-aarch64: ELF 64-bit LSB executable, ARM aarch64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=fa19c63e3c60463e686564eeeb0937959bd6f559, for GNU/Linux 3.7.0, not stripped, too many notes (256)

  $ bin/hello-aarch64
  bash: bin/hello-aarch64: cannot execute binary file: Exec format error

  $ qemu-aarch64-static bin/hello-aarch64
  Hello World!
  ```

</details>

<details>
<summary>Day 8</summary>
<a name="dev_ecosystem"></a>

- Bincrafters
  - [Bincrafters](https://bincrafters.github.io/2017/06/06/using-bincrafters-conan-repository/)
  - Bincrafters is a community repository that provides Conan package recipes for many popular C/C++ libraries like Boost, OpenSSL etc. 
  - The key benefit of using packages from Bincrafters is that it can significantly reduce build times for C/C++ projects that depend on these libraries as they are able to provide prebuilt binaries, cached artifacts, better dependency management, precompiled headers, parallel builds etc.
  - `conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`
  - `Boost.System/1.64.0@bincrafters/stable`

<a name="cpp"></a>

- system_clock vs steady_clock in std::chrono
  - std::chrono::system_clock
    - Tracks wall-clock time from the system-wide realtime clock.
    - The time points of this clock can jump forwards and backwards as the system time is changed.
    - Time points are convertible to UTC through system_clock::to_time_t() and std::gmtime().
    - Useful for synchronizing events across system time changes.
  - std::chrono::steady_clock
    - Provides a monotonically increasing clock, that never jumps forwards or backwards.
    - Time points from this clock cannot be converted to UTC.
    - Useful for measuring intervals of time. e.g. benchmarking, repeatable timeouts.
    - Unaffected by system time adjustments or changes to the system clock.

    - In summary, system_clock represents wall-clock time and steady_clock represents monotonic time since an arbitrary point. 
    - Choose based on whether you need UTC mapping or monotonic timings.  
</details>

<details>
<summary>Day 9</summary>
<a name="productivity"></a>

- Speed reading
  - Takeaway from Technical Leaders' Guild meetup #1
  - Eye exercises - circular motion, circular motion following a pacer
  - Breathing, food, water, oxygen, posture
  - Reading following finger
  - Speed read to beat sub-vocalization.
  - Read table of contents
  - Focus on interesting chapters to read
  - Try to comprehend what you read rather than blindly focusing on reading entire text.
  - Even if you slow-read, brain can't capture or retain all information you read.
  - Regular practice makes speed reading better
  - Useful resource
    - [How to Speed Read | Tim Ferriss](https://youtu.be/ZwEquW_Yij0)
    - [How long will it take to read that book?](https://www.readinglength.com/)
  - Action item : Try to read `Accelerate` : Part 1 over the week; and meeting scheduled for next Thursday (16-11-2023).

  <a name="cpp"></a>
  - `struct TimingSpec timing_spec{};` vs `TimingSpec timing_spec_1;`
    - Sometimes (likely in a header), you forward-declare a class instead of including its header, and declare use a pointer or reference to that class.
      - e.g. as a function parameter
      - for example
        ```cpp
        class Animal;
        void play_cry(Animal* p_animal);
        ```
      - and that's fine, after the forward declaration, Animal is what you'd call an "incomplete" type, and you can have pointers and references to those
      - Instead of doing a forward declaration, you can write `void play_cry(struct Animal* p_animal)` as a short hand with the same effect. 
      - struct or class, doesn't matter
</details>

<details>
<summary>Day 10 </summary>
<a name= "dev_ecosystem"></a>
<a name="clang_tidy"></a>
- clang_tidy valuable points
  - CMake runs Clang-Tidy as it builds the code `CMAKE_CXX_CLANG_TIDY` is set in its options. 
  - The `run-clang-tidy.py` script can be used to run against code which hasn't been built, using a `compile-commands.json` file. 
    - Ensure that any required source code generation is done first. 
  - As Clang-Tidy takes a lot of time, that's probably going to be an issue either way. 
    - Refer `clang-tidy-diff.py` for optimizing Clang-Tidy runs to only run against a set of changes.
</details>

<details>
<summary> Day 11 </summary>
<a name="cpp"></a>
- C++ Essentials : Templates (By Klaus Iglberger)
  - [Templates training Materials](https://github.com/igl42/oreilly)
</details>

<details>
<summary> Day 12 </summary>
<a name="dev_ecosystem"></a>
- Sonatype 
  - Vulnerability analysis tool
  - Details added under #Developers toolbox section
</details>

## Knowledge Bank
<details>
<summary>Reusable code snippets</summary>

<a name="code_snippets"></a>
- C++
  - Some sample printing using `fmt` library : `reusable_code_snippets/cpp/fmt_print_sample.cpp`
  - Convert string to vector of characters : `reusable_code_snippets/cpp/string_to_vector_of_chars.cpp`
  - Generic function template for logging exceptions: `reusable_code_snippets/cpp/generic_function_template_for_logging.cpp`
  - Converts stringstream to string to raw char buffer : `reusable_code_snippets/cpp/string_stream_to_string_to_raw_char_buff.cpp`
  - Converts string view to raw char buffer : `reusable_code_snippets/cpp/string_view_to_raw_buffer.cpp`
  - Extracts file name from path : `reusable_code_snippets/cpp/extract_file_name_from_path.cpp`
  - String empty check : `reusable_code_snippets/cpp/string_empty_check.cpp`
  - Struct instantiation formats : `reusable_code_snippets/cpp/struct_instantiate_formats.cpp`
  - Nested try catch inside catch block : `reusable_code_snippets/cpp/nested_try_catch_inside_catch.cpp`
- Python
  - Finds number of CPU cores : `reusable_code_snippets/python/num_cpu_cores.py`
</details>

<details>
<summary>Cheatsheets</summary>

<a name="cheatsheets"></a>
- Gitlab markdown emoji cheatsheet
  - [Emoji cheatsheet](https://github.com/ikatyang/emoji-cheat-sheet/blob/master/README.md)

</details>

<details>
<summary>My go-to references</summary>

<a name="cpp_standards"></a>
- C++ draft standards
  - [C++ unofficial working papers github page](https://github.com/timsong-cpp/cppwp)

<a name="cpp"></a>
- Modern C++ features
  - [Anthony Calandra modern-cpp-features github page](https://github.com/AnthonyCalandra/modern-cpp-features)
- Reference for resources to learn C++
  - [Modern C++ resources blog by `modernescpp`](https://www.modernescpp.org/resources/)
  - [Resources that help you to delve into C++ by @LesleyLai](https://lesleylai.info/en/delve_into_cpp)
  - [Where to Get Started Learing C++ and What Resources to Use](https://shafik.github.io/c++/learning/2019/09/05/getting_started_learning_cpp.html)
  - [C++ Resources Available to All, Bay Area C++ Meetup, June 2022](https://www.youtube.com/watch?v=QDWLDRTvZIw&list=PLY0Zjn5rFo4MrVc-iNrD1cCdMxYoSgdwT&index=9)

<a name="system_design"></a>
- System Design
  - [System design byte sized lessons by Alex Xu](https://github.com/ByteByteGoHq/system-design-101)

<a name="tech_conferences"></a>
- Worldwide developer conferences
  - [Developer conference agenda github](https://github.com/scraly/developers-conferences-agenda)

<a name="study_support_for_my_son"></a>
<a name="language_learning"></a>
- Pronunciation helper
  - [Sounds of text](https://soundoftext.com/)

</details>

<details>
<summary>Developers toolbox</summary>

<a name="cpp"></a>
- Utilities
  - [camomilla](https://github.com/vittorioromeo/camomilla)
    - camomilla is a simple Python 3 script that simplifies errors produced by C++ compilers. It is very useful while dealing with heavily-templated code (e.g. when using boost::hana or boost::fusion).
  - [ctcache](https://github.com/matus-chochlik/ctcache)
    - Cache for clang-tidy static analysis results.
    - clang-tidy-cache is a command-line application which "wraps" invocations of the clang-tidy static analysis tool and caches the results of successful runs of clang-tidy. 
    - On subsequent invocations of clang-tidy on an unchanged translation unit, the result is retrieved from the cache and clang-tidy is not executed. 
    - For most C/C++ projects this allows to have static analysis checks enabled without paying the cost of excessive build times when re-checking the same unchanged source code.
- Tools
  - [Sonatype](https://www.sonatype.com/)
    - Manage your software supply chain at scale. Deliver products faster with safer open source. Protect software from malware attacks.
    - [Sonatype OSS index](https://ossindex.sonatype.org/)
      - OSS Index is a free catalogue of open source components and scanning tools to help developers identify vulnerabilities, understand risk, and keep their software safe.
    - [Sonatype github](https://github.com/sonatype)
    - [Webinar : Fireside Chat with BMW and Their Software Supply Chain Management Journey by Fred Farber, Enterprise Architect for BMW of North America](https://www.brighttalk.com/webcast/19417/589101?bt_tok=&utm_source=Sonatype)
</details>

<details>
<summary> Potential Github repos to contribute </summary>

<a name="cpp"></a>
  - C++
    - [Boost::stacktrace](https://github.com/boostorg/stacktrace/)
    - [Awesome-cpp](https://github.com/fffaraz/awesome-cpp)
    - [Modern CPP Tutorial](https://github.com/changkun/modern-cpp-tutorial)
    - [CppCoreGuidelines](https://github.com/isocpp/CppCoreGuidelines)
    - [Indicators](https://github.com/p-ranav/indicators)
    - [C++ tip of the week](https://github.com/tip-of-the-week/cpp/tree/master)
<a name="coding_challenges"></a>
  - Coding challenges
    - [John Crickett's crowd-sourced coding challenges solution website](https://github.com/CodingChallegesFYI/SharedSolutions)
<a name="python"></a>  
  - Python
    - [Precommit](https://github.com/pre-commit/pre-commit-hooks)
    - [Home automation](https://github.com/home-assistant/core)
<a name="cmake"></a>  
  - Cmake
    - [Lefticus' cmake template](https://github.com/cpp-best-practices/cmake_template)
<a name="technical_review"></a>
  - Review and learning
    - [Lefticus' cppbestpractices](https://github.com/cpp-best-practices/cppbestpractices)
    - [Jan Wilmans' C++ guidelines](https://github.com/janwilmans/guidelines/tree/main)

</details>

<details>
<summary>Interesting concepts learning workshops</summary>

<a name="cmake"></a>
- Cmake
  - [Coderefinery Cmake workshop](https://coderefinery.github.io/cmake-workshop/)
  - [More modern Cmake](https://hsf-training.github.io/hsf-training-cmake-webpage/)

<a name="git"></a>
- Git
  - [Coderefinery Git workshop](https://coderefinery.github.io/git-intro/)

<a name="documentation"></a>
- Documentation
  - [How to document your research software](https://coderefinery.github.io/documentation/)

- Open source software
  - [Social coding and open software - What can you do to get credit for your code and to allow reuse](https://coderefinery.github.io/social-coding/)

- Jupyter notebooks
  - [Jupyter notebooks - A tool to write and share executable notebooks and data visualization](https://coderefinery.github.io/jupyter/)

- Automated testing
  - [Automated testing - Preventing yourself and others from breaking your functioning code](https://coderefinery.github.io/testing/)

- Modular code development
  - [Modular code development - Making reusing parts of your code easier](https://coderefinery.github.io/modular-type-along/)

- Data visualization
  - [Data visualization using Python](https://coderefinery.github.io/data-visualization-python/)

<a name="artificial_intelligence"></a>
- Artificial intelligence
  - [Neural Networks: Zero to Hero](https://www.youtube.com/watch?v=VMj-3S1tku0&list=PLAqhIrjkxbuWI23v9cThsA9GvCAUhRvKZ&index=2)
    - [Associated notebook](https://colab.research.google.com/drive/1JMLa53HDuA-i7ZBmqV7ZnA3c_fvtXnx-?usp=sharing)
  - [Neural network training course](https://www.3blue1brown.com/topics/neural-networks)
  - [1hr Talk - Intro to Large Language Models](https://www.youtube.com/watch?v=zjkBMFhNj_g&list=PLAqhIrjkxbuW9U8-vZ_s_cjKPT_FqRStI)
  - [MIT Introduction to Deep Learning | 6.S191](https://www.youtube.com/watch?v=QDX-1M5Nj7s)

<a name="ready_templates"></a>
- Empty lesson template
  - [Empty lesson template](https://github.com/coderefinery/sphinx-lesson-template)

</details>

<details>
<summary>Technical learning wishlist</summary>

<details>
<summary>Technical writing</summary>
<a name="technical_writing"></a>

|Resource|Progress|
|---|---|
|[Article: 33 Good Technical Writing Examples](https://templatelab.com/technical-writing-examples)| |
</details>

<details>
<summary>General technical knowledge</summary>

|Resource|Progress|
|---|---|

|[Article: What Every Programmer Should Know About Memory](honey-speaks-tech/daily-tech-learnings-of-honey/tech_concepts_upskilling/memory/WhatEveryProgrammerShouldKnowAboutMemory.pdf)| |

|[Article: Ten simple rules for quick and dirty scientific programming](honey-speaks-tech/daily-tech-learnings-of-honey/tech_concepts_upskilling/BetterProgramming/Ten simple rules for quick and dirty scientific programming.pdf)| |
</details>

<details>
<summary>Software Architecture</summary>
<a name="software_architecture"></a>
|Resource|Progress|
|---|---|

|[Article: Learning resources for software architecture](honey-speaks-tech/daily-tech-learnings-of-honey/tech_concepts_upskilling/SoftwareArchitecture/15WaysToLearnSoftwareArchitecture.md)| |
</details>

<details>
<summary>C++ articles</summary>

<a name="cpp"></a>

|Resource|Progress|
|---|---|

|[Blog: Understanding when not to std::move in C++](https://developers.redhat.com/blog/2019/04/12/understanding-when-not-to-stdmove-in-c)| |
</details>

<details>
<summary>C++ videos</summary>

<a name="cpp"></a>

|Resource|Progress|
|---|---|

|[Video: Let's get comfortable with SFINAE (C++)](https://youtu.be/-Z7EOWVkb3M?si=VDtWDJfC-erAfGbI)| |
</details>

<details>
<summary>C++ committee support</summary>
<details>
<summary>Papers review wishlist</summary>

|Resource|Progress|
|---|---|

|[Paper: P2951R3 - Shadowing is good for safety](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/p2951r3.html)| |
</details>
</details>
</details>

<details>
<summary>Open-source projects I contribute</summary>

<a name="open_source"></a>
- [Free programming books](https://github.com/EbookFoundation/free-programming-books)
</details>

<details>
<a name="books"></a>
<summary> Book recommendations </summary>

- Professional
  - "You Are a Badass” by Jen Sincero
  - NPR’s How I Built This hosted by Guy Raz.
  - Rich Dad Poor Dad
</details>

<details>
<summary>My other learning interests</summary>

<a name="visual_art"></a>

- Visual art
|Resource|Progress|
|---|---|
  - |[Mike Rhode's 15 minute lesson on 5 basic elements of drawing](https://www.youtube.com/watch?v=msWjW15Uzhk)| |
  - |[](https://burobrand.nl/wp-content/uploads/2021/01/Whitepaper-Five-Visual-Thinking-Types_160121.pdf)| |

  - Books
    - Visual Meetings - Dave Sibbet
    - Visual Leaders - Dave Sibbet
    - Understanding Comics - (For Nivu)
    - Making Comics - (For Nivu)
    - Creating clarity - Holger Nils Pohl
    - How to design visual templates - Bas Bakker
    - 100 daily drawings - Holger Nils Pohl

  - Some visual artists to follow
    - @tbx314
    - James Durno
    - @visual_jam
    - Andy Gray

  - Some more resources
    - [Martin Haussmann, the founder of Bikablo](https://bikablo.com/en/home-page/)
    - [Visual Jam community](https://community.thevisualjam.com/invitation?code=EF66B6)
    - [Visual friends radio](https://www.visualfriends.de/bikablo-radio-more-to-explore-in-the-world-of-visualisation-with-martin-haussmann/)
    - [Sketchnote army podcast](https://sketchnotearmy.com/podcast)
    - [Paddy Dhanda's LinkedIn Post](https://www.linkedin.com/feed/update/urn:li:activity:7117929494740381696/)

</details>

<details>

- Brain training

  - [Rubik's cube tutorials by Andrej Karpathi](https://www.youtube.com/user/badmephisto/featured)

</details>

<details>

- Daily self-help wisdom nuggets
  - [O'Reilly Audiobooks playlist by Assemble You](https://learning.oreilly.com/publisher/assemble-you/)

</details>

<details>
<summary>Meetups/Conferences I attended</summary>

<details>
<summary>C++ meetups</summary>
<a name="cpp"></a>

|Date|Name|Session|Youtube Video|
|---|---|---|---|
|14-10-2023|[GRCCP] - Athens C++ Meetup|Let's get comfortable with SFINAE|https://youtu.be/-Z7EOWVkb3M?si=RFCo7rbRQPQAcZWS|
</details>

</details>

<details>
<summary>Inspiring technical people</summary>

- [Andrej Karpathy](https://karpathy.ai/)
- 
</details>

### Hashtags
  - [#artificial_intelligence](#artificial_intelligence)
  - [#refactoring](#refactoring)
  - [#software_craftsmanship](#software_craftsmanship)
  - [#tech_quotes](#tech_quotes)
  - [#cheatsheets](#cheatsheets)
  - [#libraries](#libraries)
  - [#code_snippets](#code_snippets)
  - [#dev_ecosystem](#dev_ecosystem)
  - [#cmake](#cmake)
  - [#conan](#conan)
  - [#clang_tidy](#clang_tidy)
  - [#coding_challenges](#coding_challenges)
  - [#technical_writing](#technical_writing)
  - [#cpp_standards](#cpp_standards)
  - [#cpp](#cpp)
  - [#cppcoreguidelines](#cppcoreguidelines)
  - [#tech_conferences](#tech_conferences)
  - [#language_learning](#language_learning)
  - [#study_support_for_my_son](#study_support_for_my_son)
  - [#git](#git)
  - [#ready_templates](#ready_templates)
  - [#visual_art](#visual_art)
  - [#system_design](#system_design)
  - [#software_architecture](#software_architecture)
  - [#books](#books)
  - [#open_source](open_source)
  - [#qnx](#qnx)
  - [#python](#python)
  - [#technical_review](#technical_review)
  - [#productivity](#productivity)
