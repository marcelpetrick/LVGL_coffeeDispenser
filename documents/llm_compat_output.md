total 152K
drwxrwxrwx 10 mpetrick mpetrick 4.0K Apr 28 10:58 .
drwxrwxrwx 98 mpetrick mpetrick 4.0K Apr 28 09:51 ..
-rw-r--r--  1 mpetrick mpetrick   94 Apr 20 16:39 .clang-format
drwxr-xr-x  2 mpetrick mpetrick 4.0K Apr 20 15:06 cmake
-rw-r--r--  1 mpetrick mpetrick 2.7K Apr 22 15:27 CMakeLists.txt
-rw-r--r--  1 mpetrick mpetrick 1.9K Apr 20 17:41 Doxyfile.in
drwxrwxrwx  9 mpetrick mpetrick 4.0K Apr 28 10:58 .git
-rw-r--r--  1 mpetrick mpetrick  655 Apr 22 15:27 .gitignore
-rw-r--r--  1 mpetrick mpetrick  35K Dec  8 10:50 LICENSE
-rw-r--r--  1 mpetrick mpetrick    0 Apr 28 10:58 llm_compat_output.md
-rwxr-xr-x  1 mpetrick mpetrick  27K Apr 22 15:27 localPipeline.sh
-rw-r--r--  1 mpetrick mpetrick  199 Dec  8 10:50 .mailmap
drwxrwxrwx  2 mpetrick mpetrick 4.0K Apr 22 15:27 media
-rw-r--r--  1 mpetrick mpetrick  17K Apr 22 15:27 README.md
drwxr-xr-x  2 mpetrick mpetrick 4.0K Apr 22 15:27 scripts
drwxrwxrwx  2 mpetrick mpetrick 4.0K Apr 22 15:27 src
drwxr-xr-x  2 mpetrick mpetrick 4.0K Feb 27 14:11 testItemFolder
drwxr-xr-x  2 mpetrick mpetrick 4.0K Apr 22 15:27 tests
drwxr-xr-x  2 mpetrick mpetrick 4.0K Apr 22 13:00 translations
-rw-r--r--  1 mpetrick mpetrick 6.4K Apr 21 18:33 worst_findings.md
-------------------- ./.gitignore --------------------
# C++ objects and libs

*.slo
*.lo
*.o
*.a
*.la
*.lai
*.so
*.dll
*.dylib
*.exe
*.pdb
*.obj
*.ilk

# Qt-es

/.qmake.cache
/.qmake.stash
*.pro.user
*.pro.user.*
*.qbs.user
*.qbs.user.*
*.moc
moc_*.cpp
moc_*.h
qrc_*.cpp
ui_*.h
Makefile*
*build-*

# QtCreator

*.autosave

# QtCtreator Qml
*.qmlproject.user
*.qmlproject.user.*

# QtCtreator CMake
CMakeLists.txt.user*

# current project
*.qmake.stash
Cullendula

*.vcxproj.user
*.vcxproj.filters
*.v12.suo
*.sln
*.sdf
/debug/
/release/
/CppDependOut/
*.cdproj
/CppDependOut1/
*.aps
/build/
/llm_compat_output.md
/.codex
/.localPipeline/
/reports/
---------- end ----------
-------------------- ./README.md --------------------
# Cullendula
A program to pick out the best shots of the vast amount of taken pictures per photo session.  
The name itself is a wordplay of the plant `Calendula` and the activity `to cull` (slang for filtering photos).

## How to use?
Start it and then drag&drop a folder with the pictures or an example picture to the central area of the app. Cullendula figures out itself which path to use.  
It also creates automatically a new folder named "output" inside the given path.  
The first picture of the files is loaded automatically too.  
Cullendula scans the dropped directory for the image file extensions currently enabled in `Main -> Extensions`. The menu offers up to ten common Qt-supported formats such as `jpg`, `jpeg`, `png`, and `webp`, and all entries are enabled by default.  
The widget-based UI also provides `Main -> Style` with `Light`, `Dark`, and `Purple` themes. Light mode is the default, dark mode keeps the original high-contrast palette, and Purple adds a gloomy violet/cyan variant. The theme is applied application-wide so Qt dialogs follow the selected mode as well.  
Switch between the images via the buttons at the bottom of the app or use the arrow-keys (**LEFT** and **RIGHT**).  
The button "save" (or **UP** arrow-key) moves the current image to the output-folder.  
The button "trash" (or **DOWN** arrow-key) moves the current image to the trash-folder.  
Undo and redo keep the in-memory image list and the visible main view synchronized with the on-disk file moves.  
When you are done, then close the app. The result (the best photos) are inside the output-folder :)  

![](media/Cullendula_current_state.png)

### Preview of the language- and style-switching
![Runtime language switch recording](media/i18n_example_run.gif)

## Build

### tl;dr
Use the `localPipeline.sh` to handle all steps for building, test-runs, coverage generation, documentation, Cppcheck analysis, and a final interactive launch of the built `Cullendula` app.

```sh
time ./localPipeline.sh
[INFO] Project root: /home/mpetrick/repos/Cullendula
[INFO] Build directory: /home/mpetrick/repos/Cullendula/build
[INFO] Coverage build directory: /home/mpetrick/repos/Cullendula/build-coverage
[INFO] Parallel jobs: 20
[INFO] Configuring project in '/home/mpetrick/repos/Cullendula/build'.
[INFO] Building project with 20 parallel job(s).
[INFO] Running unit tests via CTest with 20 parallel job(s).
[INFO] Configuring dedicated coverage build in '/home/mpetrick/repos/Cullendula/build-coverage'.
[INFO] Building coverage configuration with 20 parallel job(s).
[INFO] Generating coverage report.
[INFO] Coverage HTML entry point: /home/mpetrick/repos/Cullendula/build-coverage/coverage/html/index.html
[INFO] Total line coverage: 94.4%
[INFO] Opening coverage report with 'xdg-open'.
[INFO] Generating Doxygen documentation.
[INFO] Doxygen warnings file is empty.
[INFO] Doxygen HTML entry point: /home/mpetrick/repos/Cullendula/build/doxygen/html/index.html
[INFO] Opening generated documentation with 'xdg-open'.
[INFO] Running Cppcheck static analysis.
[INFO] Cppcheck XML report: /home/mpetrick/repos/Cullendula/reports/cppcheck/cppcheck.xml
[INFO] Cppcheck HTML entry point: /home/mpetrick/repos/Cullendula/reports/cppcheck/html/index.html
[INFO] Running clang-format on project C++ sources.
[INFO] clang-format left all tracked source files unchanged.
[INFO] Launching Cullendula as the final pipeline step.
[INFO] Close the application window to let the script finish.

========== Local Pipeline Summary ==========
Configure+Build    : PASS Project configured and built in /home/mpetrick/repos/Cullendula/build
Unit Tests         : PASS CTest completed without failures
Coverage           : PASS Coverage HTML generated successfully in /home/mpetrick/repos/Cullendula/build-coverage
Coverage Gate      : PASS Line coverage is 98.6% (threshold 90.0%)
Open Coverage      : PASS Coverage index.html was handed to the desktop opener
Doxygen            : PASS Documentation generated successfully
Doxygen Warnings   : PASS warnings.txt is empty
Open Docs          : PASS index.html was handed to the desktop opener
Cppcheck           : PASS XML and HTML reports generated in /home/mpetrick/repos/Cullendula/reports/cppcheck
clang-format       : PASS Formatting completed without changing files
Launch App         : PASS Cullendula was started; the script resumed after the window was closed
============================================
./localPipeline.sh  2.05s user 0.67s system 47% cpu 5.718 total
```

----

By default, the documented build commands use all available CPU cores via `--parallel $(nproc)`.
If you want the same behavior without repeating the flag, export `CMAKE_BUILD_PARALLEL_LEVEL=$(nproc)` in your shell first.

```
cmake -S . -B build
cmake --build build --parallel $(nproc)
./build/src/Cullendula
```

## Format the code
This repository ships a `.clang-format` using the default Google C++ style.

Run it from the repository root like this:

```bash
clang-format -i src/*.cpp src/*.h tests/*.cpp tests/*.h
```

## Generate API docs
If `doxygen` is installed when CMake configures the project, a `doxygen` target is available.

Generate the HTML documentation like this:

```bash
cmake -S . -B build
cmake --build build --target doxygen --parallel $(nproc)
```

The generated HTML entry point is:

* `build/doxygen/html/index.html`
* `build/doxygen/warnings.txt`

The configured Doxygen project version follows the current CMake project version automatically.

## Run Cppcheck

Cppcheck is integrated through the compilation database that CMake now exports automatically as `build/compile_commands.json`.

Run it from the repository root like this:

```bash
cmake -S . -B build
cmake --build build --parallel $(nproc)
./scripts/run_cppcheck.sh --build-dir build
```

This produces:

* `reports/cppcheck/cppcheck.xml`
* `reports/cppcheck/html/index.html` when `cppcheck-htmlreport` is installed

The default Cppcheck run is intentionally conservative:

* it uses `--project=compile_commands.json`
* it enables `warning`, `style`, `performance`, and `portability`
* it uses the bundled Qt library model via `--library=qt`
* it limits analysis to project sources in `src/` and `tests/`
* it keeps findings informational in phase 1 by generating reports without failing purely because findings exist

Tool/setup failures still fail the script and the local pipeline.

## HTML Cppcheck report

The optional HTML report is available when `cppcheck-htmlreport` is installed before running the analysis.

Run the same command as above:

```bash
cmake -S . -B build
cmake --build build --parallel $(nproc)
./scripts/run_cppcheck.sh --build-dir build
```

This writes:

* `reports/cppcheck/html/index.html`

The local pipeline also prints that path and tries to open the generated `index.html` automatically, just like the coverage and Doxygen reports.

### Current state of the Cppcheck report:
![](media/cppcheck_report.png)

## Run the tests after building

The unit tests cover the core CLI and GUI behavior from the command line. They verify:

* `CullendulaUndoStack` push/undo/redo semantics
* `CullendulaFileSystemHandler` path parsing, navigation, file moves, and undo/redo integration
* `CullendulaMainWindow` drag and drop, button flows, menu actions, and basic widget state

You can run them in three supported CLI ways:

```
cmake --build build --target test --parallel $(nproc)

cmake --build build --target check --parallel $(nproc)

./build/tests/CullendulaTests
```

At the moment the test suite contains one test executable registered with CTest:

* `CullendulaUndoStackTest`

## Compute coverage

Coverage is opt-in and uses `gcov`. The default build is unchanged.

Build, run the tests, and generate the text coverage report:

```
cmake -S . -B build-coverage -DCULLENDULA_ENABLE_COVERAGE=ON
cmake --build build-coverage --parallel $(nproc)
cmake --build build-coverage --target coverage --parallel $(nproc)
```

This produces:

* `build-coverage/coverage/coverage.txt` as a text summary
* `build-coverage/coverage/gcov/*.gcov` as the detailed per-file gcov output

Because `gcov` also reports inlined code from headers, the coverage output includes relevant Qt and standard-library headers alongside the project source file.

The current coverage target reports on the production code exercised by the existing unit tests. Right now that includes:

* `src/CullendulaUndoStack.cpp`
* `src/CullendulaFileSystemHandler.cpp`
* `src/CullendulaMainWindow.cpp`

## HTML coverage

HTML coverage is only available if one of these standard tools is installed before configuring CMake:

* `gcovr`
* `lcov` together with `genhtml`

Install the tool first, then reconfigure and run:

```
cmake -S . -B build-coverage -DCULLENDULA_ENABLE_COVERAGE=ON
cmake --build build-coverage --target coverage-html --parallel $(nproc)
```

If the tool is missing, CMake disables the `coverage-html` target and prints a status message during configure.

This writes:

* `build-coverage/coverage/html/index.html`

### Current state of the coverage report:
![](media/coverage_report.png)

## Localization
The repository now contains Qt Linguist translation source files in `translations/` for:

* German: `translations/Cullendula_de.ts`
* Croatian: `translations/Cullendula_hr.ts`
* Chinese: `translations/Cullendula_zh_CN.ts`

The CMake build uses Qt 6 `LinguistTools` to turn these `.ts` files into `.qm` files and embeds the generated `.qm` resources into the application. English remains the default language because the source strings are written in English. The runtime language switch is wired through `QTranslator`; the actual translation content can be filled in later without changing the surrounding application structure.

### Translation workflow
User-visible strings from Qt Designer `.ui` files are discovered automatically by Qt `lupdate`.
User-visible strings from C++ sources are discovered when they are marked with Qt translation APIs such as `tr(...)` or a class translation context like `Q_DECLARE_TR_FUNCTIONS(...)`.
Qt also supports translator-facing context:

* in C++ via translator comments written as `//:` immediately before a `tr(...)` call
* in Qt Designer `.ui` files via the `<string comment="...">...</string>` attribute
* for true same-text ambiguities in the same translation context via the optional disambiguation/comment parameter of `tr("Text", "meaning")`

Regenerate the translation source files after adding or changing source strings:

```sh
cmake -S . -B build
cmake --build build --target update_translations
```

This updates the `.ts` files in `translations/`.

After editing the translations, rebuild the application to regenerate the `.qm` files and embed them into the app:

```sh
cmake --build build --parallel $(nproc)
```

In short:

* `update_translations` refreshes the `.ts` files from source code and `.ui` files
* a normal build regenerates the `.qm` files from the current `.ts` files
* the `.ts` update is manual; the `.qm` generation is automatic during builds

## Build information
This is version 0.6.30.

### Builds and runs with:
* Linux, cmake 4.1, GCC 15.2.1, Qt 6.10 (and QtCreator 17)
* not supported nor tested anymore:
  * Windows 7, Qt 5.5 and QtCreator 4.6
  * Win 10, Qt 5.15.1 and Qt 6.0 beta with MinGW 8.1 and QtCreator 4.13.2

## History
* v0.1 was the basic release; working, but ugly
* v0.2 improved useability and stability; more features (move to trash!); refactored code-base; improved code-quality
* v0.3 added tooltips; fixed the "pumping center-label"-issue; added menus; fixed some resizing-issues with the image-label
* v0.4 added undo/redo-functionality with unit-test; added a nice violet icon for the executable and program
* v0.5 moved the buildsystem to cmake (from qmake)
* v0.5.1 suppresses the QtCreator maintenance-tool warning during CMake configure
* v0.5.2 makes the CMake project buildable out of the box from QtCreator
* v0.5.3 fixes the QTest target integration for XML output
* v0.5.4 fixed the undo-stack unit tests, clarified the CLI test workflow, and corrected the README
* v0.5.5 adds opt-in coverage support with standard gcov-based tooling
* v0.5.6 expanded coverage with deterministic MainWindow tests and documented the HTML coverage workflow
* v0.6.0 ports the project build and test setup to Qt 6.10
* v0.6.1 restores image loading across the Qt-supported readable image formats
* v0.6.2 adds a configurable `Main -> Extensions` menu for choosing which image suffixes are loaded
* v0.6.3 adds a repository-local clang-format configuration based on the default Google C++ style
* v0.6.4 closes the stale-session reload gap with explicit regression coverage when switching to an empty folder
* v0.6.5 strengthens the test suite around extension-filter normalization and the all-filters-disabled UI case
* v0.6.6 adds switchable light and dark widget themes under `Main -> Style`
* v0.6.7 adds a Doxygen target with generated HTML output, warning logging, and dependency graphs
* v0.6.8 fixes the remaining Doxygen warnings and keeps the generated warning log clean
* v0.6.9 keeps undo/redo synchronized across the filesystem state, in-memory image list, and visible main view
* v0.6.10 applies the selected light or dark theme across the application palette and Qt dialogs
* v0.6.11 fixes the doxygen-documentation globally
* v0.6.12 adds a repository-local pipeline script for build, test, docs, coverage, and formatting checks
* v0.6.13 resolves filename collisions during save/trash moves and surfaces move failures to the user
* v0.6.14 validates drag payloads at drag-enter time so unsupported drops are rejected before the UI advertises acceptance
* v0.6.15 caches the currently displayed image so window resizes only rescale the in-memory preview instead of reloading from disk
* v0.6.16 broadens coverage across bootstrap, filesystem, main-window, and undo-stack edge cases to exercise more failure paths and branch outcomes
* v0.6.17 aligns the repository with clang-format output so the local pipeline finishes with a clean worktree after formatting checks
* v0.6.18 makes undo/redo history transitions atomic with the filesystem rename so failed undo or redo attempts preserve history and surface actionable errors
* v0.6.19 replaces the remaining filesystem TODOs with explicit directory-setup error handling, on-demand recreation of output folders, and regression coverage for those failure paths
* v0.6.20 extends the local pipeline with a final app-launch step that waits for the user to close Cullendula without changing the script exit status
* v0.6.21 lays the Qt 6 localization groundwork with embedded TS/QM resources, runtime `QTranslator` switching, and a new language menu for English, German, Croatian, and Chinese
* v0.6.22 adds the `localPipeline.sh --noRun` option so the final app launch can be skipped without affecting the script return value
* v0.6.23 makes CMake the single source of truth for the visible application version while keeping the version in the window title
* v0.6.24 marks the remaining user-visible strings for Qt translation extraction and documents the TS/QM workflow in the README
* v0.6.25 prepares the German, Croatian, and Chinese translations for the current Qt 6 localization scaffolding
* v0.6.26 adds translator-facing Qt context comments and UI string comments so Linguist translations can distinguish ambiguous labels and status text more reliably
* v0.6.27 adds a third gloomy purple-and-cyan style while keeping the existing light and dark themes intact
* v0.6.28 covers the real application entry point with a headless executable smoke test and includes `main.cpp` in coverage reporting
* v0.6.29 pushes bootstrap and filesystem coverage further with deterministic helper seams, stronger edge-case tests, and improved coverage of failure-path handling
* v0.6.30 adds repository-local Cppcheck infrastructure with compilation-database input, XML and HTML reports, pipeline integration, and usage documentation

## Open tasks
* show left and right (if possible) neighbour of the current image as smaller preview ... so that you have some preview of similar pictures follow
* show position and amount: like: "3/234 output: 7 trash: 10" - maybe in the status-bar?
* add an icon for the program - started as feature-branch, but problematic for Linux/Wayland
* important: add a file-existance_check before loading to QPixmap
---------- end ----------
-------------------- ./LICENSE --------------------
                    GNU GENERAL PUBLIC LICENSE
                       Version 3, 29 June 2007

 Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.

                            Preamble

  The GNU General Public License is a free, copyleft license for
software and other kinds of works.

  The licenses for most software and other practical works are designed
to take away your freedom to share and change the works.  By contrast,
the GNU General Public License is intended to guarantee your freedom to
share and change all versions of a program--to make sure it remains free
software for all its users.  We, the Free Software Foundation, use the
GNU General Public License for most of our software; it applies also to
any other work released this way by its authors.  You can apply it to
your programs, too.

  When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
them if you wish), that you receive source code or can get it if you
want it, that you can change the software or use pieces of it in new
free programs, and that you know you can do these things.

  To protect your rights, we need to prevent others from denying you
these rights or asking you to surrender the rights.  Therefore, you have
certain responsibilities if you distribute copies of the software, or if
you modify it: responsibilities to respect the freedom of others.

  For example, if you distribute copies of such a program, whether
gratis or for a fee, you must pass on to the recipients the same
freedoms that you received.  You must make sure that they, too, receive
or can get the source code.  And you must show them these terms so they
know their rights.

  Developers that use the GNU GPL protect your rights with two steps:
(1) assert copyright on the software, and (2) offer you this License
giving you legal permission to copy, distribute and/or modify it.

  For the developers' and authors' protection, the GPL clearly explains
that there is no warranty for this free software.  For both users' and
authors' sake, the GPL requires that modified versions be marked as
changed, so that their problems will not be attributed erroneously to
authors of previous versions.

  Some devices are designed to deny users access to install or run
modified versions of the software inside them, although the manufacturer
can do so.  This is fundamentally incompatible with the aim of
protecting users' freedom to change the software.  The systematic
pattern of such abuse occurs in the area of products for individuals to
use, which is precisely where it is most unacceptable.  Therefore, we
have designed this version of the GPL to prohibit the practice for those
products.  If such problems arise substantially in other domains, we
stand ready to extend this provision to those domains in future versions
of the GPL, as needed to protect the freedom of users.

  Finally, every program is threatened constantly by software patents.
States should not allow patents to restrict development and use of
software on general-purpose computers, but in those that do, we wish to
avoid the special danger that patents applied to a free program could
make it effectively proprietary.  To prevent this, the GPL assures that
patents cannot be used to render the program non-free.

  The precise terms and conditions for copying, distribution and
modification follow.

                       TERMS AND CONDITIONS

  0. Definitions.

  "This License" refers to version 3 of the GNU General Public License.

  "Copyright" also means copyright-like laws that apply to other kinds of
works, such as semiconductor masks.

  "The Program" refers to any copyrightable work licensed under this
License.  Each licensee is addressed as "you".  "Licensees" and
"recipients" may be individuals or organizations.

  To "modify" a work means to copy from or adapt all or part of the work
in a fashion requiring copyright permission, other than the making of an
exact copy.  The resulting work is called a "modified version" of the
earlier work or a work "based on" the earlier work.

  A "covered work" means either the unmodified Program or a work based
on the Program.

  To "propagate" a work means to do anything with it that, without
permission, would make you directly or secondarily liable for
infringement under applicable copyright law, except executing it on a
computer or modifying a private copy.  Propagation includes copying,
distribution (with or without modification), making available to the
public, and in some countries other activities as well.

  To "convey" a work means any kind of propagation that enables other
parties to make or receive copies.  Mere interaction with a user through
a computer network, with no transfer of a copy, is not conveying.

  An interactive user interface displays "Appropriate Legal Notices"
to the extent that it includes a convenient and prominently visible
feature that (1) displays an appropriate copyright notice, and (2)
tells the user that there is no warranty for the work (except to the
extent that warranties are provided), that licensees may convey the
work under this License, and how to view a copy of this License.  If
the interface presents a list of user commands or options, such as a
menu, a prominent item in the list meets this criterion.

  1. Source Code.

  The "source code" for a work means the preferred form of the work
for making modifications to it.  "Object code" means any non-source
form of a work.

  A "Standard Interface" means an interface that either is an official
standard defined by a recognized standards body, or, in the case of
interfaces specified for a particular programming language, one that
is widely used among developers working in that language.

  The "System Libraries" of an executable work include anything, other
than the work as a whole, that (a) is included in the normal form of
packaging a Major Component, but which is not part of that Major
Component, and (b) serves only to enable use of the work with that
Major Component, or to implement a Standard Interface for which an
implementation is available to the public in source code form.  A
"Major Component", in this context, means a major essential component
(kernel, window system, and so on) of the specific operating system
(if any) on which the executable work runs, or a compiler used to
produce the work, or an object code interpreter used to run it.

  The "Corresponding Source" for a work in object code form means all
the source code needed to generate, install, and (for an executable
work) run the object code and to modify the work, including scripts to
control those activities.  However, it does not include the work's
System Libraries, or general-purpose tools or generally available free
programs which are used unmodified in performing those activities but
which are not part of the work.  For example, Corresponding Source
includes interface definition files associated with source files for
the work, and the source code for shared libraries and dynamically
linked subprograms that the work is specifically designed to require,
such as by intimate data communication or control flow between those
subprograms and other parts of the work.

  The Corresponding Source need not include anything that users
can regenerate automatically from other parts of the Corresponding
Source.

  The Corresponding Source for a work in source code form is that
same work.

  2. Basic Permissions.

  All rights granted under this License are granted for the term of
copyright on the Program, and are irrevocable provided the stated
conditions are met.  This License explicitly affirms your unlimited
permission to run the unmodified Program.  The output from running a
covered work is covered by this License only if the output, given its
content, constitutes a covered work.  This License acknowledges your
rights of fair use or other equivalent, as provided by copyright law.

  You may make, run and propagate covered works that you do not
convey, without conditions so long as your license otherwise remains
in force.  You may convey covered works to others for the sole purpose
of having them make modifications exclusively for you, or provide you
with facilities for running those works, provided that you comply with
the terms of this License in conveying all material for which you do
not control copyright.  Those thus making or running the covered works
for you must do so exclusively on your behalf, under your direction
and control, on terms that prohibit them from making any copies of
your copyrighted material outside their relationship with you.

  Conveying under any other circumstances is permitted solely under
the conditions stated below.  Sublicensing is not allowed; section 10
makes it unnecessary.

  3. Protecting Users' Legal Rights From Anti-Circumvention Law.

  No covered work shall be deemed part of an effective technological
measure under any applicable law fulfilling obligations under article
11 of the WIPO copyright treaty adopted on 20 December 1996, or
similar laws prohibiting or restricting circumvention of such
measures.

  When you convey a covered work, you waive any legal power to forbid
circumvention of technological measures to the extent such circumvention
is effected by exercising rights under this License with respect to
the covered work, and you disclaim any intention to limit operation or
modification of the work as a means of enforcing, against the work's
users, your or third parties' legal rights to forbid circumvention of
technological measures.

  4. Conveying Verbatim Copies.

  You may convey verbatim copies of the Program's source code as you
receive it, in any medium, provided that you conspicuously and
appropriately publish on each copy an appropriate copyright notice;
keep intact all notices stating that this License and any
non-permissive terms added in accord with section 7 apply to the code;
keep intact all notices of the absence of any warranty; and give all
recipients a copy of this License along with the Program.

  You may charge any price or no price for each copy that you convey,
and you may offer support or warranty protection for a fee.

  5. Conveying Modified Source Versions.

  You may convey a work based on the Program, or the modifications to
produce it from the Program, in the form of source code under the
terms of section 4, provided that you also meet all of these conditions:

    a) The work must carry prominent notices stating that you modified
    it, and giving a relevant date.

    b) The work must carry prominent notices stating that it is
    released under this License and any conditions added under section
    7.  This requirement modifies the requirement in section 4 to
    "keep intact all notices".

    c) You must license the entire work, as a whole, under this
    License to anyone who comes into possession of a copy.  This
    License will therefore apply, along with any applicable section 7
    additional terms, to the whole of the work, and all its parts,
    regardless of how they are packaged.  This License gives no
    permission to license the work in any other way, but it does not
    invalidate such permission if you have separately received it.

    d) If the work has interactive user interfaces, each must display
    Appropriate Legal Notices; however, if the Program has interactive
    interfaces that do not display Appropriate Legal Notices, your
    work need not make them do so.

  A compilation of a covered work with other separate and independent
works, which are not by their nature extensions of the covered work,
and which are not combined with it such as to form a larger program,
in or on a volume of a storage or distribution medium, is called an
"aggregate" if the compilation and its resulting copyright are not
used to limit the access or legal rights of the compilation's users
beyond what the individual works permit.  Inclusion of a covered work
in an aggregate does not cause this License to apply to the other
parts of the aggregate.

  6. Conveying Non-Source Forms.

  You may convey a covered work in object code form under the terms
of sections 4 and 5, provided that you also convey the
machine-readable Corresponding Source under the terms of this License,
in one of these ways:

    a) Convey the object code in, or embodied in, a physical product
    (including a physical distribution medium), accompanied by the
    Corresponding Source fixed on a durable physical medium
    customarily used for software interchange.

    b) Convey the object code in, or embodied in, a physical product
    (including a physical distribution medium), accompanied by a
    written offer, valid for at least three years and valid for as
    long as you offer spare parts or customer support for that product
    model, to give anyone who possesses the object code either (1) a
    copy of the Corresponding Source for all the software in the
    product that is covered by this License, on a durable physical
    medium customarily used for software interchange, for a price no
    more than your reasonable cost of physically performing this
    conveying of source, or (2) access to copy the
    Corresponding Source from a network server at no charge.

    c) Convey individual copies of the object code with a copy of the
    written offer to provide the Corresponding Source.  This
    alternative is allowed only occasionally and noncommercially, and
    only if you received the object code with such an offer, in accord
    with subsection 6b.

    d) Convey the object code by offering access from a designated
    place (gratis or for a charge), and offer equivalent access to the
    Corresponding Source in the same way through the same place at no
    further charge.  You need not require recipients to copy the
    Corresponding Source along with the object code.  If the place to
    copy the object code is a network server, the Corresponding Source
    may be on a different server (operated by you or a third party)
    that supports equivalent copying facilities, provided you maintain
    clear directions next to the object code saying where to find the
    Corresponding Source.  Regardless of what server hosts the
    Corresponding Source, you remain obligated to ensure that it is
    available for as long as needed to satisfy these requirements.

    e) Convey the object code using peer-to-peer transmission, provided
    you inform other peers where the object code and Corresponding
    Source of the work are being offered to the general public at no
    charge under subsection 6d.

  A separable portion of the object code, whose source code is excluded
from the Corresponding Source as a System Library, need not be
included in conveying the object code work.

  A "User Product" is either (1) a "consumer product", which means any
tangible personal property which is normally used for personal, family,
or household purposes, or (2) anything designed or sold for incorporation
into a dwelling.  In determining whether a product is a consumer product,
doubtful cases shall be resolved in favor of coverage.  For a particular
product received by a particular user, "normally used" refers to a
typical or common use of that class of product, regardless of the status
of the particular user or of the way in which the particular user
actually uses, or expects or is expected to use, the product.  A product
is a consumer product regardless of whether the product has substantial
commercial, industrial or non-consumer uses, unless such uses represent
the only significant mode of use of the product.

  "Installation Information" for a User Product means any methods,
procedures, authorization keys, or other information required to install
and execute modified versions of a covered work in that User Product from
a modified version of its Corresponding Source.  The information must
suffice to ensure that the continued functioning of the modified object
code is in no case prevented or interfered with solely because
modification has been made.

  If you convey an object code work under this section in, or with, or
specifically for use in, a User Product, and the conveying occurs as
part of a transaction in which the right of possession and use of the
User Product is transferred to the recipient in perpetuity or for a
fixed term (regardless of how the transaction is characterized), the
Corresponding Source conveyed under this section must be accompanied
by the Installation Information.  But this requirement does not apply
if neither you nor any third party retains the ability to install
modified object code on the User Product (for example, the work has
been installed in ROM).

  The requirement to provide Installation Information does not include a
requirement to continue to provide support service, warranty, or updates
for a work that has been modified or installed by the recipient, or for
the User Product in which it has been modified or installed.  Access to a
network may be denied when the modification itself materially and
adversely affects the operation of the network or violates the rules and
protocols for communication across the network.

  Corresponding Source conveyed, and Installation Information provided,
in accord with this section must be in a format that is publicly
documented (and with an implementation available to the public in
source code form), and must require no special password or key for
unpacking, reading or copying.

  7. Additional Terms.

  "Additional permissions" are terms that supplement the terms of this
License by making exceptions from one or more of its conditions.
Additional permissions that are applicable to the entire Program shall
be treated as though they were included in this License, to the extent
that they are valid under applicable law.  If additional permissions
apply only to part of the Program, that part may be used separately
under those permissions, but the entire Program remains governed by
this License without regard to the additional permissions.

  When you convey a copy of a covered work, you may at your option
remove any additional permissions from that copy, or from any part of
it.  (Additional permissions may be written to require their own
removal in certain cases when you modify the work.)  You may place
additional permissions on material, added by you to a covered work,
for which you have or can give appropriate copyright permission.

  Notwithstanding any other provision of this License, for material you
add to a covered work, you may (if authorized by the copyright holders of
that material) supplement the terms of this License with terms:

    a) Disclaiming warranty or limiting liability differently from the
    terms of sections 15 and 16 of this License; or

    b) Requiring preservation of specified reasonable legal notices or
    author attributions in that material or in the Appropriate Legal
    Notices displayed by works containing it; or

    c) Prohibiting misrepresentation of the origin of that material, or
    requiring that modified versions of such material be marked in
    reasonable ways as different from the original version; or

    d) Limiting the use for publicity purposes of names of licensors or
    authors of the material; or

    e) Declining to grant rights under trademark law for use of some
    trade names, trademarks, or service marks; or

    f) Requiring indemnification of licensors and authors of that
    material by anyone who conveys the material (or modified versions of
    it) with contractual assumptions of liability to the recipient, for
    any liability that these contractual assumptions directly impose on
    those licensors and authors.

  All other non-permissive additional terms are considered "further
restrictions" within the meaning of section 10.  If the Program as you
received it, or any part of it, contains a notice stating that it is
governed by this License along with a term that is a further
restriction, you may remove that term.  If a license document contains
a further restriction but permits relicensing or conveying under this
License, you may add to a covered work material governed by the terms
of that license document, provided that the further restriction does
not survive such relicensing or conveying.

  If you add terms to a covered work in accord with this section, you
must place, in the relevant source files, a statement of the
additional terms that apply to those files, or a notice indicating
where to find the applicable terms.

  Additional terms, permissive or non-permissive, may be stated in the
form of a separately written license, or stated as exceptions;
the above requirements apply either way.

  8. Termination.

  You may not propagate or modify a covered work except as expressly
provided under this License.  Any attempt otherwise to propagate or
modify it is void, and will automatically terminate your rights under
this License (including any patent licenses granted under the third
paragraph of section 11).

  However, if you cease all violation of this License, then your
license from a particular copyright holder is reinstated (a)
provisionally, unless and until the copyright holder explicitly and
finally terminates your license, and (b) permanently, if the copyright
holder fails to notify you of the violation by some reasonable means
prior to 60 days after the cessation.

  Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.

  Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, you do not qualify to receive new licenses for the same
material under section 10.

  9. Acceptance Not Required for Having Copies.

  You are not required to accept this License in order to receive or
run a copy of the Program.  Ancillary propagation of a covered work
occurring solely as a consequence of using peer-to-peer transmission
to receive a copy likewise does not require acceptance.  However,
nothing other than this License grants you permission to propagate or
modify any covered work.  These actions infringe copyright if you do
not accept this License.  Therefore, by modifying or propagating a
covered work, you indicate your acceptance of this License to do so.

  10. Automatic Licensing of Downstream Recipients.

  Each time you convey a covered work, the recipient automatically
receives a license from the original licensors, to run, modify and
propagate that work, subject to this License.  You are not responsible
for enforcing compliance by third parties with this License.

  An "entity transaction" is a transaction transferring control of an
organization, or substantially all assets of one, or subdividing an
organization, or merging organizations.  If propagation of a covered
work results from an entity transaction, each party to that
transaction who receives a copy of the work also receives whatever
licenses to the work the party's predecessor in interest had or could
give under the previous paragraph, plus a right to possession of the
Corresponding Source of the work from the predecessor in interest, if
the predecessor has it or can get it with reasonable efforts.

  You may not impose any further restrictions on the exercise of the
rights granted or affirmed under this License.  For example, you may
not impose a license fee, royalty, or other charge for exercise of
rights granted under this License, and you may not initiate litigation
(including a cross-claim or counterclaim in a lawsuit) alleging that
any patent claim is infringed by making, using, selling, offering for
sale, or importing the Program or any portion of it.

  11. Patents.

  A "contributor" is a copyright holder who authorizes use under this
License of the Program or a work on which the Program is based.  The
work thus licensed is called the contributor's "contributor version".

  A contributor's "essential patent claims" are all patent claims
owned or controlled by the contributor, whether already acquired or
hereafter acquired, that would be infringed by some manner, permitted
by this License, of making, using, or selling its contributor version,
but do not include claims that would be infringed only as a
consequence of further modification of the contributor version.  For
purposes of this definition, "control" includes the right to grant
patent sublicenses in a manner consistent with the requirements of
this License.

  Each contributor grants you a non-exclusive, worldwide, royalty-free
patent license under the contributor's essential patent claims, to
make, use, sell, offer for sale, import and otherwise run, modify and
propagate the contents of its contributor version.

  In the following three paragraphs, a "patent license" is any express
agreement or commitment, however denominated, not to enforce a patent
(such as an express permission to practice a patent or covenant not to
sue for patent infringement).  To "grant" such a patent license to a
party means to make such an agreement or commitment not to enforce a
patent against the party.

  If you convey a covered work, knowingly relying on a patent license,
and the Corresponding Source of the work is not available for anyone
to copy, free of charge and under the terms of this License, through a
publicly available network server or other readily accessible means,
then you must either (1) cause the Corresponding Source to be so
available, or (2) arrange to deprive yourself of the benefit of the
patent license for this particular work, or (3) arrange, in a manner
consistent with the requirements of this License, to extend the patent
license to downstream recipients.  "Knowingly relying" means you have
actual knowledge that, but for the patent license, your conveying the
covered work in a country, or your recipient's use of the covered work
in a country, would infringe one or more identifiable patents in that
country that you have reason to believe are valid.

  If, pursuant to or in connection with a single transaction or
arrangement, you convey, or propagate by procuring conveyance of, a
covered work, and grant a patent license to some of the parties
receiving the covered work authorizing them to use, propagate, modify
or convey a specific copy of the covered work, then the patent license
you grant is automatically extended to all recipients of the covered
work and works based on it.

  A patent license is "discriminatory" if it does not include within
the scope of its coverage, prohibits the exercise of, or is
conditioned on the non-exercise of one or more of the rights that are
specifically granted under this License.  You may not convey a covered
work if you are a party to an arrangement with a third party that is
in the business of distributing software, under which you make payment
to the third party based on the extent of your activity of conveying
the work, and under which the third party grants, to any of the
parties who would receive the covered work from you, a discriminatory
patent license (a) in connection with copies of the covered work
conveyed by you (or copies made from those copies), or (b) primarily
for and in connection with specific products or compilations that
contain the covered work, unless you entered into that arrangement,
or that patent license was granted, prior to 28 March 2007.

  Nothing in this License shall be construed as excluding or limiting
any implied license or other defenses to infringement that may
otherwise be available to you under applicable patent law.

  12. No Surrender of Others' Freedom.

  If conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot convey a
covered work so as to satisfy simultaneously your obligations under this
License and any other pertinent obligations, then as a consequence you may
not convey it at all.  For example, if you agree to terms that obligate you
to collect a royalty for further conveying from those to whom you convey
the Program, the only way you could satisfy both those terms and this
License would be to refrain entirely from conveying the Program.

  13. Use with the GNU Affero General Public License.

  Notwithstanding any other provision of this License, you have
permission to link or combine any covered work with a work licensed
under version 3 of the GNU Affero General Public License into a single
combined work, and to convey the resulting work.  The terms of this
License will continue to apply to the part which is the covered work,
but the special requirements of the GNU Affero General Public License,
section 13, concerning interaction through a network will apply to the
combination as such.

  14. Revised Versions of this License.

  The Free Software Foundation may publish revised and/or new versions of
the GNU General Public License from time to time.  Such new versions will
be similar in spirit to the present version, but may differ in detail to
address new problems or concerns.

  Each version is given a distinguishing version number.  If the
Program specifies that a certain numbered version of the GNU General
Public License "or any later version" applies to it, you have the
option of following the terms and conditions either of that numbered
version or of any later version published by the Free Software
Foundation.  If the Program does not specify a version number of the
GNU General Public License, you may choose any version ever published
by the Free Software Foundation.

  If the Program specifies that a proxy can decide which future
versions of the GNU General Public License can be used, that proxy's
public statement of acceptance of a version permanently authorizes you
to choose that version for the Program.

  Later license versions may give you additional or different
permissions.  However, no additional obligations are imposed on any
author or copyright holder as a result of your choosing to follow a
later version.

  15. Disclaimer of Warranty.

  THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM "AS IS" WITHOUT WARRANTY
OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM
IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF
ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

  16. Limitation of Liability.

  IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS
THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY
GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF
DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD
PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS),
EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF
SUCH DAMAGES.

  17. Interpretation of Sections 15 and 16.

  If the disclaimer of warranty and limitation of liability provided
above cannot be given local legal effect according to their terms,
reviewing courts shall apply local law that most closely approximates
an absolute waiver of all civil liability in connection with the
Program, unless a warranty or assumption of liability accompanies a
copy of the Program in return for a fee.

                     END OF TERMS AND CONDITIONS

            How to Apply These Terms to Your New Programs

  If you develop a new program, and you want it to be of the greatest
possible use to the public, the best way to achieve this is to make it
free software which everyone can redistribute and change under these terms.

  To do so, attach the following notices to the program.  It is safest
to attach them to the start of each source file to most effectively
state the exclusion of warranty; and each file should have at least
the "copyright" line and a pointer to where the full notice is found.

    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

Also add information on how to contact you by electronic and paper mail.

  If the program does terminal interaction, make it output a short
notice like this when it starts in an interactive mode:

    <program>  Copyright (C) <year>  <name of author>
    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.

The hypothetical commands `show w' and `show c' should show the appropriate
parts of the General Public License.  Of course, your program's commands
might be different; for a GUI interface, you would use an "about box".

  You should also get your employer (if you work as a programmer) or school,
if any, to sign a "copyright disclaimer" for the program, if necessary.
For more information on this, and how to apply and follow the GNU GPL, see
<http://www.gnu.org/licenses/>.

  The GNU General Public License does not permit incorporating your program
into proprietary programs.  If your program is a subroutine library, you
may consider it more useful to permit linking proprietary applications with
the library.  If this is what you want to do, use the GNU Lesser General
Public License instead of this License.  But first, please read
<http://www.gnu.org/philosophy/why-not-lgpl.html>.
---------- end ----------
-------------------- ./.mailmap --------------------
Marcel Petrick <mail@marcelpetrick.it> <mail@marcelpetrick.it>
Marcel Petrick <mail@marcelpetrick.it> <petrick@instrumentsystems.com>
Marcel Petrick <mail@marcelpetrick.it> <mpetrick@data-modul.com>
---------- end ----------
-------------------- ./cmake/GenerateCoverage.cmake --------------------
if(NOT DEFINED GCOV_EXECUTABLE OR GCOV_EXECUTABLE STREQUAL "")
    message(FATAL_ERROR "GCOV_EXECUTABLE must be set")
endif()

if(NOT DEFINED COVERAGE_OUTPUT_DIR OR COVERAGE_OUTPUT_DIR STREQUAL "")
    message(FATAL_ERROR "COVERAGE_OUTPUT_DIR must be set")
endif()

if(NOT DEFINED COVERAGE_REPORT_FILE OR COVERAGE_REPORT_FILE STREQUAL "")
    message(FATAL_ERROR "COVERAGE_REPORT_FILE must be set")
endif()

if(DEFINED COVERAGE_CONFIG_FILE AND NOT COVERAGE_CONFIG_FILE STREQUAL "")
    include("${COVERAGE_CONFIG_FILE}")
endif()

if(NOT DEFINED COVERAGE_OBJECTS OR COVERAGE_OBJECTS STREQUAL "")
    message(FATAL_ERROR "COVERAGE_OBJECTS must be set")
endif()

set(coverage_objects ${COVERAGE_OBJECTS})

file(MAKE_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
file(WRITE "${COVERAGE_REPORT_FILE}" "Cullendula coverage report\n")
file(APPEND "${COVERAGE_REPORT_FILE}" "Generated with gcov\n\n")

execute_process(
    COMMAND "${CMAKE_COMMAND}" -E remove_directory "${COVERAGE_OUTPUT_DIR}/gcov"
)
file(MAKE_DIRECTORY "${COVERAGE_OUTPUT_DIR}/gcov")

list(LENGTH coverage_objects coverage_object_count)
math(EXPR last_index "${coverage_object_count} - 1")
foreach(index RANGE ${last_index})
    list(GET coverage_objects ${index} coverage_object)

    execute_process(
        COMMAND "${GCOV_EXECUTABLE}" -b -c "${coverage_object}"
        WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}/gcov"
        RESULT_VARIABLE coverage_result
        OUTPUT_VARIABLE coverage_stdout
        ERROR_VARIABLE coverage_stderr
    )

    file(APPEND "${COVERAGE_REPORT_FILE}" "== ${coverage_object} ==\n")
    if(NOT coverage_stdout STREQUAL "")
        file(APPEND "${COVERAGE_REPORT_FILE}" "${coverage_stdout}")
    endif()

    if(NOT coverage_stderr STREQUAL "")
        file(APPEND "${COVERAGE_REPORT_FILE}" "${coverage_stderr}")
    endif()

    file(APPEND "${COVERAGE_REPORT_FILE}" "\n")

    if(NOT coverage_result EQUAL 0)
        message(FATAL_ERROR "gcov failed for ${coverage_object}")
    endif()
endforeach()

message(STATUS "Coverage report written to ${COVERAGE_REPORT_FILE}")
---------- end ----------
-------------------- ./src/CullendulaMainWindow.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

// own includes
#include "CullendulaAppBootstrap.h"
#include "CullendulaFileSystemHandler.h"

// Qt includes
#include <QtCore/QMap>
#include <QtCore/QStringList>
#include <QtCore/QVector>
#include <QtGui/QPixmap>
#include <QtWidgets/QMainWindow>

namespace Ui {
class CullendulaMainWindow;
}

class QActionGroup;

//----------------------------------------------------------------------------

/*!
 * @file
 * @brief Main application window for interactive image culling sessions.
 */

/*!
 * @brief Top-level Qt window that wires the UI to the file-system workflow.
 *
 * The main window owns the generated widget tree, reacts to drag-and-drop
 * events, delegates file operations to CullendulaFileSystemHandler, and keeps
 * menus, status feedback, and theme state synchronized with the active session.
 */
class CullendulaMainWindow : public QMainWindow {
    Q_OBJECT

   public:
    /*!
     * @brief Supported application palette variants.
     */
    enum class ThemeMode { Light, Dark, Purple };

    /*!
     * @brief Construct the main window and initialize actions, menus, and theme.
     * @param parent Optional Qt parent widget.
     */
    explicit CullendulaMainWindow(QWidget* parent = nullptr);

    //! Destroy the main window and its generated UI object.
    ~CullendulaMainWindow() override;

    /*!
     * @brief Return the currently active application theme.
     * @return The palette mode most recently applied through the window.
     */
    ThemeMode getThemeMode() const;

   protected:
    /*!
     * @brief Accept drag payloads so image folders or files can be dropped.
     * @param event Qt drag-enter event supplied by the window system.
     */
    void dragEnterEvent(QDragEnterEvent* event) override;

    /*!
     * @brief Load the first dropped file or directory into the current session.
     * @param event Qt drop event containing local URLs.
     */
    void dropEvent(QDropEvent* event) override;

    /*!
     * @brief Re-scale the displayed preview whenever the window size changes.
     * @param event Qt resize event with the new geometry.
     */
    void resizeEvent(QResizeEvent* event) override;

    /*!
     * @brief React to runtime translator installation/removal.
     * @param event Qt change event delivered by the application.
     */
    void changeEvent(QEvent* event) override;

   private Q_SLOTS:
    //! Navigate to the previous image in the current directory session.
    void slotButtonLeftTriggered();

    //! Navigate to the next image in the current directory session.
    void slotButtonRightTriggered();

    //! Move the current image into the session's `output` directory.
    void slotButtonSaveTriggered();

    //! Move the current image into the session's `trash` directory.
    void slotButtonTrashTriggered();

    //! Show the application About dialog.
    void about();

    //! Show the Qt About dialog replacement used by this application.
    void aboutQt();

   private:
    /*!
     * @brief Show a themed, non-blocking information dialog.
     * @param title Dialog window title.
     * @param text Rich-text body shown inside the message box.
     */
    void showInformationDialog(QString const& title, QString const& text);

    //! Re-apply translatable menu, action, and window texts after a language change.
    void retranslateStaticTexts();

    /*!
     * @brief Push the checked extension menu entries into the file system handler.
     */
    void syncAllowedExtensionsToFileSystemHandler();

    /*!
     * @brief Apply one of the supported visual themes to the application.
     * @param themeMode Theme variant to activate.
     */
    void applyTheme(ThemeMode themeMode);

    /*!
     * @brief Activate a user-selected UI language and sync the menu state.
     * @param language Requested language.
     */
    void applyLanguage(CullendulaAppBootstrap::UiLanguage language);

    /*!
     * @brief Refresh the central preview and the related window state.
     *
     * The method updates the image label, button enabled state, and status bar
     * message based on whether a current image is available.
     */
    void refreshLabel();

    /*!
     * @brief Enable or disable the navigation and move buttons as a group.
     * @param active When `true`, all action buttons become usable.
     */
    void activateButtons(bool const active = false) const;

    /*!
     * @brief Show a temporary message in the status bar.
     * @param message Text to display to the user.
     */
    void printStatus(QString const& message) const;

    //! Create QAction instances for menus, shortcuts, and toolbar-style commands.
    void createActions();

    //! Create the menu bar structure and insert the previously created actions.
    void createMenus();

    //! Synchronize the enabled state of undo and redo actions with the handler.
    void updateUndoRedoButtonStatus();

    /*!
     * @brief Load an image from disk into the in-memory preview cache when needed.
     * @param path Absolute image path to display.
     */
    void loadAndCachePhoto(QString const& path);

    //! Scale the cached image to the current label size and assign it to the UI.
    void showCachedPhoto();

    //! Clear the cached preview image and its source-path bookkeeping.
    void clearCachedPhoto();

    // [members]
    //! Generated widget tree from the `.ui` file.
    Ui::CullendulaMainWindow* ui;

    //! Backend object that manages session scanning, navigation, and file moves.
    CullendulaFileSystemHandler m_fileSystemHandler;

    //! Top-level menu that groups application configuration entries.
    QMenu* m_mainMenu = nullptr;

    //! Menu that exposes the selectable file-extension filters.
    QMenu* m_extensionsMenu = nullptr;

    //! Menu that lets the user switch between theme variants.
    QMenu* m_styleMenu = nullptr;

    //! Menu that lets the user switch the UI language at runtime.
    QMenu* m_languageMenu = nullptr;

    //! One toggle action per supported image extension, keyed by lowercase suffix.
    QMap<QString, QAction*> m_extensionActions;

    //! Action that activates the light palette.
    QAction* m_lightThemeAction = nullptr;

    //! Action that activates the dark palette.
    QAction* m_darkThemeAction = nullptr;

    //! Action that activates the gloomy purple palette.
    QAction* m_purpleThemeAction = nullptr;

    //! Exclusive action group backing the theme menu.
    QActionGroup* m_themeActionGroup = nullptr;

    //! Exclusive action group backing the language menu.
    QActionGroup* m_languageActionGroup = nullptr;

    //! Action that keeps the untranslated English source strings active.
    QAction* m_englishLanguageAction = nullptr;

    //! Action that loads the German translator resource.
    QAction* m_germanLanguageAction = nullptr;

    //! Action that loads the Croatian translator resource.
    QAction* m_croatianLanguageAction = nullptr;

    //! Action that loads the Chinese translator resource.
    QAction* m_chineseLanguageAction = nullptr;

    //! Edit menu that contains undo and redo commands.
    QMenu* m_editMenu = nullptr;

    //! QAction used to trigger undo of the last move.
    QAction* m_undoAction = nullptr;

    //! QAction used to trigger redo of the last undone move.
    QAction* m_redoQtAction = nullptr;

    //! Help menu containing application and Qt information dialogs.
    QMenu* m_helpMenu = nullptr;

    //! Action that opens the application About dialog.
    QAction* m_aboutAction = nullptr;

    //! Action that opens the Qt About dialog replacement.
    QAction* m_aboutQtAction = nullptr;

    //! Theme mode currently applied to the application palette and stylesheets.
    ThemeMode m_themeMode = ThemeMode::Light;

    //! Absolute path of the image currently stored in the preview cache.
    QString m_cachedImagePath;

    //! Original-resolution pixmap for the currently displayed image.
    QPixmap m_cachedPhoto;
};
---------- end ----------
-------------------- ./src/CullendulaAppBootstrap.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

// Qt includes
#include <QtCore/QString>

class QApplication;
class CullendulaMainWindow;
class QTranslator;

/*!
 * @file
 * @brief Small startup helpers that keep the GUI bootstrap testable.
 */

namespace CullendulaAppBootstrap {
/*!
 * @brief Supported user-selectable UI languages.
 */
enum class UiLanguage { English, German, Croatian, Chinese };

namespace detail {
/*!
 * @brief Internal hooks used to test translator setup edge cases deterministically.
 */
struct TranslatorHooks {
    bool (*load)(QTranslator&, QString const&);
    bool (*install)(QApplication&, QTranslator*);
    void (*remove)(QApplication&, QTranslator*);
};

/*!
 * @brief Return the translation resource path for a specific UI language.
 * @param language Language whose embedded `.qm` resource should be used.
 * @return Qt resource path, or an empty string for untranslated English.
 */
QString translationResourcePath(UiLanguage language);

/*!
 * @brief Low-level language switch helper used by tests to inject translator behavior.
 * @param language Target language to activate.
 * @param app Application instance that should own the translator, or `nullptr`.
 * @param hooks Translator operations to use for loading and installation.
 * @return `true` when the requested language becomes active.
 */
bool setApplicationLanguage(UiLanguage language, QApplication* app, TranslatorHooks const& hooks);

/*!
 * @brief Return the production translator hooks used by the public bootstrap API.
 */
TranslatorHooks defaultTranslatorHooks();
}  // namespace detail

/*!
 * @brief Force the offscreen Qt platform plugin for headless test runs.
 *
 * Production startup should inherit the desktop platform plugin from the
 * environment. Tests can call this helper to default to the offscreen backend
 * when no explicit plugin was configured yet.
 */
void ensureQtPlatformPluginForTests();

/*!
 * @brief Show the main window during application startup.
 * @param mainWindow Main window instance to present to the user.
 */
void showMainWindow(CullendulaMainWindow& mainWindow);

/*!
 * @brief Return the currently installed application language.
 * @return Active UI language selection, with English meaning "no translator".
 */
UiLanguage getApplicationLanguage();

/*!
 * @brief Switch the application UI language at runtime.
 * @param language Target language to activate.
 * @return `true` when the requested language is active after the call.
 *
 * English keeps the untranslated source strings. Other languages are loaded
 * from embedded `.qm` resources generated during the build.
 */
bool setApplicationLanguage(UiLanguage language);

/*!
 * @brief Execute the Qt event loop for the current application instance.
 * @param app QApplication that owns the event loop.
 * @return Process exit code returned by Qt.
 */
int runEventLoop(QApplication& app);

/*!
 * @brief Optionally schedule an automatic application exit for smoke tests.
 * @param app QApplication whose event loop should be stopped automatically.
 *
 * When the environment variable `CULLENDULA_EXIT_AFTER_STARTUP_MS` is set to a
 * non-negative integer, the application will call `quit()` after that many
 * milliseconds. Normal production runs leave this unset and are unaffected.
 */
void scheduleAutoQuitForTests(QApplication& app);
}  // namespace CullendulaAppBootstrap
---------- end ----------
-------------------- ./src/CullendulaUndoStack.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

// due to concerns while thinking about the API in combination with Redo, reading about the Command/Memento-Pattern is necessary ..
// https://en.wikipedia.org/wiki/Command_pattern
// https://en.wikipedia.org/wiki/Memento_pattern

#pragma once

// Qt includes
#include <QtCore/QString>
#include <QtCore/QVector>

//----------------------------------------------------------------------------------

/*!
 * @file
 * @brief Undo/redo data structures for file move operations inside Cullendula.
 */

/*!
 * @brief Value object that describes one file move operation.
 *
 * The application models undo and redo as file renames between two absolute paths.
 * Each item therefore stores the original location and the destination location of
 * a single move so that the caller can replay the operation in either direction.
 */
class CullendulaUndoItem {
   public:
    //! Construct an empty item.
    CullendulaUndoItem() = default;
    //! Destroy the item.
    ~CullendulaUndoItem() = default;

    /*!
     * @brief Construct an item from a source and target path.
     * @param from Absolute path the file is moved from.
     * @param to Absolute path the file is moved to.
     */
    CullendulaUndoItem(QString const& from, QString const& to) : sourcePath(from), targetPath(to) {
        // nothing else to do :)
    }

    /*!
     * @brief Absolute source path of the move operation.
     *
     * For an undo item pushed by the file system handler this is the path before
     * the file was moved.
     */
    QString sourcePath;

    /*!
     * @brief Absolute destination path of the move operation.
     *
     * For an undo item pushed by the file system handler this is the path after
     * the file was moved.
     */
    QString targetPath;
};

//----------------------------------------------------------------------------------

/*!
 * @brief Lightweight undo/redo stack for file move operations.
 *
 * The stack stores move operations as pairs of absolute paths. Callers can
 * inspect the next undo/redo item without mutating the stack, then commit the
 * history transition only after the corresponding filesystem rename succeeds.
 * The class itself only manages history; callers remain responsible for
 * actually renaming files on disk.
 */
class CullendulaUndoStack {
   public:
    //! Construct an empty undo stack.
    CullendulaUndoStack() = default;

    //! Destroy the undo stack.
    ~CullendulaUndoStack() = default;

    /*!
     * @brief Append a new move operation to the undo history.
     * @param from Absolute source path before the move.
     * @param to Absolute destination path after the move.
     *
     * Pushing a new operation clears any redo history because it starts a new
     * branch of user actions.
     */
    void push(QString const& from, QString const& to);

    /*!
     * @brief Inspect the most recent undo item without mutating history.
     * @return The last operation from the undo history, or an empty default item
     *         when no undo step is available.
     */
    CullendulaUndoItem peekUndo() const;

    /*!
     * @brief Commit the most recent undo item after the caller completed it.
     *
     * The method removes the last undo entry and appends the inverse operation
     * to the redo history. Callers should invoke this only after the actual
     * undo rename succeeded on disk.
     */
    void commitUndo();

    /*!
     * @brief Inspect the most recent redo item without mutating history.
     * @return The last operation from the redo history, or an empty default item
     *         when no redo step is available.
     */
    CullendulaUndoItem peekRedo() const;

    /*!
     * @brief Commit the most recent redo item after the caller completed it.
     *
     * The method removes the last redo entry and appends the inverse operation
     * back to the undo history. Callers should invoke this only after the
     * actual redo rename succeeded on disk.
     */
    void commitRedo();

    /*!
     * @brief Check whether at least one undo step is available.
     * @return `true` when the undo history is non-empty.
     */
    bool canUndo() const;

    /*!
     * @brief Check whether at least one redo step is available.
     * @return `true` when the redo history is non-empty.
     */
    bool canRedo() const;

    /*!
     * @brief Return the current number of undo entries.
     * @return Depth of the undo stack.
     */
    long getUndoDepth() const;

    /*!
     * @brief Return the current number of redo entries.
     * @return Depth of the redo stack.
     */
    long getRedoDepth() const;

   private:
    //! Storage for operations that can currently be undone.
    QVector<CullendulaUndoItem> m_undoContainer;

    //! Storage for operations that can currently be redone.
    QVector<CullendulaUndoItem> m_redoContainer;
};
---------- end ----------
-------------------- ./src/CullendulaFileSystemHandler.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

// own includes
#include "CullendulaUndoStack.h"

// Qt includes
#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QSet>
#include <QtCore/QStringList>
#include <QtCore/QVector>

class Test_CullendulaFileSystemHandler;

//----------------------------------------------------------------------------

/*!
 * @file
 * @brief File-system facing application logic for browsing and moving images.
 */

/*!
 * @brief Manages the current image session for one working directory.
 *
 * The handler scans a directory for supported image files, keeps track of the
 * currently selected image, exposes wrap-around navigation, and moves images
 * into dedicated `output` or `trash` subdirectories. It also maintains the
 * corresponding undo/redo history for those move operations.
 */
class CullendulaFileSystemHandler {
    Q_DECLARE_TR_FUNCTIONS(CullendulaFileSystemHandler)

   public:
    //! Construct an empty handler with the default set of suggested extensions.
    CullendulaFileSystemHandler();

    /*!
     * @brief Return the preferred image suffixes supported by the current Qt setup.
     * @return Up to ten normalized, lowercase suffixes ordered by application
     *         preference and filtered against the active Qt image plugins.
     */
    static QStringList getSuggestedImageExtensions();

    /*!
     * @brief Set the image suffixes accepted for the next directory scan.
     * @param extensions Candidate suffixes without the leading dot.
     *
     * Unsupported, empty, duplicate, and differently cased values are filtered
     * and normalized to lowercase before being stored.
     */
    void setAllowedImageExtensions(QStringList const& extensions);

    /*!
     * @brief Return the currently active image suffix filter.
     * @return Sorted list of normalized suffixes without a leading dot.
     */
    QStringList getAllowedImageExtensions() const;

    /*!
     * @brief Load a new working directory or a file inside that directory.
     * @param urlPath Path provided by the UI drop operation.
     * @return `true` when the directory could be resolved, scanned, and at least
     *         one matching image is available after applying the current filter.
     *
     * Passing a file path selects its parent directory. Any previous handler
     * state and undo history are cleared before the new path is processed.
     */
    bool setWorkingPath(QString const& urlPath);

    /*!
     * @brief Return the absolute path of the currently selected image.
     * @return Absolute file path when the internal state is valid and the file
     *         still exists on disk; otherwise an empty string.
     */
    QString getCurrentImagePath();

    /*!
     * @brief Select the previous image in the current list.
     * @return `true` when the handler contains a valid image list and the
     *         selection could be advanced with wrap-around semantics.
     */
    bool switchCurrentPositionToTheLeft();

    /*!
     * @brief Select the next image in the current list.
     * @return `true` when the handler contains a valid image list and the
     *         selection could be advanced with wrap-around semantics.
     */
    bool switchCurrentPositionToTheRight();

    /*!
     * @brief Move the current image into the `output` subdirectory.
     * @return `true` when the file move succeeded and the internal image list
     *         was updated accordingly.
     */
    bool saveCurrentFile();

    /*!
     * @brief Move the current image into the `trash` subdirectory.
     * @return `true` when the file move succeeded and the internal image list
     *         was updated accordingly.
     */
    bool trashCurrentFile();

    /*!
     * @brief Return a user-facing description of the current selection.
     * @return Status text in the form `showing X of Y`.
     */
    QString getCurrentStatus() const;

    /*!
     * @brief Return the most recent user-facing error message.
     * @return Empty string when no actionable error is pending.
     */
    QString const& getLastErrorMessage() const;

    /*!
     * @brief Check whether an undo step is currently available.
     * @return `true` when at least one move can be undone.
     */
    bool canUndo();

    /*!
     * @brief Check whether a redo step is currently available.
     * @return `true` when at least one move can be redone.
     */
    bool canRedo();

    /*!
     * @brief Undo the most recent move operation on disk.
     * @return `true` when the file rename succeeded and the in-memory image list
     *         was rebuilt successfully.
     */
    bool undo();

    /*!
     * @brief Redo the most recently undone move operation on disk.
     * @return `true` when the file rename succeeded and the in-memory image list
     *         was rebuilt successfully.
     */
    bool redo();

   private:
    friend class Test_CullendulaFileSystemHandler;

    //! Reset the cached image list, current index, and undo history.
    void resetCurrentState();

    /*!
     * @brief Resolve the configured path into a usable directory and scan it.
     * @return `true` when a directory exists, at least one matching image is
     *         found, and the auxiliary output folders are ready.
     */
    bool processNewPath();

    /*!
     * @brief Rebuild the image cache from the current working directory.
     * @return `true` when at least one matching image file was found.
     */
    bool createImageFileList();

    /*!
     * @brief Rebuild the cached image list while preserving the current selection.
     * @param preferredImagePath Absolute image path to keep selected when still present.
     * @param fallbackPosition Index to clamp to when the preferred image is gone.
     * @return `true` when the rebuilt list contains at least one matching image.
     */
    bool rebuildImageFileList(QString const& preferredImagePath, int fallbackPosition);

    /*!
     * @brief Ensure that a move target subdirectory exists below the working path.
     * @param subdir Name of the subdirectory, such as `output` or `trash`.
     * @return `true` when the directory exists after the call.
     *
     * On failure this stores a user-facing error that explains whether the
     * path is blocked by a non-directory entry or the directory creation
     * attempt itself failed.
     */
    bool createOutputFolder(QString const& subdir);

    /*!
     * @brief Move the current image into a dedicated subdirectory.
     * @param subdir Name of the destination subdirectory below the working path.
     * @return `true` when the file move succeeded and the undo stack plus image
     *         selection state were updated.
     *
     * The destination directory is validated and recreated on demand so manual
     * filesystem changes after the initial load are handled gracefully.
     */
    bool moveCurrentFileToGivenSubfolder(QString const& subdir);

    /*!
     * @brief Validate the internal working directory, image list, and selection.
     * @return `true` when the handler can safely access the current image.
     */
    bool checkInternalSanity() const;

    /*!
     * @brief Shift the current image selection by a signed offset.
     * @param offset Relative number of steps to move inside the image list.
     * @return `true` when the handler was in a valid state before the shift.
     */
    bool adjustCurrentPositionBy(const int offset);

    /*!
     * @brief Find the index of an image path inside the cached image list.
     * @param imagePath Absolute path to search for.
     * @return Zero-based index when the image is present, otherwise `-1`.
     */
    int findImageIndexByPath(QString const& imagePath) const;

    /*!
     * @brief Build a collision-free destination path for a moved file.
     * @param initialTargetPath Preferred absolute destination path.
     * @return The preferred path when unused, otherwise a suffixed alternative
     *         such as `name (1).jpg`.
     */
    static QString createUniqueTargetPath(QString const& initialTargetPath);

    //! Clear the stored user-facing error state.
    void clearLastErrorMessage();

    /*!
     * @brief Store a user-facing error for the next UI query.
     * @param message Error text to expose through getLastErrorMessage().
     */
    void setLastErrorMessage(QString const& message);

    // [members]
    //! Current working directory containing the image session.
    QDir m_workingPath;

    //! Cached and sorted list of matching images in the working directory.
    QVector<QFileInfo> m_currentImages;

    //! Zero-based index into `m_currentImages`, or `-1` when no image is selected.
    int m_positionCurrentFile = -1;

    //! Undo/redo history for image move operations executed by this handler.
    CullendulaUndoStack m_undoStack;

    //! Active set of accepted image suffixes, normalized to lowercase.
    QSet<QString> m_allowedImageExtensions;

    //! Most recent user-facing error produced by a mutating operation.
    QString m_lastErrorMessage;
};

namespace CullendulaFileSystemHandlerDetail {
/*!
 * @brief Hooks used to test output-directory preparation failure paths.
 */
struct OutputFolderHooks {
    bool (*pathExists)(QString const& path);
    bool (*pathIsDirectory)(QString const& path);
    bool (*directoryExists)(QString const& path);
    bool (*mkdir)(QDir& parentDir, QString const& subdir);
};

/*!
 * @brief Build the default list of suggested image extensions from supported suffixes.
 * @param supportedSuffixes Lowercase Qt-supported image suffixes.
 * @return Up to ten normalized suffixes ordered by application preference.
 */
QStringList getSuggestedImageExtensions(QSet<QString> const& supportedSuffixes);

/*!
 * @brief Return the production hooks for output-directory handling.
 */
OutputFolderHooks defaultOutputFolderHooks();

/*!
 * @brief Prepare an application-managed subdirectory below a working path.
 * @param workingPath Parent directory used by the handler.
 * @param subdir Name of the application-managed subdirectory.
 * @param errorMessage Output parameter for a user-facing failure message.
 * @param hooks Filesystem operations to use.
 * @return `true` when the target directory exists after the call.
 */
bool createOutputFolder(QDir& workingPath, QString const& subdir, QString& errorMessage, OutputFolderHooks const& hooks);
}  // namespace CullendulaFileSystemHandlerDetail
---------- end ----------
-------------------- ./src/main.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#include "CullendulaAppBootstrap.h"
#include "CullendulaMainWindow.h"

// Qt includes
#include <QtWidgets/QApplication>

//----------------------------------------------------------------------------

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    CullendulaMainWindow mainWindow;
    CullendulaAppBootstrap::showMainWindow(mainWindow);
    CullendulaAppBootstrap::scheduleAutoQuitForTests(a);

    return CullendulaAppBootstrap::runEventLoop(a);
}
---------- end ----------
-------------------- ./src/CullendulaUndoStack.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

// own includes
#include "CullendulaUndoStack.h"

//----------------------------------------------------------------------------------

void CullendulaUndoStack::push(const QString& from, const QString& to) {
    // A new operation invalidates any redo history from an older branch.
    m_redoContainer.clear();
    m_undoContainer.append(CullendulaUndoItem(from, to));
}

//----------------------------------------------------------------------------------

CullendulaUndoItem CullendulaUndoStack::peekUndo() const { return canUndo() ? m_undoContainer.last() : CullendulaUndoItem(); }

//----------------------------------------------------------------------------------

void CullendulaUndoStack::commitUndo() {
    if (!canUndo()) {
        return;
    }

    CullendulaUndoItem const returnValue = m_undoContainer.last();
    m_undoContainer.removeLast();
    m_redoContainer.append(CullendulaUndoItem(returnValue.targetPath, returnValue.sourcePath));
}

//----------------------------------------------------------------------------------

CullendulaUndoItem CullendulaUndoStack::peekRedo() const { return canRedo() ? m_redoContainer.last() : CullendulaUndoItem(); }

//----------------------------------------------------------------------------------

void CullendulaUndoStack::commitRedo() {
    if (!canRedo()) {
        return;
    }

    CullendulaUndoItem const returnValue = m_redoContainer.last();
    m_redoContainer.removeLast();
    m_undoContainer.append(CullendulaUndoItem(returnValue.targetPath, returnValue.sourcePath));
}

//----------------------------------------------------------------------------------

bool CullendulaUndoStack::canUndo() const { return !m_undoContainer.isEmpty(); }

//----------------------------------------------------------------------------------

bool CullendulaUndoStack::canRedo() const { return !m_redoContainer.isEmpty(); }

//----------------------------------------------------------------------------------

long CullendulaUndoStack::getUndoDepth() const { return static_cast<long>(m_undoContainer.size()); }

//----------------------------------------------------------------------------------

long CullendulaUndoStack::getRedoDepth() const { return static_cast<long>(m_redoContainer.size()); }

//----------------------------------------------------------------------------------
---------- end ----------
-------------------- ./src/CullendulaMainWindow.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

// own includes
#include "CullendulaMainWindow.h"

#include "ui_CullendulaMainWindow.h"

// Qt includes
#include <QtCore/QDebug>
#include <QtCore/QEvent>
#include <QtCore/QLibraryInfo>
#include <QtCore/QMimeData>
#include <QtGui/QAction>
#include <QtGui/QActionGroup>
#include <QtGui/QColor>
#include <QtGui/QDropEvent>
#include <QtGui/QPalette>
#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QStyleFactory>

//----------------------------------------------------------------------------

// for constants
namespace {
QString applicationVersionSuffix() { return QStringLiteral(" - v" CULLENDULA_PROJECT_VERSION); }

//! Determines how long the status message stays visible.
unsigned int const c_StatusBarDelay = 5000;

//! Accounts for the window frame when fitting the preview area.
int const c_extraPixelsBecauseOfFraming = 2;

struct ThemeDefinition {
    QColor windowColor;
    QColor surfaceColor;
    QColor menuSurfaceColor;
    QColor textColor;
    QColor mutedTextColor;
    QColor borderColor;
    QColor buttonColor;
    QColor buttonHoverColor;
    QColor buttonPressedColor;
    QColor disabledButtonColor;
    QColor disabledBorderColor;
    QColor accentColor;
    QColor accentHoverColor;
    QColor accentPressedColor;
    QColor highlightColor;
    QColor tooltipBaseColor;
    QColor tooltipTextColor;
};

ThemeDefinition getLightThemeDefinition() {
    return {QColor("#f6f3ee"), QColor("#fffaf2"), QColor("#ece6dc"), QColor("#1f252d"), QColor("#7a7f86"), QColor("#c9bba8"),
            QColor("#efe2cc"), QColor("#e3d1b5"), QColor("#d3bd9d"), QColor("#ddd7ce"), QColor("#c8c0b5"), QColor("#b79d7f"),
            QColor("#d7c9b4"), QColor("#c8b08b"), QColor("#d7c9b4"), QColor("#fff6df"), QColor("#1f252d")};
}

ThemeDefinition getDarkThemeDefinition() {
    return {QColor("#0b0f14"), QColor("#131c26"), QColor("#111821"), QColor("#f4f7fb"), QColor("#7a8795"), QColor("#3e5875"),
            QColor("#16324b"), QColor("#1d4668"), QColor("#24567f"), QColor("#1b2128"), QColor("#39424d"), QColor("#79c0ff"),
            QColor("#24415f"), QColor("#2f5d87"), QColor("#24415f"), QColor("#182634"), QColor("#f4f7fb")};
}

ThemeDefinition getPurpleThemeDefinition() {
    return {QColor("#110d1b"), QColor("#171127"), QColor("#1d1630"), QColor("#f0ecff"), QColor("#9d93ba"), QColor("#53436e"),
            QColor("#372454"), QColor("#4a2f6e"), QColor("#5a3b84"), QColor("#221b31"), QColor("#3e3353"), QColor("#63d5f7"),
            QColor("#6fe3ff"), QColor("#3cc7ef"), QColor("#2a3d5e"), QColor("#171127"), QColor("#dbfaff")};
}

QPalette createThemePalette(ThemeDefinition const& theme) {
    QPalette palette;

    palette.setColor(QPalette::Window, theme.windowColor);
    palette.setColor(QPalette::WindowText, theme.textColor);
    palette.setColor(QPalette::Base, theme.surfaceColor);
    palette.setColor(QPalette::AlternateBase, theme.menuSurfaceColor);
    palette.setColor(QPalette::ToolTipBase, theme.tooltipBaseColor);
    palette.setColor(QPalette::ToolTipText, theme.tooltipTextColor);
    palette.setColor(QPalette::Text, theme.textColor);
    palette.setColor(QPalette::Button, theme.buttonColor);
    palette.setColor(QPalette::ButtonText, theme.textColor);
    palette.setColor(QPalette::BrightText, Qt::white);
    palette.setColor(QPalette::Link, theme.accentColor);
    palette.setColor(QPalette::Highlight, theme.highlightColor);
    palette.setColor(QPalette::HighlightedText, theme.textColor);
    palette.setColor(QPalette::PlaceholderText, theme.mutedTextColor);

    palette.setColor(QPalette::Disabled, QPalette::WindowText, theme.mutedTextColor);
    palette.setColor(QPalette::Disabled, QPalette::Text, theme.mutedTextColor);
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, theme.mutedTextColor);
    palette.setColor(QPalette::Disabled, QPalette::Button, theme.disabledButtonColor);
    palette.setColor(QPalette::Disabled, QPalette::Highlight, theme.disabledBorderColor);

    return palette;
}

QString getStandardThemeStyleSheet(ThemeDefinition const& theme) {
    return QStringLiteral(
               "QMainWindow, QDialog, QMessageBox {"
               "    background-color: %1;"
               "    color: %2;"
               "}"
               "QWidget#centralWidget {"
               "    background-color: %1;"
               "    color: %2;"
               "}"
               "QMenuBar {"
               "    background-color: %3;"
               "    color: %2;"
               "}"
               "QMenuBar::item:selected {"
               "    background-color: %4;"
               "}"
               "QMenu {"
               "    background-color: %5;"
               "    color: %2;"
               "    border: 1px solid %6;"
               "}"
               "QMenu::item:selected {"
               "    background-color: %4;"
               "}"
               "QToolTip {"
               "    background-color: %5;"
               "    color: %7;"
               "    border: 1px solid %6;"
               "}"
               "QLabel#centerLabel {"
               "    background-color: %5;"
               "    color: %2;"
               "    border: 2px solid %8;"
               "    padding: 18px;"
               "}"
               "QLabel {"
               "    color: %2;"
               "}"
               "QMessageBox QLabel {"
               "    color: %2;"
               "}"
               "QPushButton {"
               "    background-color: %9;"
               "    color: %2;"
               "    border: 1px solid %8;"
               "    border-radius: 6px;"
               "    padding: 8px 14px;"
               "}"
               "QPushButton:hover:!disabled {"
               "    background-color: %10;"
               "}"
               "QPushButton:pressed:!disabled {"
               "    background-color: %11;"
               "}"
               "QPushButton:disabled {"
               "    background-color: %12;"
               "    color: %13;"
               "    border-color: %14;"
               "}"
               "QStatusBar {"
               "    background-color: %3;"
               "    color: %2;"
               "}"
               "QStatusBar::item {"
               "    border: none;"
               "}")
        .arg(theme.windowColor.name(), theme.textColor.name(), theme.menuSurfaceColor.name(), theme.highlightColor.name(), theme.surfaceColor.name(),
             theme.borderColor.name(), theme.tooltipTextColor.name(), theme.accentColor.name(), theme.buttonColor.name(), theme.buttonHoverColor.name(),
             theme.buttonPressedColor.name(), theme.disabledButtonColor.name(), theme.mutedTextColor.name(), theme.disabledBorderColor.name());
}

QString getPurpleThemeStyleSheet(ThemeDefinition const& theme) {
    return QStringLiteral(
               "QMainWindow, QDialog, QMessageBox {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %15);"
               "    color: %2;"
               "}"
               "QWidget#centralWidget {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %15);"
               "    color: %2;"
               "}"
               "QMenuBar {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %3, stop:1 %16);"
               "    color: %2;"
               "}"
               "QMenuBar::item:selected {"
               "    background-color: %4;"
               "}"
               "QMenu {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 %5, stop:1 %15);"
               "    color: %2;"
               "    border: 1px solid %6;"
               "}"
               "QMenu::item:selected {"
               "    background-color: %4;"
               "}"
               "QToolTip {"
               "    background-color: %5;"
               "    color: %7;"
               "    border: 1px solid %6;"
               "}"
               "QLabel#centerLabel {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %5, stop:1 %15);"
               "    color: %2;"
               "    border: 2px solid %8;"
               "    padding: 18px;"
               "}"
               "QLabel {"
               "    color: %2;"
               "}"
               "QMessageBox QLabel {"
               "    color: %2;"
               "}"
               "QPushButton {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %9, stop:1 %17);"
               "    color: %2;"
               "    border: 1px solid %8;"
               "    border-radius: 6px;"
               "    padding: 8px 14px;"
               "}"
               "QPushButton:hover:!disabled {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %10, stop:1 %8);"
               "}"
               "QPushButton:pressed:!disabled {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %11, stop:1 %14);"
               "}"
               "QPushButton:disabled {"
               "    background-color: %12;"
               "    color: %13;"
               "    border-color: %14;"
               "}"
               "QStatusBar {"
               "    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 %3, stop:1 %16);"
               "    color: %2;"
               "}"
               "QStatusBar::item {"
               "    border: none;"
               "}")
        .arg(theme.windowColor.name(), theme.textColor.name(), theme.menuSurfaceColor.name(), theme.highlightColor.name(), theme.surfaceColor.name(),
             theme.borderColor.name(), theme.tooltipTextColor.name(), theme.accentColor.name(), theme.buttonColor.name(), theme.buttonHoverColor.name(),
             theme.buttonPressedColor.name(), theme.disabledButtonColor.name(), theme.mutedTextColor.name(), theme.disabledBorderColor.name(),
             theme.tooltipBaseColor.name(), theme.highlightColor.darker(155).name(), theme.buttonPressedColor.darker(135).name());
}
}  // namespace

//----------------------------------------------------------------------------

CullendulaMainWindow::CullendulaMainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::CullendulaMainWindow) {
    setAcceptDrops(true);
    ui->setupUi(this);

    // make the current version information visible to the user - as long as no menu with help&stuff exists
    // disable the buttons immediately; until the directory is set
    activateButtons(false);

    // connects for the usable push-buttons (and their hot keys)
    connect(ui->leftPB, &QPushButton::clicked, this, &CullendulaMainWindow::slotButtonLeftTriggered);
    connect(ui->rightPB, &QPushButton::clicked, this, &CullendulaMainWindow::slotButtonRightTriggered);
    connect(ui->savePB, &QPushButton::clicked, this, &CullendulaMainWindow::slotButtonSaveTriggered);
    connect(ui->trashPB, &QPushButton::clicked, this, &CullendulaMainWindow::slotButtonTrashTriggered);

    // necessary! even if the QLabel itself accepts already drops
    setAcceptDrops(true);

    // create the menu
    createActions();
    createMenus();
    retranslateStaticTexts();
    applyTheme(ThemeMode::Light);
    applyLanguage(CullendulaAppBootstrap::getApplicationLanguage());
    syncAllowedExtensionsToFileSystemHandler();

    // set undo/redo correctly
    updateUndoRedoButtonStatus();

    //: Status bar message shown once after the main window is fully initialized.
    printStatus(tr("system is up and running :)"));
}

//----------------------------------------------------------------------------

CullendulaMainWindow::~CullendulaMainWindow() { delete ui; }

//----------------------------------------------------------------------------

CullendulaMainWindow::ThemeMode CullendulaMainWindow::getThemeMode() const { return m_themeMode; }

//----------------------------------------------------------------------------

void CullendulaMainWindow::changeEvent(QEvent* event) {
    QMainWindow::changeEvent(event);

    if (event != nullptr && event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
        retranslateStaticTexts();
        refreshLabel();
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::dragEnterEvent(QDragEnterEvent* event) {
    if (event != nullptr && event->mimeData() != nullptr && event->mimeData()->hasUrls() && !event->mimeData()->urls().isEmpty()) {
        event->acceptProposedAction();
        //: Status bar prompt during drag-and-drop after the payload was recognized as file-system URLs.
        printStatus(tr("drop current load and let's see what you dragged?"));
        return;
    }

    if (event != nullptr) {
        event->ignore();
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::dropEvent(QDropEvent* event) {
    const QMimeData* mimeData = event->mimeData();

    // check for our needed mime type, here a file or a list of files
    if (mimeData->hasUrls()) {
        const QList<QUrl> urlList = mimeData->urls();

        // extract the local paths of the files: print all of them; can be removed laters
        qDebug() << "new drop:";
        for (auto const& url : urlList) {
            qDebug() << "\tdropped: " << url;
        }

        // just use the very first one ..
        if (!urlList.isEmpty()) {
            bool const success = m_fileSystemHandler.setWorkingPath(urlList.first().path());
            refreshLabel();
            updateUndoRedoButtonStatus();
            if (!success) {
                QString const errorMessage = m_fileSystemHandler.getLastErrorMessage();
                if (!errorMessage.isEmpty()) {
                    printStatus(errorMessage);
                } else {
                    qDebug() << "\tNo matching image files found for the current filter";
                }
            }
        }
    } else {
        //: Status bar error after a drop payload was rejected because it did not contain usable local file URLs.
        printStatus(tr("The load was not usable! :("));
    }

    event->acceptProposedAction();
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::resizeEvent(QResizeEvent* event) {
    qDebug() << "CullendulaMainWindow::resizeEvent()";

    QMainWindow::resizeEvent(event);

    // reload the current picture (or text)
    refreshLabel();
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::slotButtonLeftTriggered() {
    qDebug() << "CullendulaMainWindow::slotButtonLeftTriggered()";

    bool const success = m_fileSystemHandler.switchCurrentPositionToTheLeft();
    // check if that was successful and then refresh
    if (success) {
        refreshLabel();
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::slotButtonRightTriggered() {
    qDebug() << "CullendulaMainWindow::slotButtonRightTriggered()";

    bool const success = m_fileSystemHandler.switchCurrentPositionToTheRight();
    // check if that was successful and then refresh
    if (success) {
        refreshLabel();
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::slotButtonSaveTriggered() {
    qDebug() << "CullendulaMainWindow::slotButtonSaveTriggered()";

    // move the current file to the output-folder
    bool const success = m_fileSystemHandler.saveCurrentFile();
    if (success) {
        refreshLabel();
        // set undo/redo correctly
        updateUndoRedoButtonStatus();
    } else {
        QString const errorMessage = m_fileSystemHandler.getLastErrorMessage();
        //: Fallback status bar error after moving the current image to the "output" folder failed without a more specific message.
        printStatus(errorMessage.isEmpty() ? tr("Could not save the current file.") : errorMessage);
        qDebug() << "\tERROR: moving file did not succeed";
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::slotButtonTrashTriggered() {
    qDebug() << "CullendulaMainWindow::slotButtonTrashTriggered()";

    // Move the current file into the trash folder.
    bool const success = m_fileSystemHandler.trashCurrentFile();
    if (success) {
        refreshLabel();
        // set undo/redo correctly
        updateUndoRedoButtonStatus();
    } else {
        QString const errorMessage = m_fileSystemHandler.getLastErrorMessage();
        //: Fallback status bar error after moving the current image to the "trash" folder failed without a more specific message.
        printStatus(errorMessage.isEmpty() ? tr("Could not trash the current file.") : errorMessage);
        qDebug() << "\tERROR: moving file did not succeed";
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::loadAndCachePhoto(QString const& path) {
    if (m_cachedImagePath == path && !m_cachedPhoto.isNull()) {
        return;
    }

    qDebug() << "CullendulaMainWindow::loadAndCachePhoto(): path=" << path;

    QPixmap const pixmap(path);
    if (pixmap.isNull()) {
        clearCachedPhoto();
        return;
    }

    m_cachedImagePath = path;
    m_cachedPhoto = pixmap;
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::showCachedPhoto() {
    if (m_cachedPhoto.isNull()) {
        ui->centerLabel->clear();
        return;
    }

    // scale while keeping the aspect ratio
    int width = ui->centerLabel->width() - c_extraPixelsBecauseOfFraming;
    int height = ui->centerLabel->height() - c_extraPixelsBecauseOfFraming;

    // prevent upscaling of smaller photos
    if (m_cachedPhoto.width() < width) {
        width = m_cachedPhoto.width();
    }

    if (m_cachedPhoto.height() < height) {
        height = m_cachedPhoto.height();
    }

    // assert that both values are positive
    width = std::max(0, width);
    height = std::max(0, height);

    // set a scaled pixmap keeping its aspect ratio
    ui->centerLabel->setPixmap(m_cachedPhoto.scaled(width, height, Qt::KeepAspectRatio));
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::clearCachedPhoto() {
    m_cachedImagePath.clear();
    m_cachedPhoto = QPixmap();
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::refreshLabel() {
    qDebug() << "CullendulaMainWindow::refreshLabel():";

    QString const path = m_fileSystemHandler.getCurrentImagePath();
    if (path.isEmpty()) {
        clearCachedPhoto();
        //: Center label placeholder when no further images match the current extension filter in the active directory.
        ui->centerLabel->setText(
            tr("no more valid images found: work maybe finished? :)\n"
               "drag&drop the next folder or files if you want!"));

        activateButtons(false);

        //: Status bar message when the current directory no longer contains any matching images to show.
        printStatus(tr("no more files"));
    } else {
        if (QFile::exists(path)) {
            loadAndCachePhoto(path);
            if (m_cachedPhoto.isNull()) {
                clearCachedPhoto();
                //: Error shown both in the center label and the status bar when Qt cannot render the current image preview.
                ui->centerLabel->setText(tr("could not load the current image preview"));
                activateButtons(false);
                printStatus(tr("could not load the current image preview"));
                return;
            }

            // scale the cached file to the current label geometry
            showCachedPhoto();

            activateButtons(true);

            // print the current file-path as user-notification
            QString const message = m_fileSystemHandler.getCurrentStatus() + ": " + path;
            printStatus(message);
        } else {
            clearCachedPhoto();
            qDebug() << "CullendulaMainWindow::refreshLabel(): given path did not exist: " << path;
        }
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::activateButtons(const bool active) const {
    // en-/disable all four buttons
    ui->leftPB->setEnabled(active);
    ui->rightPB->setEnabled(active);
    ui->savePB->setEnabled(active);
    ui->trashPB->setEnabled(active);
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::printStatus(const QString& message) const {
    // messages shall disappear after five seconds
    ui->statusBar->showMessage(message, c_StatusBarDelay);
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::createActions() {
    QStringList const suggestedExtensions = CullendulaFileSystemHandler::getSuggestedImageExtensions();
    for (QString const& extension : suggestedExtensions) {
        QAction* extensionAction = new QAction(extension.toUpper(), this);
        extensionAction->setCheckable(true);
        extensionAction->setChecked(true);
        extensionAction->setObjectName("extensionAction_" + extension);
        //: Tooltip for a checkable menu entry that enables a filename extension such as jpg, png, or webp for future directory scans.
        extensionAction->setStatusTip(tr("Enable loading of *.%1 files when opening the next directory").arg(extension));
        connect(extensionAction, &QAction::toggled, this, [this]() { syncAllowedExtensionsToFileSystemHandler(); });
        m_extensionActions.insert(extension, extensionAction);
    }

    m_themeActionGroup = new QActionGroup(this);
    m_themeActionGroup->setExclusive(true);

    //: Menu label for the light visual theme.
    m_lightThemeAction = new QAction(tr("Light"), this);
    m_lightThemeAction->setCheckable(true);
    m_lightThemeAction->setObjectName("themeAction_light");
    //: Tooltip for switching the whole application to the light theme.
    m_lightThemeAction->setStatusTip(tr("Use the light application theme"));
    connect(m_lightThemeAction, &QAction::triggered, this, [this]() { applyTheme(ThemeMode::Light); });
    m_themeActionGroup->addAction(m_lightThemeAction);

    //: Menu label for the dark visual theme.
    m_darkThemeAction = new QAction(tr("Dark"), this);
    m_darkThemeAction->setCheckable(true);
    m_darkThemeAction->setObjectName("themeAction_dark");
    //: Tooltip for switching the whole application to the dark theme.
    m_darkThemeAction->setStatusTip(tr("Use the high-contrast dark application theme"));
    connect(m_darkThemeAction, &QAction::triggered, this, [this]() { applyTheme(ThemeMode::Dark); });
    m_themeActionGroup->addAction(m_darkThemeAction);

    //: Menu label for the gloomy purple visual theme.
    m_purpleThemeAction = new QAction(tr("Purple"), this);
    m_purpleThemeAction->setCheckable(true);
    m_purpleThemeAction->setObjectName("themeAction_purple");
    //: Tooltip for switching the whole application to the gloomy purple-and-cyan theme.
    m_purpleThemeAction->setStatusTip(tr("Use the gloomy purple application theme"));
    connect(m_purpleThemeAction, &QAction::triggered, this, [this]() { applyTheme(ThemeMode::Purple); });
    m_themeActionGroup->addAction(m_purpleThemeAction);

    m_languageActionGroup = new QActionGroup(this);
    m_languageActionGroup->setExclusive(true);

    //: Language menu entry naming the English user-interface language.
    m_englishLanguageAction = new QAction(tr("English"), this);
    m_englishLanguageAction->setCheckable(true);
    m_englishLanguageAction->setObjectName("languageAction_en");
    connect(m_englishLanguageAction, &QAction::triggered, this, [this]() { applyLanguage(CullendulaAppBootstrap::UiLanguage::English); });
    m_languageActionGroup->addAction(m_englishLanguageAction);

    //: Language menu entry naming the German user-interface language in German.
    m_germanLanguageAction = new QAction(tr("Deutsch"), this);
    m_germanLanguageAction->setCheckable(true);
    m_germanLanguageAction->setObjectName("languageAction_de");
    connect(m_germanLanguageAction, &QAction::triggered, this, [this]() { applyLanguage(CullendulaAppBootstrap::UiLanguage::German); });
    m_languageActionGroup->addAction(m_germanLanguageAction);

    //: Language menu entry naming the Croatian user-interface language in Croatian.
    m_croatianLanguageAction = new QAction(tr("Hrvatski"), this);
    m_croatianLanguageAction->setCheckable(true);
    m_croatianLanguageAction->setObjectName("languageAction_hr");
    connect(m_croatianLanguageAction, &QAction::triggered, this, [this]() { applyLanguage(CullendulaAppBootstrap::UiLanguage::Croatian); });
    m_languageActionGroup->addAction(m_croatianLanguageAction);

    //: Language menu entry naming the Chinese user-interface language in Chinese.
    m_chineseLanguageAction = new QAction(tr("ä¸­æ–‡"), this);
    m_chineseLanguageAction->setCheckable(true);
    m_chineseLanguageAction->setObjectName("languageAction_zh_CN");
    connect(m_chineseLanguageAction, &QAction::triggered, this, [this]() { applyLanguage(CullendulaAppBootstrap::UiLanguage::Chinese); });
    m_languageActionGroup->addAction(m_chineseLanguageAction);

    //: Edit menu action label that reverses the most recent file move.
    m_undoAction = new QAction(tr("Undo"), this);
    //: Tooltip for the Undo action that moves the previously moved image back to its original location.
    m_undoAction->setStatusTip(tr("Revert the last file-move-operation"));
    m_undoAction->setShortcut(Qt::CTRL | Qt::Key_Y);
    connect(m_undoAction, &QAction::triggered, this, [=]() {
        qDebug("pressed Undo");
        if (m_fileSystemHandler.undo()) {
            refreshLabel();
        } else {
            QString const errorMessage = m_fileSystemHandler.getLastErrorMessage();
            //: Fallback status bar error after an undo request failed without a more specific message.
            printStatus(errorMessage.isEmpty() ? tr("Could not undo the last file move.") : errorMessage);
        }
        updateUndoRedoButtonStatus();
    });

    //: Edit menu action label that reapplies the most recently undone file move.
    m_redoQtAction = new QAction(tr("Redo"), this);
    //: Tooltip for the Redo action. "undo undo" here means reapplied after an Undo.
    m_redoQtAction->setStatusTip(tr("Redo the last file-move-operation (means: undo undo)"));
    m_redoQtAction->setShortcut(Qt::CTRL | Qt::Key_Z);
    connect(m_redoQtAction, &QAction::triggered, this, [=]() {
        qDebug("pressed Redo");
        if (m_fileSystemHandler.redo()) {
            refreshLabel();
        } else {
            QString const errorMessage = m_fileSystemHandler.getLastErrorMessage();
            //: Fallback status bar error after a redo request failed without a more specific message.
            printStatus(errorMessage.isEmpty() ? tr("Could not redo the last file move.") : errorMessage);
        }
        updateUndoRedoButtonStatus();
    });

    // help menu
    //: Help menu action label that opens the application's About dialog.
    m_aboutAction = new QAction(tr("About Cullendula"), this);
    //: Tooltip for opening the application's About dialog.
    m_aboutAction->setStatusTip(tr("Show the application's About box"));
    m_aboutAction->setShortcut(Qt::CTRL | Qt::Key_A);
    connect(m_aboutAction, &QAction::triggered, this, &CullendulaMainWindow::about);

    //: Help menu action label that opens Qt's built-in About dialog.
    m_aboutQtAction = new QAction(tr("About Qt"), this);
    //: Tooltip for opening Qt's built-in About dialog.
    m_aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    m_aboutQtAction->setShortcut(Qt::CTRL | Qt::Key_Q);
    connect(m_aboutQtAction, &QAction::triggered, this, &CullendulaMainWindow::aboutQt);
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::createMenus() {
    // main menu
    m_mainMenu = menuBar()->addMenu(QString());
    m_extensionsMenu = m_mainMenu->addMenu(QString());
    for (QAction* extensionAction : m_extensionActions) {
        m_extensionsMenu->addAction(extensionAction);
    }
    m_styleMenu = m_mainMenu->addMenu(QString());
    m_styleMenu->addAction(m_lightThemeAction);
    m_styleMenu->addAction(m_darkThemeAction);
    m_styleMenu->addAction(m_purpleThemeAction);
    m_languageMenu = m_mainMenu->addMenu(QString());
    m_languageMenu->addAction(m_englishLanguageAction);
    m_languageMenu->addAction(m_germanLanguageAction);
    m_languageMenu->addAction(m_croatianLanguageAction);
    m_languageMenu->addAction(m_chineseLanguageAction);

    // edit menu
    m_editMenu = menuBar()->addMenu(QString());
    m_editMenu->addAction(m_undoAction);
    m_editMenu->addAction(m_redoQtAction);

    // help menu
    m_helpMenu = menuBar()->addMenu(QString());
    m_helpMenu->addAction(m_aboutAction);
    m_helpMenu->addAction(m_aboutQtAction);
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::retranslateStaticTexts() {
    //: Main window title; the version suffix is appended separately in code.
    setWindowTitle(tr("Cullendula") + applicationVersionSuffix());

    if (m_mainMenu != nullptr) {
        //: Top-level menu containing application settings such as extensions, style, and language.
        m_mainMenu->setTitle(tr("Main"));
    }

    if (m_extensionsMenu != nullptr) {
        //: Submenu listing the enabled image filename extensions for directory scanning.
        m_extensionsMenu->setTitle(tr("Extensions"));
    }

    if (m_styleMenu != nullptr) {
        //: Submenu for switching between visual themes.
        m_styleMenu->setTitle(tr("Style"));
    }

    if (m_languageMenu != nullptr) {
        //: Submenu for switching the user-interface language.
        m_languageMenu->setTitle(tr("Language"));
    }

    for (auto it = m_extensionActions.begin(); it != m_extensionActions.end(); ++it) {
        if (it.value() != nullptr) {
            it.value()->setText(it.key().toUpper());
            //: Tooltip for a checkable menu entry that enables a filename extension such as jpg, png, or webp for future directory scans.
            it.value()->setStatusTip(tr("Enable loading of *.%1 files when opening the next directory").arg(it.key()));
        }
    }

    if (m_lightThemeAction != nullptr) {
        //: Menu label for the light visual theme.
        m_lightThemeAction->setText(tr("Light"));
        //: Tooltip for switching the whole application to the light theme.
        m_lightThemeAction->setStatusTip(tr("Use the light application theme"));
    }

    if (m_darkThemeAction != nullptr) {
        //: Menu label for the dark visual theme.
        m_darkThemeAction->setText(tr("Dark"));
        //: Tooltip for switching the whole application to the dark theme.
        m_darkThemeAction->setStatusTip(tr("Use the high-contrast dark application theme"));
    }

    if (m_purpleThemeAction != nullptr) {
        //: Menu label for the gloomy purple visual theme.
        m_purpleThemeAction->setText(tr("Purple"));
        //: Tooltip for switching the whole application to the gloomy purple-and-cyan theme.
        m_purpleThemeAction->setStatusTip(tr("Use the gloomy purple application theme"));
    }

    if (m_englishLanguageAction != nullptr) {
        //: Language menu entry naming the English user-interface language.
        m_englishLanguageAction->setText(tr("English"));
        //: Tooltip for switching back to the original English source texts.
        m_englishLanguageAction->setStatusTip(tr("Use the default English source texts"));
    }

    if (m_germanLanguageAction != nullptr) {
        //: Language menu entry naming the German user-interface language in German.
        m_germanLanguageAction->setText(tr("Deutsch"));
        //: Tooltip for loading the German translation file.
        m_germanLanguageAction->setStatusTip(tr("Load the German user-interface translation"));
    }

    if (m_croatianLanguageAction != nullptr) {
        //: Language menu entry naming the Croatian user-interface language in Croatian.
        m_croatianLanguageAction->setText(tr("Hrvatski"));
        //: Tooltip for loading the Croatian translation file.
        m_croatianLanguageAction->setStatusTip(tr("Load the Croatian user-interface translation"));
    }

    if (m_chineseLanguageAction != nullptr) {
        //: Language menu entry naming the Chinese user-interface language in Chinese.
        m_chineseLanguageAction->setText(tr("ä¸­æ–‡"));
        //: Tooltip for loading the Simplified Chinese translation file.
        m_chineseLanguageAction->setStatusTip(tr("Load the Chinese user-interface translation"));
    }

    if (m_editMenu != nullptr) {
        //: Top-level menu for undo and redo actions.
        m_editMenu->setTitle(tr("Edit"));
    }

    if (m_undoAction != nullptr) {
        //: Edit menu action label that reverses the most recent file move.
        m_undoAction->setText(tr("Undo"));
        //: Tooltip for the Undo action that moves the previously moved image back to its original location.
        m_undoAction->setStatusTip(tr("Revert the last file-move-operation"));
    }

    if (m_redoQtAction != nullptr) {
        //: Edit menu action label that reapplies the most recently undone file move.
        m_redoQtAction->setText(tr("Redo"));
        //: Tooltip for the Redo action. "undo undo" here means reapplied after an Undo.
        m_redoQtAction->setStatusTip(tr("Redo the last file-move-operation (means: undo undo)"));
    }

    if (m_helpMenu != nullptr) {
        //: Top-level menu for About dialogs and other help-related actions.
        m_helpMenu->setTitle(tr("Help"));
    }

    if (m_aboutAction != nullptr) {
        //: Help menu action label that opens the application's About dialog.
        m_aboutAction->setText(tr("About Cullendula"));
        //: Tooltip for opening the application's About dialog.
        m_aboutAction->setStatusTip(tr("Show the application's About box"));
    }

    if (m_aboutQtAction != nullptr) {
        //: Help menu action label that opens Qt's built-in About dialog.
        m_aboutQtAction->setText(tr("About Qt"));
        //: Tooltip for opening Qt's built-in About dialog.
        m_aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::syncAllowedExtensionsToFileSystemHandler() {
    QStringList enabledExtensions;
    for (auto it = m_extensionActions.cbegin(); it != m_extensionActions.cend(); ++it) {
        if (it.value()->isChecked()) {
            enabledExtensions.append(it.key());
        }
    }

    m_fileSystemHandler.setAllowedImageExtensions(enabledExtensions);
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::applyLanguage(CullendulaAppBootstrap::UiLanguage language) {
    if (!CullendulaAppBootstrap::setApplicationLanguage(language)) {
        //: Status bar error when loading the requested translation catalog failed.
        printStatus(tr("Could not load the selected language."));
        return;
    }

    if (m_englishLanguageAction != nullptr) {
        m_englishLanguageAction->setChecked(language == CullendulaAppBootstrap::UiLanguage::English);
    }

    if (m_germanLanguageAction != nullptr) {
        m_germanLanguageAction->setChecked(language == CullendulaAppBootstrap::UiLanguage::German);
    }

    if (m_croatianLanguageAction != nullptr) {
        m_croatianLanguageAction->setChecked(language == CullendulaAppBootstrap::UiLanguage::Croatian);
    }

    if (m_chineseLanguageAction != nullptr) {
        m_chineseLanguageAction->setChecked(language == CullendulaAppBootstrap::UiLanguage::Chinese);
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::applyTheme(ThemeMode themeMode) {
    m_themeMode = themeMode;
    ThemeDefinition theme;
    QString styleSheet;
    switch (themeMode) {
        case ThemeMode::Light:
            theme = getLightThemeDefinition();
            styleSheet = getStandardThemeStyleSheet(theme);
            break;
        case ThemeMode::Dark:
            theme = getDarkThemeDefinition();
            styleSheet = getStandardThemeStyleSheet(theme);
            break;
        case ThemeMode::Purple:
            theme = getPurpleThemeDefinition();
            styleSheet = getPurpleThemeStyleSheet(theme);
            break;
    }

    if (qApp != nullptr) {
        qApp->setStyle(QStyleFactory::create("Fusion"));
        qApp->setPalette(createThemePalette(theme));
        qApp->setStyleSheet(styleSheet);
    }

    if (m_lightThemeAction != nullptr) {
        m_lightThemeAction->setChecked(themeMode == ThemeMode::Light);
    }

    if (m_darkThemeAction != nullptr) {
        m_darkThemeAction->setChecked(themeMode == ThemeMode::Dark);
    }

    if (m_purpleThemeAction != nullptr) {
        m_purpleThemeAction->setChecked(themeMode == ThemeMode::Purple);
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::updateUndoRedoButtonStatus() {
    if (m_undoAction != nullptr) {
        m_undoAction->setEnabled(m_fileSystemHandler.canUndo());
    }

    if (m_redoQtAction != nullptr) {
        m_redoQtAction->setEnabled(m_fileSystemHandler.canRedo());
    }
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::about() {
    //: Status bar trace shown when the user opens the application's About dialog from the Help menu.
    printStatus(tr("Invoked Help|About"));
    //: Title of the application's About dialog.
    showInformationDialog(tr("About Cullendula"),
                          //: Rich-text body of the application's About dialog.
                          tr("Helper program to sort out (\"cull\") a collection of pictures in a directory after a nice photo-walk or event.<br>"
                             "Should work cross-platform.<br>"
                             "<br>"
                             "Developed by <a href='mail@marcelpetrick.it'>mail@marcelpetrick.it</a><br>"
                             "Source code can be found inside the repository at <a "
                             "href='https://github.com/marcelpetrick/Cullendula/'>https://github.com/marcelpetrick/Cullendula</a><br>"
                             "Feel free to use and share: GPL v3 :3"));
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::aboutQt() {
    //: Status bar trace shown when the user opens Qt's About dialog from the Help menu.
    printStatus(tr("Invoked Help|About Qt"));
    //: Title of the Qt runtime information dialog.
    //: Rich-text body of the Qt runtime information dialog. %1 is the Qt version, %2 is the Qt installation prefix path.
    showInformationDialog(tr("About Qt"), tr("This application currently runs with Qt %1.<br>"
                                             "Qt installation prefix: %2<br>"
                                             "<br>"
                                             "Qt is a cross-platform application framework for building desktop and embedded applications.")
                                              .arg(QString::fromLatin1(qVersion()), QLibraryInfo::path(QLibraryInfo::PrefixPath)));
}

//----------------------------------------------------------------------------

void CullendulaMainWindow::showInformationDialog(QString const& title, QString const& text) {
    auto* messageBox = new QMessageBox(QMessageBox::Information, title, text, QMessageBox::Ok, this);
    messageBox->setAttribute(Qt::WA_DeleteOnClose, true);
    messageBox->setTextFormat(Qt::RichText);
    messageBox->open();
}

//----------------------------------------------------------------------------
---------- end ----------
-------------------- ./src/CMakeLists.txt --------------------
#
# Library containing all core + UI logic (except main.cpp)
#
add_library(CullendulaLib
    CullendulaAppBootstrap.cpp
    CullendulaMainWindow.cpp
    CullendulaFileSystemHandler.cpp
    CullendulaUndoStack.cpp

    CullendulaAppBootstrap.h
    CullendulaMainWindow.h
    CullendulaFileSystemHandler.h
    CullendulaUndoStack.h

    CullendulaMainWindow.ui
)

target_link_libraries(CullendulaLib
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Expose src/ headers to targets linking CullendulaLib.
target_include_directories(CullendulaLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions(CullendulaLib
    PUBLIC
        CULLENDULA_PROJECT_VERSION="${PROJECT_VERSION}"
)

#
# GUI Application â€” links to the library
#
add_executable(Cullendula
    main.cpp
    ../media/cullendula.rc
)

target_link_libraries(Cullendula
    PRIVATE CullendulaLib
)

# Windows subsystem settings (optional)
if(WIN32)
    set_target_properties(Cullendula PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
---------- end ----------
-------------------- ./src/CullendulaAppBootstrap.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#include "CullendulaAppBootstrap.h"

#include <QtCore/QByteArray>
#include <QtCore/QProcessEnvironment>
#include <QtCore/QTimer>
#include <QtCore/QTranslator>
#include <QtWidgets/QApplication>
#include <memory>

#include "CullendulaMainWindow.h"

namespace {
std::unique_ptr<QTranslator>& applicationTranslator() {
    static std::unique_ptr<QTranslator> translator;
    return translator;
}

CullendulaAppBootstrap::UiLanguage& currentApplicationLanguage() {
    static CullendulaAppBootstrap::UiLanguage currentLanguage = CullendulaAppBootstrap::UiLanguage::English;
    return currentLanguage;
}

bool loadTranslator(QTranslator& translator, QString const& resourcePath) { return translator.load(resourcePath); }

bool installTranslator(QApplication& app, QTranslator* translator) { return app.installTranslator(translator); }

void removeTranslator(QApplication& app, QTranslator* translator) { app.removeTranslator(translator); }
}  // namespace

QString CullendulaAppBootstrap::detail::translationResourcePath(UiLanguage language) {
    switch (language) {
        case UiLanguage::German:
            return QString(":/i18n/Cullendula_de.qm");
        case UiLanguage::Croatian:
            return QString(":/i18n/Cullendula_hr.qm");
        case UiLanguage::Chinese:
            return QString(":/i18n/Cullendula_zh_CN.qm");
        case UiLanguage::English:
            break;
    }

    return {};
}

CullendulaAppBootstrap::detail::TranslatorHooks CullendulaAppBootstrap::detail::defaultTranslatorHooks() {
    return TranslatorHooks{loadTranslator, installTranslator, removeTranslator};
}

bool CullendulaAppBootstrap::detail::setApplicationLanguage(UiLanguage language, QApplication* app, TranslatorHooks const& hooks) {
    if (app == nullptr) {
        return false;
    }

    if (language == UiLanguage::English) {
        if (applicationTranslator()) {
            hooks.remove(*app, applicationTranslator().get());
            applicationTranslator().reset();
        }
        currentApplicationLanguage() = UiLanguage::English;
        return true;
    }

    QString const resourcePath = translationResourcePath(language);
    if (resourcePath.isEmpty()) {
        return false;
    }

    auto nextTranslator = std::make_unique<QTranslator>();
    if (!hooks.load(*nextTranslator, resourcePath)) {
        return false;
    }

    if (applicationTranslator()) {
        hooks.remove(*app, applicationTranslator().get());
    }

    applicationTranslator() = std::move(nextTranslator);
    if (!hooks.install(*app, applicationTranslator().get())) {
        applicationTranslator().reset();
        return false;
    }

    currentApplicationLanguage() = language;
    return true;
}

void CullendulaAppBootstrap::ensureQtPlatformPluginForTests() {
    if (qEnvironmentVariableIsEmpty("QT_QPA_PLATFORM")) {
        qputenv("QT_QPA_PLATFORM", QByteArray("offscreen"));
    }
}

//----------------------------------------------------------------------------------

void CullendulaAppBootstrap::showMainWindow(CullendulaMainWindow& mainWindow) { mainWindow.show(); }

//----------------------------------------------------------------------------------

CullendulaAppBootstrap::UiLanguage CullendulaAppBootstrap::getApplicationLanguage() { return currentApplicationLanguage(); }

//----------------------------------------------------------------------------------

bool CullendulaAppBootstrap::setApplicationLanguage(UiLanguage language) {
    return detail::setApplicationLanguage(language, qApp, detail::defaultTranslatorHooks());
}

//----------------------------------------------------------------------------------

int CullendulaAppBootstrap::runEventLoop(QApplication& app) {
    Q_UNUSED(app)
    return QApplication::exec();
}

//----------------------------------------------------------------------------------

void CullendulaAppBootstrap::scheduleAutoQuitForTests(QApplication& app) {
    bool parsedSuccessfully = false;
    int const exitDelayMs = qEnvironmentVariableIntValue("CULLENDULA_EXIT_AFTER_STARTUP_MS", &parsedSuccessfully);
    if (!parsedSuccessfully || exitDelayMs < 0) {
        return;
    }

    QTimer::singleShot(exitDelayMs, &app, &QCoreApplication::quit);
}
---------- end ----------
-------------------- ./src/CullendulaMainWindow.ui --------------------
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>CullendulaMainWindow</class>
 <widget class="QMainWindow" name="CullendulaMainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>651</width>
    <height>487</height>
   </rect>
  </property>
  <property name="sizePolicy">
   <sizepolicy hsizetype="Minimum" vsizetype="Minimum">
    <horstretch>0</horstretch>
    <verstretch>0</verstretch>
   </sizepolicy>
  </property>
  <property name="acceptDrops">
   <bool>false</bool>
  </property>
  <property name="windowTitle">
   <string comment="Main window title shown before the runtime version suffix is applied from C++ code.">Cullendula - your smol helper to pick the best shots</string>
  </property>
  <widget class="QWidget" name="centralWidget">
   <property name="sizePolicy">
    <sizepolicy hsizetype="Preferred" vsizetype="Fixed">
     <horstretch>0</horstretch>
     <verstretch>0</verstretch>
    </sizepolicy>
   </property>
   <property name="acceptDrops">
    <bool>false</bool>
   </property>
   <layout class="QVBoxLayout" name="upperVLayout">
    <item>
     <layout class="QHBoxLayout" name="horizontalLayout">
      <item>
       <widget class="QLabel" name="centerLabel">
        <property name="sizePolicy">
         <sizepolicy hsizetype="Expanding" vsizetype="Expanding">
          <horstretch>0</horstretch>
          <verstretch>0</verstretch>
         </sizepolicy>
        </property>
        <property name="font">
         <font>
          <pointsize>15</pointsize>
         </font>
        </property>
        <property name="acceptDrops">
         <bool>true</bool>
        </property>
        <property name="toolTip">
         <string comment="Tooltip for the large central preview area. It accepts a dropped image file or a directory containing images.">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
        </property>
        <property name="autoFillBackground">
         <bool>false</bool>
        </property>
        <property name="frameShape">
         <enum>QFrame::Box</enum>
        </property>
        <property name="text">
         <string comment="Placeholder text in the central preview area before any image is loaded.">drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</string>
        </property>
        <property name="scaledContents">
         <bool>false</bool>
        </property>
        <property name="alignment">
         <set>Qt::AlignCenter</set>
        </property>
        <property name="wordWrap">
         <bool>true</bool>
        </property>
       </widget>
      </item>
      <item>
       <spacer name="verticalSpacer">
        <property name="orientation">
         <enum>Qt::Vertical</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>0</width>
          <height>0</height>
         </size>
        </property>
       </spacer>
      </item>
     </layout>
    </item>
    <item>
     <layout class="QHBoxLayout" name="buttonHLayout">
      <item>
       <spacer name="leftHSpacer">
        <property name="orientation">
         <enum>Qt::Horizontal</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>0</width>
          <height>0</height>
         </size>
        </property>
       </spacer>
      </item>
      <item>
       <widget class="QPushButton" name="leftPB">
        <property name="minimumSize">
         <size>
          <width>0</width>
          <height>45</height>
         </size>
        </property>
        <property name="maximumSize">
         <size>
          <width>16777215</width>
          <height>45</height>
         </size>
        </property>
        <property name="font">
         <font>
          <pointsize>25</pointsize>
          <weight>75</weight>
          <bold>true</bold>
          <kerning>true</kerning>
         </font>
        </property>
        <property name="toolTip">
         <string comment="Tooltip for the left navigation button; it shows the previous image in the current directory order.">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
        </property>
        <property name="text">
         <string comment="Label of the previous-image navigation button. Keep the arrow symbol if possible.">â†</string>
        </property>
        <property name="shortcut">
         <string comment="Keyboard shortcut for the previous-image navigation action; use the standard Left Arrow key sequence.">Left</string>
        </property>
        <property name="autoRepeat">
         <bool>true</bool>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="savePB">
        <property name="minimumSize">
         <size>
          <width>0</width>
          <height>45</height>
         </size>
        </property>
        <property name="maximumSize">
         <size>
          <width>16777215</width>
          <height>45</height>
         </size>
        </property>
        <property name="font">
         <font>
          <pointsize>20</pointsize>
         </font>
        </property>
        <property name="toolTip">
         <string comment="Tooltip for the Save button. This moves the current image into the app-managed 'output' subdirectory, it does not write image edits.">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
        </property>
        <property name="text">
         <string comment="Label of the button that keeps the current image by moving it into the 'output' subdirectory.">save â†‘</string>
        </property>
        <property name="shortcut">
         <string comment="Keyboard shortcut for the Save action; use the standard Up Arrow key sequence.">Up</string>
        </property>
        <property name="autoRepeat">
         <bool>false</bool>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="trashPB">
        <property name="minimumSize">
         <size>
          <width>0</width>
          <height>45</height>
         </size>
        </property>
        <property name="maximumSize">
         <size>
          <width>16777215</width>
          <height>45</height>
         </size>
        </property>
        <property name="font">
         <font>
          <pointsize>20</pointsize>
         </font>
        </property>
        <property name="toolTip">
         <string comment="Tooltip for the Trash button. This moves the current image into the app-managed 'trash' subdirectory, it does not delete it permanently.">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
        </property>
        <property name="text">
         <string comment="Label of the button that rejects the current image by moving it into the 'trash' subdirectory.">trash â†“</string>
        </property>
        <property name="shortcut">
         <string comment="Keyboard shortcut for the Trash action; use the standard Down Arrow key sequence.">Down</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="rightPB">
        <property name="minimumSize">
         <size>
          <width>0</width>
          <height>45</height>
         </size>
        </property>
        <property name="maximumSize">
         <size>
          <width>16777215</width>
          <height>45</height>
         </size>
        </property>
        <property name="font">
         <font>
          <pointsize>25</pointsize>
          <weight>75</weight>
          <bold>true</bold>
         </font>
        </property>
        <property name="acceptDrops">
         <bool>false</bool>
        </property>
        <property name="toolTip">
         <string comment="Tooltip for the right navigation button; it shows the next image in the current directory order.">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
        </property>
        <property name="text">
         <string comment="Label of the next-image navigation button. Keep the arrow symbol if possible.">â†’ </string>
        </property>
        <property name="shortcut">
         <string comment="Keyboard shortcut for the next-image navigation action; use the standard Right Arrow key sequence.">Right</string>
        </property>
        <property name="autoRepeat">
         <bool>true</bool>
        </property>
       </widget>
      </item>
      <item>
       <spacer name="rightHSpacer">
        <property name="orientation">
         <enum>Qt::Horizontal</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>0</width>
          <height>0</height>
         </size>
        </property>
       </spacer>
      </item>
     </layout>
    </item>
   </layout>
  </widget>
  <widget class="QMenuBar" name="menuBar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>651</width>
     <height>18</height>
    </rect>
   </property>
   <property name="acceptDrops">
    <bool>false</bool>
   </property>
  </widget>
  <widget class="QStatusBar" name="statusBar">
  <property name="toolTip">
   <string comment="Tooltip for the status bar at the bottom of the main window.">This is the status bar. It will display any kind of information like current position, failure messages, ..</string>
  </property>
  </widget>
 </widget>
 <layoutdefault spacing="6" margin="11"/>
 <resources/>
 <connections/>
</ui>
---------- end ----------
-------------------- ./src/CullendulaFileSystemHandler.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

// own includes
#include "CullendulaFileSystemHandler.h"

// Qt includes
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QList>
#include <QtGui/QImageReader>
#include <algorithm>

//----------------------------------------------------------------------------

// for constants
namespace {
//! Determines the name of the output-folders
QString const c_hardcodedOutput = "output";
QString const c_hardcodedTrash = "trash";
int const c_maxSuggestedExtensions = 10;

QSet<QString> getSupportedImageSuffixes() {
    QSet<QString> suffixes;

    QList<QByteArray> const supportedFormats = QImageReader::supportedImageFormats();
    for (QByteArray const& format : supportedFormats) {
        suffixes.insert(QString::fromLatin1(format).toLower());
    }

    return suffixes;
}

QStringList normalizeExtensions(QStringList const& extensions, QSet<QString> const& supportedSuffixes) {
    QStringList normalizedExtensions;

    for (QString const& extension : extensions) {
        QString const normalizedExtension = extension.trimmed().toLower();
        if (!normalizedExtension.isEmpty() && supportedSuffixes.contains(normalizedExtension) && !normalizedExtensions.contains(normalizedExtension)) {
            normalizedExtensions.append(normalizedExtension);
        }
    }

    return normalizedExtensions;
}

QStringList normalizeExtensions(QStringList const& extensions) { return normalizeExtensions(extensions, getSupportedImageSuffixes()); }

QString formatMoveErrorMessage(QString const& fileName, QString const& subdir, QString const& details) {
    //: Error message after moving a file into a named subdirectory such as "output", "trash", "undo", or "redo" failed.
    return CullendulaFileSystemHandler::tr("Could not move '%1' to '%2': %3").arg(fileName, subdir, details);
}

QString formatDirectorySetupErrorMessage(QString const& subdir, QString const& directoryPath, QString const& details) {
    //: Error message after preparing an application-managed subdirectory such as "output" or "trash" failed.
    return CullendulaFileSystemHandler::tr("Could not prepare '%1' directory at '%2': %3").arg(subdir, directoryPath, details);
}

bool pathExists(QString const& path) { return QFileInfo(path).exists(); }

bool pathIsDirectory(QString const& path) { return QFileInfo(path).isDir(); }

bool directoryExists(QString const& path) { return QDir(path).exists(); }

bool mkdirInDirectory(QDir& parentDir, QString const& subdir) { return parentDir.mkdir(subdir); }
}  // namespace

//----------------------------------------------------------------------------

CullendulaFileSystemHandler::CullendulaFileSystemHandler() : m_workingPath("") {
    setAllowedImageExtensions(getSuggestedImageExtensions());
    qDebug() << "CullendulaFileSystemHandler::CullendulaFileSystemHandler()";
}

//----------------------------------------------------------------------------

QStringList CullendulaFileSystemHandler::getSuggestedImageExtensions() {
    return CullendulaFileSystemHandlerDetail::getSuggestedImageExtensions(getSupportedImageSuffixes());
}

//----------------------------------------------------------------------------

QStringList CullendulaFileSystemHandlerDetail::getSuggestedImageExtensions(QSet<QString> const& supportedSuffixes) {
    QStringList const preferredExtensions = {"png", "jpg", "jpeg", "webp", "gif", "bmp", "tif", "tiff", "svg", "ico"};

    QStringList suggestedExtensions = normalizeExtensions(preferredExtensions, supportedSuffixes);
    if (suggestedExtensions.size() >= c_maxSuggestedExtensions) {
        suggestedExtensions.resize(c_maxSuggestedExtensions);
        return suggestedExtensions;
    }

    QStringList additionalExtensions = supportedSuffixes.values();
    std::sort(additionalExtensions.begin(), additionalExtensions.end());

    for (QString const& extension : additionalExtensions) {
        if (!suggestedExtensions.contains(extension)) {
            suggestedExtensions.append(extension);
            if (suggestedExtensions.size() >= c_maxSuggestedExtensions) {
                break;
            }
        }
    }

    return suggestedExtensions;
}

//----------------------------------------------------------------------------

CullendulaFileSystemHandlerDetail::OutputFolderHooks CullendulaFileSystemHandlerDetail::defaultOutputFolderHooks() {
    return OutputFolderHooks{pathExists, pathIsDirectory, directoryExists, mkdirInDirectory};
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandlerDetail::createOutputFolder(QDir& workingPath, QString const& subdir, QString& errorMessage, OutputFolderHooks const& hooks) {
    QString const outputDirPath = workingPath.path() + QDir::separator() + subdir;

    if (hooks.pathExists(outputDirPath) && !hooks.pathIsDirectory(outputDirPath)) {
        errorMessage = formatDirectorySetupErrorMessage(subdir, outputDirPath,
                                                        CullendulaFileSystemHandler::tr("the path is already occupied by a non-directory filesystem entry"));
        return false;
    }

    if (hooks.directoryExists(outputDirPath)) {
        qDebug() << "output-folder exists already :) - nothing to do";
        return true;
    }

    bool const creationSuccessful = hooks.mkdir(workingPath, subdir);
    if (!creationSuccessful) {
        errorMessage = formatDirectorySetupErrorMessage(subdir, outputDirPath, CullendulaFileSystemHandler::tr("creating the directory failed"));
        return false;
    }

    if (!hooks.directoryExists(outputDirPath)) {
        qDebug() << "very severe error - could not create output-dir :(";
        errorMessage =
            formatDirectorySetupErrorMessage(subdir, outputDirPath, CullendulaFileSystemHandler::tr("the directory is still missing after creation"));
        return false;
    }

    qDebug() << "output-folder exists after creation!";
    return true;
}

//----------------------------------------------------------------------------

void CullendulaFileSystemHandler::setAllowedImageExtensions(QStringList const& extensions) {
    QStringList const normalizedExtensions = normalizeExtensions(extensions);
    m_allowedImageExtensions = QSet<QString>(normalizedExtensions.cbegin(), normalizedExtensions.cend());
}

//----------------------------------------------------------------------------

QStringList CullendulaFileSystemHandler::getAllowedImageExtensions() const {
    QStringList extensions = m_allowedImageExtensions.values();
    std::sort(extensions.begin(), extensions.end());
    return extensions;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::setWorkingPath(const QString& urlPath) {
    bool returnValue(false);

    qDebug() << "CullendulaFileSystemHandler::setWorkingPath(): urlPath=" << urlPath;
    resetCurrentState();
    m_workingPath.setPath("");
    m_workingPath.setPath(urlPath);

    returnValue = processNewPath();

    return returnValue;
}

//----------------------------------------------------------------------------

void CullendulaFileSystemHandler::resetCurrentState() {
    m_currentImages.clear();
    m_positionCurrentFile = -1;
    m_undoStack = CullendulaUndoStack();
    clearLastErrorMessage();
}

//----------------------------------------------------------------------------

QString CullendulaFileSystemHandler::getCurrentImagePath() {
    QString returnValue;
    qDebug() << "CullendulaFileSystemHandler::getCurrentImagePath():";

    if (checkInternalSanity()) {
        QString const path(m_currentImages[m_positionCurrentFile].absoluteFilePath());
        qDebug() << "\tpath:" << path;
        QFile const tempFile(path);
        if (tempFile.exists()) {
            returnValue = path;
        }
    }

    return returnValue;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::adjustCurrentPositionBy(int const offset) {
    bool const returnValue = checkInternalSanity();

    if (checkInternalSanity()) {
        m_positionCurrentFile = (m_positionCurrentFile + m_currentImages.size() + offset) % m_currentImages.size();
    }

    return returnValue;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::switchCurrentPositionToTheLeft() {
    bool const returnValue = adjustCurrentPositionBy(-1);

    return returnValue;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::switchCurrentPositionToTheRight() {
    bool const returnValue = adjustCurrentPositionBy(1);

    return returnValue;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::saveCurrentFile() {
    qDebug() << "CullendulaFileSystemHandler::saveCurrentFile():";
    clearLastErrorMessage();

    return moveCurrentFileToGivenSubfolder(c_hardcodedOutput);
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::trashCurrentFile() {
    qDebug() << "CullendulaFileSystemHandler::trashCurrentFile():";
    clearLastErrorMessage();

    return moveCurrentFileToGivenSubfolder(c_hardcodedTrash);
}

//----------------------------------------------------------------------------

QString CullendulaFileSystemHandler::getCurrentStatus() const {
    //: Status bar message showing the current 1-based image position and the total number of loaded images.
    auto returnValue = tr("showing %1 of %2").arg(QString::number(m_positionCurrentFile + 1), QString::number(m_currentImages.size()));

    return returnValue;
}

//----------------------------------------------------------------------------

QString const& CullendulaFileSystemHandler::getLastErrorMessage() const { return m_lastErrorMessage; }

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::canUndo() { return m_undoStack.canUndo(); }

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::canRedo() { return m_undoStack.canRedo(); }

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::undo() {
    clearLastErrorMessage();
    if (!canUndo()) {
        //: Error shown when the user requests Undo but the undo history is empty.
        setLastErrorMessage(tr("No undo step is currently available."));
        return false;
    }

    qDebug() << "CullendulaFileSystemHandler::undo()";
    CullendulaUndoItem const item = m_undoStack.peekUndo();
    QString const targetPath = item.sourcePath;
    QString const sourcePath = item.targetPath;
    qDebug() << "\tsource: " << sourcePath;
    qDebug() << "\ttarget: " << targetPath;

    QDir fileHandler;
    bool const successfullyRenamed = fileHandler.rename(sourcePath, targetPath);
    qDebug() << "rename was: " << (successfullyRenamed ? "TRUE" : "ERROR");

    if (!successfullyRenamed) {
        //: Low-level filesystem failure detail inserted into a larger user-visible move error message.
        setLastErrorMessage(formatMoveErrorMessage(QFileInfo(sourcePath).fileName(), QStringLiteral("undo"), tr("the filesystem rename operation failed")));
        return false;
    }

    m_undoStack.commitUndo();
    return rebuildImageFileList(targetPath, m_positionCurrentFile);
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::redo() {
    clearLastErrorMessage();
    if (!canRedo()) {
        //: Error shown when the user requests Redo but the redo history is empty.
        setLastErrorMessage(tr("No redo step is currently available."));
        return false;
    }

    qDebug() << "CullendulaFileSystemHandler::redo()";
    CullendulaUndoItem const item = m_undoStack.peekRedo();
    QString const targetPath = item.sourcePath;
    QString const sourcePath = item.targetPath;
    qDebug() << "\tsource: " << sourcePath;
    qDebug() << "\ttarget: " << targetPath;

    int fallbackPosition = m_positionCurrentFile;
    int const sourceIndex = findImageIndexByPath(sourcePath);
    if (sourceIndex >= 0) {
        fallbackPosition = sourceIndex;
    }

    QDir fileHandler;
    bool const successfullyRenamed = fileHandler.rename(sourcePath, targetPath);
    qDebug() << "rename was: " << (successfullyRenamed ? "TRUE" : "ERROR");

    if (!successfullyRenamed) {
        //: Low-level filesystem failure detail inserted into a larger user-visible move error message.
        setLastErrorMessage(formatMoveErrorMessage(QFileInfo(sourcePath).fileName(), QStringLiteral("redo"), tr("the filesystem rename operation failed")));
        return false;
    }

    m_undoStack.commitRedo();
    return rebuildImageFileList(QString(), fallbackPosition);
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::processNewPath() {
    bool returnValue(false);

    qDebug() << "CullendulaFileSystemHandler::processNewPath():";

    // Dropped file URLs can carry a leading slash before the Windows drive letter.
    QString const intermediatePath =
#ifdef __linux__
        m_workingPath.path();
#else
        m_workingPath.path().remove(0, 1);  // remove the leading slash ("/")
#endif
    QFileInfo const fileInfo(intermediatePath);

    qDebug() << "\tfileInfo.isDir():" << fileInfo.isDir();
    qDebug() << "fileInfo.absoluteFilePath(): " << fileInfo.absoluteFilePath();
    qDebug() << "fileInfo.absolutePath(): " << fileInfo.absolutePath();

    QDir const tempDir = QDir(fileInfo.isDir() ? fileInfo.absoluteFilePath() : fileInfo.absolutePath());
    qDebug() << "\t resulting directory:" << tempDir.path();

    // additionally check if the directory is usable
    if (tempDir.exists()) {
        m_workingPath.setPath(tempDir.path());

        bool const foundImages = createImageFileList();
        bool const outputReady = createOutputFolder(c_hardcodedOutput);
        bool const trashReady = createOutputFolder(c_hardcodedTrash);

        returnValue = foundImages && outputReady && trashReady;

        if (!outputReady || !trashReady) {
            m_currentImages.clear();
            m_positionCurrentFile = -1;
            m_undoStack = CullendulaUndoStack();
        }
    } else {
        qDebug() << "ERROR: given directory does not exist";
        //: Error after a dropped path or selected path does not resolve to an existing directory on disk.
        setLastErrorMessage(tr("The path '%1' could not be resolved to an existing directory.").arg(intermediatePath));
    }

    return returnValue;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::createImageFileList() {
    qDebug() << "CullendulaFileSystemHandler::createImageFileList():";
    return rebuildImageFileList(QString(), 0);
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::rebuildImageFileList(QString const& preferredImagePath, int const fallbackPosition) {
    m_currentImages.clear();
    m_positionCurrentFile = -1;

    QSet<QString> const supportedImageSuffixes = getSupportedImageSuffixes();
    QFileInfoList const availableFiles = m_workingPath.entryInfoList(QDir::Files, QDir::Name);
    QFileInfoList availableImages;

    for (QFileInfo const& file : availableFiles) {
        QString const suffix = file.suffix().toLower();
        if (supportedImageSuffixes.contains(suffix) && m_allowedImageExtensions.contains(suffix)) {
            availableImages.append(file);
        }
    }

    if (availableImages.isEmpty()) {
        qDebug() << "no nice files found :(";
        return false;
    }

    qDebug() << "found the following image files:";
    for (QFileInfo const& file : availableImages) {
        qDebug() << "\t" << file.absoluteFilePath();
    }

    m_currentImages = availableImages.toVector();

    int const lastValidIndex = static_cast<int>(m_currentImages.size()) - 1;
    int positionToSelect = 0;
    if (!preferredImagePath.isEmpty()) {
        int const preferredIndex = findImageIndexByPath(preferredImagePath);
        if (preferredIndex >= 0) {
            positionToSelect = preferredIndex;
        } else {
            positionToSelect = std::clamp(fallbackPosition, 0, lastValidIndex);
        }
    } else {
        positionToSelect = std::clamp(fallbackPosition, 0, lastValidIndex);
    }

    m_positionCurrentFile = positionToSelect;
    return true;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::createOutputFolder(QString const& subdir) {
    qDebug() << "CullendulaFileSystemHandler::createOutputFolder():" << subdir;
    QString errorMessage;
    bool const success = CullendulaFileSystemHandlerDetail::createOutputFolder(m_workingPath, subdir, errorMessage,
                                                                               CullendulaFileSystemHandlerDetail::defaultOutputFolderHooks());
    if (!success) {
        setLastErrorMessage(errorMessage);
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::moveCurrentFileToGivenSubfolder(QString const& subdir) {
    bool returnValue(false);
    qDebug() << "CullendulaFileSystemHandler::moveCurrentFileToGivenSubfolder():";
    clearLastErrorMessage();

    bool const saneInternalState = checkInternalSanity();
    if (!saneInternalState) {
        //: Error shown when the user tries to save or trash an image but no current image is loaded.
        setLastErrorMessage(tr("No current image is available to move."));
        return false;
    }

    if (!createOutputFolder(subdir)) {
        return false;
    }

    QDir outputDir(m_workingPath.path() + QDir::separator() + subdir);

    QString const sourcePathAndName(m_currentImages[m_positionCurrentFile].absoluteFilePath());
    qDebug() << "\t sourcePathAndName:" << sourcePathAndName;
    QFileInfo const fileInfo(sourcePathAndName);
    QString const fileName(fileInfo.fileName());
    QString const preferredTargetPath = outputDir.path() + QDir::separator() + fileName;
    QString const targetPathAndName = createUniqueTargetPath(preferredTargetPath);
    qDebug() << "\t targetPathAndName:" << targetPathAndName;
    bool const successfullyRenamed = outputDir.rename(sourcePathAndName, targetPathAndName);
    qDebug() << "\t successfullyRenamed?" << successfullyRenamed;

    if (!successfullyRenamed) {
        //: Low-level filesystem failure detail inserted into a larger user-visible move error message.
        setLastErrorMessage(formatMoveErrorMessage(fileName, subdir, tr("the filesystem rename operation failed")));
        return false;
    }

    m_undoStack.push(sourcePathAndName, targetPathAndName);

    m_currentImages.removeAt(m_positionCurrentFile);
    int const listSize = m_currentImages.size();
    m_positionCurrentFile = (listSize > 0) ? (m_positionCurrentFile % listSize) : -1;
    returnValue = true;

    return returnValue;
}

//----------------------------------------------------------------------------

int CullendulaFileSystemHandler::findImageIndexByPath(QString const& imagePath) const {
    auto const match = std::find_if(m_currentImages.cbegin(), m_currentImages.cend(),
                                    [&imagePath](QFileInfo const& fileInfo) { return fileInfo.absoluteFilePath() == imagePath; });
    if (match != m_currentImages.cend()) {
        return static_cast<int>(std::distance(m_currentImages.cbegin(), match));
    }

    return -1;
}

//----------------------------------------------------------------------------

QString CullendulaFileSystemHandler::createUniqueTargetPath(QString const& initialTargetPath) {
    if (!QFileInfo::exists(initialTargetPath)) {
        return initialTargetPath;
    }

    QFileInfo const fileInfo(initialTargetPath);
    QString const directoryPath = fileInfo.absolutePath();
    QString const completeBaseName = fileInfo.completeBaseName();
    QString const completeSuffix = fileInfo.completeSuffix();
    QString const suffixPrefix = completeSuffix.isEmpty() ? QString() : "." + completeSuffix;

    for (int counter = 1;; ++counter) {
        QString const candidateFileName = QString("%1 (%2)%3").arg(completeBaseName, QString::number(counter), suffixPrefix);
        QString const candidatePath = directoryPath + QDir::separator() + candidateFileName;
        if (!QFileInfo::exists(candidatePath)) {
            return candidatePath;
        }
    }
}

//----------------------------------------------------------------------------

void CullendulaFileSystemHandler::clearLastErrorMessage() { m_lastErrorMessage.clear(); }

//----------------------------------------------------------------------------

void CullendulaFileSystemHandler::setLastErrorMessage(QString const& message) { m_lastErrorMessage = message; }

//----------------------------------------------------------------------------

bool CullendulaFileSystemHandler::checkInternalSanity() const {
    bool returnValue(true);

    QDir const outputDir(m_workingPath.path());
    if (!outputDir.exists()) {
        qDebug() << "CullendulaFileSystemHandler::checkInternalSanity(): ERROR: workingPath not valid!";
        returnValue = false;
    }

    if (m_currentImages.empty()) {
        qDebug() << "CullendulaFileSystemHandler::checkInternalSanity(): ERROR: list of current images is empty!";
        returnValue = false;
    }

    if (m_positionCurrentFile < 0) {
        qDebug() << "CullendulaFileSystemHandler::checkInternalSanity(): ERROR: position" << QString::number(m_positionCurrentFile) << "is a negative number!";
        returnValue = false;
    }

    if (m_positionCurrentFile >= m_currentImages.size()) {
        qDebug() << "CullendulaFileSystemHandler::checkInternalSanity(): ERROR: position" << QString::number(m_positionCurrentFile)
                 << " is out of range of the image-list with size" << QString::number(m_currentImages.size());
        returnValue = false;
    }

    return returnValue;
}
---------- end ----------
-------------------- ./localPipeline.sh --------------------
#!/usr/bin/env bash

# -----------------------------------------------------------------------------
# localPipeline.sh
#
# Purpose:
#   Run a local, developer-oriented verification pipeline for the Cullendula
#   project and summarize the outcome in one place.
#
# What it does:
#   1. Configure the project with CMake
#   2. Build the configured targets in parallel
#   3. Run the unit test suite with CTest, using parallel workers when possible
#   4. Build a dedicated coverage configuration and generate an HTML report
#   5. Fail if total line coverage is below 90%
#   6. Generate Doxygen documentation
#   7. Verify that the Doxygen warnings file exists and is empty
#   8. Print the generated Doxygen index.html path and try to open it
#   9. Run Cppcheck and generate XML plus optional HTML reports
#   10. Run clang-format on the C++ sources in src/ and tests/
#   11. Detect whether clang-format changed any files
#   12. Launch the built Cullendula application by default as the final interactive step
#   13. Suppress application launch when --noRun is provided, which is intended for CI
#   14. Print a final stage-by-stage summary and exit with a useful status code
#
# Invocation:
#   ./localPipeline.sh
#   ./localPipeline.sh --verbose
#   ./localPipeline.sh --noRun
#   ./localPipeline.sh --build-dir /absolute/or/relative/build-dir
#   ./localPipeline.sh --coverage-build-dir /absolute/or/relative/coverage-build-dir
#   CULLENDULA_PIPELINE_JOBS=8 ./localPipeline.sh
#   ./localPipeline.sh --help
#
# Exit codes:
#   0  All mandatory stages succeeded:
#      configure/build, tests, coverage generation, coverage threshold,
#      Doxygen generation, zero Doxygen warnings, and clang-format execution.
#      Launching the GUI application does not affect the exit code and may be
#      suppressed with --noRun.
#   1  One or more mandatory stages failed.
#   2  Invalid command line arguments.
# -----------------------------------------------------------------------------

set -u
set -o pipefail

readonly SCRIPT_NAME="$(basename "$0")"
readonly PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly DEFAULT_BUILD_DIR="${PROJECT_ROOT}/build"
readonly DEFAULT_COVERAGE_BUILD_DIR="${PROJECT_ROOT}/build-coverage"
readonly STAGE_LOG_DIR="${PROJECT_ROOT}/.localPipeline"
readonly DEFAULT_CPPCHECK_REPORT_DIR="${PROJECT_ROOT}/reports/cppcheck"

VERBOSE=0
NO_RUN=0
BUILD_DIR="${DEFAULT_BUILD_DIR}"
COVERAGE_BUILD_DIR="${DEFAULT_COVERAGE_BUILD_DIR}"
CTEST_COMMAND=""
PARALLEL_JOBS=1
GCOV_COMMAND=""
GCOVR_COMMAND=""
readonly COVERAGE_MIN_LINE_PERCENT="90.0"
PYTHON3_COMMAND=""
CPPCHECK_COMMAND=""
CPPCHECK_HTMLREPORT_COMMAND=""
CPPCHECK_REPORT_DIR="${DEFAULT_CPPCHECK_REPORT_DIR}"

declare -a SUMMARY_LINES=()
declare -a FORMAT_TARGETS=()
declare -a FORMAT_CHANGED_FILES=()

BUILD_OK=0
TESTS_OK=0
COVERAGE_OK=0
COVERAGE_THRESHOLD_OK=0
OPEN_COVERAGE_OK=0
DOXYGEN_OK=0
DOXYGEN_WARNINGS_OK=0
OPEN_DOCS_OK=0
CPPCHECK_OK=0
OPEN_CPPCHECK_OK=0
FORMAT_OK=0
FORMAT_CHANGED=0
COVERAGE_LINE_PERCENT=""

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [--verbose] [--noRun] [--build-dir PATH] [--coverage-build-dir PATH] [--help]

Local project pipeline:
  1. Configure and build the project
  2. Run unit tests
  3. Build a dedicated coverage tree, generate coverage, and enforce a 90% line coverage threshold
  4. Generate Doxygen documentation
  5. Check that the Doxygen warning log is empty
  6. Open the generated HTML reports when possible
  7. Run Cppcheck with XML output and optional HTML report generation
  8. Run clang-format on project C++ sources
  9. Report whether formatting changed any files
  10. Launch the built Cullendula app by default and wait for the user to close it
     Use --noRun to suppress the application launch (intended for CI)
EOF
}

log() {
    printf '[INFO] %s\n' "$*"
}

warn() {
    printf '[WARN] %s\n' "$*" >&2
}

error() {
    printf '[ERROR] %s\n' "$*" >&2
}

verbose_log() {
    if [[ "${VERBOSE}" -eq 1 ]]; then
        printf '[VERBOSE] %s\n' "$*"
    fi
}

add_summary() {
    SUMMARY_LINES+=("$1")
}

mark_result() {
    local label="$1"
    local status="$2"
    local details="$3"
    add_summary "$(printf '%-18s : %-4s %s' "${label}" "${status}" "${details}")"
}

run_command() {
    local description="$1"
    shift
    local log_file=""

    verbose_log "${description}"
    verbose_log "Command: $*"

    if [[ "${VERBOSE}" -eq 1 ]]; then
        "$@"
    else
        mkdir -p "${STAGE_LOG_DIR}" || {
            error "Could not create stage log directory: ${STAGE_LOG_DIR}"
            return 1
        }

        log_file="$(mktemp "${STAGE_LOG_DIR}/$(printf '%s' "${description}" | tr ' /' '__').XXXXXX.log")" || {
            error "Could not create a temporary log file for '${description}'."
            return 1
        }

        if "$@" >"${log_file}" 2>&1; then
            rm -f "${log_file}"
            return 0
        fi

        error "${description} failed. Captured output:"
        sed 's/^/  | /' "${log_file}" >&2
        return 1
    fi
}

require_command() {
    local command_name="$1"
    if ! command -v "${command_name}" >/dev/null 2>&1; then
        error "Required command '${command_name}' was not found in PATH."
        return 1
    fi
    return 0
}

resolve_ctest_command() {
    local cmake_path=""
    local cmake_dir=""
    local sibling_ctest=""

    cmake_path="$(command -v cmake 2>/dev/null)" || return 1
    cmake_dir="$(dirname "${cmake_path}")"
    sibling_ctest="${cmake_dir}/ctest"

    if [[ -x "${sibling_ctest}" ]]; then
        printf '%s\n' "${sibling_ctest}"
        return 0
    fi

    if command -v ctest >/dev/null 2>&1; then
        command -v ctest
        return 0
    fi

    return 1
}

extract_summary_json_number() {
    local json_file="$1"
    local key="$2"

    "${PYTHON3_COMMAND}" - "${json_file}" "${key}" <<'PY'
import json
import sys

json_path = sys.argv[1]
key = sys.argv[2]

with open(json_path, "r", encoding="utf-8") as handle:
    payload = json.load(handle)

value = payload.get(key)
if value is None:
    raise SystemExit(1)

print(value)
PY
}

detect_parallel_jobs() {
    local configured_jobs="${CULLENDULA_PIPELINE_JOBS:-}"
    local detected_jobs=""

    if [[ -n "${configured_jobs}" ]]; then
        if [[ "${configured_jobs}" =~ ^[1-9][0-9]*$ ]]; then
            printf '%s\n' "${configured_jobs}"
            return 0
        fi

        error "CULLENDULA_PIPELINE_JOBS must be a positive integer, got '${configured_jobs}'."
        return 1
    fi

    if command -v nproc >/dev/null 2>&1; then
        detected_jobs="$(nproc)"
    elif command -v getconf >/dev/null 2>&1; then
        detected_jobs="$(getconf _NPROCESSORS_ONLN 2>/dev/null || true)"
    elif command -v sysctl >/dev/null 2>&1; then
        detected_jobs="$(sysctl -n hw.ncpu 2>/dev/null || true)"
    fi

    if [[ "${detected_jobs}" =~ ^[1-9][0-9]*$ ]]; then
        printf '%s\n' "${detected_jobs}"
        return 0
    fi

    printf '%s\n' "1"
    return 0
}

detect_open_command() {
    if command -v xdg-open >/dev/null 2>&1; then
        printf '%s\n' "xdg-open"
        return 0
    fi

    if command -v open >/dev/null 2>&1; then
        printf '%s\n' "open"
        return 0
    fi

    return 1
}

collect_format_targets() {
    mapfile -t FORMAT_TARGETS < <(
        cd "${PROJECT_ROOT}" &&
            find src tests -type f \( -name '*.h' -o -name '*.cpp' \) | LC_ALL=C sort
    )

    if [[ "${#FORMAT_TARGETS[@]}" -eq 0 ]]; then
        warn "No C++ source files were found below src/ or tests/."
        return 1
    fi

    verbose_log "Formatting targets (${#FORMAT_TARGETS[@]} files):"
    if [[ "${VERBOSE}" -eq 1 ]]; then
        local target
        for target in "${FORMAT_TARGETS[@]}"; do
            printf '  - %s\n' "${target}"
        done
    fi

    return 0
}

checksum_files() {
    (
        cd "${PROJECT_ROOT}" || exit 1
        sha256sum "$@"
    )
}

find_changed_files_from_checksums() {
    local before_file="$1"
    local after_file="$2"

    awk '
        NR == FNR {
            before[$2] = $1
            next
        }
        {
            if (!($2 in before) || before[$2] != $1) {
                print $2
            }
        }
    ' "${before_file}" "${after_file}"
}

configure_and_build() {
    log "Configuring project in '${BUILD_DIR}'."
    mkdir -p "${BUILD_DIR}" || return 1

    if ! run_command "Running CMake configure step" cmake -S "${PROJECT_ROOT}" -B "${BUILD_DIR}" -DCULLENDULA_BUILD_TESTS=ON; then
        error "CMake configure step failed."
        return 1
    fi

    log "Building project with ${PARALLEL_JOBS} parallel job(s)."
    if ! run_command "Running project build" cmake --build "${BUILD_DIR}" --parallel "${PARALLEL_JOBS}"; then
        error "Project build failed."
        return 1
    fi

    return 0
}

run_tests() {
    log "Running unit tests via CTest with ${PARALLEL_JOBS} parallel job(s)."
    if ! run_command "Executing CTest" "${CTEST_COMMAND}" --test-dir "${BUILD_DIR}" --output-on-failure --parallel "${PARALLEL_JOBS}"; then
        error "Unit tests failed."
        return 1
    fi

    return 0
}

configure_and_build_coverage() {
    log "Configuring dedicated coverage build in '${COVERAGE_BUILD_DIR}'."
    mkdir -p "${COVERAGE_BUILD_DIR}" || return 1

    if ! run_command "Running CMake coverage configure step" cmake -S "${PROJECT_ROOT}" -B "${COVERAGE_BUILD_DIR}" -DCULLENDULA_BUILD_TESTS=ON -DCULLENDULA_ENABLE_COVERAGE=ON; then
        error "CMake coverage configure step failed."
        return 1
    fi

    log "Building coverage configuration with ${PARALLEL_JOBS} parallel job(s)."
    if ! run_command "Running coverage build" cmake --build "${COVERAGE_BUILD_DIR}" --parallel "${PARALLEL_JOBS}"; then
        error "Coverage build failed."
        return 1
    fi

    return 0
}

generate_coverage() {
    local coverage_output_dir="${COVERAGE_BUILD_DIR}/coverage"
    local coverage_html_dir="${coverage_output_dir}/html"
    local coverage_index_file="${coverage_html_dir}/index.html"
    local coverage_summary_file="${coverage_output_dir}/summary.json"
    local open_command=""

    log "Generating coverage report."
    if ! run_command "Building the coverage-html target" cmake --build "${COVERAGE_BUILD_DIR}" --target coverage-html --parallel "${PARALLEL_JOBS}"; then
        error "Coverage HTML generation failed."
        return 1
    fi

    if ! run_command "Generating coverage JSON summary" "${GCOVR_COMMAND}" \
        --root "${PROJECT_ROOT}" \
        --filter "${PROJECT_ROOT}/src" \
        --gcov-executable "${GCOV_COMMAND}" \
        --json-summary "${coverage_summary_file}" \
        --json-summary-pretty \
        "${COVERAGE_BUILD_DIR}"; then
        error "Coverage summary generation failed."
        return 1
    fi

    if [[ ! -f "${coverage_index_file}" ]]; then
        error "Expected coverage HTML entry point was not created: ${coverage_index_file}"
        return 1
    fi

    if [[ ! -f "${coverage_summary_file}" ]]; then
        error "Expected coverage summary file was not created: ${coverage_summary_file}"
        return 1
    fi

    COVERAGE_LINE_PERCENT="$(extract_summary_json_number "${coverage_summary_file}" "line_percent")"
    if [[ -z "${COVERAGE_LINE_PERCENT}" ]]; then
        error "Could not parse line coverage percentage from ${coverage_summary_file}."
        return 1
    fi

    log "Coverage HTML entry point: ${coverage_index_file}"
    log "Total line coverage: ${COVERAGE_LINE_PERCENT}%"

    if awk "BEGIN { exit !(${COVERAGE_LINE_PERCENT} >= ${COVERAGE_MIN_LINE_PERCENT}) }"; then
        COVERAGE_THRESHOLD_OK=1
    else
        warn "Coverage is below the required threshold of ${COVERAGE_MIN_LINE_PERCENT}%."
    fi

    if open_command="$(detect_open_command)"; then
        log "Opening coverage report with '${open_command}'."
        if run_command "Opening coverage index.html" "${open_command}" "${coverage_index_file}"; then
            OPEN_COVERAGE_OK=1
        else
            warn "Could not open the generated coverage report automatically."
        fi
    else
        warn "No supported open command was found. Coverage report will not be opened automatically."
    fi

    return 0
}

generate_doxygen() {
    local warnings_file="${BUILD_DIR}/doxygen/warnings.txt"
    local index_file="${BUILD_DIR}/doxygen/html/index.html"
    local open_command=""

    log "Generating Doxygen documentation."
    if ! run_command "Building the doxygen target" cmake --build "${BUILD_DIR}" --target doxygen --parallel "${PARALLEL_JOBS}"; then
        error "Doxygen generation failed."
        return 1
    fi

    if [[ ! -f "${warnings_file}" ]]; then
        error "Expected Doxygen warnings file was not created: ${warnings_file}"
        return 1
    fi

    if [[ ! -s "${warnings_file}" ]]; then
        log "Doxygen warnings file is empty."
        DOXYGEN_WARNINGS_OK=1
    else
        warn "Doxygen warnings were reported. See: ${warnings_file}"
    fi

    if [[ ! -f "${index_file}" ]]; then
        error "Expected Doxygen index file was not created: ${index_file}"
        return 1
    fi

    log "Doxygen HTML entry point: ${index_file}"

    if open_command="$(detect_open_command)"; then
        log "Opening generated documentation with '${open_command}'."
        if run_command "Opening Doxygen index.html" "${open_command}" "${index_file}"; then
            OPEN_DOCS_OK=1
        else
            warn "Could not open the generated documentation automatically."
        fi
    else
        warn "No supported open command was found. Documentation will not be opened automatically."
    fi

    return 0
}

run_cppcheck() {
    local xml_report="${CPPCHECK_REPORT_DIR}/cppcheck.xml"
    local html_index="${CPPCHECK_REPORT_DIR}/html/index.html"
    local open_command=""
    local cppcheck_args=(
        --build-dir "${BUILD_DIR}"
        --report-dir "${CPPCHECK_REPORT_DIR}"
    )

    if [[ "${VERBOSE}" -eq 1 ]]; then
        cppcheck_args+=(--verbose)
    fi

    log "Running Cppcheck static analysis."
    if ! run_command "Running Cppcheck" "${PROJECT_ROOT}/scripts/run_cppcheck.sh" "${cppcheck_args[@]}"; then
        error "Cppcheck execution failed."
        return 1
    fi

    if [[ ! -f "${xml_report}" ]]; then
        error "Expected Cppcheck XML report was not created: ${xml_report}"
        return 1
    fi

    log "Cppcheck XML report: ${xml_report}"

    if [[ -f "${html_index}" ]]; then
        log "Cppcheck HTML entry point: ${html_index}"
        if open_command="$(detect_open_command)"; then
            log "Opening Cppcheck report with '${open_command}'."
            if run_command "Opening Cppcheck index.html" "${open_command}" "${html_index}"; then
                OPEN_CPPCHECK_OK=1
            else
                warn "Could not open the generated Cppcheck report automatically."
            fi
        else
            warn "No supported open command was found. Cppcheck report will not be opened automatically."
        fi
    else
        warn "Cppcheck HTML report was not generated. XML output is still available."
    fi

    return 0
}

run_clang_format() {
    local before_checksums_file
    local after_checksums_file

    log "Running clang-format on project C++ sources."

    mkdir -p "${STAGE_LOG_DIR}" || {
        error "Could not create stage log directory: ${STAGE_LOG_DIR}"
        return 1
    }

    before_checksums_file="$(mktemp "${STAGE_LOG_DIR}/format.before.XXXXXX.txt")" || {
        error "Could not create the pre-format checksum file."
        return 1
    }
    after_checksums_file="$(mktemp "${STAGE_LOG_DIR}/format.after.XXXXXX.txt")" || {
        error "Could not create the post-format checksum file."
        rm -f "${before_checksums_file}"
        return 1
    }

    checksum_files "${FORMAT_TARGETS[@]}" >"${before_checksums_file}" || {
        error "Failed to capture file checksums before formatting."
        rm -f "${before_checksums_file}" "${after_checksums_file}"
        return 1
    }

    (
        cd "${PROJECT_ROOT}" || exit 1
        clang-format -i "${FORMAT_TARGETS[@]}"
    ) || {
        error "clang-format failed."
        rm -f "${before_checksums_file}" "${after_checksums_file}"
        return 1
    }

    checksum_files "${FORMAT_TARGETS[@]}" >"${after_checksums_file}" || {
        error "Failed to capture file checksums after formatting."
        rm -f "${before_checksums_file}" "${after_checksums_file}"
        return 1
    }

    mapfile -t FORMAT_CHANGED_FILES < <(find_changed_files_from_checksums "${before_checksums_file}" "${after_checksums_file}")
    rm -f "${before_checksums_file}" "${after_checksums_file}"

    if [[ "${#FORMAT_CHANGED_FILES[@]}" -gt 0 ]]; then
        FORMAT_CHANGED=1
        warn "clang-format changed one or more files."
        log "Changed files after formatting:"
        printf '%s\n' "${FORMAT_CHANGED_FILES[@]}" | sed 's/^/  - /'
    else
        log "clang-format left all tracked source files unchanged."
    fi

    return 0
}

launch_application() {
    local app_path="${BUILD_DIR}/src/Cullendula"

    if [[ ! -f "${app_path}" ]]; then
        warn "The built application was not found at '${app_path}'."
        return 1
    fi

    if [[ ! -x "${app_path}" ]]; then
        warn "The built application is not executable: '${app_path}'."
        return 1
    fi

    log "Launching Cullendula as the final pipeline step."
    log "Close the application window to let the script finish."

    if ! run_command "Launching the Cullendula application" "${app_path}"; then
        warn "The Cullendula application could not be launched successfully."
        return 1
    fi

    return 0
}

print_summary() {
    printf '\n========== Local Pipeline Summary ==========\n'
    local line
    for line in "${SUMMARY_LINES[@]}"; do
        printf '%s\n' "${line}"
    done
    printf '============================================\n'
}

parse_arguments() {
    while [[ "$#" -gt 0 ]]; do
        case "$1" in
            --verbose)
                VERBOSE=1
                ;;
            --noRun)
                NO_RUN=1
                ;;
            --build-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --build-dir."
                    exit 2
                fi
                if [[ "$1" = -* ]]; then
                    error "Invalid build directory value: '$1'."
                    exit 2
                fi
                BUILD_DIR="$1"
                ;;
            --coverage-build-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --coverage-build-dir."
                    exit 2
                fi
                if [[ "$1" = -* ]]; then
                    error "Invalid coverage build directory value: '$1'."
                    exit 2
                fi
                COVERAGE_BUILD_DIR="$1"
                ;;
            --help|-h)
                print_usage
                exit 0
                ;;
            *)
                error "Unknown argument: $1"
                print_usage
                exit 2
                ;;
        esac
        shift
    done
}

main() {
    parse_arguments "$@"

    log "Project root: ${PROJECT_ROOT}"
    log "Build directory: ${BUILD_DIR}"
    log "Coverage build directory: ${COVERAGE_BUILD_DIR}"
    if [[ "${VERBOSE}" -eq 1 ]]; then
        log "Verbose logging is enabled."
    fi
    if [[ "${NO_RUN}" -eq 1 ]]; then
        log "Application launch is suppressed because --noRun was provided."
    fi

    local missing_prerequisites=0

    require_command cmake || missing_prerequisites=1
    require_command clang-format || missing_prerequisites=1
    require_command sha256sum || missing_prerequisites=1
    require_command gcov || missing_prerequisites=1
    require_command gcovr || missing_prerequisites=1
    require_command python3 || missing_prerequisites=1
    require_command cppcheck || missing_prerequisites=1

    if ! CTEST_COMMAND="$(resolve_ctest_command)"; then
        error "Could not resolve a usable CTest executable."
        missing_prerequisites=1
    else
        verbose_log "Using CTest executable: ${CTEST_COMMAND}"
    fi

    GCOV_COMMAND="$(command -v gcov 2>/dev/null || true)"
    GCOVR_COMMAND="$(command -v gcovr 2>/dev/null || true)"
    PYTHON3_COMMAND="$(command -v python3 2>/dev/null || true)"
    CPPCHECK_COMMAND="$(command -v cppcheck 2>/dev/null || true)"
    CPPCHECK_HTMLREPORT_COMMAND="$(command -v cppcheck-htmlreport 2>/dev/null || true)"

    if ! PARALLEL_JOBS="$(detect_parallel_jobs)"; then
        missing_prerequisites=1
    else
        log "Parallel jobs: ${PARALLEL_JOBS}"
    fi

    if ! collect_format_targets; then
        missing_prerequisites=1
    fi

    if [[ "${missing_prerequisites}" -ne 0 ]]; then
        add_summary "Prerequisite check failed. See errors above."
        print_summary
        exit 1
    fi

    if configure_and_build; then
        BUILD_OK=1
        mark_result "Configure+Build" "PASS" "Project configured and built in ${BUILD_DIR}"
    else
        mark_result "Configure+Build" "FAIL" "Build step did not complete successfully"
    fi

    if [[ "${BUILD_OK}" -eq 1 ]]; then
        if run_tests; then
            TESTS_OK=1
            mark_result "Unit Tests" "PASS" "CTest completed without failures"
        else
            mark_result "Unit Tests" "FAIL" "CTest reported at least one failing test"
        fi
    else
        mark_result "Unit Tests" "SKIP" "Skipped because build failed"
    fi

    if [[ "${TESTS_OK}" -eq 1 ]]; then
        if configure_and_build_coverage && generate_coverage; then
            COVERAGE_OK=1
            mark_result "Coverage" "PASS" "Coverage HTML generated successfully in ${COVERAGE_BUILD_DIR}"
        else
            mark_result "Coverage" "FAIL" "Coverage generation failed in ${COVERAGE_BUILD_DIR}"
        fi
    else
        mark_result "Coverage" "SKIP" "Skipped because tests did not complete successfully"
    fi

    if [[ "${COVERAGE_OK}" -eq 1 ]]; then
        if [[ "${COVERAGE_THRESHOLD_OK}" -eq 1 ]]; then
            mark_result "Coverage Gate" "PASS" "Line coverage is ${COVERAGE_LINE_PERCENT}% (threshold ${COVERAGE_MIN_LINE_PERCENT}%)"
        else
            mark_result "Coverage Gate" "FAIL" "Line coverage is ${COVERAGE_LINE_PERCENT}% (threshold ${COVERAGE_MIN_LINE_PERCENT}%)"
        fi

        if [[ "${OPEN_COVERAGE_OK}" -eq 1 ]]; then
            mark_result "Open Coverage" "PASS" "Coverage index.html was handed to the desktop opener"
        else
            mark_result "Open Coverage" "WARN" "Coverage index.html path was printed but auto-open was unavailable or failed"
        fi
    else
        mark_result "Coverage Gate" "SKIP" "Skipped because coverage generation failed"
        mark_result "Open Coverage" "SKIP" "Skipped because coverage generation failed"
    fi

    if [[ "${BUILD_OK}" -eq 1 ]]; then
        if generate_doxygen; then
            DOXYGEN_OK=1
            mark_result "Doxygen" "PASS" "Documentation generated successfully"
        else
            mark_result "Doxygen" "FAIL" "Documentation generation failed"
        fi
    else
        mark_result "Doxygen" "SKIP" "Skipped because build failed"
    fi

    if [[ "${DOXYGEN_OK}" -eq 1 ]]; then
        if [[ "${DOXYGEN_WARNINGS_OK}" -eq 1 ]]; then
            mark_result "Doxygen Warnings" "PASS" "warnings.txt is empty"
        else
            mark_result "Doxygen Warnings" "FAIL" "warnings.txt contains entries"
        fi

        if [[ "${OPEN_DOCS_OK}" -eq 1 ]]; then
            mark_result "Open Docs" "PASS" "index.html was handed to the desktop opener"
        else
            mark_result "Open Docs" "WARN" "index.html path was printed but auto-open was unavailable or failed"
        fi
    else
        mark_result "Doxygen Warnings" "SKIP" "Skipped because Doxygen generation failed"
        mark_result "Open Docs" "SKIP" "Skipped because Doxygen generation failed"
    fi

    if [[ "${BUILD_OK}" -eq 1 ]]; then
        if run_cppcheck; then
            CPPCHECK_OK=1
            if [[ -n "${CPPCHECK_HTMLREPORT_COMMAND}" ]]; then
                mark_result "Cppcheck" "PASS" "XML and HTML reports generated in ${CPPCHECK_REPORT_DIR}"
            else
                mark_result "Cppcheck" "PASS" "XML report generated in ${CPPCHECK_REPORT_DIR}; HTML generation unavailable"
            fi
        else
            mark_result "Cppcheck" "FAIL" "Static-analysis execution or report generation failed"
        fi
    else
        mark_result "Cppcheck" "SKIP" "Skipped because build failed"
    fi

    if [[ "${CPPCHECK_OK}" -eq 1 ]]; then
        if [[ -n "${CPPCHECK_HTMLREPORT_COMMAND}" ]]; then
            if [[ "${OPEN_CPPCHECK_OK}" -eq 1 ]]; then
                mark_result "Open Cppcheck" "PASS" "index.html was handed to the desktop opener"
            else
                mark_result "Open Cppcheck" "WARN" "index.html path was printed but auto-open was unavailable or failed"
            fi
        else
            mark_result "Open Cppcheck" "SKIP" "Skipped because HTML report generation is unavailable"
        fi
    else
        mark_result "Open Cppcheck" "SKIP" "Skipped because Cppcheck did not complete successfully"
    fi

    if run_clang_format; then
        FORMAT_OK=1
        if [[ "${FORMAT_CHANGED}" -eq 1 ]]; then
            mark_result "clang-format" "WARN" "Formatting completed and changed files"
        else
            mark_result "clang-format" "PASS" "Formatting completed without changing files"
        fi
    else
        mark_result "clang-format" "FAIL" "Formatting step failed"
    fi

    local exit_code=1
    if [[ "${BUILD_OK}" -eq 1 && "${TESTS_OK}" -eq 1 && "${COVERAGE_OK}" -eq 1 && "${COVERAGE_THRESHOLD_OK}" -eq 1 && "${DOXYGEN_OK}" -eq 1 && "${DOXYGEN_WARNINGS_OK}" -eq 1 && "${CPPCHECK_OK}" -eq 1 && "${FORMAT_OK}" -eq 1 ]]; then
        exit_code=0
    fi

    if [[ "${BUILD_OK}" -eq 1 ]]; then
        if [[ "${NO_RUN}" -eq 1 ]]; then
            mark_result "Launch App" "SKIP" "Suppressed by --noRun (intended for CI)"
        else
            if launch_application; then
                mark_result "Launch App" "PASS" "Cullendula was started; the script resumed after the window was closed"
            else
                mark_result "Launch App" "WARN" "Launching Cullendula failed or was unavailable; this does not affect the pipeline result"
            fi
        fi
    else
        mark_result "Launch App" "SKIP" "Skipped because the application build did not complete successfully"
    fi

    print_summary
    exit "${exit_code}"
}

main "$@"
---------- end ----------
-------------------- ./media/cullendula.rc --------------------
IDI_ICON1 ICON DISCARDABLE "cullendula_icon.ico"
---------- end ----------
-------------------- ./media/cullendula_icon.ico --------------------
        (  &         è  N  (                €                       €  €   €€ €   € € €€  €€€ ÀÀÀ   ÿ  ÿ   ÿÿ ÿ   ÿ ÿ ÿÿ  ÿÿÿ UUUUUUUUUUUUUUUUUUUUUUUUUUUwwUUUUUWuWuUUUUwUUuUUUUwUUUUUUUwUUUUUUUwUUUUUUUwUUUUUUUwUUuUUUUWuWuUUUUUwwUUUUUUUUUUUUUUUUUUUUUUUUUUU                                                                (       @                                €  €   €€ €   € € €€  €€€ ÀÀÀ   ÿ  ÿ   ÿÿ ÿ   ÿ ÿ ÿÿ  ÿÿÿ UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUwwwwUUUUUUUUUUUUwwwwUUUUUUUUUUUwwUUwwUUUUUUUUUUwwUUwwUUUUUUUUUwwUUUUwUUUUUUUUUwwUUUUwUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUUUUUUUUUUUwwUUUUwUUUUUUUUUwwUUUUwUUUUUUUUUUwwUUwwUUUUUUUUUUwwUUwwUUUUUUUUUUUwwwwUUUUUUUUUUUUwwwwUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU                                                                                                                                ---------- end ----------
-------------------- ./media/i18n_example_run.mp4 --------------------
    ftypisom   isomiso2avc1mp41   free —umdat   gM@4ÚCäˆ„     @<`Ê€   hïÈ  qÿÿmÜEé½æÙH·–,Ø Ù#îïx264 - core 165 r3222 b35605a - H.264/MPEG-4 AVC codec - Copyleft 2003-2025 - http://www.videolan.org/x264.html - options: cabac=1 ref=1 deblock=1:0:0 analyse=0x1:0x111 me=hex subme=2 psy=1 psy_rd=1.00:0.00 mixed_ref=0 me_range=16 chroma_me=1 trellis=0 8x8dct=0 cqm=0 deadzone=21,11 fast_pskip=1 chroma_qp_offset=0 threads=16 lookahead_threads=4 sliced_threads=0 nr=0 decimate=1 interlaced=0 bluray_compat=0 constrained_intra=0 bframes=0 weightp=1 keyint=100 keyint_min=10 scenecut=40 intra_refresh=0 rc_lookahead=10 rc=crf mbtree=1 crf=23.0 qcomp=0.60 qpmin=0 qpmax=69 qpstep=4 ip_ratio=1.40 aq=1:1.00 €  -ceˆ„/âù<Sœ˜íÃ#Šà	õ*õ^2S²gMËHâ;:ÑWj^d=åœğ>Éyº£ÿğA
 0½­ÈÀ-QW¬şò,¿ñaöe{–G·©Œ•–J¡ÊYWF¹d±Ÿ¤|µm>‘¦³İYsuC
‹îîÏË
{n­<-ŸÉ	­SøÕÄº>&_ğ†Ugà£ØI ÍÎ€mpİtÊ£_€†šE$n;¼m)*qÆ ,é€˜³îô¯4{(ğ
»× ÖÂOØ 9dJÀ {ØÎC<gÑ$ş8rRHLHfÊ0·W(#Û™æ%1â€Ø•ğ\ºÉØÄŸúò;ª¨Mş1Ïrğ1Ğ ‘ä¤¢ÃæÁPÅæ+x*„ÍŞˆXY‹µàMÕsM`âTË€ôw7EW˜\_“9' CF¡w-…CGè&8>&FTL±–š—tÚ|cØıÃ¸Şk]°RM+³È-D=M³}ñ÷%«°¯ı¬ÖEÅ9Û·ıÃ¸í¹jùï{ÛöàfüYİ¿ôÅ›û®â	0‹²Iİ«—	A¡¥<èâ•0c$òQÅ|Ãñmû¹e[ğv6Ô|â4Z½Ñ˜‘¨ˆNßşzÑ:7ªÄ,ü
ÌG­/$*jÅ|5#Q	 *aø…›ƒıc¥ØçÒ¢µ/9³K²çÒ¤Aß¡1Ò1dñDh<>üw¬¯xÑ´@L?4 "¯èè ‰Ñ±R›¬
ÏMÄ¾ÔûØØüØ4PJqTv}›àïÅ]ôŸÕ†­%OîÀ‘+»!ƒÈ	ß¯R+™‹B9Xt3n¼U!¥t¸‡QŒ§)×°ÿèHt/3D€×@4¦ƒS‹KÏwå¤’³Õ ÜÔ5WP/±„8êúã@GŞ‚¶Yß™F2•ø„L	ÉWÎÉi\óæT êãºm‹HÓ><‘j²qßÈÈõ³šÖÔ>AÉqºşøD‚(È‰Ö‹Mæƒ¬o6+<g£#!Êm°eRoš¶Áí~g¾çR:¹‚6D7ßO~ŞÌGhâ.Ó˜½Îÿû /k?Ğ”¨ÇÜÌ«—É ‘.Pü¨¢UWzÙîz›ÁW"£(ÿIO`y§Íş¬ÑkcS¢VŸˆ)K-®âÄ}ê(XÆÌ›Ób¥ñ›T¼oßÃZïWäşì‚®Õe¡:jÖ5¬‚ß~UµJH›Z¢ PqŒ•]©½ô'¬Û©FŞzßÛÍî¡ÂLÌ72
E§÷ûTØŠâS
‘#ù’ŒÇã§"8ã¹õFâJ¿7¼PEÑA„Gj©°i¦Ä|ô._^@	Y3Œcùş(¾Â#Ò;>ù†‘ÙŞÌ¶jË„íÖ|7 
Ú?&‹¨k9ç™›^èd‰…sZKÕ°’O‡Ï[NØœ3ØW¹ÁòêŒÑJ)PSÎ<Ú)¾Íå„¯¢-T?9€x_’N9°Í¾€‰©&(p…²Å‹¡‰ê©qØw/ïèÃn¹<[:Â‹-=NBIeLf
N¤®ï_è
+â0ú·£LÓ£¢Ódm™W„mĞ¸ë]¯!gIÈp•4
êæ6½ç£	GÛ¢%}Òœ+?ÕOÆUuœÛÉà{BÛ·Àc«÷	Ñ®~xùÜ\÷AÉ„€ùkÇ4­)lÙìÍã.İT$2A‡Ÿ„ç—@òoÙ¹_œ.ÿ@i¬ú” #Üy½m¿’#¡À  +í?Aq0Í²J‹™ìGĞ×•†õ	Ô;ö¨`¥«h3XúİÄÊŠ	l4Ah9†V"Åy	ÇÁœŠ´v9¨ÈGzüÍâÄ/Útbl~ñ.]Õi4Ø£Ä	äô»Ò´WĞŸpE_€ÑCé5FïÅMÜLÛìrƒ…+9¨cìØÙxñ=ë¥4áõŞ)û¶m)‹ŸëŞ¸zø7P‰	GÒbJÎ@÷Q79dˆ×¡N¶
)ÆäpmÁ =ë¾\»ÀZ5=É¸!}_Yp@ªó9ƒ5]}ùäÏTg@ÔĞxõR˜-dˆïŒĞ
èîMª/Áaÿ¿ıY4m¶n™ØÀkŞ2¥T¥{°ÄÂàÂYÍdÚØŞ(är„õãp	Ù/»úXYq†ß¸’´B–Úï¹?1¨íeUT·Î,@ëg2
ŠSáâ€Êš¢m®9ø$|Íq†›oï!³ßçd/ôM®şšq	åˆÅ|òº 7lc©¹‡Ôä5gäş´]Šâ5K­Œ!ÜïËúM‹Å‰ÇµCúº–Ni‘`Á ŠƒúÂcö]F´#[±†ØS¨ÂuíÕı5@‹TÿçGN¨ÒN)Ø4ˆ|I/¥3Ô—o1¸œ›Oó@ü<g™ı^"3OV€İ±\Fì« 9ı³dæÖŞB0hRjÌ#ÏEF8ï1|¶G±=ˆ}ß_jš=Ë”Ù¹1ËKµ uØ§IãÚÆïœı@Ç©ÏByU;VÁy„Çü†<…!®¾°oƒ:f—O_øbÑ¤IFÚAú[îQW§Wï%–ÅZ¡-+îEuïƒß¥É	æÕoììsÓXeÜ- @ŸÅÛI„‚…}H®Ğ²Y<÷‡);c'Å5ÇãBŒ<;´Oìôi8,IH˜8æ*¢ĞBR»MæFVë(åãÎ}iO4“%¹Å%Ğ×¨({TğQû%/¾×„ÿlñÃ°2hŠè×¶[Ñÿ#!ÂÑJİ¾ËPzÀãø®|ÜœoÉš¢¡Dº;ÁÎ     E&MõiµVÍİ¤Cş§[Š{¹Äî¡Õ¾Ó×‚É‰şb ~ÅtçıüÄÆÔºCÙoıî­Ÿ_Pº­¸²˜í®WÊpBAM\løÁdåø¸ãÃÛôê‘ÙÅjDi!ÑØv~Ã´«¯d£<½FãØSÉí‰ª1JÃ¿  	0!Fà ¿(€Ñ†¤U=î+Ÿ3O1æ02İÿRa`?2kü†$‚÷‚÷~bºúc\Es{Q|‡_ğ9\¼Næ­Ãır6½ÇÜS4¡b~JìÂ³âÇVOŒÉ3ÀY¸4	ÛÜÏ‹w–ê-/4¾SúWx¹šÄš¢D u­­³zƒ›'3Úé^&*à Èç3T’“ÑÙ&ó15ƒC05AÒPäÉımà5ˆF€sÈ‚÷#-ÉÏ÷Ôv›ûø*ã4ŸeÇä
XZ‚"ñ…Tí„õ1î9æ¦'Næu6'Ím§Ã•L f:Ys¥ ‹^|Ş…ª4|›½Ø/¹qPœ*R—¡½	RÒŠT‚’YD¯“ÕCÀ_×ZWÄ._oXÏ¹²%Y2D¹/Q',û ğ‡ClÓ??ïT³o²Á2@’ À¥‚ûœdK¡»~ÎPÈ¡ ··‹²FöÆø8¨ûóŒÃIs©h‘†WàóÄZæ«O	Fè ##½ a’™šâü•Õßÿı]«Ûÿ®‚–ÿ7áHÃä3crË¡p¢n‡Ò¿wÔ£–Gú qŠkÒ91½‰q³3›aÅé ro©Í„Kšš¤.é«–SğY²ŒİÎñæÂ¿Ë%U,İtï	œáÇ¦ä
”tJ<$^–béİ^¢|çK	A(ş”Â”ÏÎE˜¸ß€³/ÿşº·¬_	Zëqò‘å™³ñØ›Õ1Ó¤ŞV¦ÜE?%ªçlßÍJ³«s ‹¶eBy‹T#4’ãàÏÈõ8Û6˜Õå+aNŞqB6º²“Oa^Gçn66:±g9–A—ìœeÎ-ÓŸæå;Óç‡:(D,lCûhnÔ7¨ÓĞ[!‹|²‘Ì	"P_šÃm²?“ìÕ@w6düHvÙ}±“-VõN76TÎæ~R*œsrÅÉ7vÒçİHéój ±ÜdçeZş_Í¨rg?.b"­1.êäÓ_öY°Có98%Í½uGÖ $=•`w^Î0×é3õÚ˜‡tİúîh‘éN1\9ß™zşşhQË§BšX”ìWù3|8Êá´Éûç“7gÔFó÷L&,#†„=â‚
åhN:Œ&hi!«|bó¤a¬EÇI{ïı8}»>ªs'{q“‹>QvIO¿¨2(}A¿))ßşæ­ÎÓ+hPdH¦öNziú_%!D©>rçQ/iøÄÊu—©äôı©@”ËÕ?^BÂb¼€Å#èW­È5º°«¶’¢o£ëŠM|ƒ÷õ}Î|w¹D¯ı°ãšWD[hJGı'g‚²äqQÜ†vöí±
l“Lš†9ÚO9”1O’Çóï"ˆ~Ö	C­6&Î|õ&Y,V˜Á@´­‹?æòç¤}üÃº°İ‘œşŞïPíE[†Æ –¥¸Á'Í»¯y9…=îĞ XÃB Æ´Dg\µ\ûÈ`nˆxğ—®/»ŠI;H´Œ¸p¬{§±&t„Ù£SfR@«{IAI™„o»¤N"*"ÒÄ‘õ,¯Z±˜Y}ÏMÉÿìïQ3Ÿ¥ñeÔ¥¹}cbÀÖğ?Ø©5Wo¡©Š•	 Ş"ÉqıˆDD9*«‰½†À¥	RHÑ Ñôİ~d³QŠØL~q€?hqØ}bjwÓIe%“SõLÁ&ş€·fµ RÕÛïFÏ“ê n¥KÄ¿Ûï&?_¦š‰€ÒæÖ6ûîQ‚ÀHÆpÈí^^şY9uÌÚE}ÉW[ ‹ìRbX”'Û’R‡ <Õ¬ô›ÇLhC}ÅgQ( ®µX‰”x 
Â¨!`RáÉÎÂ1T"ÁJfàÓª6
GYoü=òéÜñ¢aFNÿ,£\å.tÈf@à¸ÉJª± Iw…C!Œè,kH8PjÑ‡XºrÆ=lb¢…Mßm4¥,œ§:&ö„5¼Á,"×;#qü+é¿–}¼äs´-l€äêH‹MáüQ7½ïÓVòbˆ¬ŠTW‘¹¢ôh-7f$ş¥ºr¨v`hŠ8C^÷şU¶èxÚ*çePà-Õ=5ä;µ—^­“Ïü+Goh.å~z!õËIõcRƒ0<R^¾¡¼`³E²œ'D.<# Óq	IÌb#ä[Ø'²V@íKo{:¦NŒábõœBù?XöäæäúD·¨YULÀÔo5ùÈÃ*ôGMĞdê,IÒ5=0gÙ–ó¹ÁÙ:v:ôºw»gÖáœæDt#­{:íã%	$BÓg]¸³¹ûBµ1˜.-^RüÆêËQ/Û•ÅR¤X¹÷~ŸáBã°fÕÓœÌ6@8Æ5a¦<K`/ÂC¨²\°N^X>Ú- ¡˜\ŠìøÑxc[HØü:÷ÍR#¿z¿Û‘ÔõíÕfu¤oÌÜN4‰Õd!ÅÀù"yú\Ì9OœàŠ®•‚=â¼ñİ•Ò`P‰Ûİ`LY
³z×@;ÜãJŒLRŒ9Ø6…@e¹³8Z¶·Ğ±a;w'×§æ‡Ñ•¡VpÚUwul›Ey¬
z´ğ×¶IõÜk·İ{Ìj@ûµ!EwËâ¸Ş‚Å9¾ogEÚÏÍËÃêÀ´ÚˆüRtJ¨3	¼‘fŞ} ìb9j O]ßê¢òQ,ÊÜ£ÎGjPÜ&v–R@_Õ40¶I Ë¢ßZcJß2©³2ƒH,Şë”ÔrëLädœ¯ÿAtÄÂe‘C ïH$İßWÒ[=Ê	Å®ùoü6'Ú]E€­ª¡qMVlùù¬‰^ÉI²ûÆó¿U„†ğšDµ8äÍ{şÎˆ¸!¶älØ³6H@íÍCŒ¾¢¬²cñ!;Ñ¢
;k•œšr¼y¯YıÖºùˆyiÁ¢"\å3†¢½Y´ñ‚Î4)`«Ò6İŠ	¼õ‰àµÕ›m—ºlnt›Kñjn{p[Â>G VíÎàÆay¹tŞò)ìÛV€0£f'¦«ï²ç¯‚¨îÖ¿¨NÀ—OÚ°Œ`ï„1äïWºPbtàïuHê|+§ï‚ËzÛÆá^ŞdÓğÔÀŒ´FñÖÇ@æı/Iq 4ÒJ*œ@,N?àÒ/Îh¤ZìJVÏš¹àLRÓI®ğı¥‹‚zw„GçwxÀbW²‡A}ÊŠ
ĞŒ¶‰Ãº~H>Zd­E€^Åæä³êÁs†;Å”ñk}9°ÈpëÉªëû³´f½êœ/}eN›Ì¦Jò\ÇèÃƒ)ñ¯g¦­Å‰\Ş.ªÊîª“Š6-,èŸÚj‹ï.¢_fU„g¤«Û+sçíOû{Ï½§"+ÉÇº0¤M†2®;íöááfu…°g½‚_š•®ŒÅ'ÏÇáø&¿¨[zSaûÎÒ¹%Jè¼×ø×vq&PF<ìŒOä5£Òa4;K¬;8ÂÃ›-!Q™xßDÇª³°ÿ¹|Šÿ±èÌ
"ì|%[¤(I£×<K8%7£¬$×jÆìÒK[†ÓqO‘úæ‹å\H‰x±òï~İ¶¾TRİÆÃ³]L6¡@&b(Ø° wzÇ?ìTó„ÅáúÏ)µ7œï¬LÓ«{GT_Ü‘ì„kSTçÚÙ[_Tì”]»1-ÃrOáwÀ‰Oéºpk•È€ƒÇ>nkiùñúèÖºpbµ+ãDü ùR÷‚"ß¨.—‰å€ZÛaˆÒÓ’’iHE¤sT#ú[TÕuı „~­QSå}Aâ”£vÜ±íŸ}@„øYö€­‹è‹Mø›šiM"lš›½é’Ä Cl€iS¼Bwvğ“3iéQN±»÷ í…›Ô—ó‰JîÑHñ©”º$›àÈå Pª.]2/ÙeÅÂıMR‚§õ“†¬¹îê.}S£ÃÒIe»OÙ?m=Ÿí¥ú£ï:ƒÄ…Np˜!D×ÓlI±£ò«‘hRÒÖßÈ|*¦	…Cæ£qÚ¤ì°ƒeÂ©€óğ\;=Ó³w.›;­DàÕáerÿ\Óü–‰fnááª­,Gük•Eª#ıªŸ­ê;„Ğw¦AW÷7Ioæ²§‰{#»¹GÕ§¼%ú÷<ËîƒQ¸O!£k$êÆ+ÿ²)Ó4‰Tk÷„ío‰=’Ö”ğƒÒf`AÎ‚`Äì²œa…4À“è@] §a£H>9¯BP™˜¬şóƒ›ÜÎ'Ã¼avözúÀ}E/7U!‚Ş¤,)é:BÛgÍ)—°(ì®%8îW#Æìï#·[!¢ŞÒc RmùyzÏ(—×$œŸX<ÜÉïFÕvÒ­ìHb×ĞA¾bù\-|L6®7ë’Î*ê	Dy÷éï€t×­Ì-g}Yë~/“­‚6­<âª9·š|Ø HEVîù5„Á«f­¦®VW”Kœğpşª`yUˆsàò­6'’z§¨aBÙ`h{ı?ß96«¥ºv#:
éhò3Ò™
ËVJ%©6fá„Î:»
-_ùG€;ÒÌé"¿çë¼G•ôt‰ÿ¾ºÎ[®UpÉ~p0ÌA‚x\Y V>½ìõëÀM™ƒ‰mãÆVHç¥˜è"Úğc”3 OÊ¾\L×Á¾
soIáÑõ¦Zb¨“`IcôÃ’Ã £gª¦'ÉsÏh#/ÜDıDYÒq.u´6âŒ({&`ŞmœK!ÕüÌ¹x`#ÚÆhŒ¦Îuä Îb6jÊÙ–„~tB‚vCIrPGÑåá5›êO!Ò`{ÿtÌÕJí39Õºîü%e?m=Ò!ĞvĞÆ,K¨ßX« ÷ÌIÔú¬òxâ/¢”DU¥Øf¯ïKda\Îò
x?³¬Îèe˜½%`wÜ_8?:Ufî aZ|èjL–\Ò¬˜e×ó¯ÇîãĞ½‰c?ƒˆ»#ùÑê¢ƒì4æîuë:¨¥²§'âKÔÊÏô™’]:PY°OP;L	‘ë§K‹õ†Øâi±(”x{­ŠÖx¹}F#á¢­°)‘­0™'—*Êoö&ƒ¥‚­ôQÉÚY™Aç¹Ôq€RƒÎ/jnR³ššÆmOViÿÀH³Á‹{¤½­­Ğ òØXYƒ}"òŒx%¸æíJré’heÈL¼y L‚>%vÆ:şœ{¤×_Á|zĞP?­Û>„yg>ÄºÉFöo^˜ñ–bL®Ì±ãÈ5Ğ¨U —¦‚²ç$Üşÿ/=Çkñ£°
!›ZWşÓ·Á/jr˜vrÖgFn ¾û^WQï»Ò‘# ÊšôŞ%	ÿ¿÷	W…x‰öšÜm[ìKÕ‘iÓçf2×OõùvP'´”ß«ÂìÀ@èŸ„‹\ìubùÍ]É-Ÿzx&ÓÛõ.Îè×Z•h"W-K–1GgPH+„Uûÿ “–Ù4”];EéuI†³‡_3+òtj¦LC“´f}Å¾ï–ÉœÜH† )¥f]F®îÂ TyÍ’cW«ZE¨Vºr'&<]&bpóÓßÉ=Íµ…¼F+C…]¿OŞÃ\™³Ñ›rûÇzÁ6AwA‡¹¦%’³ÈHfg_ñ¡›ÇÚZ©l3¸‰¨ãéep£¹65ã{'É%Lr|5¤JÖÆ<LQg%ûLOŸœà`rë‡ÿÿ74ÍcoLzº_1‘q	ªÕàGÿ 
Ô‚vÄZ?È#ùÌ¼9ÜC˜h7&j?À½…æ°/VH@„e«ÒùmælãÛÇÓy­ÎhÈŒyiœQ¯XÌ†ŸFÂŞ2ş{Û{uYè#68^Dt•Üf„É(Üs­ƒÄ{bÑ««v½¸œßÅTÂ©<¼ ÂvAÔŞ6úë3Vrù#wnhe‚gê—ı(Ú÷*ùî’iüšşØ2‚¹9®¯Ï3›–ª_È}£şJ“\µ^—ç‡oU¤¶s#]ùÉ¢7B»;‹?¹ƒb,úßßAkEbİ¾³(eğ¬Ğ,`¾!âïÍAï£òŒgLIÔ.›~–›v¾™öªÆN£@-í]w¬}ÿ\üVñ¯·"-ç×¼eçH…&ı¿Lq³¯ZéS1¥>ëÌef›Ñ»Ñ“Ãz\á„3ğH†Fú4åhuå¯]euÒu³²Ãê÷£nƒó/²RTF¢ÖN-İt‡Q†º.“àô…ÍÍµÜæ¯¤¤Á4vËë½«(˜Ï«¼¦8°®Bÿ]mœsŸgì“ıÉdæÛ8¢-§µg¹<æİbx€€3k‚Êêi‡}ù
ÿü°’œsÙ’£é…8Ü¦E±E¤e}Z °|!ñ—[Á­•&`ÖæJ9-¯,ïíğÁ'•)ã«Â9·Û^/{Ë´éñv¹P#ù#å5FègÌLu¤58vHü–<eBnJ&G}°Yøî¨Î‘T1˜7
D“—iµû7ê~yre¬˜8WÁG7û²ë*<Û€¶ğÔ]€]t¦åç}Ğ Î/¥âê‰Ê¾ğÇ^ÎúÇœ>hÊî¦³ıá‡ıîŞ[ƒ›$SQã×™ş½ÃQ1ûù‘[w×Z‘×gÓëıÿëHÿ‹â&‚\Ÿ ßä#¨ãº^NÄtÒS¿-hÕbhDKºÁQÀ’Íâ=;ïÚ™Ü?¡ßË«-îÎE~é.³Íã¨5¾^*_£y¯XV¥‚[*=—}R–Ñl&ˆ-õê78»?ÿœˆ&nÿÌö¿b4r‰òÛÊb#Ú§ÜKoù:×äEùó¬ân¨6pä
ı-*Ş|b™“"JñïŒ–áŒkr„0kLÜF‰c]%¡3°õ7¾¾µ¡ãç:l=D:1°ê=áÈÆ,Bâ…ò¤€´Ï‚ô~—xŸNçp#–«ÂìäÙ!¢uSµJˆFeÒ†İ1€ƒM$ûÍy0	$f_ê`1¿?¥Ô•²ïì 2¹QQ)SGYÀc<”j‘¨<¸i*Q!£P¼PïŒLh´üÛ’Å~´»9ƒ{]5Lù¤RÜåŸ £ÌïjN06 ¹òÎ c²ZˆÆã“h+g´pRMÉ¶Å
:ôG×'±\'mUúŒEf>-ÙsıGCª™êJ?à¸,â§¿&íWèCş$!B™?Ğî×BR·ò…áàö®ÿ=k§ÀAD^÷œ[k}T¨Æ†éƒ²qÙ5é¦ª_…O”@Ó›WjmÅEÈéë)©ï“X²¨vá
,²Ù1kN´—‡ÌÔº`
õ…ñ|úTİÓ<YJ™ÊÁçoí†À¹ñ‚ÜŞ%Ï˜ãè2´Ç÷TxÛ'TE]ŒèX/›.*áç?®Zè™ùñİÓ¹çÿ<ÊşœI`CØ(öÜŸPİ=d¨L7¶ïr‡œÚ5òÊlÌú‘…ß( ŠcÁ{˜h·Bœñ)]gòk
shf·‰:ßQ øÆ&h¶¡]+\õôAPÚIïüNhß{²°pZ§vÚj‡jK+ ­>=®ı’¡­ÔfWE6Gµ>ßˆµ?ãSĞ¿Rš'ˆĞ~@hÈø%¸Cã×9æšÏ¼¶‡Üv×Âı­Ô‡ÙvBd5‘Şë®G_j¶7“.aør†TgôÙ×¼ú÷°!n‘Aº:J^H» =QZxÉc·k^d}"ÛvTw8OgÆºùwJ¯ihpÖToG2òÈ³}¢#øâ5-È,œw£ÿæè€¥œ* XB±Uùd€=q²0âĞVĞ˜T^£ùÿÃöô@ÍŸ>™©(hÿ¹®‚Ö»ñDR¤-®µó!¸K;À”qg. wDÏ+‹×ı>xœ°Á ßädæè,·Ÿä~Êxgÿ÷a‹¾¤ö:àŠ
qwsœ¹J i’Š÷ŠÀ.8‚Ñ×u€¥«/ß›j×…—ğ¥Œû¤¬d\¼ÿ•âFAÖlDYÚ^>…Ñİ6ß˜Ë”ëëU¸ğéTé$¿CZ™#\Õ¾Í°K¸.¯-’$Î©±?ï n>éæğø6ÍÕ¦Ö¨ëƒåä‡n‰²æÅ Ñ§x­‡Šy „ıº±weq)ì*Eø\ïşÒE,¶Áä?`bhèf~“èÏŒµSxápŸe@ÖÑh\«ğ,+ÇN`5¾?arÙBÜõşÕÊE¡ %pÊĞµWú—iB—¯¿I¬±ÈA®²W½>$ÂàQRÂBuù¤:,p(z­ù¹yXÕ]å’ÿuìf/Ê×Ê»²½¼«Æ`Ûå$tJ¶Ç3–‘2ûêŞŸ3¤¿#ˆ“*~)l×Hø‡™]ÄO8Ùë\µ·{@º™“Éí1%Ş·¹
ƒ‚×í;ÈÈ±À`Ö“şÿåI•c5qKÄãö”?ôËŸù£_¦8L¤¸ÅUì2ÍWŒ5 *¹†1)#5˜xÌ(=Û#Î¦×[Lâ Áx¦Q*³ş•Â3‹]:
¬ÈŠ¯òHZø¯~WScXé¢9ş”3¢V¥ÂcÜÁa‘.6â
‘ˆÌî_cˆĞ”ş}í[ÂRø:¼tÜî
ôY´#q˜ı–`çé/À§è ·Ìnyî»eK zn0-”Œ½{˜]W/<–;iE•ô2š8ºP€ğğ°g„$tV›/Vu‘gĞÈÜóR•árî$Ù9Iœ3A¸	>j àP÷¶t\]4¢Íé_MÔ/g(‡{ÛHÖ!ş‚¡¤¤W¹åb»iê1”ÿ!àTIøGNÎvKÕ¦+{¿ÂÚÕôoĞh=Rß£±—B€›ÔÇ5º>x¢Tüïh}´ô~>u@Ğå}u:aR‰Ò_*å^è‰“?x2‰>Çæ–å(_²Ø¦@Ùğû»Ä ¢F²J§Z”[¢İK&Ó$–€;ÃãŒ¼ôÙ»&•ÚLoTf­lË¿š6‡a4½±I
ÑˆDô{ÎŠx4#ÅğA¤%¨ÓêfBF$§Ğ‰k`¾r?ñ”¸‹å;ªƒV®ÁM‡¶7©TäØjŞßÀ˜×ÓIùêíùN2ØT·ô3á2€¸À(>Ôp›;¼ÂiwéŸ)°¢YÕ‹¹øeòµ2±PÉ¼@O
Yãy©ÈäVB1É·çGuGİ+¿÷zgß°Âÿ²úêóxÓ3¼Â§hBúfıµæƒ‚•yYOS« r]^íÛ±kx=·E#2ë\š‚/Ôn¿”ÕÀ:öÎ;é·W’ÂgÎ§Aô<Qì_Ê)öiŸ¬Õ©\©úÆó©Ü¸!A¯±¿U]µÏ¿_ôò™qX–Ã‘8íÍxè ‚“ªƒÏy(CÍ¯²r—¼R[¸®a€Œ’ÕÏl‹´xĞ‚TÕ@*Õ´»ªÛ.¿QàÙ1&Âõá«¦ß/î’±P7s‡‚ˆ¨´`×SŒq(´'1z¨}MÒi'
µÅ0ÚıñîŒÎ{e˜ *à^°G">~Â—`ƒj„c3ÇÔ#d”ıê¬»ƒDï¢‡ÜºŞ¤kdgC£ú§Ú9–pÂ]×ÈµfVí
X´Œ  °+«´£¥zöBH6€Ò¨`¶Pã;ÿ×/Û>qøüz‡SÉ	É&ëT8½¢VgoÚå×*	ş1æ†³ Œ,Ï÷Å@'ëó¢5Â=èSª€t™Ašr«bµd„#Ìèh_æúf/ï‚qˆ-t\êÍş:Â‚“gyÑ@v<ài¥æFl·ÂRåQ¬¬ÄÔr‘6Z—'5->lé™O ”¾0Òã0K™·o@æß§0
C‘¥Ş{‹å .aßÜ¼¨rÄ‡è'ÚúÑÑ9ÑŠmaW¡Ïpğ²™—»Nâ?­ş±>q÷1Ğ?û(Ò‚Š.ZSVnM
M\&ÿÑÔÀíU»<^á.­(±sj<DõY÷P1Ç`†Õ‘W³ªŸ¬nÜ¤ñK9@•˜imúüÂ Ou™–_€aRË3Š›$bóœÓpi³Ús|”–jË³5‹¼jTYuı"ÄØ:¶2{šÔ81= şå^$¬aG*"×“0»]öRĞDBĞ`Å£^•ÌÖ.$gÿ3x8ï7 á	4Ó!}0ù¥å¾kMÊÏB±¿ó40Æp'¸ñ‹N‚Â6ş„vgó 8hŒ­“İ8
.`a[§rNpê•ğ ı÷{Üt$0‘Ùé-€ñÀóA;¬6h{ĞâM™«Máfu›¹ôq…Q•êÂ³Íù8ÑMú‹Îlu_´G7Œ£%•DYnJ“Q  ¯ŞP`½êêƒµŠ˜ÆL‡àFÑY›Ûu­¶k­·?2»,á'ègTDYrJ+5¥qü{òlÒY­:G©uã`ƒ=åĞÆ²´HŞ	[è¢ä¹œÈëÆî®´,ê›=·º³ù$6µ…´Õ½Ö
"Èiã­9dlqßƒìÜíoéªòYvKÃÜj×y»ø°ÑÏáOz 5ì¶6"+FÜ)õÎw¹à‡“–çNŠŸ×+«o<vOxÏ,=ìŒã¹ëñÉ}ÒÊ>„¬	ˆİµwÖ¾i½Ö¿Æ«r?™cÉñm ZšÇù¤0}Hùn“	¡0)ÿù‹»8ŞËM2-Ô`úŒ‰<$K;§O#YŞ¥/;HqÜ]pİá+	6Öy~7©p<jëúÍòŞtşmì¼l¦œP˜®Ã©lÆä–¡²¸0AIB‹ÈCAú´rÚ9F|aŠË}¬Nîèõo_ B˜ûx÷H†Bªé7ôJ¿óVo!òZ?Ã*[RÉb jO®™ÍÂaÚcîù°°F0‘ûSÜ™ˆ}¦ãz‰¨J¬ >+çŸt¨äú±Ç„.8T‚ÀÉ×Âˆï“ï¿óüªfe<Àe‡|ôñÚb,A.Ğ[`ŒKº/PûÙítrIƒgÛ°“jS•\¶±ƒ–h²õo®Pñ¸©3¬ğ‡DŞN=dKqıäÕñŠ‰+@vç†´ö&­Ï¨Ï¼C§ñTgÍ„4›™úØ¬ˆaRè±Íœ¥?M¢“GKã¥Ài`wCR+×!§>Ÿäç„ñH5@(y|÷­’ôztü{dØRê¼´u[•Y‰(ûÆõ#àÿ¡T$’_U»—6€ÃÛüD»o»?•É0)èä(ÎWYÚøôÒmÜr‘éNúOX&É]ÍõNÛPTß¢.µ"¡bB/şÄg50ø>^¡¡Ã‚ÍÀÓ}şÀ¾GŸFÛİÓË‚İÍÌ_úÜw¿“nÛTo<Ä3^ÁÌ¦k<HİYà«ÚÆRCÁ¶RÅ` ğ®£Btph¤wÉ,‚¼‹PØ’cÓ¯wU‡å¤{<:UÏm(3ãZVÒ8¯zæA(¸·”tF¦VØ6È#êKœ_Õ†¨gƒîêÈs“7ÕÃ[!áëM®(H(LÊµi,ödwœÖúºÄP’ÂçõÁ–u_"Ä·†^u	GºdDÚj[nÒ¹ç’‡Ğ<C{uudòã#s ñ
„×0ªJ…xø}-Ê’Wôê…ãÌ¿fe»}ìuÃÔox™iÅ\’ä-4/Â~Û1rG^™…¼<êx=px3WFÄ—¯²™V’ò‹…_Ø·÷„JÌæ^ïùvòQ&ÛõÁ½ï×jEİÆFE<2W×ì×¨6‘ŸİJ‚dVÈ¤ÀàŞ¾±í!^Ñ	ªÒHzjEŠ‹ëV¼–è(º¯»)sS(Æ’¤]5æ¿w¼	û°¥o8úÏdù¡ôlC¢Æ¿C?qÎúÎãŞ¾Ë_ëøƒI*¾bş¸?ƒï‹ÜÿUcŒ|ãò­ ßØÉZ5¿\v×Š›óç3ÏÆzUÖa†‚¦5S¨i]Âólz=s¸éIôz9 F˜%åoÇ„F³Ù¶OkAdÅ
7üÓ“¥È~—i€›ô¡ÂœËØˆóßA:Dğªæs²e[axù‹º/ãÜWUZ$Ì4ÄW]5ä‹AVv3no»ÇÎzDô2¡f/+G\—†!–‚òŞ-‡[F×FÃC(Pïµ_CWPÓæÖâÖp—ò ì~L­Ğ˜²‘‹›ÁÄ,znür‰#=@¬™<À„½	¡îY”9v¡
µí•lr¥Î&)ü·µŒ€ WÕ£«eW5ê,èä»¯Ë-(o;;oœ—” 8…@¿ØŸ½˜+]ág²v’cøÕÉ{R°’ÚŞšD€|‹Š—œ¤?Jù¼oÑ´ÓÃÁÂNi@dñíÓ®jÊí>à´ ø oUn)öç¿fÀ¬ÿıK`úÀQÚh´2DtŸ	]	\‡uE   eAš&&ÿ #	1ö€ñ†.„—+jÊ?lÃ]fJ»áò@WÌ*í{ ã+ÿfJ|*ŠÌJÎ“©&íˆŸuÚuâhïxfıö@·Ú÷•Œ5ñPk>¼hY^Ñã*)wçu   'Ašf&ÿ   N\Ğ&IÊSYÚ”jçƒáÎüazŠØ  €   ˆAš†&ÿ   W[¿ôÈBL†?•÷tZ¡Ã¶n(Có*:!Ö#ÿ˜Ïä¬Ã‘d¸+T1éİ‡Cd¹Ká#8c¡ÅË³,ßÂÂ£z†o¹à‡û¤°C¯!®&Ÿ–¯×Óá0HÎ¡GÏ­ÿ,Å‰=¼–œ{ı&³Ÿ*²LÓE©çh@ y   sAš¦&ÿ   `ZF[%§Ûğ
©Ş5Ìşyé¬(7}ûp©öj¦UPÇÒw2ŸGO¢Kz¿Îyÿ%´xio<ÿº#BÒòA‘“fF‹ƒ'´ÚOÙ_%OÚ,§¡&|Ç ˆƒó÷ûºuÂçÀ¥1%  !a   ·AšÆ&ÿ   ûğãÏP!Ú¶ÑÿÇºúÊÔ¸Kš‚t¿AnÆ£J6‰‡mU@K°2-{ÛÈ”ïŞÖ9`{}ÊÔãn™×S«Sm›šebx?>0{ºØ"ıgX
NGã«·çóÏu"<&gú¥h†ŞÌmú¢§Å­†§QL}XªÎ—´}s€wˆ²çeïvóÄĞ¹¼gè¨!¢ø…ˆ¹ÛA>G!º_é      Ašæ&ÿ   OÀîR‘^O­EEÒ1"ğ`’‰„¬‰ôõbévõ²„°Ö¿aühåö•y~ÄwÑ§;v[f$Óù_XìGA!íf•¹BeV›·½«7–í¨‘ÿ|õğBæNJ€w%æ×/#’°§Õ‰¥ôcOuÛô¦xÿÙ-àpgoöÏ3#·¸.‰[
Æ  7   MA›&ÿ  £ğß*{j4â¿6ÍøÃeÇK‚B»Ä“ßäòpæJ²u)Fû¾™¸8O6(×O¢/'j%:Æ0+@  û€   fA›&&ÿ  
ÖØÎgG~İ»½zÕ^ïc÷²ôä.e„›G.xh;¾T]¨˜ÿşĞi¦_Y9¹ÈJÄº¬O¶èæ<\ìÎxE£ûûZ ÑëúNõeÇš™ÎñÆ"„Ú@  È   jA›F&ÿ  ÊhÿûÌ„›>ø	‹«on$ø¯‡Ìpù1–À\ÌZéŞv²MØãr'PÄW1¦ê÷qE«^ôLS)…İGjóÂ»…ÚŸj#Öì[îf:Ÿ»ıÿ¤   9   /A›f&ÿ  ¦Z&‘’9ê¤± ~K
Ö\5 ³\.=®òÎÍÈ·í½»o“  p   "A›†&ÿ  ¢Ğ)ÜÖ“uÎ|ìj•ñŒ‹ÖSÑ   Ì   A›¦$ÿ  ÂJ*éºw› v’0   ±   }A›Æ&ÿ  k+qàÂşÇÃa’ØäjŞÀâ¿àÙ!ºƒ'!H—¤nÊœÈ";HÔËO%¹ÿÑğ/7ğ•êîı‡ìÈ"J¯
±Â«e¢_âéÖY
Œ‹]çcø•JÁkÁŸm…}§Ùó¡K8ÏÓ'	Ö      #A›æ$ÿ  0/˜àåº,Ûü‰2{£0ìs   ù   Aš&ÿ  b[iDYæÙÇeŞõ ™Ù(   Ö   -Aš&$ÿ  ŠëeùCO.ğüñØmNÜ-l«€ó»Š§ÜXËÜ   î   oAšF&ÿ #8„šù]Èè®º9‹öF¡Uûù)lóÉAá÷€³ğ9aßü	«™Åªö"[£x„„²;k½<gø"fÃ¥rÀ½Ú Ò<åí	Š?Ø³.-ÑõRÿ $çaíh2¡ß^Š†%”p   é   $Ašf&ÿ !%üÁëÂD<Ùb¸·hÀnn„    CÀ   aAš†$ÿ ªÖŸ%‹”+È:mÏã·6ø<¶Ÿ%Dè
µtÀÄ%~	€…0½+ 	úï¨xÙ°2ùå¢¼$‚sRûûd’¾ñ;(Ğ·ÀÆğ¥K`  Ç   BAš¦&ÿ YÕ¢M-aMçwÔ$z¢«ƒìÄ¥g@Id‚po®Ì˜®ª¢hÆ%~S Ë   ~ûÁ   +AšÆ&ÿ YÕ¢RÿaLÓÿ‘=ì™æ7Æ“sÈ­äEÌC Ÿ”˜    *`   »Ašæ&ÿ  Ø45Ôÿòè–.vğ`•+yĞ[Ö,&¨a•Ô/•ÿ‰ñ£ğ£“<¢xÃl¾EıÏ
>¥ºgÌ¤ï¨=tv”„Ív›·R{iMZ•wr¡fËÓœsñVËÌaìzã`ÿúá‰6æÅÒ4››¾á<ÙŠ«³ı·UURmğKeáş°„ˆ—G®¤‚÷]ª½1‡ø«>Ÿ¯­k¾¯BVˆñX„ˆ‚òâÃƒügVığø    7á   EA›&ÿ 	Õ—Ğ#,ºpÀrè‘pğŞöã`X†ôûåµ§»³¦jP½Çoñ³"Ê
è¸sÙÔÎÈÿiˆü–    ù   IA›&"? R˜”YÿÚ&%HmD¶Ô4Ozq¿²€ø(%õh©Ü~‚×èÕ¹“—òûeKiPo)FMò¤¹ó<Z    î€   FA›F"? ?Ö0S0È¾´jb@m¹ğÙ¨¶¢€äÇëØåıSógÈ³Z¥éûh9nä+(aÕ3|    4!   VA›f"? ?Õ¡P„€vÀfÔeÕQA³^§U¬‚î€2n÷‹Îu¤FVŠb ¹ş2Çà”SñNyë%ß2fw<’Q¢Ø‡CX4€á[ÄF„    p   ZA›†"¿ (“¤¿x6½gq'ãy¿¯NOLò¾O×‚X"ÿÚ2¿ñãÈ@Ï·DX¥S1¢ÚœÃpŒ÷~oH+MdÈÏó§§‡X+“¢òv#¤OñdŞ     ¡   [A›¦"? c×7å!£¾‚#*÷ğ{¸”
?£“œ¤p”G[PhÇæŞğôÕì¼Jñ÷¹ù%Œíî|OÍC†­Ôí¡½Êó›ÍĞ½TºŞ[*QH   5  DA›Æ&ÿÁ€WÓÜƒ
"ğ«¬|±ƒÄÁäÃøÿ¾ÂÑª!ËÊç9à÷U€‚Je¨}î‡	ªlñ\Òæzß“—»“;A›…WƒN1[„ ?tWû-‰=Á&Í[œ9_
_¥b¾_P¢6Q4áT0BWÖ6}Ú5î³ı>¦ FQV–º/-8—‰GË¡,´9WP˜)Lqî	¬®Ù”˜xÒ˜1ò¿év…`ap×?â[‡¶³àèâ)«9¼’wÉşÙcÿùqéö™gw$×+*£ğoE“°S÷§ÎàÃ«²¬’ëzMåÍ2¨}–à9Hü©jï+±õòÈ5 Kô¦Ñ%‹‹YŒ’m=MaŞqš‡‚¼j‚Ôš+Û£90êM¯Õßn¿grüxÆ;Bˆho­~AôÔÖÿhIÛŒ÷‘M.¿ï§^³aÂÄ%X–í¼3MÉ1\ıöä={éòµq3s@ÏÇ{Ü5àZÄââ¶¼Š ¤'™|ÕH»£2·íĞ«‡€o¡4	¡_5%è%ŸA‘;‚W¸
‚"‘Â¹¥­~*mv…<ák[G¢­(6µ+8>÷ŸÔÈa(ç,ğã™0æìÓ©˜Ùã!rÃ® †	ív¼]Œ1~„M!o”i,,“gà€xlø×ªzÕ¬8C’y2ïvãş•ô|ÊÏxÏ Ç×ø€Ë¿.ÇpñøqŒ€êD"¹·«S£×È’=¸H;Ùƒş”»j™`   º	²×ÿ_P,ä  #à  'A›æ&ÿ "í•ºš3”2d}Â
Ë¬H­0.QğÔFÀ‡^ÿ£µüû2~¸Xë×¶Ï¦<‹b:²ÈÉjEBÇ(û.Rß~è^S“-Í“Ã1”o'äf†Ç‰.dŒ“ÅM|!€Ñr>«®&+ ğÕÙİ->¾’‰ùb§Sš~IUıÎämö„“îçxK"E†?V?še‹"\÷’Rl„ÈíèÏÖ£…ƒWí~ú>Àªˆ´">p2j’aÍSô#JØ•õ»s@3ë’óÈıéÃŸùĞSœÆóÄÑøë]í<õ…ôã˜w;{*£nşÿm„Àl*J8ÈÅÆƒ}ùºeVàŠ8O®E8ÇGıÆµí	Ê½j÷¶›«¿×¸¢%ÏÂù`/5_y0Hš>\ğOK`Ù¸Õh’ef©¾Éè†ÁùÀL®),ğº0ÇhÃ,²¦À2|Âo2ßÄ÷!!x´x~šµñäÖC°±ø¯
CÁCpsAG. „ì´ĞvlÚ¸º’ïá¦§‚fPQ`r"ÍpÂ5bitDôšî[÷óÂ¸óK—aA×şä<‰’Í†%tĞb5ñY8¬ÜäüğˆoŠ5¨@'øaF”ºÓÃ`ƒ"zUÒhİg çHí´XÓ , & 0âĞeg‚•K^çÚ=Ê2,Œ˜Şí“|yÅ^Œª‡yTk0ÃGkR(€†Sd\13¡±ô»iø9/®Ë¾G ÔJO,¯*Ğ°¤²ô«çíïç]_6ÌBKœµ±6xKfó§°T’§ˆ­ä•—ST:ˆBÜoğC?zV"¶{OaÉÕ|ÄÇÚè8¬@ŞgğkÒ*c6š|æØˆ‰¢GiiÿÕDk-Îl\l[aS¬*g$£ïÃ©ÜˆşÓ}’6‚&Ÿ­9;[BÛ}¿UúE7Ds¦#¯äP¬¬ÖXÎƒÒjcÍîú,ö>¾ÎÜ+@¹ö$Ü®.ˆÑïqsü.·ÿ˜Ä)l¦Á’¦fÙ°*.`0aC’Ì•ÑÉëæ­«ÕÔô'¯WĞÉ¯ÀHNê;,ˆÊ®`›[iEİ‘ùGM™õrz@³Ş¹îAGªá#S‰³h&­¾Í"
¸á(XÂ&¢ØJ‹ÿD7Ü'ìÜ‘w‹ìNw…bm°u!õß»ƒ•ÍÑé¯~–¿1Ë|ÎƒX»gi±¡k@f“88Ü•êL1å’ëÔ-§@LUÛ³åbemßp‘w5ú;ˆì“!Ë¡lzOáöö	©ï•*?~Ê0€E{iû¢ÂĞÅĞu-¬9Œ§åKütËT×w¶9&…éŞ7tıº—ß€3ßÊæ{Ú³˜G¹\^§İ‘İ
`y¸)fıÍMD¡àçD`û1;×9»T˜\Á¦z~MB"•-“gƒGH%A x|óı5ùdÑçq|®"d¤–M‘˜”æ%)
Æ®İ·‡”FºGÑ®«¨Ôs½Î’Ï@Åpì*·Úáe-]ÿˆœi^¯áP—húdØ¢Wø»®1íëzh/ï–K§’ê*cZ<HY®ë+25qÿIo÷“5Ï7_14ÈÒ;µ€ x³Ôî1nTûñÆ°Ş>7ë7t^Zˆ7µ?µüùñ±ÿCjã…¨‚¡ m‚Ä¶)j‹ñÔÿ<íÀÉ‰öÀRóJxŸÿ	³eú,‚{µ½z‘qîËßGU@   p   gAš&ÿGó!?  +Ú@! sâ‹æ´eŸÈÎ0K¨}àå+Çıã!®4Ëÿoê
ë‰+Y®òI¯ğlÂÿJiî•ªdwµÜ&Âo¢KãL)]’à¼Dwíp³¾n¥Ì¢r     Ê   Aš&&ÿ       ğ   AšF&ÿ       ñ   *Ašf$ÿ¼•±ä ¸3Ó0á±=~Uûak9‡i[    
¦v;8ÓØà   Aš†&ÿ       ñ   Aš¦$ÿ  ‚İHÔ¾ş    Ñ   pAšÆ&ÿ 	²¹À½¥bGw¸È'©ReuÂ=Yºø’ÏªTŒv¡i²*ã½AY¶š¼>ûÊS‡æ4ÔJ¶  ”µ«×ú¿3ƒº˜õÓr*q»ùŞ,µJP{Ò¾)Ê|Å7Ò€   g   _Ašæ&ÿ 	Ÿ×À_Ñ&ÙÁ…´¶A§a’ãYÄm7SXÆ£:Øá„J;lğèÂ¦ˆ\ÏórO#Ö7Üi-Çd½v†Ô¢}vQ¼¹ìŞh1oßHªbs‹,YœÙ4ZP    LÁ   qA›&ÿ *QÖMî1R­•bõ¤ºK6‡%k±ù^Øşº&\ü÷ºÎÙj9ªàÛÏ›¿çÒÎäš-îÁÜoU‡]¡F >Á>¸lO“Æ–à;åÒ½Å6Vê$¼ƒÄ|{”àOƒE|    4   eA›&&ÿ 	™Äş³Ğä*X°J;ó–.ã¾.Òäp;~=’Oç	Ù ŠMb¶ßO¶ãju_%eÂi÷Š*­ À³¸ppàNWÂ`eÔß¡§bÌ¶*ØµõÔ‹şfUØN>à   N  ±A›F&ÿ /•šƒ‹­glæÜñÒø= ûQ·^CÆã¯Êr°å¢»rqGkíáM€™˜"¨7æŒäNe5r"Œù!‡«´“¿íQÆ´Ú<O™ƒ­Nù"|	ôCbKºxŠôB?ÒğÁ™Ñ} æ-êÉÏë²‘dî± »ëºpW#˜±\—–p¥–+9!äÒ»eøV¿9*áğ~BBáßlÁ8†õ®Œ;ô»¤R„£}›}¶ÖRÍn#Åº\Ê¬†VÈ8]‚=ÅÄHOıÈ¦ÿOÜwyãĞWÈrrzzhŠ
ÿ­¤íI£;~æ…C<ô\}-554Óáô‚­â#mSsÓ;Q]Jÿ”®ûÙĞ2/èËÉJ?•¢£7P?›ÍÂ\ ¯CüV´Ãr9'1
ßŒÉ@¯>cjÊƒ‚¤´÷EåñxÕ¦’[SyèÁä¬vG`—O"Fxfï!Ú{>Ô …®$ÒL·ã^iq_v]ˆÇşç¶¨YyŠJíPòëcüÏ“ƒIÉ
èKj%4ÎKçQ‚ŒMàÜ6ÂÛß©Ø­-Z,Je€   I   pA›f$ÿ Ï¯ Şn+ÃÆJY‡wHCîHşÄ)Õ›ß‰ümY5¬õk[Ì$-PäşŠG¸å°º…úæĞz¨ÉÇ®ï™k×š+‚*…C&QU±[©I0>HÖ`ÛÕ<ø5ÔEr=ú      iA›†+ÿ ~ğˆbÙ¨ÒJ<\‹6èQgJ>:m7­¬_#‘È`y@Y“©É Ä‹´axëàÿPe3ui€g™§iøÏ„¡_Ÿ­Ò æ>›CÈD(D-^XÃ¤ñƒm!¨NAzŠË‡„·3ŸS8çáœÒwf°ƒhZ#oEÊ‚P®Mô+OÙèÛ&8¿¿®¾áøLûå¯ù¼¢é°2£@?fF¨
‰ê`©¬İ˜M?Ó|„»ù•²qÒêĞ!ãºêDE¥ójºé±Y!ƒu«}¸2ô¬òçz¥ú¦&—Ù…å›é¡çDÒ]i¶Åpd2µ‡º›	gk†ÛÔSšo$ñMT®²gé&·KÛÍMnÙC¦c'˜ÆÁõÍR@´s¡@Ø—¡rĞ¬¹UÊï¼xH”¥ÂîDÉ+=‘‰,u¨¦gŒ5´³£ï±æ'~ÊB.D¤¢Á¨-X^¨#a_|¯ÍlIˆæbÍP>³@C|/Xÿ0³*‰s&÷ËTÀ:ˆ[ÛèÛ¢äKÍÒ<Öğ.tx˜÷ÕC>RñÃÏŸ·Öñ¹¦)’~üİ~*…©éÇt<!QÓ¬X|
–¾›¢³KéèÚã‚ÖĞˆó]ùW€¹…+l"¥1³3eÊoç ËÜ*>nUğEn#“jÛ6€K7&–@A&•ÿáXğô3=¦…á #-AÜÂ{mé>4”b¶²HĞ@®ÅÉAc¶Gù‚x—÷2j02
tg~¶ÇÜE[iø²y#*ók¥™/¾ %…ÃÈ>ô»ÚÍ{ŞîÎ{bugñºÂHhnkVìM%¤à¶ºˆÃü",,ò8F„õ!W1 Ò:pßıgäë°}³5–zéœ•;tï¼÷c>20ûhØãÿ‰‡Äğà9á` ½'uÒÆ^´q•šÂoÓDfîSWÈ“ßÿ‰7Y1QŒº±:·ÜÌµú¾¯öØpCÃ¸Û‰àDEïfGI1ñ=¼K	'“˜‚ì"¦wj8Mã @„¶fL3©ŒÍæ9ÈÆ¶ê.”&Oj›‰ÌáÙÂ2»¹ó€,\ÕŸ&!r™	öğƒ†™(Zéêì¨™‚ñØDŞP>ë´¨¤}S[º‚mQö½.  ’   æA›¦+ÿ G8eH^Î¶‡¿Zsë­ü¥}ÕŞ°6Æˆ`)™¸‚%€v€x     ±”¤7sk'`­v>‘dr¨¦ôÓáÆ/A¨Zndå˜÷&¨ß¼ÁÛÚÈ´âÿ‘ü>¼’œ:ˆ;N™´7_}YR‰TÒìKİÔøÛ˜=Õ&škO¿Á\ù!L»FhP{ô`$¾–J®}ß|O¦ûÇ¥Şc“®%	ƒ_Á"RY«!æĞ½6bğY¯jªW?këkÒ­yTÑ*Ğ“*«U&Î—à7©èÉà ç   šA›Æ+ÿ †Ô\ªqÁ²Ö| «|ÙPÍ•á–6NƒÌen‹¹ó?½‡Ş[şšNÔ5ì#ÉœqœvÙáKuëcø ‰oC_oRû;XK%F½„¶½Â‡IÁ5oŸã\ÿôİ½ ïC@®°JÅÑƒªÛ¯}¯ºîÆc,#—ñ|¼5ç<"¶ O€   ‹   VA›æ+ÿ 'ía¼e >ş`
í¡c²O¶9Ë4A…²€Ôz†7§ê°ÂÜÂâäÜm9…Î…–=æfœ›—H&’ÎËÔ¯ëä³›cág3]„À   ‹  ÖAš+ÿ  TqãW"*kOÍ ĞSª]ÅÙ];×VÇ]¯EÏé§”c…Ÿ¾Š<q–Q¼ÑÔ ™M6?ocY(!µÏØ/¨ˆK¯G5®RÕ¾Ül¶/s¿p51¿ü}(Û#hõ©5Ï;uº¿N´,YIõÿ Ì ÉNHÆAèá>­~NÏeÌÿºíÃõ`6ÍN:óş…ó=r;e6×ò´‡³p%¡´ÿÇ¥${1´·°B™å›AmMV¥ïÓÖøú±ö.çóX:DºQGú³‰|Yà÷sMs@5H	ØT„ÓÅ©ÖFâàOÒ;UM	À:^±<¿­¹¥)n‚,M…Ucq« (¦R²¥}YŠéB«*.“ì1»ËPƒÔ«Ä8ò¨´)&ˆèÕ†ô¢FSíH›tÕ©’Ş[S=\¹+üIã/½jN6öŠ6ğ–y…0Ú±75]t‚óªÎ9Û^1–ï\ õK0ÉAE¡vÜo,{†àf@òcºé“­ˆ¨CÃ ¦C!Öõ÷g@—]½ˆ©BÚ;‘VãÊöVoºİ¥×öÅŞ6µ±VãªŞBÇ—’â{%*`
9ÛSË&áÂpò›TXQÖpïu¡AÅ±á*ê†ê¢ÈËh’±§ô²Ÿ<Ú iEæDÒ™ÅNmÎ>æWğ«tA\ddqşikÒµœ=‘?Êë_²SêN+ê„”ï,Á$)£û_ †Ÿ€™Şª¨Ñ&ŒÁPD”wÎ§ŠôÍ#"Ï‚¬Ê”X…¡‡‹†İ¿œ¬êw;×!£E³:'âæ'šôZ¶ÍKÜ®î›
ÜÛâéªöBÊmìŠ¯ÅQ
sdHº^Ä@¿S*©”Ş“8—&
®¹¡“ Şœ(ÿë”Œ3¹\³öˆ Ü¸ezuèİ»yó„áDpÁMŒ(¬ÀKÈ‚¬ßÜı(H   Ğ   «Aš&+ÿ  L´Ó,¬eÿßPh2ßã‚LÒ ó+¾åvC)“à#Sb¡9PcÙ:Ò­±éĞÉ+­İÄ©…[ïÊ$Èºr{·ºöš‰ææÑ‹àÏ–%L”-¯ñ=«Ğ|c’½–Mş	ªT×
f´I­vOı’JºXÛÅä¦q­“Ğ®Š`OAÎVñ[
(û¼§ÖoFêvù$‚‰B¯ºqâï
yÀ A   “AšF+ÿ  	vÍ [ëYî7Ğ¿‘äß†}I¬íZd‰!-xÑg“ôE×ëA5Ò ğ÷)©:ŞÒÆBEõ<A)b™ˆ¼x…¤…/ı¯Ubuá§şV°Üív~ã£ÄÖ‚º…A“Æ¢“óUÓAôŒy°…÷,Èá¶+‡c¸/Õ›~*Qø…6€   ™   ~Ašf+ÿ  FÈVı¤oaÇ,ø™Í3ÇuA|¾ÿ‹„_}@ƒü,·¶!(õòAyĞë—ªF"s.ÉÚÓ„'g$SXBêCı-.Oa•ş–€{dCÇ2ä‡÷/_ÈJŸ©A7ğÙàˆbşlÑíßŸ,E¶ìäÛ$Ép    à  IAš†+ÿmğÛYõÍçL¡GòZ™!„rµ±šö#=„2b+÷¢Æ¸"ÚÄİıDãiŞÍLîMüZæ]ß\zí:œÙŸ˜7Ä:RXE/¿¼ÙI™BnD=Hô¹6»óÎ¤²Ó'µËL\ƒCqD¨Şæ-q÷éš˜!}2Š;†hFvD‘KşòÍ,n Ïr²‹€¯™œ·5
ı‹äõ zöÄ äÈşWö4J¤¦N„Ú„cê*S7\@p§(¯]ÇŒ Æ_óàÏï_$ixbªRİsâKéıíË,ç^³4¶Ç‚nş`ûı·^Æ×qJ©‡È†b\­2ç„¶}N8©3¯gìó»•Z@~F÷	S,>ñìì5óz%Ë\³—'GA&kŞ6ó÷ñ^Ì·ÎCĞ—¶6îŸì@FdîÌ»€ ¶  ûAš¦+ÿ  Æ/ôZ:FM7©i8Ò«¶œù‹7ù’³“ïp@¥H¨Æ³k£¦vı—)óuKšÂb°³_qÎË¾	Èù£y“¨Ãc¡‰ùK¡õîaª.`;Û3mõ™b¬ys¤[ØvwÌá‡İ¿Ô§·Õ?{?K! –r/ı·§½PÒnı,pS:En¿OÎRÛ÷sàNÚóïÿø9¨}gØ{3šzÃÕhí¸É™Aïà;ı+í*ÀüİÂ`—ùn(U0ùŞ^½úê&$æÂ—<å)³Ù›ÖîĞä˜¯Ëãwıµ0Nõ·7Íœ/ù2gĞª¾˜IˆĞg7ã$$ĞMªøÉ¿¦-ÆJ»ºr·ùÓlıé‰< óiz•Lyİ*åSoË=ÀŸµ {Lâ$P®µ.ã?KÂ¦ïj6"ƒÄ•ã‡FT/ÚL9Í’¦=^sê[0ÆHŒ(aãº`w•/Kˆ¯Œû„£å£s:–Aç¦‘³³«}·pÜ,6‹eUtÿ«äìñ5¡Ğ’öEq[•ÿ ˆ³™‰Bî_€$Ë¿Óiß$ïìjÔís/É°’xåTVÉáG¼ì`d°7±R·›Ê©c½ÕyÂ¨IúÑ¢ÖÜ€»Ò1SàŠ#œÖ®âÚÇ·À$Í^·r}–Œ î_ß‹˜)!‘‹ÉdGÜ1`sF¦×·IÛ„4gÄ
Çì°Õñ{¡OÓ’{*[× ©‰ÚÇ¸±7Ñ«’RŠÃeˆ[…4œä÷-híÒ 9Í	‚Ï¢,;•5Ö:7 CaÊUeô¥ˆœ/ïÃ|…RnÉâ@µ+˜lÎs°İo®ÁuöFdõ„=¼ŸÑ Î6g_9>8œ¿ØäZ»—ı~@m½ÊB¯Å-¶Ä”Q­·CÅ1·&ìE’a« ;Ïò¦€D'h:¶Š¦ç_<†½º×
¶¸Äe‰Ç÷I…Í{¬#o 7-’íT‰	H>ÃC0Ï£
ñ„§Î„½à±AL¥Ö+f4¿—&+Ò6^+Æpÿ—³ˆVM‘+/¿qğº=}‡J¯”GØvmŸuŒ0ÓØâìOXS%o÷a:@‘'9°';k6õ¯×]u©ûÊ'u ÿçûê#lÙ”Nª*šp‡ºB-›ÔÀ(pl4¬ñø¦‡<˜8Wä¤As_İ†Ódyß0TGeÂ=’:dO”98¯mF\ÓøÔ²3È)3—^,˜^.½Ÿ®
^Ä Ó¯xC¥a„I®ÅIoğæšÖŠ^ØÆãE›Y|QîÀÑ}#^6ôâx HYM N2«XiR÷]òB¾0 <ÚE»w²µ€Qv	ŒÍL¼–ë—$»µic	íÄ"
½y÷Q!hw®^xÏSÕzš´¢­®ö}NŒšğ M‹óÿ1ÓKñ·Ò-×ÖŒ;ÿ1€âS¹èú~÷0ÒqêÛ³½·øŸ.[FÕ*hZHgÛÃd‘‡yytV0âÀx…EY¢ZÑœ;[ÄTºËùé@×ŞB1(¡d’.1«‡%¢Ë=rï¢\ >cşËc@“æ:o>¼â­ÿÂ jqw
-Õœ†¾*š› \zz7ÜşÌP—S÷«ZvK¾¼4MŒ &Ò‰®µ |i–¹üÂîˆ¾&/^KáØ-‹*ŠŒÀèÖïï‡~‡ŒÑkÎ}é¨^©4^2"|Ö}Öë~“f²I¤¨¿V4º{»9‰Å°ÃÉà"ûı¯²k»Ïå~<á}­¹¦<86(“™µö€¶Ñ,Ÿ…İÂƒË¨¨ìÍ˜Q«í,a;ÛÆ¶Fm}ƒÎ¦H!çY~~ô\‰ñp?×Ë«l;µN¹tèÁ¦U¨×ú—×ïÏ`Â§îp÷5š»ä¡ô3ˆ}Ç´Õå¢Œ4õz>H=Rº1x ÁÒoÜèışËŸãÔ’¦Ÿh9Ïÿü„Œ˜‰îC(óşõıRà±÷¼Ÿ°ÿõ@  *a   +Ašæ$ÿ  #=,Kû:Ãy‚+¥1:Mr4'¸rÕ{£}jÒ   õ   A›$ÿ       	™   ?A›&+ÿ  Fåa÷’&iDj½2	‹ˆÛJ_æ9C7¦«=á;	mÏ¸)šw2iü¬   8   —A›F$ÿ  #zr-ô1”fwuAªs>SPˆ¡óë‚k[Q§Æ'ZGÖ‡b"GøŞ+Sç¼1€te6w¾
mÜóàë¾ 's ,©Ğ?¡ı`]’||Ê£úüâ¥SuÿğE`C~İí¶Ú\‘h0nf9«E1‹´Œ¾£,12 øáÏšÂÅ}]ú‹Î€   aA   hA›f$ÿ  ]ı±M¿ŠD*§Ê®nä]XïCeqQˆ¥ÏÉä ”IÓ÷Ú
Œ1T‹a:×6{jõGıÒ¾ÅeÍƒ•]5}ÕÅr ªï÷õ¼¹)»Ï¥©u¶O#Bºİ•³óÊ   à   _A›†+ÿ  Îà
+JG9[G2J±v=_ö8e€Ï^¶ı¡Ğ‚¡ÿIÕûuÒ Kä8„IåTŸ½…&–fC‚dùY Ü¿CNíñ1â}‡®Œ ó‰À    KÁ  ÌA›¦$ÿ  K#1œh­oéXRb¶µ¨…ìÀHu?oÁûõÇéßpñ•ÔJ¸ÇzÜûB€9ZàMz=£`xXì¡È¿Gş;™ı+$Úã)‹É­é4ÿ€ãN4oş
ıÆ‘HÅU¡ríÂºSƒ³ëõ@_#6  ¬¼{Wiü5³ïk~àª>@›	&İıã_€u|¿â „}p\š·%JT´Šµkİ—êÎ_–äİç…†5OÒrÇ‘õÅ”a\Ñşa»ZNœ'š*‘
ç:>“Õfî+Gê¿éé*¬ÚÑºûÕ<šüÙ7N%ÃÒëlõR_U 5"êA•ÙÇNÍµAï#W½Jt3›¶$­Ö¤˜/'rbqrEan‡e+M'*Ô´ŞÇ\–ÄRÿ@©*~² 5qv—øø è–B5ø2c±…So'¾€aˆŸ‘í43¥6g#²óTĞı©sÀq`9™Y™/bÙ®bß4[vçäTC›ÖëVlÓû
ùï%ô‹De+/iŒ Oùğ;7‘ÍºÑÿ%ì°#•Ê®k†n–P™0>‚—oÿ½ruçğÅª ñ4›':Ûµ·ëæÊør»Ç…Ô£†‡‰IggtRÈ¢…ÑU X´öp?H&ØøA˜ø<   8’¼Èg¢ÎÒ¶š&šı>Oaûb?§Ì††Ÿ¦‡ôÂˆÈNu›Au ½&"‚òşA GK¬ßÿè…>wğŒ½Ú>\ø ÿİä¢Sø¬ ĞÖ­73•°xÕì‚—øßökc@ıs×[«¨X ]xùÍë)vÈ	 ô–ÕƒY3³®Mï#}Ş_Gb¤ıJ—“›Å»1ºÜ/º…xCm—BëGgÜx3êvœF«­ãpÊ†¸®Ğk…´5©â—÷@½¢º¬º`üW‰r„€®CÜTÒ'&=T^w
YŞmÍ*˜ıF„wÚ/+öêWUÈ”ç2K Šå$¥.iÏkØØÈpVõÒyì§uDe©ìä››]6Ën8¢y|‹Ø?ÿ•Á>W¨ÜŸ['®Ê4ı…ıÁ¾¶•UÓMYdÓ&ş½ÉËvï!…-JË!ôŠ•LËøÕ£p‚+¹‰ ¦l@=s|Xıí–½ëb;üBúÃAA6ùVåÓ×gÖ Xy‹—!ù‡ç =Üæš	¯ĞÙ½c½&¢?;é“K!4¤;‰¸¯q›ª¾1ªÅæqÓFDÙ`‚d«cóÆ,¥t±ãß¸å‹jR©KoYiBY)záÜ5Nœue)3ôË(‚€®mnÚ¿¡^€¨AÔ(ÙZ?Ò)(6€ùÎíÀ©h>¢ÜÏÀ%ß¬¢ëi{ÈĞ+½Tøı6Ï¾"²$D<š~È‹1ëšc	“Í[IÇŸ²û`²ä®O†_ÑŠş6ôññ§^¸E—ZT0>$µ¯H=–!Ruc·8~„På?‚-i¸U´?H5/3\ußé”¬Ü(/Ø’¦{ãRê¶ê®$˜&¿3¸¡ø×fğåèæğˆ–yu³AÂgNHüÔú96Fpn\B5Îã±ƒ-ŠZ£ÆøY¼»^Ë¾ü£Fqg¹(¡¾'Ğ9ß°Ğ}Â`?‹Ìˆl9ş4Ip¸¼²I¼¼z—‚›ì^…·(ÊWJ»èâlPF(² O°(Jpr¢üåé¾wö [—NK}÷fœ{»wûwX¬OMırç=¢B’ïŠìŸwmí¦â®| #lï ^Ó(ºt=¥òÛŸÆÇ|°œ£CÚÁè¤œ^9i?\ª…Öl2òŠeâÑ¬ÄÁ…­Nˆ†V9øe@^I[,œ[¡lpı’ºµÍ“9liŸCƒ‘îşøtßŸ¤}ŠÜü<¾E—·íşIt½µT=äÛ¥.Ÿàé½ÎŠ[°†Rµ8°VÈæø©Z¢×ƒÜê†	1cÆ
Ój·Ğ5·ì3ÍZ(ëÎœÌ¹â…"ªºÔûS€ˆû$°„^ê[3®ıóCVÄkÇ{h¶ø7ÜZÚ5¾1XO™M@3–JşKüA!tošŸİØ]‘ü¨Û×_ƒ}ò÷‹æV‡éR¬î;0ı†Í%y ÊğãèãÃTTÕÑ1.ÍŒp}¡³Öê‚5K'Ì~¾„Ù«üÍÕmŒÖ³§¦n7-±º}çØ®?ŒE¸Ë¦•Ù9\Û–ÏXnû:!Ò˜!ùöpù˜€Û‚T=¥ı—ÀQú:Ì:‚ƒtñİ·	(Î3A   ×A›Æ$ÿ ‚¾ñò*8ÈN.XµÏO‚(éÎˆFİíkT’w½‘›’•vkø[ARS· ?< å‚°ìyL0€²Yõ¥ƒ+·0Ïrkã)håÎ€~œ…ı‘(ŒwE„„~CZŠ%8¼˜Ç±Ëí5gH;«ËÆº€  $íQ;ƒëB8ô	_Ü÷ó`nƒyóyLákbÌ£°Ü÷j$î²nònR
²Ó!ÁTñ%ˆM¶×jtÕ©şó¤½Ğ8éö<ò‚B¢r39Û¯Å]¢#_KØ  +A›æ/ÿ  †#sÎœViÿ¼*Kkµü7ƒ\J45ó ?(‰1*ZSïÖL6*×ğV0?Ä±‰²ª_¥ÙûO\`¾§µ:mÒKøóöòëÒk°Ê­àa¹W¥d‹œ˜].tÁ ÀFuìG¯$¤¼ËÏRç[}	)¬k#
­¤éœV«àÏ€OO)óæõ:V‚Şd~Ü0¨ˆ¼ŒğUF	Åğ àˆÛ©.CV6¬ò K„³Ã\#Ü.ÏfÉ@¤ëŒ\gX\  hoW#,ËÂîÉç;NWO6¿øn.¨±h®“ùnröKÏSQïylÇTJt€"<ªréø9OÌ:-Ø„M4‘»w‘¹:1€ÄìYÇN¯N¶¬¢ß°RÅÁ\   ?Aš+ÿ  ­~¹ğÇlQ>«_ÏíİYN<wìxš<ÀÊ·¢2®äò[d
„ÔŸöü   =   EAš&+ÿ  ­}_ÀœÚ^Cõ&»³÷¶—ß&Ñ39Sı4ˆô1ôT8šê¼BÌQb™SVNHp   )    hAšF+ÿ  ­}Åä‚Ö„X¾;2É÷w]•8^eÆš&ÊIŸ˜®¹/ÂzıL(ÊÌn• ^-Âˆ|æ2.¨Ş³ñ¤U‡t¼Z4åø‰uyÚL¤ÉlfÃÛà   RA   cAšf+ÿ  «±ŞE1ãõ·0Õ¥<wùRÛŒÄÁI#½?¸€E
ŒT×/û¿É$eCP™Øfšò™n¸ş€*åô)0n LwFWÑú»ö±|?hƒ   ¨  ÉAš†+ÿ  íĞÒÃ#âŞÄ1„­¥|Ï ±/ˆ²^À†÷Ë,RÀ½ó?#ê5bŸéï²¼^à»ãã.hKÓÁ¤`XAju¬bşf³ÿ‰¯P`áÔÏGMÒ.º6/É:·0µ}õeÖ!Ó†
»7ïííø‹FMXšÏ´%¥j–âD’ô8+‘“ LÿÍÜ•sçö»}!¶† ¢5ËÖ_ëó0Ú´d¢øÊ\8šª÷¡´Ëšï#|’p›BËDë¢.#@³•vÉ•—I¨¯öÉ¯€@YlL|¿–MóTŠä”JQµ=îo;ãjÀj5k–Æ¯üWó9hqòì¶wœæD,Èò%GÆº¶ğ[ÔTY O˜Mˆ´²t§²GenÛ¼K‹fØ¾¦‘;¿ùd'"³0ËT2ÍW5¹ãÙÀ![öWÁ—¿¦”5O4K %óm¤­„ŒùÌ{‚ï½¶o¶ŞPµ®|v)o Ké×D•üô(lÏhe¹r²&2¥3ùTÿÙ ÷CîÜ¥ÏE†×¾]RA0™!è±ãñÒŒÃ¶½’'i_#ó?Vfj¢(èe@Ğ(õÍËAõ4w•VS#ğºW(j¶-¸Y:á‰µ×Z>æGSÉÈe‡|,¦hé[à|³ÛY»0ç m·Ûˆ—(—ªqõu­µ6êˆãñòRg¾FĞÕè fHlkÇ{ñ €¢˜>Óu¦{ßc­«ÊÌÌMÀß Ëï¿(jÁÈ)É¯,RQr,á³Û÷G/HÚãÄ©tTW„¿‰›<ÓôAU;#$‚'·GğUï¤·–Ñ ^Ì"¶—5=¯B¿z×5="^Šñ’kÁ{j[ğ‹·^ëKÊNĞ`%¬RP"“õrÛ¶Kêä÷ÖO`ï+‰œi~ÓûârJÓ}K²ï9ì‡Ò;7°…z>•¥GˆRu¾˜P  ß€¥o¨îÖÿúå‹n†6¡TKÕÆ…Ë†š0ÛÚ/c(.âøax¯t¥rJ” Ì/IöÄcs¿Z«YfsxG~DQoó'ó-øÅy…wsxšƒğ.20 ²wèF†*;2WÉ>í¸ˆ–'–•671â@MH¥5¬~[ıMec8gú¬s#"bíOû÷•]º© nwœß\‹çsô3„Éa01½rÄŒïÁ=ã|goy›>åõú})Qõ™õ^À&<PÿşÑ× !º%e*£`E±™^dWqaı"À…¬…N„»ç…:'Óz/*“a™DĞw)=3¤5´c É…X¿ÿçÿÿÖsÑÊd_½·‚‘}A[àÅÄ×1k>¼j±]8Ùep<0lc€A D.6*.9ÿNB~à»îÇ*q;púñ¯ıÂkMFĞÿP‰¬yH›déT± Ş«‡9Æ+©°cıpt0é…/—±É5P©±ØŒ¸ê€øæ·};M0•%Äp|Š¼Åš±$~MäU²Ö0Œ¶œÍ7P{³ÏÕ;ŠYH> I¥9vy®ÿ·]ê-#wt”jÈ#ÏH…3d™iWß8æD¿tu4<uMÒjÂâ£? Q›NöIGâcIÙÊî[¿ø€¨'½âœUŒ£uËßËµa{n•;s|)z0b­È<Ò0È‹„…õ j7^×ãÂ(3[†º„çéà1 …ZÑ„©µñ%nD½ç[ßqµoı‘ñÇ}tù!{Ğ”gŞr"±SÛÃŒÊÒébÙêvqÜ´¬pq]ÂıÊ±Rh¨>ÿPÛÑËxX5¦	%"êrîFÃêvcçihF¼v'„â…“3´ÈãÒä¬[êócÏ¼–1”C/)¹µÎJEĞœæk°…ì ›/¦ıı5 zòª³‰æòúCÌävÆ!‹şñê7Ş$QÂ¬WVá¼ÔšpĞpY¦áº÷VuZ›Ôäz&¤áoòÅMç··dÙÍCßÅÎ2sı9ŠòÈ2˜ÓÙVJh”IÜeÇY•ß‰T¬µR}Øß)TÂÄ0°ğ¯Ü"ÖyVûşÀ7hûb‘rÅâ#ÿÿ‚şqW@y™ê™iÿù4ÛÆ*.ğ«u®¢õ0‚í÷Q6Gœ+İÖg—C#yéİ§7FÃ-K‰0õ–x	åmÂ–ì¸ìËLşûÃpÍ:ù”cch]¿Ş±°È3Õ Ó¯ˆ-Ùñq-ì×š
Z/‰©{3Ş€ßÑß}¨˜İ1ÆÚ  ¿€ï%ÿl¾ÉuHMáFØÓ2ÉhùEnF–ß‹`¬ÇÃsÊaû˜4_ÙÏ{K½¡HØVGªNoë–
+-Æ„Ÿ’3!,¸Ö0µŸßWÏLàH #¿ÔH<°İWª‡•`Á‹ó§®·@ÍP¾9¶3Í!€î_‡Oidå×|y¦ˆş®& †ïÂL†gX6g~+áŒ‚Ãr]y®Û`Õû{üøw(º‘fæ¾1Ì=ÓbÀîÉ»Ò¦º…%f@Ò>¼îğİÈ(40”,Wô×§z"p¼ÂÑ™¢è–òÂÉ®Ù©ø–Ã’[e²À­BXkEr=7Á_ÇØ3W×åœ±Ì’Š–lô(ø·¶'$>,–~ [ñµ?‚í©&Zó«qŒŸá   ÇAš¦+ÿ  ½­¬ºƒ’d"õÇĞ²<ZÀ$µ½mÜŸœ!œf¶ZUÙûÇ¨±³YÑğçmy@£`1TY=¤Ù$"#‡„– 2Œ«˜°Ô2+½ñİ¢-ÃˆQû&    €Ÿn+$®
Hß¶l_¼A½÷¯gÄM0:›'` aÆöÌeÍC›b?Â±"Ğæı0Î÷å_ÿ?€ãç©ÊØ†S‚¸Ò¯ß\•ÒPº†Ù™íT„ È_Š}‹íÒÜø#Ó,ñ   vAšÆ+ÿ   ëÄÎÅQŠ©ÆL'¤kf¯ÑÊe×zıŸÅ«ñÜıŞÒ5iòûÀï/ gÇX 2ÒŸô~j«‘Şø+^|È}ÅÄYíH®‰‘(˜GMù›ƒU.GrE[~ É¨®•)ä%Åş5Ø   :a   nAšæ+ÿ   íR§n{~‰w~ˆFZÇ@z§ é­ªu'¬$½ı¤ÃÓôŸ›·bL±ëÄ‡:`{:|˜‰¯2§~ãÁ¬U8w©Væ2é5T‡4O4îÕG`]Ÿœëã>˜3’äb   1   cA›+ÿ   î4úĞ¨¡?Oû\qc&àÕtãF+`iEòÊºUú	œ«f5ÅBu?ì£aù;AAå¼ë)oŒ
RÖZÓ–^…ñÍ–Û.	µÂ6éÆì   ;ÀÅJÀ   A›F+ÿ       (zØ('d§u+$%¡Pa   äA›f&ÿ o×À]Ñ>¿Û°“Ÿâ}>§ :r³œBBF8DÚÏå¡mEãòb›2ª¯HÍ5÷$/Ã Ø–ˆ6Î·ÈLœ®„~óg*–_İu¦ŸŸû¸›î6&È
æ	Ş¦$½.Àú öû PÌıiHÒÌ÷rŞ°EwØşRF`ÆÅ‡Öáÿ¤ø+Ypœï®Ôì™×G&í˜.¾nİ,¼#²sfˆ ,"îİ”(Ç¨ •Š D&[·6¿«j5m¬]DîËÅ–`ûâã@À }láá8½Fûg‘¸,ílÀ   gM@4ÚCäˆ„     @<`Ê€   hïÈ  8"eˆ‚	ÿÖôRx;ÚU—œS²åõhòycLöFÏ!H†GR{ïÚÅJDÙÇ\¢YmH_wêVÃùkó&q|T§Ãï¦ÎWñ*›S&vãÈ€Ç¸bÈğ!vş	Ï2‹V–öÿ?.ìÌô%OµŒ‘ †¡^Tß€ÀıiVë´ÅËE oùè}'3 ª¹â×»]§…ãù	
sl–¾nœ_ñCÃÅrÎç‘á¸—·7´s%O~éõPßıãfäcAĞ12ñbo–¬7y‰kÆTM)½ïIÂ GÜ'ïÌdÎ$«øş´˜Î³÷Sâ=M<+á‹îOâ|y.a˜Uq$¼[À§9	6Í}‘±Y»JéàÕİ”öçÀ°7¯øíx€Ğ~ßõ“X£ŒKÎ©¨^?ÏI7âzÀÄ2óº«‚Rc®œé—#ì ¹­İXU/?’¤§nêd€s:±È¶¡ GŒşÎÊÄü¦ô°r)²KØaSr°€ñ"ì6ÿ»OÒ7UÊ1s %³ñî,’26“^>ìÑ\æd²§]bŞùO<À0ğ_vÓÀ¡®<z;¬Õû™µSNŞéd|âÙ>½şòCAŠ»jœÁ9ß¼Zƒ#X˜ôO8¾Ê²‡—?Ú–/¥õ‡`   kıÛ>øÙ^%ñSÿù§ü„NĞ†½á*©ÉD˜Ò A»·¼± ›<åsV[‡ÇJwWbNZİpü,œw©…³å³æ‘z0f–Lw)’"¶)f\VvÖÁ)¡µëkÊv»U©hmƒè—n‹ÃÈ´Ãd»$·Ô'.±HèlW”'¼^;ÜY+¼«G“«<Es1bç%º°£ƒ™%¯l’#ü¯ 9×äÛOÿ0Ä‘W‚+œIµõ’au)$·ş‹"¯yaØ1\œ7Úkôï§ú»çŸ’Eg.ÿOÕÛ°3§Ä(_LÂtª½æ‚ÚoÒ|“(T´ì¦Ùê‰%GšÆ.ì 4­GŒìè'½×ïëK7­5Áà«ıíîÊ¼îx¾Âä·¹¦:\ix®‰ÑI¤v˜¨ì½y²”‘OPLR›öMqŸrP¶â	¨¶Óò—a«ärzÅXNšäQÉƒ\T|Ã–rÑ÷É`à6ÿ]ƒ+Œ	Æ'ÏßÅOnŞ4Ğâke}Ã`¦#C“úô n]3xé®E„mÁ¼î{HXş#Ñ9Q×[ûdõ[®S…Î…”qKxŒ_-àUÛXlÉÀ×Ôå™Ù¸cç›-8î3² û0nş»OW7Í n(ï^mïø&Í|yÈÆşü_ïŸ‘Şñ.-`/Ëd bdÒ[z7ó_j†¿”œ*İ4¸+&`ÿ˜óßeö«šš  fƒìô=CÊnÇxºâªËÅıÌÂ?a®šŠO¾Âİˆ„tjA¨“ÙSjÕ–>–¡a
qo«8t/bäfÜ#¼v,<E.ÖAÔ6ögç¿b¥bŸäu*uÖ–Meª°â
Ô^tz<b¿v–¦¡¨AûØRı÷¥D¦XjíA—ÎÈ(ûÎŒ†}Æ6k-Qö+6ëÛû}¦SãE8Ôî¡ß|F›u¨Ê½Ù‹|ö@{@Õåü×ÈÏzT÷•Ãls‡£Q.İ^£<ákhYwâ§o®XtX›×Œîù¯0 li’·ä²¶§#ÉÅùváyjÃõ«u¦¹¦ã?0¢ƒÅÚ÷vP–ß‹z+¶ìã~cÈVµM! ğXU"Y‡Üm·vUpÖ‰Ïà¿å'öQÂ÷¸òËáãÿ½h'Ô(ñÊÏÿÉ™&Ú´¡æ"?\eí›=2Cš†âÍØßÜ”2oŒ'j¢4[ïJ*!ì,äÿxe{ˆ“THÊ•“4€½n>4XÚDEMCgmlÁKúe>ÔùÖ4ÒÀ¬©ûEà×´ŠñXj6ìoü)Š£_şãqµìr¦X a¹„ñkËÁÿõ+MKëƒû°«ÍĞLÄ~0¢®5•fî»ôÄlÍCÒ¼Í‰}_ÎŞ®0÷ÜÂâæ8@Üfé”Mó¤I†’•¶N V	/£!A "›Ş”iè–VnO×s[o îè(s©(Ñc¼`¢ap\XtÑ†iôu¥Øw 19FÇSd¹Íğ\îé(•ıÌ¾Ã;ƒˆ¯ftg¥Á¦¦ÛÃYXEìw^ÈGÑM"éüÿnÕ
Tí}ÄºIœÉÏ\¯õv5UŸTMÆ™j3®r1SQsmXZRa‹CãGÍdOéF"({îÈ§r¬ôÁá¨'{¶q·µùA\eÙCNöù¯lÃ® J¿¥F©£ßp&Ğ‰wôAÍuÀØö‚Cb^Ç«…M¥ê;@¼ÑV+æ/ìé(&a5«êu±@3âÉÖ(xçz…	À?×^-Äà	|ao-4Ô‡H®Î°Ğ€ìÅÀ6§}dP©œş•€À…Xâ¿î+O¿7iö‚……Ë*(œVÜ3	Ä|jŸ%+¶ğ
>E	¿¶]fºV!±Mó¶$­@9Y¾»Ö²ğ|§oN°	òÌ‡¶Ò´}ü:Œ,«ÜÀ&şD?&E+mÛ	%öBo#Êlc"XK2ÅGt¢âùWzı±‹—j©şÊS…•Ùj¢·E„Kªm’Æ|¸Ïêjş{‡“rYı™È[©÷¡™pruILÇØ|I¢ Óà-uØÌ`œ.Ñ”^!WØğq;ÅiVr°ŠÙÍ²áTòİªæ†‘wU£fîZáÏ”çSæ0PÉıÓÓÓà U´“£i¼èK€    QŒÄÿüŒÇK1Æî*¤¯ÉòÁŸÇıX/ÁD  åêmñ#ÍÃ0…‹,ğ•«¤4~0…çBu FşÏMª
ÅE/kş|—c˜C6?z‰İ¼¨£%êdÆNÚ   Yv˜ áXÊ’@ğÇ“¨#hP/@Yšœ9W¢¼æa_êˆ'·Ğ'"M(WOğ?Óx3!YÁÊWÇSpƒ59:ÛßºÜ«‡„$Kt––€-ª­Ùû„?D–ı±¯’‡ü¤¨~<d’GÀFyÓÇXPvª¢+ğV‡+‡Õ™ƒÓ/ç[l]éª’@ël	×ıÙ”íèX#°ÒBjÛAQqaãbƒ}9LUù2.h$Š/šä<‰ÌH™Ü<œ¶ZˆY” já]V€×!®b½Ï8ÍÉ+mı£G‘¶Üó­e$÷%1ìBªÙj.ƒ0u[,	íŠÂğ:c*öÆ´GxÇ7×YÛ¬ä¾%mg/	†# M­,°üıÎI&†J4¼bö _Õ°õÏV%¥Òèg5›Õ& ÒHŞ3Ö1*z9•€z«0 1Úİ00ÔÏ¦¢}n1*q‚{ÿÕ´!W¯ô|tb[°\$>_R*nÌ‘ÑèÊìup¾Üÿ¯ü<”^a.Ãw#µeèñO €8FQAo·X§º°£Dïô„~išç«	N-mr³óå+PpZÛ»RÎÿ³ú[C”gçbC{±qóTòlá°:8”Å‰H«`lzQÄcpQ•µ·
ˆ’òô=«$Û^Ë(êŸËàZøÙ½¼RN]ÛÜ*ş^½«‹Ih~ù–ce»±×=ìª€}ÁüãÍ»úé(ö²]C@Eí/,É¨ÿõ¦cşé7n4‚<µHò¨C¥²|xôSïĞ„U8tßôb¼áo×<X3)­jç½×voÊ·ò0[gÛ^ bÆÀA/<†¸cG{vz]²^Î¥&d?áÊ¯ª(3n‚d›"ÕpÆ—hu+¤yø££›^Cæ>˜Yó¶KÏ]²~üï
ÃÀİ‚.•¾+Ş3İ6*™¥[ €…KõİO'Án€#WIª5AS>‘µ¯BB„Xî/¼·äÆ…7ÿ˜’G….àI‰C5>¿¸îëéÍ˜Şµ×{raœÜ0;ßŒ&‰ë[\µ¨°¤v ­Ÿñ f±:ş}.æocæ°!É-ÖGƒ»AæLüWÜÇ+&B&†W{&EKÔ<.ıí“»İu7êâAE0•üÎbÍh[q~1O´²qõÑ°	`¾›¸¯ÌmìX—i‘¶FBĞE«!
ç6ÒAÿÑS_gSX'^YŠNdxŞÇ¡"G¼¿…k>¹‰¸¬†Û>³šsmø‰È!*¢<lÿ¼÷ÑÓ“ØµÅ«€xqÈ™¬keœæŸ}½tgÎ°Ÿæbà‹š»:Bó×V<Ûî¤h]FÔSà¨€|`VRrà·*66;°GÌ®]¬ˆÍìş?õÇôïÄĞ*>K¢ş€ƒ…Dà{²5ôŞò%Ğà*z-UdÅö~ó©»Ö9ğèê{p,Î&©í×År_³‚­~+Ï:5ÛùÀ¤0ÖŸ3Ã#8Õ7ôÉY†µ_yW—ˆL=şõ»K‹twÂ1øŸ†êŠx¸}¨ìÇyX”ò¸Ùóat!ÎW"ªæïR¿}xE<"1ú±gNœŒlMÜÖ WÈ1L›`™Œı; TXÈ¢=Eb]ÃZqò§İ¶wo¶’VÉğİy¨{²2\»¹èõ%HmÖ°TÒù©­Ò ³áVL>§è¼Ñ‚ÿhs=lUY…«Y{ùü-U»û;2¸.…VU5j´&›#ş¦F´{ÅxóAû± qBËÁá¦cÀ¶$Ä3[_TŠ’{_ö¤éšnå«,öä«¨4s56ß:XªJŒR$oÜ5S•šËâ5İÜ[öw{xW%ş¤¸ÿkrmßŞËkCË$HÎ‡â¶1ÙœŞx-!q<:ï3áÆåƒ–âV{6!•v`-µ ùÆd9.6<ùE†3xÍ—]m7!•èuro!Îß¦KÌ‰SuÉüpÄŠ Æ%åPHtñèÿh+Ò‹Y}*„¡$É¯?ºû Ñ1ã4òÓÜéojw­ôP”›Ag¬¬ĞÙMY}%Q^>¢/í¨ÒF[.\Bt°î³”ë~D$Ğ€k¸d©¦ÄEyãÉOÁŸÑ×.7ÊÚ‹HÏª>Îg5Ç#Â"¤(ãİ…|î,‹@±ñ
ô8¯Rº‚ã\áwO3Qbl•Šˆc˜öuNÄÀEí² •¶,ZìÊÌ±Xó±ï;5í<¬¼éT«ú9?‹	“ªqà\äƒUïPdİƒ‰,Iôh`ÿ¨iÂ2câF²iäîãï))NRyó°–J·ò’ú¦áoiÔåÕ«øiËÈHÌaWå¹ïuØØq›9™máßÃˆÑŞRšÿæ÷ıZEäâşØw±uÃi°R^!ˆÌwjBİI¾Ä¦	²¨ÙZ¸°¾ºO’"wtH>M¢ğ`=>Ãë†åÇJ­×qi®{v×t¤L³-¦Ôú³ ¬në”ƒ@u¡¢Õˆj&j¬-ÇåXAÓÍ^«ÕP–»¨fE¤&‡?%…¹•ı#õ‡C™„ê“Ú›]»ÀFÍL¤k¹=L£Æ…Gó=4Øgäµà«İkMdÏ6·DsÛòçƒFø2môÈÖÅõş4VØy•¿ı‰ŸÚß+£ÇËp™*åŸ'³Âü>étMëÛùÕ¢vÁOŞ‘æ’6)ÚÙ	e­C30ú%q…ı4ØYLkS±š1›ë6ÊtU©O ¤ÕéVÕÆü¢öIfYW½l~>Ü‰ÊÇq0ş¢ó!ª%]ûwpÛ­kzaôQÚÊZ¸©İ*B Û’§Û+xà´šÍš[ ÜĞã tAŒD·ïxÁİAËj+$äPU0¾âÓ°ŸæÈó{]¦`ÍjÜ0L1[ÖÈ¤RGÛrp—¢@¶Ús¤–¶W<¿®®bÅ¥÷–„oğ!³æô^ôHÑ‚ò6a6hw
².Ã¿eb”B‡¸şNßåxÒÈF!CIÚ—=5ÿ^Íbs
8A?ø“ìıÂÕò¢¹¶eş@£0QW¡f!4 }Lÿ)_sá¨†š;0Xö|y!Ø7Äáø½LW‰ò¤h>Dv¨ÿ]B7ğƒrièußÔâå¾İ‹Fm	µÃ‘ÒdâX¸€W’[[nÙa~%0…Ì_1şšĞ_-Vô‚Ç³¯„–Zè¥ıtXLCĞ†Š´«£·³nCG„ï ¦ú ¸.˜UÑA^§şÒ÷LñÁ†µüÚ¥¨É…Ü'w<íŸÕ§wŸ([µÓ äzÔ”y\:Ø.{oÔ[mD0_ùøïSŸ·ï*±ÔŸŞ¿ıuéÓÂV«	c‘ÏISg
ğÖŞ„z8|¼Àì#ä»;¥ «Ï%Ä(Âá¥ñ×<a@¹íâÍ;¾"Y¦ñŸN!XŠ^UM›ºËÉ2‰óá{Â2Q—Âó³ò‚ğ@ËÅ”¹ñ_iˆE¾uë'!l^éEöh şwˆQà‡+2Lü_œK1ßfİÛ$V‹èZæ¯jğoôb™š!üüô¯`ûØ'òÈ>nQwÜ`.î½’äØDì~e8š}|jSlÅòœ<=Áa­ƒXœ˜EytiZÊûJÂ¡g–O¬Õe³Åñ.†¼F3Q;İi¨b““Y¼R%	úå:‰Í£úL$Òi1Xãø’H‘ŒÔ3×šİmá5CJ Ù3r›‰0&ùÈÇÎI<j´Ò+±3DFÁ+šºt#R5è2¾úäCV]¸«¿Oç/PG_•]Cº@%xİ¶0úl;Ã#Ûù94p\<á;ŸÉ¨hòœd)}ğcåäÂû1·]Ù­#xGµR'M?ù—”
e–Ok`HôS4 ‚ÙÑEÒ²Í_¡2Ï$Äf 1V¢÷ÖÀ²{»—»7¢Ê©{)ãz_¾ä¡Àô&¨ÿî_:î)Oşæ¥ÙÖL°ş–pL"u½oCÍ%(j!Ò»æÎ[jî¦Ï]±ªeiIdí™4ŸÏ}¼[üdÖ±‰dïûíÄäÜCÀî¨¦Q‰ºt®çømŒ•/¥ÑÖc>Ëøçê$MØ¢ØS¬T–“õÁß«´|.f)Íb¾Ìl:$9JòvX˜ Œ]vO›«²´LİÁ\8Ú·”ş¼'€|DaP€Ç®ÉÎ/’NÎ³má’¿!7‹ÖÁk+7ØŸzğ_§`]yÌ£ÚÛKêK–QÒ]ĞóXCöÑF´úkMz÷}Sˆ†1nı•ú¯½Ó.5²n˜3(ô1rÌ»Ù&úğ›4GM–&èìåÇ#Û=léÎİWîG…“æãè'aı\¼Ã"ü®ıáæVF]ıÕ_Ù€Y›\Å¬üùaº%…/ƒí¡ŞÀ€*R¢/Ì«d+Î›¦“yšc:±¾E]„ò;Zj"`Ipúqpœ ŸóğÈ!•<¸©O6 ºÊÚ?±#o-‹€ÖBÁV>'ÁFtmui¶ü\õŒEEn’5o>6Æ³#(\ÊI„ìs#Í3F©¨„I©-³›Ñnß5æïÒA¿äƒùÎó°yøÉVšC†šó ãthÛ[\BÙH cı( ÌÃLË»µJ¬±Èºœ’Â/ùJüR½­ğ~O&eñ…5ï»a0ÈÄ®Òb®1&4]T•ê5áòIÅm}{5G?>_˜¡FAHq‘÷övµøhŒbÄç5ÅWì÷@aÜèÜp=bo¬ç”O‚eTH‡¯0]
Óó¾Šá'ò}7Ë¼	°Ã9H†=¸Ü„‡9‡B ¨ãÑİ +OùÕÒ_»œ•úBınôvá—ÓÆíFñòşÛJ¤ŠÇ»<ôòOß/$¢9íA¨ÑxÛë-êk,«“|ÂãíŸ@ì#‰¾±İµ¶:gØgä-o!"S,IÚèm½}J&eFAš¶‹bàà®)N¢ÔÊòÆ#äûŠú`½/$T„Î#‡s=™)Ş-ŒJûÁù²O¯é«ŞeÃW=§Òã†šÍgÖ|W‰,Ç\`oÆî¬@äàşŞ	BC~%ªæüšÎïtL‡#bV&Üµÿ~çìäˆ°…Q ‚€á‡*\£¶c‰ú÷&k<õĞvd  &p,‘ÃSŠµâJšÔ9òo‡tAá“VxIÅ:tÂ9ƒSHâİcğåñ÷³`h¦Ãm¹L¢Å²°$ññ#™×ÏÎñì? ¿#Âi²ıC3•0ˆ&ÀƒÛ¸†êÜn®´Æ,P‡µäq¥îB
5Qm±æ°àŞ`#Ü'88Ü :^İğõáÔêeÕfª!âº7ÌÁ_Y$%x‚i’Èˆ•Ğ	—Ì²YõäÇ"Š±“Ì5ôãÅá4eæ?¥Xœ\¢ÿ¹Ğ–œÚ.c_t,’GÊ‹æjWäè-İ7qÒ9t"›IˆÄúG°`«ŠJúhH`“U‰•`!
Ïd™Vİ×ÁF{°’ÿ…d‡G
NÔüè51EaàYÔm_BzÜ"›šyyÉ‡{²€ Vx¥°á•|ÉÇJ¿¹4æçšäÅÈA~Éœ0ZJš‚ëĞbla”@û¸{i¿ËHõH	Ê³œñø¡‘	¾AÊÜ”äÂc3!ˆj%$ç³‹•¨´Ï‰Ò\N§ßÆ»|ÅHÂd¾–qV®‚äu­Áiª%¬[ÁÏÁş±^*ÁŒ$ÏØ&¾„ğŒEÍ9wôÄ5Æ¡ßMø[3¯¸‚ÁP`{¨Gˆ>´"æ¥°XâäÀw}dG
˜ç›èèEµ8³÷¦oÇûDÔjætÒn»<¸3« ÷ÿôæ1Šî	lg%ğ‘â½´2>Áchx$’Ô^ğùNìÏJ^“©ÂŸN$2\¤Q$
Y¥­ÊJx¹_fn‹¿ÕÌë«˜¿*¨qL%»EI“JÇ¨Æµ
°v+ß8”ª¨À2n¦/YûÚşàbO//ğ®nOû¹`Z¨-¡9Šş^*æ€Óşæ–x¾f…¸Œ
RÒˆj—©ÃR–Z?^•¸îÃeÿUéÙ< ;é@'9#öŒ5ù* M“5v¢ùÉ,¥í„Ê­Ğå{¢ÿb©1÷‰ÂÈ^$İiT³!ß‹»wNcòø¢~Â³±†Æ{(Î¦‚'éAgBˆ—1mT·¨š~é›7vã¦/øŒö¼³ù„¥×(#”l1½™)÷±f+ìb/ëÃq=_í©‹ÔÙumÛ½uÀ™ÌK¥²–E¶@Ç¡¨‰¸©˜½¿^ÒK†|!Ù…ÃÔàÇó˜Ô‡Ÿy:š:q·‡(®Ø(ğX`hG&c:ïmı”"O½×É¶KŸeDö*0¸¤šğ,˜µ3àÊÂ5¶=¯aYöË@n#Jj»ÓÁ,„M•-óCÔŒºzgÇĞq(LœEcŠÃID,ò†úñÆ=>” 5ÑO…HÛó1g˜K
YüP>Ü¼ÚôŞqÑr&:@òUÏµ2y÷uê3ãò?	 ‘îrCÕëG÷ööéämyiŞcön¹€ø>İñ?XòXä$«ŞœX¬¡‹ÓI*ÓdˆJëÒD>õÆ@	såóø¶o5±¯ªB×ìp=sw
}DŠvgşX²Sšh2IlywdŸÃı9a¥Î¬Ší„7U»ç
lcËş'" ıÎ†23BÆ{G]VÌÅÀM±Uby¬İƒë:eí|T%§7‡l"¹KØ)<1‹‚Ó¼_6cÛ)lbéêX¶³«ón?ú‰Úây2^Í´u¢ğ»O½ZIˆ¦ëy­a!˜µ¥‚s“fx°o¿È¹C¢lúqĞÅEÿú8¦
½g„·_ş"ÛÅÔjĞ–yô›¾IŒYµë–˜¾ ægc¬Vªy©\õL/cŠU`”ıt|lÙÔÎàEvõÃH¯aû)4Ñ.TR®Ÿ¢¿­n*¦çÑ‹|âÆí¼ªˆ_EÅşøéò\uéËÒÏ¢ıWğ7¨ä?¾'Áò­  £ºÿ0„ Ttª	ÿ°]Şè‰”õÆë`ãt‚ïç*ÆÎˆ~©ş·¿æ°;K9sp70ûc‚æÙ¸+ÕkÕA7Ş¾îeÒ“^¦1è÷¡@‰R•ä~€ÿùß¥<//o{L´úÇnıÃ”lêbn>ä” {‡–1¶Ÿàw."Š÷\LÂæ Èeó\ppÄeG]x’w<µsÆ€€óúM:l‚˜J'ÖÉÏ›ÚcşÓÛ®`”ëb´¿üâÔ¾ûŠÚ;}:ùe Q¬Má¿è½¦kÏ¨ÅæiäÚôkqÑ‰óÛÃÑió#$,^‹×íº9Ìèÿ§oäé¯yF@ùÚ}…y²üv¾‰ğVºqÎ¬0çÃÇƒ+•l·26j‹¶ğGÍ*°¸>‰©,^‹ÊùNæÇ¿<qMÑhQO½_|îÂ€}è
3Ü$ éƒîUŠì6êşµÄ ‘>a+Õ]ö%­#7%ô¹ş~ı°€Êò¯°Ò€â¬fè¿Êm¾fN”×vë2xMUÿé·áO—)W›¬·Ö¾N‚9;ºIªóê‹`vriŠ;].GIÑAy0ò•Ñıf¸ôİ«¾¬C5›&t·>Èº?ë¡¤2Cf¿mye+øöµî`zH€Ôœ? §&¬eÛ×«›´Ş8ì@{_÷=µæ˜½Ù	åo™½‚Õô»"s0ÔšLÿ†bàà)õ¥ñ•şT(ªĞÕ¦¨;(²ÛrúˆŠŞ³“µŸÅ‹¨ßÜ+¹ZÇLœèWÚÃİ8 ·’íßÓà®
5ivcr±˜3:+r#5ªÃÅC£6½1t'†?BÉGÚÈ™&í%è)c½G›BqšÏavÕMZ!Ÿ¨4ÏBîºÿúûÓnš‡£ô® Â·(ì¸ÏZ›Zïœª
Ÿ×˜‰••1w®cÜÃ±QÉ_Ö„ó2¥¯”9?/
Š}QƒºÔ¿NºE|¹5à.oÛ1ô¼ØÚº™Zò–¯är/vñæ³àÈ8aßúı‚ ØNç5|’Şÿõ#›¼ljD<GååeG,IœÁ) íÍR£vîº²Åûèì½óhø¿TÅ‘îIIÔaîne7IİüòOBõe Ÿiš
dAŠ‡^,áğÑ¢Pò‰GVÍ’	Èæq'á}^í¢Ä‘Çš!èèèP`˜ú}â\}T›—^;Š<0f•(zI);a¹ãô±°RáîL?JJN·mgR¤P/b<ñ§>3nªò¿uZu¤/Ú+\mzã˜‹å»ˆö:¬ÉÅi@ ñĞŞOµĞ#V¡fP±€OEX°±Bâq¹'4ÜêÉ ôÜÌ>/×(lNÄë2Õ¼v‘G]„ñ#/­&èF¢¸èFºc3cRã\²ó‚>õ|Gè›v‚‘Sÿìäñ§ü²fºôe•İœKa«o4
,MZ·ô¸Û¢’œ1¿µÑËgr¹!%<î0ÈÌ“PIÆvé¾ôsw`)!¤¬£¬¢“D±Ò<3)å 04-«]óÿ5ÎfËk¹•Êâ×¶D-'8–¥P­F3’$Øî(X!!r‹Ü–šiŒßP+ırE+Ä@¶6ªÔ›x}xø"îyÕö|V‚|ê_Àp«ê†ÁÎM³³ÎIÁü¨áÀ]õ}À¶$Â92“i0²Î¸•JÜ\¡ôxŠÕ|áZ¡±â¥û°­·À›jmëİ„$Èë©A…öÑç>']ŠcM¾ÊÂ2=HÄÉ+®¯şR
ĞB9G:Öj ‰¦®üôpÎX„M›·¥Ù)Ü¤‹I¹%:+˜)ßÛ6r%W´†tõ#_¼`gDgÌÀaN=£Šå¹Ğ@§İv9>Š÷úÊœTu¶s¾;Ó©‘q.²×ë‰†	›!XüŸ!W	¶Ù`LBïİÃuÜ²8.(G¸q	.quâe3’òù¦‘İJÜ¬dPÀ&Âß*úwmçk€LÌš´ÒÕÉŸç¤"óUöŠ4çzt¢ KìÜÕ7Ví…‰ÆêÜ#l¦Œı{@6rW:u¡£RK›­¶Ş1ÑÜ¥­ËbLÒmøœôë›ÊîzÖ]HÆâ×”,”êµ‚¥”©ÜÊÆ{…âw,*F›Hw„Á5òÃ¹Çen‘×½‡ÑÎ¬õ~+aØ¶ÑÃŸçU-:Ğ®;Zõ™Ãà$¹LîÏ%Èç!­T†€Q€$íÌ…M8_‡§xäW°&Û1ve“ö|³ÒÛ\íšã-ï‹8/–ñô‘®Z,&œQŞe'{Pú¢ĞšÃ'lìC0cÛÖE$²¤s7²gî9Jù°«¬îi!ı°UÔ'íƒÊÑ»¬İğ(÷m<÷@¨lûàïÑ‚|+ºI¸äR!\3%Ÿ&S¶‚û¿Š[›Q¥)
§%:ÆX£N®’ÑƒÉITÅr¡¤k^ây˜÷ßî»Bš“kA-pûÉ–ÇÙÍÍZp8ÇZò€ş!Y›
jzM¯øP,_rƒğ–y)–\}øÜ$[ÿıõoEà]po:—º4<ioÆ%s×„˜GÍ¥W¹áá¤+vŞ•ßÜE'XA[Jm÷û§$"NYã¾ıøqq×'`|ÔúAE¸YÿF…âU?
m$¨¼ßiæé¨€0*Y¤@õm-™Z>ÔVz[`½`µgJË,Ü¾€Q	6Oí:3h›	Y‹V»®ÊSÉ‰_=uãmÂtú>—Nyì;sÓÀ˜›Ë‚!ÆäZáû4<’qP[ûZ³¬Ï4ì(‹–‡!BtN>oAâcKfRâğ%I{ZDùµ]Ä•aÅù€6W½9Î‘Ğµ¶ë°Ô]„Á`4÷:åçŠñ\KcS–˜.×¬}r†ãÜkm¨økë·)À™vÉ™™'’-dÓôC	‚ìçø»tt81—õÈWÎå…>å]÷_~Œ€"ûŸ[Q"¸ÆáZ…Ò «Üğ‡tv™÷/aÇ#@×|ás˜”œğÊ¿fZ{ÒO`HŒ¤Â^gKÜWfÌ)Ìj¿®5¡ôVReÍ¢u>éªƒ@šXa­€Ë•/wívrUªİ\½à¸šàÌzßW×Ñ·0\§¾¥İqXÔ`jÓœDÓH{ûYœôëò~êØAÓ{,bÊŸo‰ ½ø5SŒAC=á³égçz6¯ÇñêFï¯€¸‹aZBkZØ¸K\#²
w{PÛËÕ½¯]ŞŠykbÔµÆŠá+s/p´Ãq%xŒdõÈŠ7×îeGhA'ÕšÔ ›•¨$9ä’Q 	ª|\4iN¼%x6ŞVÅÈˆ>j¡ÍD­³Í_MyÒ­M­XÁ¾†åÃ†Ïâ®4DíëoĞç—¯‡=î—ÄQ¿‹ö°Ah¹¹dLyR«K[Ä1(™!œÍ-ƒ[6†G¼Æ¤>ÏHnƒf®$?ÅuVë€¥dp9t~X]!{.$×j\l”us%¦wˆ#‘Æ5s'0Ã¤¤W^S™mÎKÂšì—¼§ŞíÎ)Ãß})ÿy5JÀ‚a¡
¸n£æ?’Ÿ¥b-)(7ú›ã˜kExFóïÕøûH» C†ïŠ×œ0dr8
Z¢RÀ4Tµ„¬aîZ`CÕ%äÔ0Ñ—Áò¡	=à,/Lº”‡8­ÿbÙX22×óö#¥ÅC‘äëËã0¢ âg.æ|¾tŞâÜ
Œ…jmşNÖªø&!ge;aF
‚Pÿ»úSdHÅºìéÓZ‡ÿ\r~••Í6ëşÃådş$š=Î(²ãÌş
ıÈ(I¿zşëúKG‰n–ÙIƒ Øê¥âd¡âÈ· m«1u(_<¦ÂËü¿İè:•–í÷AşƒXÎÂÑ’3£˜É¡JGÄ°•F¦uRØGãáÎêÓµXI:~W*ù†°æ-‡º¼pT³Î¦ßâgö; t˜Èâ¢(Ëh¥cíùqdRê«÷óD´ô¾£D¾ÆÓ0;¨ ğÒQxm
¼ï9#!×vñ•â|'"8³àÿïM©Ñô¨_!cİ²™ÿ·ù‰Jâ€ÿ±X€òº¼„vÉÑ‘ôéÁ¨·EkÛ®‚‚˜ÇÃµÛz¯–Ëuy²r…ªN±Ñ€?˜jÀ\UA ¹lLö<F­»HÒÌ›Ò·‰\oìîÛU½-kòuC0Õ•sÉFÔŸnû™Q`–ÆF?¯¾Š®„AÕÏ~»¥ˆõƒíô	º®DPê3LÀŸ±¬&(Y¨uçË~jvÅ\ÖÔÎØ¢™Ü¼èaâŠ¶çè—a4X_d'dS¸ÿ7§Ç$§êeå<Wï0º·>âúÉëQWqGô³LJ|=˜ßşáİÚ7ôÉ"8¯êuR;NÌ¥¬8S‹¡BÌxUÃnÜNÿÍòõL[mL¦u5Õ0Ë‹ 5’¶«â¤òÚeè¦7¹º'D5˜PcSGy/X‹ú|h‰ãPø­}·ê–„Ò”òÿ “ñ¦Œ¡39=ÈŒ}]G[2ö\šíPQa/2v¥^Îš—HŞêZúßßÏ’H':Ô¼¡‚9WI>ş
YZÃıTĞ­óW[j¿ªYÌ÷i²‰1I¶c1›Ko„N¾ÓEÚrç@Ãtì#‹ğ„ bhŞÀ
;ANFÜåĞ÷ºxj6úµ_ùy~ÁUûüZK‡í³hmcàéÅÑš]Š$•À15f¡G6Ğä[RÁ€ÛpâCˆÎÅ<š¨¨ujÒpùI˜)d%·¦|1ÑÀ›h>]ÀC¯ı‹.ñB1åWOEK5o7iáŠf»šƒ®9wöeçá‡=O^±Š£9±î>!è¨9åÛÈªh²4+8‚¯iÎYxfÿ®2R%lV·ÓJ†Ï9¯ŒD%ò¥Ë[<°å¤ÓuÀàû,ğ`¬R²DJÉh1ÿîô¯Ÿµ¸;å|zÁ†´`æûJaKR Ñ~‚ÛŒòb–ó øUÜAE!›^5æ»0A¹iú ÏÊ*c¼”ù7×l‹zï€9m§¶­.|©Ñ%ôôûY}±cY¬/é§$6-ZoÓ¨qÕÊó˜×.œ/À)nôË•ú¬~¥Zv:jÛ½|Ò‡2YñAö4;7˜çUQ ÍÏK)Œü€ş#‘¾ç3÷ÙY™‡Ğ_A²÷ÊÏöâçZ#T{ÙO–4A½bëÛ¦Í¡R+½KLğl–G~\€jSÚØë4• è5Ÿ‹„ñg’éoYêÜû¬@f˜­&ÜR§9ÁGú%/¤ÄÃ	·ôÚÚq‡šà³”‡P'5wñ‰J*¦AØ;»ß¼ß±¢(†Yõ£õ(›†ıQ«%5_’ë7».€
•kLJˆA²ôÂ:Ã1•Uİ>O”ÿÙAªüRiòb HƒUğô‡{HJ´ØŠ<ÏZ[NÚÀ  Ğ_º}`mçtfV­=™Uv«ÿ¾D¼iØ:ºcï"Vö'®æûNrµ¿Š«¹Àßì­ŸúÍÈû`tõ{Løx„BçAÌ,Hm.ñÓÎôèœ'B•­4cµUñ™ıÄ	+çs³ÜñI©6ëÑCÇXGÍ²$­!É„otÏ¬FGeæ'ª$ñ<bW!ï„qëŒË;N}Ê}·åõƒ'Ê†•Œlôî»£‚S¶I¨ùQYŸ¨©ür
)SÉ]Aâ’áºãù0SN’  a:r•°FÒœÚ}Yñ2oPéDXè‘ı_F¸½a™ ¾PûŸ_Á0È”Ú„]Ğ>mè¡ˆÄÁ„äMÓvaò'WfıŒ¤‰±uF4ÖbÎ§ú©›^¿£{12le`’ÖjLÊÍ‚h5ıª«1Æg¾|ù3r­Û'|WyİÊfÑXî"‚õe”[ r%Å¦„Eš¾âŠ*qÙEÊ×meÆ4‡•—n<Ÿè0Œ‡.=ÍèÉà½jÙÉµ=í[›Å3yÉÎıùíğiXüçÈ°88lëå£İşè#WÜí œ 3MğĞ·•,¯&¬ë+"eí¤o°AÏ8² ·{¯–õ¹ÖmÃ‘]xc‰–YLˆ†Æî‡)_g9˜§sqxfÇw|Ôóä6wÉÔ<-E,Uöğ˜õm˜ËtÏW^ Å<‡_ÖxZ#†ùáĞú<ôŞí‚ «ºE‰qïß·ˆÔöAš«øKææk)”^¸\äÙŞğmM[ü1á[j¹üvæ4I¼=ú¹·\z÷²§Hü?Ó_t½uÆ8Â<ZH–™¯]€ÏùQXoQ”hG`^ğšÓœè7v˜n"&ó;!§Q^Ôu"¹Õ¨~e±? Ÿ¡z¦…|?]Vå
ê?™ÙMŞ\ã9êW¼1eÇ›Oµú(€|srı#Ä¨†Üœáôœ‹™Âàn†ÒjÛÑrÓ€ğuß’FÊK€Û¯îÜŸş±©«šŸ²}Wx<5e™àV0ÕbqD„QäêV§uå/N•H5{2:;0•·w"Ca‚
M_Êi½®Q¸šüxvŸ›E]m”²ÿ1åôŒBÍÖ¾8´ÅÚöäÊ*‹ş^é~n|å¬Ë	x/ğõ©ïR¥á³ÅàÆ>Öd²F41ÕOA·•<çŠ”îwO¿<3¤ìğığÀôÒ@¨4´T/Y(dú']¸½Ùù'Õ“Œ2,X‘JÃğx¿Uõ~™ÕÃ‰Eˆ9©‡râœ$y•%ûIÀòTˆuYt‘%?†V€}ğzÃø£¡¥¥‘öëÙçÕí1Úå¹¬E®ÔÇ2+ñ¹ 9í7Ñc¥`z0¾¯îß/BóØQ>/ÙsûJBŞ›Q[ÍuuÊ”°%ıÇ,{z ôZÒTÖ±"AşıÈÖ.¶Tô·G„9‰¦ÌySd‡…İ&ËÔ^vf9®u€\nıpÓy…$s¶nÙ‰lWy¸¦t4Úìz<¤Cò¨È4`=aìmLs½ä@(`ÅÙ¥ly”ƒô€û‚,.|ô8áÙ ÷åZnY6ıi	pws[6.Ü‹åÌqvÿÏ*ßä)åM–Ù!ÈşiæÇ€#Ü)&BB8yäÆX&å‹›Ï™yÓ–[bò\3›E¨»§“Q °´wš?F¦`9)ï°ÀˆÈXkÖc™è
ÁàŠå‘qfÿÑøìäò’ØhTP`P*ú~‹w¡ôı¬b]Ğ–şÂÿ\!#‡Ó‹âŒWÆÙ•ßß¶ç…Té‹$ª†ËœÅÍr›Ùş¸Yy=ıRIoÚ"aU‹ùôùĞOXb«?’å¹í~¤6ŠEàNæ+:Ç#­‰ÁSìOãíÍÛ{°?+«$şÇ&8[<BŠÈñ¸¥”ÒØªg¦ºk¬ó1…Ævµ<‚Û™>ë¿Bşq E6M8[„Ó3>ÒÅC<bkHFÛ<ÿßV_XM°şĞÔ^q¹éçÄ§ªi6LáL²Ê»4nº[Zr8âÎğ×|PÆpGÆ‰,µo°±87>Ã¦ÊLşx~Å^†~ì_H!»­É+ğIgÉŒú"¬ÙğğcşH/?ïÖ3yÀ™d‘tÒt‡²zcÊ>$şóÿ€S~°„nzÿ{}Ô¨jBœD" ’ÁÌòeK‰+ bR·aåÑ²¶z¯BÉş+´~œ¤(}Ë¯m9ÿ+°ª‘ˆ*¯W=¼18EAÍnÉJğìB"ôÙßGÇ„Z¼¬ûãŸÎÀ:¯%j;YÔ¿8¬¡»Ğ¶±&$é0…;´ä/­‘DŠÀú¼<’hX À)(Ì|¨q:Å/%$I3í4–€L~§Ş©eo£±6çÌ>£ªË·£*1¥ê@^ İêN‚¥ê×w¡ûö^®è„á¢ØùíÂ¥] œÆÒ«tŸ®C£wGCHò©¦ğhXÕ`ĞµŠ,r=ßë¸xR%ÄA”‹êb#æ\†Qb±ıJH·PÄ›Ô-Õ®(?IEp™§ó É¾±prt>vÏ€½.A’G€¬É\¯&±QÎ>°;4PvÿÑ>pÃı„Òè¦†…´ ìQÉÈµ¢pcÛüX?ÉÙGÎ9"…~÷×YØæë¨h…}ä<Ù=ÔÄ´àVá«¬¦ë’ÛØ=î+Wáæi.¨½à!ŒÌÍ¹•(¬9y¼Ê°ªÎ½^üı'ëšs†o€Ê8GH­oçàä”x$¹sLil<Ãv„X²E™`İÃç{çZªÖãç˜
x®\\Zv»Â»Gæ M¯öÇ#>ù\ Õû®èÇñI*³FnE[sMkSÙŸ@MŸ¿¥æ¯˜r˜zláÆd$=î•\a‚)<T‹µÀ-R´±øZÅlŒ»yxR1èûX'\û?õ 5¸ÑÂ±Ç¯™Ÿ¹¯ôbAÆí0ç…ùgÍÑßØ„’Ø™,ÓÕãgù07öÖ¶jF»X*‰ûışZÊBáU#áÔWÓb®b¯KQ#õSÉä)ÈĞ­ŞÚ_zÏ7¢PÖ‘éò„VÃ¢cw^ê|ã†÷)Ey³Á4!çƒ"ë`¥×r}è)çõ8æx›]¬Ô¯×Æ(¨®2j¤úO.©£ÕV¤\§ö$ºmV3:É ‰ì×õ÷ğœÏıfÃ  Cu,ÈWÒ3ä“²FşØØË¯ñ›ËÛÁ"3¾Í4ÙŠ»_!5‰Ì˜1‹+ÁßÅoŒOm™Ü~*aå‘ê÷êœíîaù®¥P¯  y¶Úp>|Á%t7ìÁS_Íbc3Ü0’FAwî{¦-‚PáïÁpG`   ¢Aš&$ÿ à>}34ØØœV}{ôËÈÑt9§ö@äÿ'k«c`×åbTÚZ~	uÃ`'ŒØÛ")ß#”%½…y¡ú§à½ıG¨€3ùÿkzöÊ¤ëç†Ê’;Á•B%E€4á`˜Pv¡dE[,˜L-âÑ‚õ˜HÄ®õ™Fû°Gi4¤ú_¨€[ë«†±îÈÏe%#Èdôü¸   5AšF&ÿ  ¾z (ïãÄãòíÇQÊO¾iÈ'zã·^ÒRàø•¿µ„íWr€  ™   Ašf&ÿ  |Zv÷@   ‹   Aš†$ÿ  Èaç&!å"øÄø   8à   GAš¦&ÿ  £÷˜<¦ÒxÍÔßŞó?åæ´q6Jé£Ê?âùYzÖ¡8[D²éÈÆÏ•rKWIî<>©	Ã8š   ‹€   XAšÆ$ÿ  wó5a	º•d>ŠøÅ](áÔÂ€#–ÈaåiŞ}Æ ¹ ğ FïØ±ÌÉÖÜ<ñûœd<áçõá×ò¸‡müZèù‹ef5›®   Ñ   nAšæ&ÿ  k+qà`ÓÊÔ	£ ä¿„…ö™åQ hŒRdá¸@sX:É‚“ªŞ`·­ÅYwÆqXÕº·"KšâKim¸Â@Ûyì	b2
X­lë773èM~â+ê^èA5Œ   Ú    A›$ÿ  B×’Läk¼€ imÁkFV      #A›&&ÿ   %İè•Ş 	˜KÕç÷ö™‰UÓH€   ü   8A›F$ÿ  5éÛ@À•Å?€WWW8òï­kåºUåC×~}¶	äÆi)|ÃÓàÉÿ.”ŞÇ   hA›f&ÿ  b~ıZT2C—,'÷‰W1ğ®xN90º:ïÑEõ”½Úåêk–šÀúX{ÍqÕJş·õ’°Ã5Ñ$rº°5Ÿ/'Sb¸ÑÂö³œ)n@-ÒtZ3û€  Z`r0A   A›†&ÿ  c	DYY–X¹  I\Ú@   $á   *A›¦$ÿ  1íş°eå2ÏñÆ!Ê^¤8ãè„•Ïà   ­uã7êâ    A›Æ&ÿ ’<¢köŸ²ö
EŞ2 :ö$ıÀ   (!   A›æ&ÿ æ_Ù!D"¨°–ûâB    uÀ   FAš$ÿ öë¶e]qqU !"¶·º¾ÅãI•U‘TÇ­å"a›Ú„Õvİr3âŒÊ»   6¡·¯âGĞ‰³¨±   CAš&$ÿ £Cè„Ë7IV©ÍkèEI=z‚(LóƒFÃznï4^“™TÖgà°½Ìó•OU]#²¸Uà   ¹   TAšF+ÿ ö`æ|9Åk—Ößœs5"Ö¦ÃÀÒ—¬v'²¶0ML%£<šz”®N†|`‡9
Ø|Ü@ŞB¾2Æòy&\½ ƒXáÂû˜l   HAšf$ÿ ¦Êç&ÔhŒRpÈyn)Ğk0#±¡£âŸ˜>Ê{úÅ›    ¸ÚÙ®‘.t0¸¹ÉöYNä¦<#HÀ  „Aš†+ÿ 	‰I6HƒĞ×e‹Ø†%¥3}Ä¨<Ñu 5æãx†Ëû%ø8ÁJeqw¤‚œÌÒt~öè·Õ¾œû2T6Xôo]Emm™¼‰7³G*†æÓû:i˜:x‚ ;,åµ†òhµdš°Ka2è(iT“BZ•§yV.Ë7£2ñ-K2RQ4mFiÛ^kÁ¦¼€àq7‚T~j®“"Ç­h?İúïIŞÿ!éùÄ¹Rıìvpbü€°±‘0£ò
øÕäóLlNRs‹Ìã¸X…#W	5ğœ™ã¦¹Sé´­‰3¼ÚU>#æ¸6i›bÊ›¥øn!ÎRÕÍÃ nn^EÊo[_rÄàñL…c“ÇÅÖµ®—‘N:Óo€ 7ËÈvQê8T:•CÖ{TÌöŠ	£v³õb‹Ùæ6V»ìÑCßi>aGÉ6B©_bÇÍ×Pe§û‘ŠñØ>û€wÔ  Ó×dâ©Bù6Qù¤CÄ
^¢L[êç™   ˜Aš¦$ÿ ×xtšvï*Ây=¿»X¾
kH|Å¤‹ºYs/áˆN:cªW=W÷2 Qfsœzñ9êÍéÍ0¨[æ+/tQŞ"ÃÁ‰µıµºbRP"çÎ<©DR>†	õœØ/–jY–rrYJ=÷¦Äˆû¨ßÆ¡?OÊkßd*€Ò:!%DI¸   %`   °AšÆ+ÿ •Ê#S¦×¨%÷|Êóã|ŸgŠ~û[CT^òI ÌRè ±²üµ™z?\fn¡‚3gË@Ûš9¶Øo~~ÓÆ¦>_™´ÂKºŞÙg@X#Kõjš(Å#›Hã1 6Z§¿bä†­W”×çğ´÷_xÚNDtÅ¥P&Q´\üÌ±à ÉrB¦
–’ÄYµsIÁLµ)pä  ûÙ²€A   ÛAšæ+ÿ —yÅ¬£±çügrîCí…ğ7e¹¾ÿËå*ZÕ½ÏƒöÕ,?Ú£+À¹ÅÅ
ÅòTšL*ĞÍ+ŠaôõŸËq¹,÷yØNÑ™¥ŞkLz[½ÄÎŒË0Š˜i›iaê4çWâ¶5êç5½A¨q§­›|i#ş‘	„ø‚åwGBƒ~Î¶?!#izYÀ_ĞtE¤ØÌ7šgEÇ|*¬ø¸–õØ‡Òñt$TáMFnºáXÙ:>,ûÛ|ÌrS÷y‘½DıK¸a4j   
H   ˜A›$ÿ ·]|˜ÑN%¶mL;!3o‰ÄŞÓE‡rĞ\^„±ğ©eU°‘ ¹Ä·á5ÕÒÏJ›½Ö^z†³üW3Æ~^¼şûªöáĞó4–EĞi„ÌÿGQBˆÁiAí¨ãHT-¾ïê9”mUÔÀ·Ö¼ÇÆÚä°·ç71-Rdj    İ  _A›&$ÿ wİ|k1 ³9¹¢)V±UC³÷o·ï*/8|óï]Ú‡4´3@t¿5Jè"ÜHjZ²[°ã»ü8Fì›¿©¢ÕÉo¼‹fé€Ö‹°°¦4Ÿ^û¯`›-ka¿/óI¦ü*Ü–	"P`&”«òƒáw‰xmW†ÅûİĞ«ˆ^°‘{*EÕKóu,Š—íl	–èX:°ı!“»è-,îòl$’ÎÊ-Ó•6LèöFHÔÛ|™|`;5ä‡•=ò4Êƒ»i –R§Ë,P€zHçıóãåœ"Õı©Yõ¢‚wèQŒ;KÍ®VC36ˆvÅÈx}L@ß8a]°©–MáÜ=  {Ó5­µˆÆ	Ù}®·Íıc¨·ow·æ²³ü“uÚ«@îİsä‰R9y; :b¾e_îR4#ã¼Ñ 8?BAz@Û~jâQ×'ÊÚd Ø³ñô©ĞE|EÍø;,RşÀâÚ’Ua`-á*ìƒu†ÜøY qôİ^ƒïQuÏï×NL ¯Í®j.?»¥…ãÆpÜıß%‹kciß™€§óI=#Ÿv÷r0¿­_ÎÖşÚV<nîl;ÄÀ4ƒAáHåŠnîzÃŠœæA=‰w=x_\Ûù’h¨éNçî^%ót—ÑYë¯´¦%gĞºîŸÑe÷~]9qˆ~Cw7"¡2ğRÆâ‹9AƒƒíŠ~hb€¶Aóà/Tq¦òO® ¿à£Ó~™Jîç¤SĞğû`€ifK³ªŠzÚ‡ÆG×ÛXÓ^áshÚó¦&Êä<ÂgîRÏ\ŞÆš¯´õ4l0hU¯~k*Œh&_øt¹æ£@S->*aíÅÇàıùC[7Ò2”Ú½8D¥ûäz?û9)9ßm÷ÑwŞİÎR[ºÒXÈq4Ö‘¶#lCkÿëÌ”èlOtÁÄ±[ ¬ÈßfúÛä M^Q¥æ§ócü|àM-èS¥ñ}
a»ìoê†	2é†ËuCO@¾S¹²omß3Bòt=|¦#}ê™S
ÌáÚ
AÂ-éDZj bÿŠ,Äá7( $Àè,8'¥ĞMBÙº~XŞ²Xé¤P¾‚Î¨´¦Ñ!·š‹¤+ü;Û¬*ÑÕ°É¨LtR7(—ä>Ğ“Ezì1fÇéû{Åóõ	FõÂ÷µ† Î÷¢¾n\Š‚¸%›jÒj%êYp¿Š=aŠ¢¼DÔzuf¬;Õ2:[ßƒ(AhÀÑ*ó_ô²àÂ…øRdÁšÌŸ—½:°Ä×Óİ}b+4Zœ°E·	C^°t]İA"k„}Ê²=TëQnêÜâ0 €sù?,&ŞÔ@-;Œß'ê¨]MTN=>½óÂÂ6iş›‡.Şb«”­>|ºÍµÌïû¢Qjù‘›ãS—£¤š¨ÈÈÍ²f%WNR‰ÿÉ¶ş#hƒ¨ª6ƒêD¥Ë@}PD7CíÜÌXË1–ÃrßIø%~›ñ{õîBõ]œÒNœK	[öMGÜx…/yW8”ÁPŠoÃãB£ZÄæMgè´-z•©ƒ÷ï¡Q‰‘×é8Zà?ÆìĞîÜàè¼ÒíD­†&n¬‹ü“+}Õ uq­•‘n”÷š*]ºqcœ?x8ãoomU‘x=t)Zå-°^6eBiúşõ&şHFù˜ ^vÙö1ÅYsÆ÷Š;›~ªçÅ*¼v®„é5î³d6È´VÜa$ä@#2”ä    ƒ   OA›f$ÿ ÜşBuÃÍ+‡ÿlp@H{8çÇa0¯nR–Ámš:y¼^51ú¤@ñtÌ¡–¡âDô2û!şb”°Ï­ûD     2¡   A›†$ÿ õX“¯†S-BÓ{XÇã‡øN]£ä*ÖıXÑ¯‚aÜ#«û–Â×÷A‡äº,íX”ÙV½ŒÑş¡”ài…|fb·´´Cï2¼Š=º÷Uk%kÕÀ	xà#JÌo#~²åcc÷-ĞkH1µğ'~À,²\äïìcôJÑD¶aHù ¤£€¸Ì.¸Œû€   º    A›¦$ÿ ·Ã¨³Œ}×ÊDxÄ÷ªÁôæR	vL×Òõy1+XhqÀÇu;±+w´ñYÅ¾ó4Ã#	Q'À'seûéÒ«ÊCFñ@ĞzÄ±Í#¯¯3‹3ÇFï¢¡´€*“Ì .øÚá‰î lÓjf=\0ÔU±¸úvëâ÷Ÿv¬X!¨¯È7)O)`-FĞ    ê€  ÀA›Æ$ÿ ¾÷ÃŒÜ›‚)áøîúów1ÑïX»½Ô™/½¸Ë-8qµº©"Ï„Âr¥‘¹JG[• ×%!u\$Pé?˜Kë²ì*p\^YéÔˆàHèrµ|ñgk¶Ö!7›çã"“ï.vişMÄs¦ü+:Õ…uï1í¤²§ş¢/Ü+Ü’ç†eÂ™ı¢è¾¼ù¾"Ş£éS'CX®VPóÑ5øºñş¤º‚º¬RutyšŒ_Vh×4y„{aÑëQÈËc*oHò,j‡XZ~Kr4 íOâEMå¾³ñ_e—Œaf9e ¡†qfQ<ö¹³Óá‰Ö£ã”ÊÁ‡ ×LY,!vl…‘—ƒú¿[`éo£GDù3 c§­ë Ô:/’N+¡MŠ
ä5Üf1}IH0‘ÅèÕ%–± ıŠS{`Ÿ#mE\J·'}Á <z˜øªøÔ:´b&ï4 &
$ÿÁnÒ {™\^6Ö©‘â©‡sÁºqì*ôvÆ½ÅŞ„?ŞSdnSO.
ƒåL¨·Ë<|Xk‹o&×_ÿÆ“íåx£¥u¡„    Ï  eA›æ$ÿ öİ˜tRwš
VÒÉdy°‚)wøëÊ:TCwşhª.iîâÂ Áowí½xŸ‘@®-û¤ _’{€wsö+Ce"O™
 ¤÷/¯¯%¾è0;·‡¸×ñ§FºŠ²‡ö…aŒªÄà[ùñÃÅ·Y7ÑTäáşRòªŞ_cİ23$>o¡JPoì†Øèú²àÌ¸Û|¨í4¡Şz¦P/#F3÷Ó8.egypU’¾uH­ q‹ãÂ¤Á×£{øñ£:Âk.ÌsÆLşi&­…ÒÆG3ogv†wğìG@IAıH‰T
€qŠ¡k	{§§»AäÕ^fAw¡ñÏD®Ó‘‘º@?;‚
áÂLÀt¶òkMŸÍ“·ĞnúPMZ_<šPö¾_«Öº²nËrL’Æíºæ$%É¾ñA! ¯£Œ±ÿ¾ã½.Œ+¸ìi˜€*†öOı½lğ-ŒÇráˆ!’ùYøSÁ‹„·ó•F)Ôb˜ŒÆºäò–ƒF¨„ğuˆ¢evı­Æ®7±?ò9ü¶_ù¦FÀ·sšQ·¬*Æ™yddåœ0]‰ÜÔÁ“u
©¯Py±¸÷d“~ÕË U{U[êƒİ6´&å5Ì’¬¥8o&,öö‡kx[úUıµ&ğººFj0Å°ÓÎM+ÌIAÑ]Ş
gW¢Óf)¼ıìÍı®OŞ™\›ó˜?MÙôßŞë†À»^ãZıÍş…T¡gÎÂĞÃ“ßv¹AÆFNµñ”ñö[“`k‘zY£|km\ÇH|_«‘$¿T¨:qlBòX„æ+“èXsÌ|¼¶^©'YÍ¼+ÀÉ(EÙ­fP~ä{Z.ä7p\bW+
IQÂ´KÛæ¯¡e²ª³Ä¡£ï¯oçYL~øLö¯•ft[}´ß:‡õh¨7I­êö»tmØä§Øşaµ:¡0EtïC– v{õ¸şU}Ä2ÊÊFÂ5kXú2ş>*XâÛ©ÕÏ‡+¶Á>•ª¼Õ`Ï
ûD{Úg!æc[G‰	ãOIÖø@<KÒd¼fxjØá(,ß1:×{"äéwç—¬—ãjò +ƒÜğà   bÀ   pAš$ÿ ×\ãÄ!fwj)»z]§íÈÌ£U|äs'É&$Æ[Å~ş8ËLS•&³[ÁËS1"|ïØ¥TÆÁ_İ{FÜ,Á.N£süÑXV‚?Pšw”â·„5AàËK¼   ¨   ŒAš&$ÿ  2Ş}Ÿ
p‚¬T”“kq8Óö
RösÚ³ ƒŞ»Œ„§Ê5á÷T>~‚.Ô³¦´ıV¯Ÿ¸«k÷_U Ì›â	wø½
×j„ÿóö…³³ïcáÅËsÎ†g»	ø<Áœ6@Õ.2¶Ã¥×›?«½Lgoó<ÒO4|Ša'/nQf€    ŒAšF$ÿ tG?y[JñÔ7æ–.·é{:Yâ§´ÀìP„»c½O´—ÔiR3YC&K“ªHÍ(=©–¤Õ,J¬&»°)NŒÆéª0äÀi›YÜÀ?Õåî:cäã¹¤íuwşO,2= SøKC`	Š><wÏÆ5Í¾"DĞÇ&ëùFQ:FgÏ w¡mf ç`ÜÔ€Ÿ—ìöº–¥oês°yèí³dÕÇ¢MÜ›7)/u×¼%ª!5Ÿıâ!,vçÔÑXÔí‹6ğè7º¾€÷¹©Fi¤YªÑ·ˆ”)÷<ÅÀcV¬¶'7ØÉä*%Ï¿ÈµçGşx[6qâ-Õ
Z®»Nwü±FqVû=çß]ghğsşÒŠš3AGöH›ç^’^?«³ñÅGÛîëf‚OÒA
ü	j%RŸÚ&2^ Zº)Ü°ê6É@˜¬VI±[`/He,³úóÎµİíoîÙ!³i`N„å‰¡ÌÏ÷„Z½ã‘F0q¦zR_äÛßhÛ½d/ıFÿ@nT"I}óp‚åÂj…±µ—µîùè ï—fÚòT–< Ê‰"+Z¢·<®,âd‹P±Û†ş£ÓQÃJ¬?ç×ZÖë¾‰-õ¥“zZ¨Ã´9B9ç‘š&+Î·JDô¡ÎšóÅô„q›çØgNCgXØéi³Û§¾ÊíÂ˜ĞøôX…øÂLÎ‰O±61DšÊÃm¢(‰tˆ*…ÃC Vø€ÍôG—È¡\÷ymÙõÙ6Õô¶cb¬)¼íŒÈÇì“ª#Ñ¿Õ_C8ƒxÒhşMº×ÃSëUÆ3`R€Ş€¦-€ I©Æ“í#ºÎœF­Ò¿À  uÁ   ]Ašf$ÿ  Õ“_æ|Ì3«~2#‘ +yİÃ¯÷™;d#îcĞ›?2EÆıÔÑ
x«Vn$)·å²‡DòÒ)(edE¨K]ø?]tmE´AŠh°)×êû   ù   KAš†$ÿ  K]«Ælm?fh÷“| Q™bò31çéu];,®r×xİù¿Ë‘ˆ¢tWñ‘~oñQ¹,a   e  ƒAšÆ$ÿ  ¿NorüØÉ"³>}É{Œ
0Ñ®Î$Ê¬ !(G¸³…7o-*ÔŞîÜNßÈ#µŠìsx²ßf—Æ°Öb¢H“b s#YÕ¾»5QÜLw¶ƒØı	ÆÒqUC™9mR§kSÛ,Õq¦U¸3Ô©!ßƒÄcdgmîjÊ¤dò4;P¿Z~¬ X¿’—mşOÙ¿4-Kæ­b(
F»µ&ïFÎ›ê‹L”*#æœ;yƒˆ™\k2^ä¯	lNÓ\Õºè¬9 Ñ—ïgğhG„çdó.«cÛÑÆCÇ/SKş–*óù£
å…÷íDÔõ@¤Va!&BÖÛú´ğ"˜‡‡÷,9ş RƒkÑ¯CN >ŠcD¬UœçôŞv›FØÌáë0
’œ²€t6%{ŠÖvãYÛÎôÇÚû8¦«1 øO×„Q›`ªıBH.Ñ=ÃîSX¬0ıZ¶« ÃeTÄá¹I^Ü¦š>ÛV¦şÛA,ø ëò‹§ºÆ#MöOVúZQÖô:‚'è g›ß‡ğ7BÈ£*xò÷¨ués–§Å³Á	÷—ÉĞ5n¨¢i'û¦e¶áû,ıŞ¡Ôâî"rŠtr†{^euz%7nÒÕ’¼ÿ€b^’©[É#äZ•E'C>\ô9pÿvJ\..F›PW‡jSÚ4{Ûp|‰Lm*®™ØùW‘¢b$·Éú…çÜ—0Ctx	\­‚­_]š¬5êî_tÒê©´2˜˜KTÅQÊ]…a·Îy‚•Ñ1îÆ×déVÑ¹SJ©ë—qª2àî°W+øÿ†Yg×<ïöÄ`®xy²àE–1ÒFóŸ:HâøÅ0ğöÛôw”ğB4¸¶ã¡Ù}BÏi—?¶_ ‡O†.w„!ô<D€òˆëø½3³3º.…Ü@´¾2RsUD—)CQÿË×Köàüßirxï?!‚Î‚IG#µº‚Ü 4
c€ÀJ6³;Âš:Ós¬¸ŠİtÕVX'´„†›CAÑ®;Dèæğôó®Ä‹œÒŞˆ0ø¾Şs˜¿S ß³CT&ÿô¨gZæÀ½Nm=Óâæšmë,lx[íNìA¾W)Pœb~x×^µC¼¶Å7W³4bTÁ1Ø–©âOg½˜ò6jã±HÛs`“gØ‚z´.\ia|öÓ[!%„İ•¸Ä2ÌİıÏq*ŸN„òó’]«6·£QTõG‹«bŸn.ÙæÎ®‹Ãøãô&7?n ¥ÒÖs!Lq°á¹÷°óço¶ÑY‘÷<9¬ÊAg'á¼©µ¹`¹PĞu}mi	º_¥Ü?ú`HÕ»2rC@#6ÜØç~yÁ¨T\c®£êyB‹Ÿp\%$„„Q‘âwk¾Äâú·¶¶&×]
^–«æ†(1¥‡ @ì4îĞ$Âaÿo=ım$²â™pÆ±áÔÛF”•ºJ•ÈÏ¦Ôø¡—Rà¶bM¢d¯BêK¡Šš-Màöµ¾Ï²oÍ®ãşØÉš«h×¶ØK›h.qöŒè[Ù^ ­Á›,Ó¹å4ŒÇEĞ²ÛºªN*ş«’¬`~ß8Ş–TO†Œç
	‚"»®W+z:‘qÉ{üÅ(Í·vÄÊÖ¿gG ZÁP6ˆK¸ÃÂÏ|xA¬•'ÆRÔÿ	ö­§ıoĞK‘Ja3‚êûŠßÏ\¨‘û™˜ší†kÍƒß#ÉQ\íy¤g‡%²Œ`.=íy5~)(="êY‡7ğòg?µ@ŒA¹fê9· 'Ó
!pD#5¾Y)À+c@<IL1Ä90ÑbßØˆ1LESRÊ{N½7gÂçíriî˜>Ê'!Ëã;UáK4X–I3•yBùÌ¯æ#GĞÏ(¬çÁyÁ³˜à5£ô©ÿÿÿ³ã`~ü—ÜßXıx3GGÿ=ã¹˜Ä%ßQçÔ‡‚z‘e4LÒ+½äQRWdní!\l—ueÜ{?«„ŠaH(8dgnZZgàœóêmÓÙšÂRòe	ä ©5dœãüá^0J¤Óøów­Zè€‘%ÆÅ½gU‹ùÑ9²"¥¥‚ Ç|èş˜]ú}­ÀÆÊÄ¾@ùeíÙo*qßúÉÙ`w‹éø,‘ŒC†aÀ2Š³hİ¼€ë„seIõ–Ôµ³pL†ëõUç|È'  6a   ]Ašæ&ÿ  !¼I¶0¯1v[aF¶¬İŒ·ÎŸ;Z±]Ş9{nN‡ıoÍ¡òdÚ9şU¬oVÌd°}X$¦Ÿß‡’È×:N²ÛÊ-3jµø«}«Hhíú¨ î   7A›&ÿ  !¾•Ö8ÕH€T<8±äa†5.äY^®ëŸusÑ¤´”ûvŒ¸x(   °   -A›&$ÿ  ÅâÊ&í çé±òjˆˆB%>İ´ÁİœÉix€   “   fA›F$ÿ   „qœl
µq¶¾QIµßÁ¶È…UGäº­64£É2È³ÕÑşb«kó*ª%7ÍROÿz¬ÄMCrÑDñÒb¢\}„Íî•Š¡né¯±ÚŸ¥>JúÔ   ”   A›f$ÿ  B¡âıºåJŒ%úUú„‹ä   å   ZA›†&ÿ   ÚTèë R+å…>zï×g&İçˆ8Uoàg²+åç—‰úõeVó¢ßI’~”G:s<ğ*[f\š‘›Éø¿}•^±2m·@e2Dbù|`   ‘   @A›¦$ÿ  ®
ÛÜãÁôN²"¬`ˆ¬Ô8±¦(^ÁæÄ]“®éRk×d¥ƒSÈém†4‰ÂzÒ   .   JA›Æ&ÿ  |˜è'1Ê{ÎâOÙóÂD›BĞ„%|í1ó øDhoˆ7ˆ¥¯ãs®}¶[”xc‹‡ı¯ºP   1   lA›æ$ÿ  %Hgï¨$¬Ú1İRdÛNjÿ])ø£úµÿÔ®@²Tjñâm"Z{ŠU7úí=¼y=Šã
ˆªfhåáîws
§Õ1:	ù…rÜ”™>k#‚½ñ•28¿;·   M  ±Aš&ÿ  †W’{æ¿ULoêÍé »õWAD$Nw—M58ühş5!'³‚M×{Gful_/‡ÇÊW’Y“±ã¸(>CóÒ˜ßxó.zegşt¨üÃabğìÖ¥ñì	€ÈéÕì“aÿíà,ôş~ÕÑP\ìıÌ/vé‹.!ò‰ı˜e6?â2¸0NåÎ=ç2
]\zó_¯Xi ""yê‡mæWªLeC#nKûaßÊíBy°°¿aHå¿Pªı#ä•g$N¦IGyJï2B!ÍÈÎœó<Lç ?…IeÙÕ”İÅÑO£É{*‡±B­²\æ2ıöG’»Ò§‡ĞI¶GÜQE_½•²Ôyô@ëƒ@ü¬&¡’Ê—Ì#RñâiÑV,íˆŞöœEÔGê€  Ê!:D	¾	ób¸ílEÅÔúÏà
!ó&Q&¼36)}jí™ã]ûX}JŒ"òÑix:¨uSÑsXœüSèşpòVÉ#Ï™²‹ÿâöP©‘eP#°ª2¿œË‰qKK„g.YõJ~ÚL7ÚÂº¤­,Ú?d
í
JÑŞ.wI¸’åe4H‹Q¬@Áì€b4T«:8´åV×|ä§IF§<Ÿ6o@ñf•2‚@q+™›è‚Šr!´:xÓÚ³¾£ZÿE¬pzÕèŠQóQùÍ(IÀ·•)¹Ñæ{ÍK+Htù'ùëĞµ’K¥°ÈZİ6¯èİ¤E%Ù•WqLÙÒÈ°yÔeJ§c*Çåk3Ïk_ów¹éŸG#Î@¦¤ŞÙFF—I’×­C;vvíRèv—à°V<í«`•«D§›Ò1ö	ğF6 +Ö£ìî,v( ß_ï3Ï·Ái%â’ ‡/	Ğƒ™æìŒ®¨kkÄÜqkh“ö"2v 8t…Zë­ótpÈBJ“º¡_ªg9¡¤%#í¦ó~eÒV+şèÈw>a	ë‹²·É¼ş~œ:˜Ï,/2‘•n¡Œ¸m•yR‘ ¢¿2ntÆì«Ÿ_¨(\!ésø`ÚÈ[¯w<‘md¢s¨pæÿp1°2×(i$•Î{°hd‚¼Æ¡µ¨1H)|ıæFgœ>?E·İêè5µwòßìn£Ó¼cõhŒ$¤±*3_®ã}à;fÉ e—JOÂN®‡˜º½Å¸~/.tç:Æ’¢HÿßÚvÇ”xD“ØÕœM„RK#ŒV#­Wl½„c[k¿øğ-» ÕÂ(à+bÂï¾Á‚[ÉRM×¶+¸(ŸÔD×ÀQQØ.¢@ÏAÊªÇ ‹“ªã–c§†ÿ¤”@=«½‘ÈçI‰D‰“3‚¿éXŸˆƒ;â§ª™eæú(ŞC\éÏ;¿¬Ù¥r0"“öE^m|»$ßÃ.¯ñæaMé-EYòÊâBQ)-Bº‰å¦‚ğ`ğKXG‰ìP—_fÉèÓÿ–»vüo¡»hEß6*FÅæ»_ô…½Ş4³ĞğV×£à7-Í¤ŒÒ±¯¸ÈsğVKv#Ešhåòõû>	Ôç£zçrd¸Å¾èªËôí‡qzM#/)ÉëÇx©œ‹É™ëJSüÌuW5!LõaKv§C÷ĞA=>YRÂæÇ4rnß­öbèÎ˜·nÍV¼ü£Q½ÔZ{‡‘ÔÉ«ôŸâ™Lé‰(ùÈy‰ÕÜâº QI‚¬ 0OÉÛñ¨Ô£Âcb/”ª}j¥;YòáàéàYC9ÕÁº&ó.…bI{¶„ãù)Ÿ7rÃÓ~ ø1¿d$ÊÏX¡åÚ®qâ,Ö !}*Mêùş•.5d-Iq1òÚ·Šv/lE±R4˜$=Ó›ğS;ßCTÙƒÉ»'åÕwNRı9BÜ±MÚ.~3Êr*u	'>q®}´»r€9#Z%lq7á5å¹-„¡g¤UÂÑókcñqÚ™Å=éÇù%Oç.âeê#Éœ iAñ‚ĞÎÅ‚i‚ı§	Êa¸°Î)‰Oş¯Qÿwˆİ§1PÒêıÚØ•2×‘":‘¹÷£"é"Nš~º[Î—Å“Hß>%—Ä{%Q"–è¤a§	°òşß7äL“V0¢êã‚\°Lßº-;È;ÏW Ò;Ÿ%@½iÚK°éì}–C÷)÷Ïî¿~4©Zï,û‘T Õ…ÎµšX©Ö¢võg MkB‚ï„ïTÜë¬Ë4G!>¤Š{E;Ã;¾Ÿ îöcüA¶E&Ú€æÌª…Z5Vóğ©¹O¯Øh%»’Ï–’*œ¬F÷¢y0îÙşœ×ÌIíò™pİlwê†5Ş 5M@øşôn;(Áì‹Ü	‘uÓ„›¨µş—öh‰akÓ±‡Vˆâ}§º
O¸Í.ÜğC¸ÉÀEr__gÎ\yÆ¥æI•£vìZ‘±'É ‘Í|z¯M²æ'`Ş€÷&‘9 cô¾Îş³+{Ş ·áß£ú°è¨e²	™Ç+³Î/î!rùòLp|ñ Úú¿5ªş
ı;(ÉhåÆ$ nÕç¡¨Ë$á   ›Aš&+ÿ  -ïÀxC	j‹	ÕMEµ~~Jä…£¯”ZÌê:CÀ>	ü2x<ÏÅ-¿hIé$´MŸŠK×ÆW‹[/Dşé÷¾Ï!ià  ÒŞÏdõ¤ñê­«M1Uî+Õ:¥?L‰v±ŠŠÿÉ±ò}ÄÓƒº NËó;/­¾•u:lvµ#Â|Ö ©îšÕbÛ)*&òsf3ñ   VAšF$ÿ  Mğwõà	dİ$œÈPİi±œ‹×h£M6	G5´+áç–•X/ªÚ£Å“X=›¦ —0E¯!âJ¨ŠWh=^DÌ   %6u¶Ö7#fAÕP  	ÔAšf$ÿ  ›,é]ê\n,7”Ö|ñù‡ù,D–ñ%¢¯š£MÜÿ]$®¹¿L/5—ÍôŠ#,YŸ†Ë€ %f°¯wÁØ.‘òCf§Ó“÷ù5Á~&fQ¾ı˜UÜu-‰~XŒKZUŸ¸¼u€Q4Ûˆ”·]ĞŠÓe\³B‡¾á	1÷±
}ò1½áHt!c§t–Oq¨)ÀOË(.º¹íûÖØñ¡Ç¾ÿˆ·$Lât‰W<¿šÈH½S?iG (‘¡ˆ)ßŒ99“¯4İ5Şxp1á° ³Æˆ¬w||p[	ÍZ4MJÁB…ûÙÈl•Úû Å¾mE}öS.R—oÜ†<üCÄÇu‡Š3¨¢½À¥§/µó±í»VÌ[Úd@KP‹ñî+CVØ3¡;G_låâYÂ‘áuÂÔ÷ÙEK8"|o›gqÂŒZK1üsõ)“-wşU/ÅtvØhè¤é‰M›j
:Êô³ŸïÄŒãå)rd†‚'*§Â:Ät<«ÇôÎyŠŒæÔKPÊÿ]N,†šc¾«xIU—,—eÉÚ+Ú
 „™>µxãŒ‡Xä€FÿŒl$X²_O…˜ª×`·XÖàöĞbHKITh£+É~Ç!ÊÙÜÛ_9ÒB³6ízÿşÇVtúÁèåp0¤ =ëŞC³É bİêĞ˜ÄĞ“k|YLMÔ—3N¯ßæØuc:I‡Àà  òÏÌ¾ÜM A}ô¨¼Ê9V$½'ŞisÍ8ÄK6ù¯hé^S,ƒ ›Kcôß•…–t‹al4#Q§À­¦ì÷«R(mºfJ¬˜àç°ÖO7¸7CUË zšæ]¥îpÕx‹Sjj·Ó±¸twµÇù$
3%`uú.`ÔbóŒó;;ğ©!˜8©cEõ†¼^*@¿Ì{Aeq¬ÈÃ‡6‡ìbrÌŠ[ÏúÁß6s°n\ƒ_şÛtÆy,A³§K{Ú,dÉ`4ds†–>|ÿ"ü0e|ä/Ù›™‘ˆ3îMòÔı^Ñ‚.t©{g}œä[t÷S²Áà°XaHAE¸F¢wâ‚»~ã;HâÈ-óf›ÕÈ«íNCæƒ"—”x³¦1!çs‡Æ-¯Aø½=-ö9¥o‰DƒÈŠ.¥¾}[{æù"Ğ¨Ü°E!OYUıÉ'~snú>Œ@°V…½<Î!X¦Ã0YbãGs²¡0sÔÁjYÚ˜-ÇÆä­cÜ9’K)&ˆs¹‰eiC`/3åğæì‡’!îj3ÚãÛöŠåì)ƒĞŒğPñÆ"6^Â¬êC6¨×õòÚW¤àÔÚÀ[±¬ùª?{ªéÜ8·ÿ_¼oÌ€üSxìß@ ÷½¼l2Q?ú‚óxN]iµ„5•bì})œ¾ç`÷ÔıâR©¯ùEÆEQ}µ†F¥€ƒ‹/hˆQ6vÎ°
½ä>îï¯ljà_Ÿ)]å¸/M¨,9AìşH``&”£¼”aNM
˜¨ïgğOÿ#ó¹]¿ÙõJÒ‚ÚäÜéªËÒ8*pÀk&ZuŸ%(=t5ïl‡ëQr
ôõM]!Õ×ZÅø}bzÅ}VÎ©“ºøû¥À–Û"êTÂ…˜Ó(Ã³àa ©34†BFj9Î9/h‘0[¤±Òd`ŒfÆê3pbDã‘q2¿ —Ò”‘\(EÅRÖX;ËÍ¿½Ib¨H‘@ZD`Ÿk‚7á€ù Xì‘ŒsiV1…JV¸ßªf[’^§*›Të¿sÍK¦Èş·ÿö¦Ÿkébf¥Y÷°õ‡¬™šl¾Òè$Ëßì |cèå’~ŸZ<J ¿}ŒÙ> {Õ<ãÖÚÛ¹ƒı•Ô° Áİ$ôøæ‘+äÛ4£;í¶ 1˜SÒ•H¨XYi7™o‰ÁXQW\ JÈ7xÁ7sÃb[ä×üezÀ&=‚¹Y~6â× $ƒzAäÚ…bM"ÿ_òÑ–h<„Õ¹öbìVs] ¦Ù*nó5È+çR.;Va2ï] ›>xq0¨åRí ¬jrn(dè0¶u„é¶™³%úO'/”0_VĞ÷ÛJÿ ¥CmPÚïğ»ha0®g §xqÒ$şT¬®ÄòREôêCMÕ-	§®Ù—¯)(Ø%fûãlYçà€æüj+Ån¨ZÔ„% ·à
Î†L­{©©•¹^3>¿B†Ş…`“Ì-r©£0&9èObùuúMˆX=í/”
<ç’™'CïØœÒÒ‡UŒòİ>zè„Èã)s$ò0Ó-UuåİíÃHP	NŸßƒ «]‡œe¼\Ú£gs¨ü8¢ÿ¢rK{ï…ÇŸlg@ê"@“µm÷Ë*ú„ÅsDïn¸–ÎîËJ]ü$]³XİÀ%b‚¦ÿ¸yÈšÖÛjÄX+¼3İ¨™¶ãvÚ>Šã-O-èõY˜í¹–É?ªœüĞENUµÈulš†å=R?O6{iè˜M=¬Œ±?ÂŒ‰%l?çˆºúæWŠ£áüÊĞDÉ³°rk—øk.ØL¤’¾+G U“î ÷½¥QJØÜ5<²Pı:ñçª8@!ëoùàKTÿ>ÇµpEB	ÃıPÑ«’	Ì-¯lŞñøÁÍ¸°C{D,>µ%2H©Ë/'HXç’ÈÏsâ^&$³0ÖL`÷uùçzQ€›aà^o!ãÜøƒÜü s§sõ³Ëêé;z!Á÷Á™¿A¿ÍàÖ|:Q@ÒOÿ@ğ`uŸÕªu²Œfw…JoµdgÜœaïÒcdƒ)ö«¹×?»Wëxâè"iüüD·é½÷J%Pí¶MÇÇøß£Ì·8´}hNï†ˆÙv­Ë@–¨®	åi¼f€ñ#•«ÎÂóÁ(_î»`:ë¶aÌÜn»ÙÈîToÃu)FVñ¸³ Ş#¡ª“âÉwª«*áB¯¤_é#ø6Ìv¤{¾Súe5Ñ¼Ü1%ıWüh¹¨ÑTo{Q£ID÷Õ:`‡8nÛr«ÿÿÄ—éÜhl:t=1ÂÿĞ·íòæßEQ‰Å\¨æ;D³å1—Vˆõ¾pÁØ‚Í&¨&†k ®=ñZ{éã|æz7fƒ9p}¼oëğ~QjÅ¨¯IÁ öOÑzª¦Ğ7•AsWTÙZl‰İÄœñ©Ÿ ¹EQ‘jg²wîÃ‹ZE:Ş¯hÿ^T--5{R2Ÿàà~Øİ3rİŒx!mÛQsŞã3ı/¿ƒşŸo¾kOÓD52ÅT  Aš†+ÿ  /J€ï'N~–[|¤ÎJ‚plyoœÃî-ˆ8Óµ¶G#ãJ®ÙØèà4úR¥Æõ ŞœØ+	hÅwl|h´‰—vôùPÂ{ìiw¾t|?i‡y•j$²%4¶ylşEK©dŠ*•iLW¸Ø›•å@ıc¦NæÕêÌrÏ:ôWÛ¸8ĞæY1ô&ü7ş³ãq ÿö‡ÃÿşMï¤‘_+DL~òºç	­F-Üê>eyªÙ+• uòu óP  “éÀu?qK'?æäo‚5}1BAÛ RÔêekcŞö’òòÌÔÇaŠG'œQ,?âÍ•ˆ\ç’M´Šïî¾~%à}Aj¯[(	ß9   ŞAš¦+ÿ ;×‚òBÔ†oJìŞ­7Ñ€×u”&=Èïmb¿ˆÁ¦¶ˆ¼©Ìí–ÈQL,ıÖ5·Œ!¦>XX\lI››æ†a¬¸Š½f¿QªéØ©G?øæJÀ{â,È¶ß.ŞC¬qLK¢Š‹¸Ó>Ì]Šµ¥ ë½¶MŠ–Ún˜3¢#	Æºï¡Zp—º?È)ê‹º'6”4º¶UwéßÀkìtQØöĞíŞÅÕu¿Á—à‰Ö†5¬ÊÉ„‘¬‰äŒ­3¶”xéy]´Æã
  ³AšÆ+ÿ   óøC«È!ä¬®Ü2F¡e®,v£sõ¾`s MíWg,àèá—Ëpa™dC şFÔù'ƒÙá·ÿş†8ÏÄ¼‹Fì}¤:(øX>ø¡ò,ÅZÀš›¥V~¦äásqôÍRwÈ§Ú=OOñÇ®JCùë˜dp7*´b¬ÏU|+-¥rô[3ÜlÅ‡Vê?‚*ñ8Fï%K¯ğóy‡Ğ=5]Xäe=¯ûÚŠĞ^`V€ÓC`ï•u:²ş_½IsxâñRß»ÁôÀàôÈ‰l€d¾sÕz`ñlµçk_nìóº´;ª’\UCCµÌ½gLÿ‚¨#e|$/ô^,qNŠ’àDËÔófœ?SFZw•ê¹ÄC‰^ärñÙ`B C2ƒ !òo=9>(zû2ÚRzí'ÇMJ×,úGƒKËG€Õ8YŠıG'c%á6‘WlÖê7¢¬pX–—OÆ×v]—Çç&Q;ˆï¸#%—³Z<LGŸ˜ám&ïzFø)çlp<O¬ÇWãX½¢¶“e„’ŸëÔµø‰í÷×OÜoNÍ	§¤’Ç3¡à&íƒîˆîÒÅ
[ì¿?–‰N-ñ	>É2¬ß‰ÙğÂ¶Å{ß%òZ(Õ×J“,fJ†h¼xâ¢ïxÁú ^±¹•[ è†Ú™¼#è¯‹ç`å|%?µõ9K!ê„6#vâÇvÖ´k>V¡‹³^(Õ`¿²³
3yıËÕü_¬”µ{X*3¼\âæÇ¿kTa  
èÅRâfmÍÍôõËËşÌ©a~1·À
K¨–F!éÆM†Ã;H¿Cò¿‘è´™ã§—ïW|ƒ‚¼ËI1GK;ˆş0b$SWJÙr6Øµ½_²±KİÁ^8rÜÅï™?Ë.$ ,"ßÄnÛ=ŒÀÓïw³AŸÈ®×(±<cÿ#Şt¹^Q„œoÖ¿Z‡ò²³öÈ„f¿uµOÀaŸÕ¶pëØ’úì9'¹··ƒ¤Ï`@î* ­ìÆ« \=«Û^Ë}/Ìã+/x.\sü?;­@ovÒÈ~Â˜}@§“G"×¯æfµ:ô]°ëH‹L» :·Èêvô¼e¿`‹ûä!µûæğÛÿşNF¨ËX’ ¼v×u¼{¤Ó34E$ögnü¾„ˆ"ı ;‡1a´æ§·÷ë6H›°ş¸Ç?âØZ>$¸¾şÎE"õÛ+0SY«š6˜-m6İ[W$ùÀ­áÚœ%‚’q$•³z• åäh"òáÊÃé 0,qúY´µõƒé’)Üãjj>·dÉ|ø(P9Áğî–˜ó×Q‹@YÌ6')8o3dEü_ˆlXkj/JÊaÖßBĞ/cFÊòOÃÈk)#YÜ%j¢³ã¾Å­¥®®°Få±rÒı¡ÙÖáUú¨h¼ÑL­ëad¯©óüX³~Ç"€çCÌï¶Rÿrò1ºçMæçÛÛ}¤’í^%zvs;ÑE$‘û±·v§«yİ<¹cíĞÂdæ¢'*ôıãàÍÀ¢¼ö¬Ï™FÖ|§
¼å~’ÀV;·Ëy†2à*YãLÉK©–Èy´Uá¸ôU+©à«Íég’*<^ù‰\ıQLUµ+ĞNøö©IcèFÚ•‚¤)¹$	Ş¹È²–àw–eÒ†ÛÔéCMa¼;Te:-n…C5¢VL÷³2½»ø[@C¸ØlÛVûr»`\¼¢kó€bä‘aÎŠ]Ô´ÿlµ -İiŞ´¿dùø´°Àë/$;Må[Óú²¾-bu=›‰OÃ>Í¹¨<Òî0úG¢Y|Y0k´
@|lì)³ŸÔ¯,1Üb¦$FEÃ÷ xX  Ašæ? 0¨÷ ¯€Ä€RsUeˆİartzpÅ œÕ®²+™|äèG·_¨ğ®ı¢@ÃkÙıÈ©ïDõ±a£²0OSxoÍu·Ğklú{ñKx0³eM´¹î$í‚6Ø&cUîÆ]^!,©uù@œçé¸ÈÕÎã‹Ï¾¾h	ó*	1[úê"'C2^®¿ÍŒ CMwEZ  é«dcv´Ï©ïkª€½Ÿ«‡KÕKvL˜¿zî…VË¡ñ¤Â± -›¬õp+óÊpPÖnBxê…¯¡Ú3ıT`$\[	Ë>Å;²…t¯{pu–„ ö.bglÀƒÈ—ÿÈÌ©OÏ¼t»N‚‹N;²T®ñì&9.v$bÉÜ‚Jÿ
ábgšNQÚû‡xõ¼"ìR£ÚËS¡¤ä’@ n~ÒÍÇŠ	 “%.¤ú‡JÅª„~ã{Éì*úè9ßÿw':÷èŸEÚ§¦ ÿp‡<[3ÄQEÂf’„÷•-O7jZ§¯ëVò³µM?­†¾&Aü¯0“ß•@y?A3öİöVÆëcüï¹Òg71^A¥”²>¯^Š¤éCJ¯
v·b’÷ş!ö?H‡­½9İ2UØ¸£r5f¤Úø+/Véõ„İr[{P?g¼bã} räÕM‰‘|• mó¹åèo    ÇA›+ÿ —›Ù`Æ"U.8Wòçë±´yËüJE7ù¨F½
b.,Æó{|/JM<‰¡7Ø¹6Á±ÓşÉ×¯Íyq0+MPL¿ƒxd­çtï¹dEUÕƒíg¤J.‡_‰c…ÆñeO	Û`U:#^ıÏEÒ+Î<;ÙŸ×l‡Í¿È3”ÜF­¦DÕ-úÔÙ91Ö7Ş¡¬WzEÓ}ösŸrB  ¨Ë¶`ôÃ(ø7˜¦4xßÌaÌiWq  ‹A›&? (ø¹–ª¤¿µ¶Æ´Ökö•P¨¦OL^„Š]ÑpŒ“>hß4	õ¹_BÂÌB‡7=´¦Àèùc5j“cŒw
~¨T,ÃÒÁL7Á`hvY uK£Ø8eaàÀHŸ^¶Q¡³ßÄR„ã…Ãm4íówóv2#(­WO	mğĞ2cÿ½IClÇo|vu’YaswküL‡GVEÑ8¯ã'`¢Ûóµ›(L]ğ ”şı[:ÕkïØIÌº49Ö#Ü`´­Ì¡Ÿóû¶/1*Ş„o4êôíiró±r¢)©}UòŸ&dLQs Ë×å,{'e$KWÏ_…‘	ÓÛÏpîTv(‘8üêH³~9†!ØM°{Ñ±<ähMjb<aO“w˜	‘Éí&òHCÓ–“@ 5Ôµ¾ÿ@—c9b[­ñğ7±7uÛ5£A©U,Zÿ¸¥ º€‰‹TB®åK£ I”$V¨¤ƒ™3¼ÓéQ±@L‡±Îjœ<Ò©   ±A›F+ÿ   Êã:û{°LHY^ Ü*%½5ñäÉüÀ	_ıvBë“ADU›;$²\¸Idëâk³½üo9ÓÖåzO ê+oùë<ø5Ñ«+L`„Ô·‘[8Õe­/œó^+“Oé@ zŞWèî9ş›ÕqŸ¬@Z“Z^hE‡yßö¨{àûcrEü6>Ê‹ŠÈ+Îºxøñ)ì3ş§ÓÅ€m¥Ğ ±   äA›f?}dÜÏ.ûœÎ@À.U>ûŸp¼Yãaªÿÿ“!œ]Ò.¯JÁşëJšXĞH5a·‘ùM•‘ú•ĞĞ½øj¸Š4Tşô¶JXû©JIoí
Ôšû<óè©şß…í$ÊáÌAÚj}nÃøT™   5¿Öœ»*¿*×¦oõÀ2ƒnc€¯Ñ%—C­HxìƒH€}P=pÂ‰hìaO$`ë!ñÄÈµ°ê”ÌÖ’èípÿ?1 Ç‘€óÀ[sŠ,xB"òƒ9Ê#­'ìğµYOâŸöI‚úÚ¤k÷Á   eA›†+ÿ   ¹5¬zF“…tÌ±â‚ï¿ş:?7ñIß5nYş-+9&‡kpäÛËBA
ï#ôR«M £KÙÆ0zôÜîš9÷!QÜ`ÏÙßË0¬‘&€ˆ;îR=±   A›¦+ÿ    3€Ğ x   A›æ$ÿ    	­Ô€iVà \€`°   pAš+ÿ  Äáõ‘M"T`Å¤ÁOÂ¾ÅèÁ®ºg	’#ÀF¦P½g!‹;¤UÔ\K<˜ òÄäXƒùCáªºL<Xgî“)b;ß­2·˜
  .µ£”‰ª¹jxÔ+D—oœîuŸ9i»&#Ãİ»v8   $Aš&+ÿ      õUuòî>"¶ô©¾‡@°¦Ö6›  gAšF&ÿ vëYA=6µKõÔ¼ÑÂûİñ˜ä:ê q¸4v8,?cÅg¹¨„ĞÈ‰S{…‰GCº$~zx?iT!Fr% }Û¿ød±ìVˆS¾YõºBÇá/»dó“ôÀ¼x47gŞÿ^úõMNDLuú,S×©ªr4¥ jÕK€àëzw´æI?ü-¾Ò,á‡=‘	qØ¹LW×ÜzôÒ³¨åÅD_­{Ÿ;á²™´òW ˜j¯LSz­=sn•jdˆAj>‘#OIôÚ,Í§|MùÅìÜ²t3@s$TùµaüáÌK·7R:X?/6™®ßjø‹*– gSœË-(ği®¸A6…‰@·ÅHzŒgˆÎ¯Û«“ÕàOs¬¿­âC³‚ÊPek\B°¥€Â0·ŞĞ&o}›í:¦07¦7+¾’ÈÇE%³Ú£_¥’1ZXŞ&LA?Mök‡ñ‹7×dğ¦ú„…H?<û£ÏGü˜ø‘V¼ºÁÊD^Ñ[\Ä7â:9àIÁçƒo”€‹É3/™!>ğ½iuõñ'H©Šº«—,’xUùõ ¶aÙÕZùgIíwÎ½1›‡®úpƒNtè¨øpş?–ëÛziùxË‰aÌ½õW»¡&Ä³Zm/^I:ğ_*lı>x¾áµ*å ™‹9':Í¿,qıY©a­y9hÕ\W®  –&Æ=YŞ°ÂRòÑ%)[‘g•’Kª~€Ìv²1Çµnğ ]Qßœ»4±%>Œ{H:´+T°   gM@4ÚCäˆ„     @<`Ê€   hïÈ  2Òeˆ„ÿ˜¿¾¬ærRVÖƒ°#güŞLw:İJ©¶Ó¬‡KSYÆS+PÉrËû”âT’oµ“
ÛX¨´RYû+"ì†7‡9§Äm/E#ŠÎëÑäûÖ¼$$GZ6º6V^»_P^”ªo´†éj0ç¾Ş™AüQ…¯x&N®ef…å4¢j+m#‹gTÌ[[²åFö˜€T^}BÌ:CÖôÙŞ%¶q×dÌíõî×òèlnĞ²´Ë&ªû‰³y€Üè íĞı ÂÍ¶H-Ÿ<±¯Ø°Ÿ‘SBbpxW"-É-ªyfk„™¦rş† '’ö*ŸòòÌCì‚ùäŒùÂË·T¢oEç-…€Ãİ:Ìí&’¢é=Õµ<ïVW>÷ÿ`#O§ËH@¢x¢ñ¾ß‹“Wìî	4s¤'4Ì‹us‡-46µĞ#i’»"k6@h¸Ü†„Nì®H]üÎ
BŠ²¦vº6X$I“âÒı³@+qi¸ Ş²‘ªš'_QÄW\ Ì. éduMczßV½ÔŞ+” 81 Ç^sšöïW-y¦‹ş’ğÿD X›ºú«<;%Ü{Cœ^*Ùb¢>Á’0G²AS§ê¬z+±,Z—•ÅF[\ó€ºi·¼@Bß[Ñ¿<ÅUfš$’Üm3o¬#}ËÈ·®ÑäHŸA¹òo€¬8áÅÃç=Ë©)Ğ¬ı.½,!Õ¨µCaÔÓøÛê–ÂÀÂßP¨   ÈWxt{N[7·#¢uxs:¾ˆÔ¥ut™R:KŒ‰ëN#‘è»…]Ä!’ råŒÄV3/òvÇXØŸ‹ë/<ë¯rtW„Ú½¶¦Æª#§‚U9³b¤33øsE.ßAÇOˆ@»ğò‘mƒğ0¸ÍÃNæ
d•µ¬Ô€÷;!çĞİt>R|Ùr¡[|ó¥é÷.'ë«ÿÇÂ¿¾µE ÙM„ûÕm	qå® (sÿùF¾°ÌPfÅF$ä‘ß£šK¬İÓ=»±ƒ²Xa¥Ïù^Nè©º€áENºÂ_ñHe«ÅO2³ÍwÎÁ+Ë¡Ô í°áSYÂâS‘ »‡À¹ç†}ÓTxŸ³¨ÎÏDOön†xcêj°@fägj@Ü}òs™`,Õ,RÀ:M<©®f6öã™Tù´cñİè‹æ>„›»ŠšíhÛldà¸Àp=ÉÀÿ¤\Êë—ì™r…1åÿ>àZ³‡
ÿ€R¡1œ~ÁL]O<d&àà‚ár{o1Ì}U:DÅÅK€Ü*°4«Ãf ¼®G,¶¢5‚‹²3
cà‘¦ˆzayyøì$AÄÌ v\AQ,Æ¯}»‘ˆÀ/}Ä†\1±LÕ[9Xİãa  TÚEËåVôÅÀË£ŞBQ‹ÎOÊ’•Õq>‘o!©_‹J³¶ğŞëÍ§<­à õMØlü”a	E]Ñ«2˜‹q Ÿşèã3ÂÜİ°î!‹{¾h|e[¥…|®°5ƒ©ı8×™’ŞæğexUOE$ºg^mÓ±BÏ{ğñò8 bRÂ4b´B/Û<ãF‹ã«ÈY¬kaa=²\ÿşó°ük=e¦¸'küÙeµŠeùÃtEÅÎÒóß¶¡ó"vJ*ÿÈ¤¡Ğö‹éÀáÁ~£*öŒc:>–İ2â0¼»ÎÿºWÿ©	Û ë[€AoZ(Ò*¸¾ù2;5˜4S“¥hÈSoO‘ÔÇ——]	›8Óyì™^lÈÖ»¾lä˜v_ ”ÊY¾ÕEğ˜C"í°î9¬nš»ÒLØŸ}¶^ùˆrn)²¸ˆl£\H¡¯Õ†5"í[¸îP^ÂŞñ­EIY9`>—QÑµxÂó¬ö°‡míáÄ«&¦¢ñGå¿¶äÇ¤ aUØí›/HêhbÃ–Ì\Æó·×ú}†Iñº§´#Ğ]FÄ›…nô‡uf¿¦I†ºƒôOŠpÑ±›­a—S¶{ÕvÀ¯ËÆqº“7c%¹ß¼‰hLj?¤•Aî ,nàö‹³ŞÌ]è[f¦h÷A¶Í•LJó…ß û×Së¦døšÔxë‹À­LX'Õf~kŞ*Ì D›ì!AÉ¸¸k±^hã±Ö›H‚ağğa¯S2ì„£^ìCü@JD?¨âıPÅÁ&f=³~ƒ¶K”:O› 	¡æW49©ó6Ü şÒ	ÎŞº9rÜƒå?ˆJ(0¬ñô‘SW1È5Ov¨3•;èMìàròz·íRk²S@×›ÁOÀ“ÙÌ1‹PAÅ: 
Cş—‘PÉº+¬¦HÇo;õô¸Ã~£š)¦WşAßú-ˆ“c&ø ñPƒÜŒ´ôwİbÙ@Ÿfl5f„Ÿ7_QÒ?p–Ä“'İ¹ŸÄ	sKÍ¡·Bç2ìWÅ»é±›ˆ9·N™ì (|ØÒ²sw’@mŞE¹úyvèÜ;šğ}ÿ™jì¡«ËM{ƒ€¸{İ<´0?oó'ÃéÍsPNÿCÒ”|¥¢_Ù;bd9¦éµİšš9;k:Ë§\ÂcË‡Ã¸t@!u¾ûoqÃ, Ùˆ5—ü“ù Ùc½ğï>ë·Õ)J¾0J|Àº1Ïmü„Ø•á0ºHV¹‹—Ç‘r…¸l‹“‹qu.€§x”ñ?1œê $Èq]ÛÎ Z:èåWª¶—}Bì„Éfœ¡Èk   VAˆÉ(‚Bê4™6ßôsmÜÌpºÙj÷lqFê§§±±ÏOó²ŒÄ6GLÅØ(îß5H'ÄSÌn?÷¹_C)ô™:˜!w”ß€èr¶Ğ êğ»mßXxcĞŠEAµĞcÏx<©"0{eüÃ°Ó¦Q6IÂÁÕ™IÒ¸×òüöÔĞ(Å„Ãá#u ›ñµ~û#sß•å}‡£@¤ùBæ½$H«zÖ"©Ì€Æº+%Û`½CR­Ö!@Ny¡!.P°8ì”ÇÖÊ+=<Î¨U’¤†
’ğkâÈ½¬İ‡¥Õ¬í,&ï›>Ffúñ¬µËS­uõg®Sí’Ñ2éÙù&Äº†)µ6ßâoP›çå•å°{¨7›¯í!]G„¶À²q.»„¬ÓğªŸ…°¨ñÇ„t±j·*®›^›6¢ƒMËx$Ÿ‡£ª›{	#4wíë’î#Ê2€z‹Š§ÛŒMÆë†›T†9´¤Áüó‹,<	øµÄ·`9©¬@[Di,ùuQ5zwôGb¿ ¯·¢üÅîeíJ&H¤W–‰tşùÈ¯pOÉÌé"ÔÇÏ$íær¯ö;­Âxªf-c¹U¯Õ³3yIè:Q¿<Œ£ùİÕÛ9 {ğöYÖ[ËºL HOäõíNs~t¥*uhHO¦®5»÷Ìi<!ÃbiĞ™eSpõ·¢8cÕœ³ÑšöÆŒ"üñ<wDïøÎWGßIwŠ~5æ¢íŒÿëú—z.‰ŞÒeøİV_¡ÍÓT2ãËçv_D×òåa¸®)Y(Z®¨hÅÙÂÒCNJ3CÙ¸ïŒÁ,_‰>í¾l›øÓ»#ÆPŞ^°}A’­K´)!uşÌ°‚ÓÒ´qe ˆ&ÊáÿCh3g¡zĞp¢‡ã‹ÀF“Ù¶L¤IıŠõ¬$“;wŸL÷g¬âës)‹X•ÌJ‹°»Pb5û÷	G 9ÂàM¡Á^ÇL$1Œ¥½¥TŞà3¢y´)¢èòÃ`lœæâšS+”l[ŸZA|K©ü*FÎ9§tğ>ÍDü+‘ç—Üê¥½—ûÄÇ¦(Q yõ¿Pÿ©¨Ap¨Ï–éÇeä2#eâf9¼jS0)ÕüL£rúã>AÍ	wúl öSõ+öÊßÆî=ÓÈ±úß…ò«ÿUB	Ú+0©(´qeéñR*;øøé ,fÆ–Œğùíg‹Úì³:5%Ê¢Y<Ù»dnxßëÿ15ñ‘7Ùüã)Ÿ¯ŒJ¨hO­lÌbL~É	Â³åÌsG‹è¹Ô<{›ÎšœÕÂW)â^i´
 ªUïÿÕL^-	N³¡ÂIs¢Ğu¶›İKÊ7áı™	>ÕR›ér#Z'İvCdM «—ºÙjêpîAÄmºŠƒOb@g´œMmäêà2ğ6`½!
›ˆ}õ¿ñëP‹ÿ)b]¡çF!TySá–í ›#_çÅİØÑÓyl-Vöµ©×OÔ‚ıı_C yäŒ”zkœƒPĞ˜|=¶²SŸjmıÛ§w^giÚIÑöF
G'W’õ»E *86fÎüñ5å®pÜ˜‡43Ã¹÷‚ÿıÔh†9–0Şt²ŞÔ¢Cìù>ÚaM¤Lê†’Á
ıĞ}¼Š;"ø7­+{bdVŠÍ¢´3UäH`	Còâg4/›6›ƒš#òF6ï*g6šÀS`ÓtÆLû]í†ëeŞ Té@š$ncË!z-ë˜Ùx8ñË´
¾Ôï…‘{»]KÓÀÍê“Á¸LFĞ¬ê¼o!×µ)q³ìJ˜6¯w169å´íq«`5P?£`'.ï<WqG’®PßåØ7-´^[z×}‹.]LMc—ãkıd£
Ê/blÇç¡ …jf¶Ns®ş‹ïÓei9cï]€4“ôˆ¥ÊH#àb
ÈùdğêˆnaÍe&d“Ø¿,íÂ­HvŞá šÜâ¨„Ÿ=Ù®9;ÌZÉêé™W¬Ç¾2•$ó9Á'¿|{ğnüËzò§|†–ßğÎÓTHB/Xğ¬µ¹¶EÒ½8“AÛ_ízBúğ„Ëõ(m¾d]zK8¦H'5$caÌÅRÓª—\ªö0EÜ”ğI­ûù‡àÍnø/Y§×¼BÜ1‰¡Me›*ÀÚt—-å·Ñ~Ê‡ˆı2®Ğ1Ó{©´VÖ¸ª#ŠVU[äpkÃá¦ª¾»ÑH•œ%ğ¸p¥b+>Àû¸³¥›¥:Õ:‡™µ‰J™Ìû´gŸN¯—A@=„ÍôG{™K?ùæ>[ŸÔÓÄ}Ğ'w×…ü»Edd EN³m$Ç!î|IÒ¸õÕH1ò,nä˜=ŸèÖÜ)Ù?Ğ´hHDu–üMY(ı›fGµYœÚ¸Üå¦.W½®óïŠ±8cA„„C\(Dìõ‹Ó!>_àwRbcÎ˜¨€ôsZòÒ00ûx¥l6ydya¤á¬öŒv9z>5›P1+xÃ`z¬´÷e-"û÷^6±ŞĞ´¯ñ˜€aÁØ¡òÃµB²Veú÷Æú§ şKëêÄéa¿¨ù0ôc
Ú~LéÔåßa«ÒûrôS¿9¿TFæ¹oÊCÈ˜ÊçË–º’?Ñçvä©[î„A„ŸÃ¬@	İëÜª2è~F±R+¡\SøàakD=óSbÿ—]Q—!eÎYµâU.À"(3à·¦ñ±ğ{søs H]š'd‰ˆÆüÔç¥­_ÎIî¨R»Z¹@cDÏ‘ı?ù‰±^*$‘­ƒA™°_ ˜Ê:ucMúN¾v)÷!Ùë@<ÛÏXß±¦Ã@¤N¦Rdùùr9ôu«ökZ¶¥¯âC„!¾NúxQ¶Pj&•›…=É›;Iˆ¬Ê—RÚ«üi!Ò3ŸÊ0Út³ù> [Ñ"jÕô]Cé¼ü»_Ù¢F$Õå¯Ü&:2IäJE¼:˜òg5!®Ãc¾D¹ŠzÔ@sÕ›1eZ‘’ÎÚÊÂEœ¬Ì7ÍÑWÔYıö&9>X¤S'‘QÆ“À.f5üÖ™ç–¡ØCÓ3 †œ@h™ ñ|ûˆ¹ÖPËÖ(†´‘,­5ïRÂÔò>ÓO9$F?q#öÉÊ¶¥cûÆ’¥¦frB¶×øİ7"@01>ášdh´j½Ù×V-—0BC×Hß$b»:ø«(nXEËJŠ‰î}ùİEa‚¥¼
G†Sçdü'e<Ü[ÂÈT&—ıO±kÓ¯ŞÇXV Â"¹*s^,¾ğŠOø“)e5áñºÜ¢„)ß—T©uœò‘ÛFÜbëaŞLƒâgX<r;5û¶³iÏ“›eğS…dûŞ&&-Æ50QBÕšúO/ñ‘Â… vg‰åï„¹W–÷Ùü¼¿ém¦‹ıÃ`64såĞŞG³fX×·¤±QOÑƒcÆ6œµ/‡©¤…ÏR‡/€˜>|ıQ~Æ¡vÜÏ©vGªEÂ+ûÕ€ÿùÇ§†Ã²q±ñR“Ş1@Î.!Ñë_ëcšÓåsÆm4J"#Õ³Ô»¿=c3ÿ‚èºP”;²%‹[µöStló-]ÊÊn‚@K¢

_şv·à·J:´à£	xş´»É~ı£zgí@>û¯ÇÌR€Ø$úºğİ=xêd%éÄğä~Ò^·ßÊßsóÆrŸx~—ñ~Úf£rÄÉÔ¡0øËã®a±Lää˜GŠ½¸Åæ°i2¡š½»ö„:ëN3IYÕ·G1Ø]1Ó“‡/RÎ¦%sÄ:‹(dò=AÆ¹ ozÜ?We±.¨ù€l+Ê·±iæ ”0Ù¿¡MÎ³Tµ±ÀÉ­™<øqkH°@Šx¤ç1Ú¦.îæ:ú°±ôÇ±~¶hÆó©­*É;rbg°~ƒ^Pÿ9"ƒN¤Ì
©ÒÑÄ+7Øßu£¶°º
ª;7cö{˜"ØÍŒ”Å‹‰oSÌCvÄ^ñ”â"™qPãû¬33Œ•<OÖˆ¡%K¾ùïŞ*ÁdN—Kh«³oz‡Ğ00ßoOB›+R@H”>pKuø©ø€Ÿ°§·Ò»[Ô^œdÛ MUÒ’D‘ì@¼e•®qd*WÕkCI`òpŸ²vNiutôˆ¾Ì;š£±ójËÌ“¶}5NRF£ş@LÄ±Q˜ş¦Râ” ´;Œ¯¸_¿a¼ºïé/AÓsd¡ßErùhµ^7ùFE]òWØf‹2¸ã²—¦qf£äxyLğ9[t;WVÛP®2înwéĞW1ÎH!¤í’¸Ûô±VNÉÜsÂø)€¦÷!¹ÓŸªOW5[Ädì+ãüñšÆÅíå} {Å±Ò$;Hıgê=FÙ‘›hƒ€Ê±¤âxœ|šĞfØ½‹Ÿğkul[¸iK®ä ^rèˆ<ZAù°ÃÄ®$OOÜ0½mCÜ¢·»Šïèn+¥ÏÄW‡®p*sÿ«^íóCn|%“ mf+4ílÄÛùõcãlê”I@¡€2Ÿ&¥/´%!0Ä7a‘?Ş“ÆB=‹…H/z>“	ÏiSG‚Ä Ì¼.ƒ@«Dùàö` ½ddí@xÚñ;ş‡©Gş'FjRoŠ„¼<êT‘Šè‰
¬$É;fğ*{ôP‚IG×‹A	ÕC5–;Ğ<&ÇqdÆ/Ò`V]¯‡Ğ×“ó‡êzéÅ¥«Ö¤i:±©xü®eĞnZøÚóìğ½—Ì„ûQb•æù‰v×¦É¹Á-oĞ/±¸j^< )÷÷üÍz&Mö¥?m*Nx_ ä²oÊ.Ëº÷)‰{PÒÖ†‚~Ó[ä#z=ƒBz0ä·°Ã,‡Z"KUŞ·%Ìƒz¾İi=p£KµGòyÎ"|ä)¢¿sÌÄş<9t‡ØÉ,+m6x+³—ø+L­0ÊŞš‡æ´[¨,ôÀC«ˆÜ¯ÔKhSëFñp”Ù¯æ¿Ÿy€ùZŠ.rï ÒÂäòõÊw
„'q°JÎÃÜ À]jAìí¦ÿ³à
Ï¾c1lô©(£Ù™8N²Õ“Œ€ÿ `Í$·ø|6À
¼×TQ‘N;O8cXşm[ÆóiÀ‰A}Ø–W!– ¦ïcÖGåË–¿–87¯Á[‹ÄzŸœÄ_.IÁK"rOøÙ­î®ö!~—Æ&"ã<{O¯Ûj¥×+8*Ä‚Ô[æ"Ôj÷¸éŞ}«JRÊ;4ßùk¯s03t°¢ZòqğÙè’=Y"C<õR60èí¡…­‘†5	ÍÑ›ÑÁOv°-ûumf$m®Ş¯¸	À¨i.Eğ¨:>-jDÒéÌ)³P [ıò>=Ïw<•ÉçäkìJøGZ=üNMYÒ±~vÛîa•7(Œ>¥™|ÔÌùSŠÑO|‚?¦0uÕ)/¼šæµ”¼<É…wb]§„ÃÚYÍJâh˜üÈÀÜà-4İÕo´ô°%5Ú›ZÜ2S I®0”kx–_¾‡?£N³0Îæš™¯èNeù«Ï9¢ç€¥½–“ë»ô¢jnøå9‡8;'qi/¡§5Ì·¸*)İSÈY<CÅ>0]U4ªvÊÁvO‡FìE„ÀµA¥ÒBÄ¼V
yû²û¥ò”Ñ¹åÆ¯ı‚ãÅ!¥W­wÙ:ˆIü„ÓŞ5¬=™ş–v'ìè\–İ»Z±H*÷x²`ycåĞÏ4ë8WÄÒ”ÎµÒ^{âµË‰£BÖî†jÿı*¤’b´¾ZD«­áô³üxƒrÀ³'DŸ³p*ßªÍk¦¬–IÍ}º1×<o«ƒÍ[ÑİÊ~İÇ7õÛEyŒEòíØ®1ñWı_Ú×C‡† µYuv=ªª{¨s©3®fÆ‡nI~$Cé+Äë…¨²à»HÓİa×ÒùK|ÅTÃ2C–şì’;6]D§‚ ºo!^ƒ‰Æ7›K>«<¨\]Yói#*ªíÁZı¨Åç,Œ³{;Y^w 	Ã¼şæáÑÌ)ÚFTİ•Ç)±
Â°|¬¹¬“O  ëf$†rg{v,?àõ'3nRéâå9­>XôN»ŞÏèf¦Ç3{2ì…>‚÷î¤Û4cQE.nº²/İŠIŸc]æµXèÊÿI´ãšŠÏd8v1™”3€ÌÙ|í'7iLŸ¢xÇÌšm0˜ı¢Î<€³ü^qÒ²÷QïçÙ¸[Âw=ÊêÂ–‡}À`¾¼Äzëğ(AvP›¥°×·›Ÿ[K(¾;zÁÓN-.ºA¼0ŞÃ<C^ŞwµCÓw9;(wâv¿?i´.+ß˜<)9ã¦¯@Ê¼PÖZ”"QpbŠ0<v¹?Ñ­¿BÊ\#–:Fƒ"t	—V9¢'*ÔPäå{üÑ´ÇÚdíñÌ´ÈàXWÇ÷}ö.°‚ş!—C-í‹¿‚S³Ë†De”ŸÿüÄ?Ä~%™šÆ3swu@ÙÅ¥Õİ‚ŞMÍê¡€uÔ-“çˆ«é»Úë4ŒNa8Èà”D*¢ë{YÈ•‘ªl»Cprù,ö×¹ç7ò`Ê—·¿Ùs4Ši`‹ Ñæ³î19L]ß…o)ºÈ›Æ=ˆ–Iy{?±¶İIµôß"Ö‚§Ã2g,SM¾ïDñè·¼fóî#Ï“İ˜şdO‚+’átàó¨±lhÿ€¦1æDZ€¥›ê[4=È~\¢lL|É¦‰ú@—˜}øvØÌŸtnÉf7d“Çét†y&î$Ä®gQf1w8QXKÛÔô¦íò·…“'¡+‰_?ûe?ÿ¥š]'b_D"ŒÍ¦{»g@¯Ö9±ösêÔØ,,Ó"×­×°–µ—bDæüó—‚‰4u ¤~;!@ä¡MoØgvËŠJPƒÕ
›Âä#ôch$›U{š¦kŠ+¹xa:£ ö=éÕb¼6mmqÇXÿ¶XÄxÏë³ö½Àá÷és/ˆ¹HÉkÁÀU{wÉÍ5.±×Í‘î×!9.n^ÎwWÜ«“{¹Õø¯XÉ²3«’Æ$Šc|õxå^àÔˆØN¸ákÁ,¯V·ôNÎÕgÅa2µMÎÒ¸#5çï’³vo›òg.~ö;Ø¯áö®ıë`H3ˆÍ£óÑÖI2åá+'0a<cVJo‡é)êX¶“½Š÷Úîj5ÌñP­Í¢üÒ›Lù)Ã¶)ãìÎğ¶º×3^$¥DaşMl‡y½óÀ•
	 Ø¦wáş¥‚¶¾¦+\mWız-Æ\ãj”Ììdj´•2ÎêëéO“8•Ş[kaˆª]ÿÁÌşVøªiÄ€@«­¯ô
û›óıA‘z±xå­Ex˜xñ!(£g?ûKn´I!É†­óõßY(@ÇŒPs6µ`—”:Å2×ÂûO«d.ã¨ËtP†½LfdŸ­É’“Ìp qˆtX:¤5u ´Fåï«Î.WÕ_pô»—D5LqîJR§âÇs¾ø½Éüµ*Ì}ûî÷ßù4qOƒÚû—«Ú¦~¯ñ;Gm^N_»]>BÅ¿oã¦$¬tŞî8‹…ÊƒµÀÎÇ¿ÀÂ¯„8«£zXtl9üãX€(y©Õ{}*í'í?]5Ë_ÿİñë—eÄ>u¦m¬`ñTã«˜ÉYn›}´ğ¨ÓoÊ™Œ´K’“Us÷òŒÖ-¦-¾Š¬Hºkt‚ ßÛğÑÑşÑåC˜÷YéiëD(÷`ªäK^ØµÅ—=Ñx‹Ô(2h¡ÜHuØúÇol…Ë­F¡íZ'œV»3Ó‹ªºônoS‹“š3j¼•9šfôß2ş[âss„Xá1îEû‹Aô‡å,õíø~®a^UvĞ¢‰ôÛR .<Gé¬Ô¢Ñ†»ÒN.j»=8Ë¡gÆ®-ßÄº›/ã†	©«4Œ­é¨{cÀÌş¢A\Ói„İIeü<A…ßØ`L¥sşpıÿ4E_MÁ|xÔ‚PÛ2íÜ´…v­ ›‡öªmup–œo'uæíó)J{¹ï`8¶>S™‡»œ7Y§~Ç6Õì2¸[·ƒ9í·ÔÑ
üë.v»&6»…¸ ¢p¦}*MbB\~æ˜“†sñü±ÓÂO›çÉ~nÒyÍöÔk(iĞ~Ï¨(1ğ5{?;U¶Ú“ğe|¤†XN†ÕVuòš(˜³¿»kX§;Ÿó½”	;‘³j™R”n»aœî W0¶1äâõı ñ9âú4–Z²ëÌjy4j½+¶{jõ3BµIqY’Ù+%}»/Ç8aµ#ÎÇëQ…×ûcq
îƒoY³—×g¿üÔÕ©µı¿³ö{)C|ÛasÏÊ˜‡xÿª’=rŞnvÉ¤½5;®UÆÉìƒîo±UùËÈ¾Ic_oWì®)S
4‰§é¨8€Ó^b®irf;İüƒBµ‰>sY$˜jFáŒ¶Ç\=ÿŸ*('¿…Z=t•ÚhVa<ª{ÔoÑÆ‡ÚÉôsv„zw¶/¤îÅ0³¿éà}Í‡Ë¤+µp|ég¶“?}™ Ÿ5óäé®7#—Ç±t5!@M‚n¼4e_ò¿ Ï¶ÍºÀf?’è­ñÊzn1 ã½F¯õ"ŞÀ0¿@ùŸ®±¿¦<Z\­Ršú6³ú<‚ÖˆúYñ²oÖèÿäµïá­F!%8oÛë Ì/F
àZwH5/u!ˆ´>õ&ÿOÂ•lŸVÙêõ‚±ê™‚İşÿtµ¾/Â>Ğhá(|Í-ØÀì²Š®YÖİlıy£ØkP•¡tò™ÄñÚ !&•ÁPabKÈ~9U³‹ßí²oHfÈdÒô³½+Ş³r¤3dıÊêy•²{—R5hæ÷ùÍ§ÅòŠ;o$äpÀŞ²¯ËÀiõÄ‰H˜¹øŠp­>U9Ó^%¶DÀ·Hyóÿ-0*4éú-„­i¾Ü‡E­CƒVˆp8ç¨R5¡ş+;¸æ
‘œ›Â¼§süS Ô5ƒÊ«ë5XŠ¡¤b&ezÔ—ädæ«ŸùÀ‘¬K[Átß£çg dµAĞ!×'	¼øÿÙV«¥~É˜µüá…ù,n¼õ"Åxˆ•°QW¸OLy²çßFœÒwêÎNs
4O0ûöØ:99*-É
2ş³µr—…W»¦÷	÷3ãı(’vŠ=ø³óRó˜Ù‘Ã#Å×GıÖºk;c2ßîŞaçXŠUª—†l éç‘âõà”.A¬…L†âÖi$S6}µ{¦lJm¹O¦»@”±£:¥@È_–à{¬Ô2»Æ I”ğH[†#&î¼ƒ"H›+ğ—]Â];¨PœIç¡â©Æ,ƒğ¨–[y‚»÷	î§¥ˆøàÆË1BŸô,ÏıòµüPû§ ü`ƒ*vAšÈŒ¢!‡‡Dİ†Z¸èÑ}4Ğ©µ˜››§1–
bAX›şòäÙøˆ&:Û% J? kŒpgl/èÇøÑ³ÙÂš½}IÎnÁµt„‰Ø@ÜëM3ï³8‡Jd.`Ä{×9Ù¯Uw ßxıèv`°#!ÙÖız‰äÕøò¡d*…®oeZ4Fh )yê¼FÀQûø½œ¬æ
«½g1Fs¶­ÔŞéÏßgÒ¸•VAÚ,ı®è	ÌWÆ&	åiÒ·ÚCS
Ñ`{·ÃZ•îÀ(óD ÏW^èCÓ@A¢ë·¥ê¯¯±°»ú¬Ó7 "F¸Üš)OÛ7º”·†Í©Ò)öÆ±Ó®êÍªiŠ‹ü®:Ì—Qÿö:»uaqŸãkMË®/äÈ`ÓUrx‘¹s¡×—ññ¯¯P\q) h‚¦`¦‚ fi½9’ÿızÖ—`}•{…©z®çøJ]Vss¼ùÙç|¯Xœ$vp8nC¢2oóoîéÚ›ªÇéıõÂÉâ İÊbI5-YÏuSŒ:é—I¼¼ Õ/#
àÛ4êÊßMU49hçH’Ôe¿T^QuTwÃP ó$À¼Ã¿Zš=£ÔïßN†|2 .»¿ùïÍ¿I$ñåbr¬d ‘´áÎdcÔõğÔÈ4#8À;(ÂişâV^B’wjÙj´èuP>tu_µ¹ÉÎ d€ÿ§»f5+e†?Â8ò3í;Ú£Z²‰~ÎmG5S¥†hØ  ÅmU	ğM€´h†oÒ‡âÂ¶ö¦ 3M6F?ó¾ÿY)ÓäNÕñF/	 Ì¸k›rÍRó¸e9  P}ì†µ’­¿T¸Õ»®õ/÷jµ§üt×H–ËÂ¡Å_Şşİ¬¤2ZöÏÿİ<ùB Y™Ù§ù<¬…öß‡uÓ4ËoÙF $^š¦àtúk`s”kÎv}mEF¡+&0Ş§ò EÎ^ËVvKé½¿ÛOl8¡²kZ8k»ÇúM€¿UÒ(Yùö·k3O¤¨^ExÒüÀ‰ù5¼çl›?>tÍšı¡…ó¯Oâ2?Sô…AJ6Å/İÓí×h÷uÓ—	øjárDSÏdZGíü0ë;§³^>ÕOÚÅŠe?é•oµü/:¢ÔãÀ–Ë¢óß‚¬òÂ–ıñ.ÓÌfòSpïÛ s.^*Ë/YTn$¿«Ï‡fY*‚‡í+³­İ*˜|BÒ<8²7HI#*õ`AÃ­i¿ºE?®º[[Ô!³YÌ´y¯
¦»Ä\èĞÈA°BŸM_½ç`ár!ä… Oºmb.ÎÖôàCcrı±«òV
“<iZöz:´‰Æ“ñ2kÖÆbüdô„¶4?Î8ÀÆïFÌx:vŞîîGAykÅ½±£Ş/Õ 8Tk•‰[yËLİàÙ¯àä`·åÎìV…‘·7Sıˆ½–• ïVúv³]Gñ?|ÔYL ï8&ä¸”Kíå÷½„A´R‘+X™ÙÉº°Q½NÿÍ°Y½ éûÊ±Ë6`9œÛ\YnÈ¬EV½h3Sl†;±¹³~Ú–Ñ>°è‰]gC·¡TAŞÂØ…ŞĞ~X1 K(¬ˆdİoÖòzYHìÎà¨œ<oõ¯«²ŸS–ÍÎNƒõ)âòl—ÀöIÀ}g’ìfŒ	zb^GÓdÖ(P1Å¥-³j´e–#òrv¤ùàöû(î“×tİ-Á{’ÌÑáq¤å'ŸdÚ¾˜İ3’ÓkãœO,í¢Í;İQÃj‹&«Uåím%K“NÌÛ¸„Î½FÖÒ¾ù‡ÒJY†#ö~Ü¹vÊHé!ù {2ŸQÅ9ôÚÏ~û?¯›ä·ÕÂUŸ.UĞüFj:Ï:R}¬Ô–¯	À™_«j®M;NÁ—¬rŒSÇì‚ëhX Z1ˆÂtÖE©*¿HUĞ¤½*°C <à´‹UÒ‰”ÃÇUkiíH£KjÍø‚tNåğc!mÔÌ®)¢ˆ&¢ÈªkÛ÷K­Z¯Ü.dïAßÜ_¡ç¯£¦.…™°Ãë$[úHk’iFKü$lõÅÎqtÕÓu±#ÿf«Eâìç6^İ`‰I,à4°A¶à¶şnbkğô;>ÁĞóšˆêÏZ6V_ÎhiÑ¿™òí4&t]ØEÇ ›qñŞ$ÀFûGĞx›7•š”>ˆ»íoëó ™„‘¥¡º`@ì4Í«%R$F79üç7‹K9ì¿!×¸è [7#U·¨£–Í· Ùn(Ç»Ş†œP£;2yuúØucp¼ªdPn‰0¸ù_‚şîcÂë«4Òdİá†çaïŠ_`Î?±!Ÿ 3l±À†Jµ4bÖ[«¨‘µ€g)åpdÚ^İƒšK‚Å¯?ŠiB°øLÛâÙü¤º!İOêWxÑÊI#o¾;pUæ_¤¥)q&ç\@Õ’?v*UWIÉ¥÷ÄøÇTŸz€úG8#-x$›«C’èo’¦êëŠä–Îß‹ØëÛFô+0L`§İNÏÕŞ¨ó¾]Æo}+ÑÌ’âÂ²Ìì't°°¶¼‘ˆ-Ïd¼¢7eßÜõFÒº‚e\´bğû	››rı÷‚¼bğMúPV.ÇÌu€çÏ*×›Ó(Ú¬/Vù»•+Ä(M@š³ÿr¾‘k³z·D¾,:ª£Æ(JwqÂB¹ÓÄ}¼:Àmò†Ï\€¿RP0Ãb|’Mõ£ÙA\Ûÿ[P,4ûôÄ·(ÙMºÒbX&—RT¸SQ¨¯i¶Œci/¦.ŠU¶ãÛ$Ûyõ§w8·U?ı	nÎÌı„üùúƒCÍ¢³‘Få"N‚¤ë‚uİÍÈeFIú¦ã‰QXœÊn¼ñhå3ˆÉs’º9h#µWï‚»‹ÿÂJWÁıëÙ½³®Œtöùu<bL½’¯ÚZò:#aˆ"‹Ø_D=Ká#æ¡½]nzuıƒUªÛ{Û•²ŒšÇ4-uÔÔ#<Èj_Óx—#zO¥±*v£;¬)uBnëç~Ål0C7äCR<Í¤W±Õ’×%º´¡ª×nÎ@¸•q»²¨€zC¨ÈÈ!•,8ÓÖG4i¾ò*Ş91É}<*£ğ÷W'I†åğ’çJÖpB-T­Nñƒ2E­VÙˆQì-‰ÏÛ¨0E1HáYòJP)j²X‹qG¬ ŸÛ£ÅÑìş¾$@ùŞ÷A“ë°Ğ5¢š89 z.ÔNèÁ‚7{¾Û|e9Rı§³ıÔRà\'Ûg»jY¹­-ön¤À}<7ˆ–¬ù¤aóp†`×Óˆm„óÔ™¨NšÄúÎQ‚ƒõÄâ#?²¬hxY­AÃ¾`À¤Ü¼<µ·I¡\sŸF[V¼xİ gDš"Q¿ÿßıææH\ÁI}zE}Ğ³Hy·áÒEr†¾ƒçÒ(#Î¾°Zœyîß' LG
¡DS•Ÿı¬6JR ¥×Ht·!OcŒ?Çëàïs”%»€\^'–YĞ,kv>ÈyÒÒ!GOcù4¬ã|’|–:'©*ÊK ó2ejıÓm-y˜©v¯@R9‚óBíÓ°ş3|÷¹ñ2™qlfŒiù·ùŞ%ëø•íéU•gjw¯¯çe¢(3È±ÁÕŸ4¶ecMps,?}jÊ]‡W†³ü;è-t½¾·íÀ67ïÇKäZ¤ÿebhz›Ê E|6ö¨/¼*_îöêR :ÂS–N„ä¤åÀ¶ıê?öHÓ%`|trFWÀNJ–ù´&R¦‡òŒq·û‚í!Ö„	.œE¨6mV’a§è$Çtos²†R÷¹„6ÆUZyn°µ¥“KÏWåå]+8ÀSÏ¨i§m¡À¶Ú¸óêû7»{Nœa­>9N%u€^ZvrŸó­k¸æÜNn50¸Ân
¯Wû‡Kj "¶2ÊYÕøö^@áZÂ¶åû\©Ï‰z '˜œµViR±$÷•b¨´r€`µväŸÀ ;1–xù•=X‚º½X;ÊUk°ø©úŞ¡G°”FMqû¿`ÓçÌŸ9u®/–tƒ=¼^Û£%µ¾šôYı!Ê…;ğ' ÌwKU¹¯¡P‘\<¶.b¨3„*2=1İñ~øzRa,~şŠcMş(«½È
Q€ƒúŒ#ÊÈı?yÙã#ô9,’…ˆG­˜@Üai½ÆØ…ê!Õ·_izİJÍX°1ÜãYº3uÙ‘YÍDv}í¡ÊQùÑ¸íä³™$Û6ë=*bª?ÚÆn· +oğŸAæøÈë¾§]-$rÿ [§¡éÃÊR2şãın^!å‘{1é@d P÷õŞO”>1“0Ô‡,ªâ¤²ğİ:Ã‘¥Šô<†¬$}›ÁRr›×vÍã\^Nô`¥á§Şö½«ãÕâ>Ä¡¼Fx’°zdàŠŠ™B¤
mÜáÛTãø_.N¦âÿ£§à1ò«ÔÕÒ.XøÊÛ&iÇ)’ÿé¬U©\£$Àœìu¬p)ã¦s•!+ú‘SiAußWÕÉlyÿpX9VqéAÈ¿•Ø£<4­í<†Èß¢;³‚Iİ°×š3;àV1½G	Á² ø\Ò·+ëvZ!ÙHÚŞ` 0³jì  ·%báæ†LûA°õ3cµ¡&s‘e5Lw{-‚ã¯»OSì’ğY1ÈUy¸
Ì!µ¨õèÜíP”áÄÌC` ™N€,w¦y×õ·$ÿäxÉC ÷ıy`/¬àqíÎda¹pHıìëÅ{   GAš&&ÿ[aL¼kPÈ	oñ]Ã	Ç>ØéËiXêıòß„_¡“Gº—·ò1¾›‡ó‘©›ïŒ
 d„"ÏÁÕX€ù€   AšF$ÿ  5WNVW#4¬Yˆ   5`   !Ašf&ÿ ¢ÚÍE›@Ué}¤v-.Õz5¸Š   9   Aš†&ÿ  6/"§7c¿¢š€ ôe0à  p   JAš¦&ÿ  £ğ]âN(„³Îõ 0zA¢å±ş}ÃdìÖwïæ·Ç*†Ú…¨\3v"t?l†ÙÚ·“ê   [@   `AšÆ&ÿ  ØÀ84ŞÂ¤eÇó¸Õ—`cÄó„R×j	úÀãÎÔoE‘×^Ø|İ	ù¥Í ¡B@4U6nr…¦‘"óŸŠ•¬Ğ‰Lg·#ÜŒ“@  g   gAšæ&ÿ  lu(8lFóø»‰.`æ_Ás,9– ²¨w‰ç•bR)‰ª£Â`ˆU–Nš¡?È¯1Œ©w4Ï÷|*Ğ«¦¡"%ÃRYÌ7’.(àı’bÙ‡#:+ó†=A   	¸   ƒA›&ÿ +¨¡dÿ‚gÛ9#D!XF
İ;T&—rI<ïdïøÿ½˜ÓˆfÁ77Cj©J8ôPêDÆ.W¦wBCóoeŞ°¬Ï¯z¸t×U¦Lµ·à¹şñUğÖ’ïÿ³hzÈá ¾»ZkíÒªCZãŠèÉhô   %   MA›&&ÿ 3û/À¢¿(tsRâ‘Ê­Á_WÌ!?úXh‚‹x¯ı¶Ò¾‘»r™9\ñ%¤'dO¢Ò’³<"€nÂ` Ö(À   [A   @A›F&ÿ 3û&öI“Å2kÿ*‰dU:ÂG³ô©Û€ÃgŸô¢XõËİ>1m,rg€AAØ^;à>M@   ğ   :A›f&ÿ 3Õe¤f‘;f[y¾|!*jÇÂ2åû7Å¨6– Å½“=«‹ÿ_şªt®ÿ    Ñ   8A›†$ÿ  ›J›ı– ß±õZ°¡ıÈŸòšÕw'Rç©€ğ¨Ñt(ıøÄN"p£FÈ    'A›¦$ÿ šÙó8&Ë«–ª‘Ä8Œ¾	…Œ¨³<¶»    ¢   !A›Æ$ÿ ™°A	²é”*rkAy]@   0a   4A›æ+ÿ ˜ºB¦ÜX/g¡®â!N6yI6édqHî5­ 2Ô×5N›ÅZöš  œ   BAš$ÿ ˆT?ˆ2g,j{²€{¨+'½2C«êÊû
·—Æ‚¹,ƒ[C£/ÂÆÍlÎØ¿×Ë    Y@   3Aš&+ÿ Ç½aéªMƒK!)ğæëSaN›(®@PµØ¿¬l¿›À 
¨0¯(á   øAšF+ÿ 	‰¯æÉzúì±obÿ‘Ğ}Ä¨<ÆdSëÉ¸Æ$òáºÁ8À5İ+nôt—(Maˆ¶œÑrglÛ6ñŠAå“Qëé Ó“‚·,‚ã8(òúëLX€Tñ)‘KëeGNËÔ·7QDbŒ¡
ŞöàÔã+å©•€PN²·¸ÜÖK¬ $–˜ğË‰p^01ŠŠp”É«)g@r'á.…j¨d’U •r!‚‚¦?¡º®Æ7³Šƒ0gs:3×€$Ú ƒµMañYGsÚ¥0   ~ÄııÛn¼G˜–/rcp…wÄÑ¥DÚö¹Øjÿ÷-$Ğ   ÎAšf+ÿ 	İöª-sL–gv¤™ÚB»Wß.ÚñÔ½HyĞ°4¨>Í(Yı(ŸÇ™AR‡÷‡Ç¨"y÷]¿Ë¹<YHe,Om%°&ådõfÖ3Ã¿¥±|°Ö*—e
C¡×6‘÷(,«£,TQ'bœS2[4/.ÇŒ³
Ô“\¢ıè[×ÿèy˜áğ1\Pı4k¥7DdBfàÛÙ©î#ê‚»JJ¸·ÓfÅ³H³Ïy;xËéæÖwÚ    cÁ   xAš†+ÿ ±n G8ôE¤H£lO\¬a&ÏoBÎQO!æ:ïh_ñDãd¹ù¹Êu Â Sbà9<ç]ğ÷Yr†ù¸°/U.'ß9Švñf&û¯]üï°lëCGr-1tÓæWy*Pøkl‰N       Aš¦+ÿ 	Û¢®4¥nkç“kšŠ"MEp#è	¦„—¯=š¿Î#Óöa)õLyÉkc=É«©›WL†J«~Ë±	¯1<:™oú1è;r›0D_KÁmÃˆxâMÿ‘Ô.~à!ßûA:ÜŞ$z/ Í(]AÙR¹Ú    =ä1m9   ŒAšÆ$ÿ Ú{V—t›öğ Ç;ª¨¦r¨À(L„†º>cijº´±c }07»¿ôfIµd*Ğ_S°"|*xŞèá`:"Ğ	aRc`ÔºJS)˜ÖñGMF+w¤ Äp“°'£|f„uz«tElÿPZê0¹çÁÏ•¦œ•XÀ   "a  ­Ašæ+ÿ ™W¿z÷±	,òJ‰3¢Vİt2Üÿ>?Ï"LD‰
ÕÿÕ”¯-íK“>='àˆÖ¤†Ùzg¡v©kƒsÚ®F»XÍ-×rÔOxÕÏ°p:¼VÄRæ‹#IMå8Q‡¿ñGãóÁõşW 
M—8¾/úDWvkfYŞq›©>…,.¡shaéÜÃ£_°­¹ÉïÓE:n0;Û!“×™†g§ÌÁ»ñ3ÚG¾ÀújÅàœ?÷peWËÔËnà¾ø˜¾„ıIUÆâ¶}°¯J*[MOhÃp0n‰y+k?eï„tÿbŠÔJÇRá07‰’¥;@º‰è‚|g…2•”;‰Ö­>9r*œ¥?o˜
éfø&‡&F6µS–j4ôxó‚Ê48âço-è;ûøŒ\”×h8óÆ& ÙwŸ­Ğ;P<FâúíºBÆ×éÛ³â+RY£PÈááOA´‚•Oöä.iaßşğdYFÓÔõA k–_-ò¡×÷Ş¿½ÙåW«ßrmÍ¿şÓ€!Ï›Rêv\§2@ÎgM2NšÄ«´¡Õxnö(ı²Ş§˜|¿<Şk“Ãm™73RÍúrps¡úQ‘z€W«dBW;(^ wV'Œ&S­G	åÆ±%{,©L"Û‹tó×\¨"|Æüà”ó› EB İÕáÁoˆìVrê_b¸ywìNhÈğÜŒEîÒd©^­¨ÉuLFãìõ¨“/SõÅµ:o{´¯\Å’D©Í8Q…sÙr!¬şjŸ$è¿Ì1lÏ-Û7Üˆ¼é°†à|şúQ ÅLüï	CÜ%Ø€NOC¡¯(íòmÏ]"}1Œ>ĞvoÚ®7õÃA°²Ãc{ø€Ğü'¨° «”^lv•í8«Æ?–€¼2$éÉYlk EµÉsGo!h±³èÒfyN ”=ìê_,ÏOÿ÷ù~½=;AÙ–„œ§hGêÜë_¦ ¼¸R ª£1dyjõâ'ÃbúËrSˆCN»ïŸJisş¿FÒc’ôx1Ü–nàxC«|ÎÀµ;l"rê~ÁŞÆwäÌ.‹@ *8N«˜fÖ¶y¥CÄÈºf½ÙC5w£‚O~Í^"WáÀ¥{­S·9‹Òs³«:`:—ŸBş’ÓÒ¹Ç£gU/ƒøœâÁ%¢æTw<ÎeJÊÂƒ‡Šá„<Io¥!¼³„Å³zûHêO™‰ñw³ÔğjÇÛ)±zniÖeq|l>##Óä•W§#ğ’rta¸t\´^†«NX{ì"Î,Øğ9(/sJBÓJK8™Îb3BHu¶^@°s¢E<ògê¬ÑËâï“i™…v€IêN,8†uª¤ü ²ÃCd¦JCxù3â{Ã –=Ê&Évp	¢ÂL€5ÙÇ»Z—ş{¶ Ñõç›G§­¯+ÉGâÅØøşùÌG¢®¤P´å¦_ÚM£Ó…×®<ÕJVQ"µ×ÃŠåĞÏªôü$"!úII§-½òÜe/§tÅ("    TÁ   ŒA›$ÿ æ_½~i>FÌ¨ÛZhçñ vq«(e+Qš`›’ßÔYyG@ê%ğ–€º:Ø– H5¸í”É’ş-oGëdïQœJC‹‘¿#!QÊòv-¤^×È26¾Í7àJd_JÙk÷6¤Ÿ?è€â
Õ%Jµÿ©n„=I#¢´¾ˆQà®©   »   9A›F&ÿ 	´¾mßĞRa$E'¶ÿ­@4¥G£)‚Ë²'O˜Âr‹ŒWh„×0ÔKXâ@€    ÿ   XA›f&ÿ 	´¾IÏé@t¼îæé—Ö\ù²÷öo­äŠ«ú¨QÑ5ŸG%?å¶rºØİŸBñ|çë@ˆnÔĞjõ
„Îa~µ¤z<Ëé“SÊÒ€   g   ]A›†$ÿ æ;²)4”á²Uô#xõ¶@çjÃüöU—*-BrïHœ¡Ğ¾å-+
õsA§#—ÿ?_9~8â.|ìï¶(Ê&ºEMFq„FÑ     ‹€   –A›¦&ÿ 	Ÿ×˜j$™-,Úó4•÷`*ñåï¢`µw¬O›>ã3…E•\×w¡Éån1æcâk5|Õ'A?ŒÁ„¥²Jy([ã}oU$cßˆÅ[‡Ìi³İ³Ğ¨BÒv…óUÓ{à‚d*Ê¿Š²-s*Zß¼’ş›"™–dæ/{]‹kgàrğ¥ ú(¦à   N  ÊA›Æ&ÿ 	˜ß!‰r·š‘¼ÔïÆ3!BcıŠm5p„ÚÔ†Ÿo”¤ì:±ÀÚ‡’ç\*÷€eÉ:ô™ßDá‡™JaÀ=ÁG(£Ô(À_ĞlÅU¶cÂ+rÙ§/v’j­ñ/ÜšàïñUíÓ ¿»g.&ĞÁeı<iºã!@y… Üå`O@JW›â¸6†ÈÑ²0´¡éA¬Ü»aç_öÿD$~•áÛêJË$¬Œãˆ[îTÑk€µ›×*‰Gx˜[ÃR‘Ã“•t!‚õ„S»»âA2< sƒ†ÇD†‚0X?£wú¶­0rÉ¸âV>UÏ+§aweªƒR$«pL±ŸWCËaë3Çy²õ>–eşë<ø=ìÈyÜÄ§Jx	.º-I,éœmlÙyu]Q¯GR˜-¸Öˆco”ºOÒàã¹>ºú?C#æÂ×ßÖlOëÔ@^Ä8ãÃYjo¸ZfŠ¨Ğq—²Pê
ĞŞJÈ±¥dşC|ö>Wã";Q;+7p³»Ä‰¹õüAJâ†å’¨@@š2f9cm©;õYCÚAº;uÔ¿«_‰Jˆ   M   ŠA›æ$ÿ ×?õ=)‘A¨uİáŸ$Ù‰`§<Êúúm×¤:|yWüÉ]jÓ_ŠB;ÜõĞ^mn¸Qı$Œ²´§©?©)q}uNÓ ù8í êä–FÄ´ä-~mš`UºzßüÀ³wÛ20¨u+c{´ï¶T"ÄÂ”¡VÂÄ    	9   eAš&ÿ H Ê1à$–£è5»L¹¥c‘n¥,ßóïgçWhíÁ~Ä"†aô±‡P,
ì#A„×(OóØx­äí	;Ä3Ÿ}÷º„‰x¦ÈXøEïÀ&éÛ_|ùø    ÿ   tAš&&ÿ 	Xı	¦µïñİšiLÆthoA* <Çš>ªâ:É| áHd¹E9p–[9Ä€H½ÁrÔ yv8òq%ª\&eú²ş1¦û¹œó>LÅ8F3¼¸’²˜
Ğ³äğlÀ¦3Ñœ †(      hAšF&ÿ ÿ}êàÆDaòX¾ùs.#G«lïW[å’‡›ôµÂëd~Ò¼Ë}(ÕŞ¤ó™ƒÇ¦©&>>}rWHcûh˜÷tü#	á¥œë:ˆŠıò¦pv3%Ó;›qré`      bAšf$ÿ ‚Ñ´#nH*êª<Àb^¯ò¢r0~1Ş™Ëë±¯ãÓŠ¼[ûõ<Û5ÙÔxåşMì-İÅ®gŒ!^j×—¾[æ …k¸·çv'‚Ì–j-.?w    ô  êAš†&ÿ ïï‰mA¦øÙµkW£8ƒ2}Ô)|,l‹¸?ugöØ~×‡\L
hÿ>nğˆ_%?4`‡Ô`VÑp„5Ø54»¯û:Şmİñ|m¸…~K$/M¸èê­ 4‰s²€8Ù™—è€#ÃVèï.æ:)ps²‡½D8BR”;aXfóÑğØ+#e
´kÓ†Nå‚ÃğeËÿÎe! ä†5î‰ØÌò H5&Ã†Ê‘Üj»ıÍmr‘Ûó’W‰©>òš&íã£K‡ÓÛ?–aèò&‰ÌÚoæµ;)Tô¼ÙéI<©9FôŒış7~¢â€Y6×ıØ…:93}8¡ p8µ!”l<¸Ğ5dZeÈ4ÿó›r%îÍ¦šÔ!Šáa8óN]˜ª­cÃwg™’’dáR.ÿYMè‡ğê¯ÃÔê„/©Î¡Œİ!®èWFÑ±Pâ 0?[~YZi9ô½-Œ^©ÊÚ‰€atXò§„A•›6‹iîİÁ¦F!ŒÁY±p¬´¬nıZÔ_sè	ÑĞû­d×²½ÅBU*•ŒŸ*”zR0,úÀ”O KìhÅ^õFìZ p2­Èd‚Zx
 Án´ö»•>o?cªÖqÉ­ãvè.Ö¦Wzã$òígMƒ–Co/è˜¿¼_ÂRÆUÊ7ìêÁ3®f¼2ĞZs=Ä!…z0äGDxÕ©†“ómá`¿èÁ)^âáúë¤R™PZQû9Ñ(Í0çv«úJ
}µ«— K·DŸ•³çväğ‰”Hµ¨„&÷ãlƒ5‘¿\œCÃ»F5ÇÿîÔÒÄÃ×¦¶Ôî0Ó§øË§-+q\‘¦‰,Á²~³'sbôq²á•1(øğ½Ä$h¥92t›zK¨öOt@¶Ç'®whLø• İ;ŠIÿÜp§ú]cÜ	€†g¸ÿøÚsK&ßÍ£'YCêZº‚¶LÚb¬ÆL®Ğì¡É‰Š7TFµ+ægû§w–%C¦¥µ¥ÉJU 8€Òaúô(ö}ËÜÒì»o~à#©	jÏKÇJSñ$ÄÁØm½S~ÿ`ÈÄX²÷vG¼í0hEí]ÆuŞiÂ1çiMÿÕ€äÂàn.©ouæôVõ¯k…Ÿñ›o—m)•€¥m‰ÄÎ#_TGHncŠØ}CôPÄ™…ªb¨¸ı-ÉV…|Øİ¾­àÎ|0j»4Õ|‰ƒÚÀ@†üıéõ…õğÂûn{¡®¸â~×®©»S¡Ö•pH~|Oh¬Wòc	[P4n2ê câ[$·Kµ2b4ÑÄ­T®NĞ¥4ÖÃ`Ÿ`)¾·ŞÒ2Å‡êáüá°,Éa\m×–ó„Û÷+Ñ0¹³[ÒCM§pD UÄO¨	`ZÚ4ïtœì¥™%MPçsŒıWœîÁè³Ü«(VÛÒâ]¿Bˆúá¥Õc`	ˆ¢­¿L”Æ?$®Ì­/!QËØi°åCçAö¼jñ{ªÍ›E‹¶äiûıùÂÌ}DDw‚È9#D”¥ğ¦X÷\QÌ§rYûVÈr.ÃU±~…ÏË0V›‚a[9Æ©5Aæ¡¹Ôa€4$}>À4LÚ«84VÒlÃ½zó/H›ñYù(5{¾`>æíñ‘
‡¨1ürK™nê @k€wq*qğ—¶%GD$ïFÀnzA
Şv —tCœ5/œ€?/”(¼·Èn?«|vÈ¤fW³ »†ŠÈnêù£÷çÉI-ÎtÇ&Û:GL¨“ˆÕ…É]åó7IJWvc¦£Ù`(™HDºŠP;fmÅoš£-*µ,³îWë´E¯F.¿~³ù¼±?äÆU)u6gäÄlĞm‘¨§ã±9m¬Q>£õ*Æ³Í€à7Åd£y”õ ©~¾_'ßvuÎĞ@sÀ™h:RphfÔişcì?z©
¹n=]]I•ÁI·æÊ©Ê€Ân\¾–îºJšlª‹fŞı¬aü†pˆôÿıÜnÅ.fz…±Â³âµ¹bú‰„GŠÅ)M610÷¤î‰ÂgA½ù5÷ö"ÔCcbUf³3˜‡å(ÒU«‘KB®·z(‰Ï`½øÖ¤¦%AÊM€9¾¼ä¹ü–f¡ìñ*‡İß‰Ğà…+ ³g:©ñ£æ¤a:Ô]$ÕÍ9±™å±(*iÍÀ6pùû	3G^Ÿ"dtKúâCÓª—Bc™‘ğY„ĞİŸ6Æîˆì•#{´0|ç´+ïzÙÚ!¦]ü+Q;¶§1SÚîR€íƒ$NIÉ‰çŞ¿•/d'Ó€ˆ/¿}>TGıĞ…Üc%ê3'CÄœw¥ñœ(×¶ŠµT%Šj¡'`©×èWÓÊ^¦ñ4ÿãët¾œ/q Ì*o ÄÉšK¶/:”!´é‚İd—Uêjë¥vi™Aş‡ë¤€ÅÔ @úu@¢cõLxÓÆx`±ƒÎlÆKÏÌaimq÷“°™G	HÙôGéè¡Öe}1‡Èˆii40=ÿÑg–Ñ[0“–iõöÏ‡Ü«QÖ}1µÜPõjvJ$B¿O“.h ³ÁÃöo$òú”ß³«RàŸ«T’˜ÑùR9UĞ`@'Š]ee¶7¹¼uJ`ÒÎ¹…‰ûfÄ3MÒsæn] ár·5Wã‘ –Ä~8ËÂ¶öFŞíÍº³<~áÇq÷I¦Ñ¾×ŸÿV}Ñ9°»¹c1tŸù9HhïÑ-é8ut?äUT¬¤Ó
u’};İÆAlŞüµ€Š7Æşj¾U#Öšûef:²¹F…U»ãõÔLµu“lß=Jr^ªu7î=©[ÕZ+ö¦º÷ãM"ŞIQéæöEÛÓ­t0c‹Ì(ùòŠw¸ø ùp£^1>°ÈÏÕ3ÅD'¬é¢‰ÿ{&tµd¹5,]âª:?¥ÔJjÀ‰£İ.™o“¶¬I$  ğ   OAš¦$ÿ ‚Ñ´ 7şj $[úƒ1dÏ?4¤ÍgrÆ±k˜ƒ…OäpÉü6¼OŒj8SÓÿ%„'¼#¾ø³,¿lÈÄs:ÜŒQÛ@ ğ  ÏAšÆ&ÿ vÛï.7+¨p(_By‡!6ñÄÊÆÂ²†•©ÿ –ÃŸæ­ ¾ª ›èl©¸÷W7ZU‚xë·ôßx	É4ÅB·yñnL§ˆˆccùA ‡$	¾‹'­±'øs§Êæ8ÊÍ ‰­ER!j¹¯ePÕõÅšLŒ¨J/ÎcÑp}¤›üg³_Ø6,¾NÈg§YO¾húÔm°É¶² ‰.å}’úB†>É|ŞSsZw¡şWg›<Šº-FŸaºÔ]"8¡pËFîy	b¡èÑ¶Ô™ äÜÇ],b¹£³=å÷½¼¦ò¥>¢ãe<ÁQ7/hG)·_Z?ab«Øø\¡^İ‹s¯ñå±‘¼ñyl·ÂİìBÊA^îDÁM§\—hÕ|Ô“á§Åâª²Cq5¹Ö'#£Û vB¤5’ºÉocØÏ^d^9ÏwB¤o{k2ÌïÉ·åö$÷øÓ76ı!÷\À)+roË®¤æ`ây‹T_›×-£ıJÀ4çµãĞ y	ÉÿÉÖöù±Ñ}Iğ‹€rÎQ®T´ô¦BaYËZ°ü°$ğï‰p7fLËìğÙù!äA6Á×“Â¨@ã;éš´NQµ(ôa
ÙVJ›ARpÑÍm¢ô>Ø³õÇNè£áRb‰Çq)Ş«¶ó}ùDäƒ„çëAAÙòFÕfÍªÂNâ£ø€Ú%7cOzÄ„×àğr‹ò>ÃKr‰œ¹šë˜ª“P8ÃBĞâÈû)¼‚zpQ%·°¦_Öh^ÿÃÚƒÿÑê®+”Pí”.áğšx¦oÑõúB`9 ómäX$£tJµÀYu
à¤vÜë›x>‹Ëîûš†ò]zİq iIB¡ÀÌàŠÜ¯ØÙ7ûÈ«Øí~S“ó¹†À   ¯   ?Ašæ&ÿ 	˜ßÈzi³BO‡VhšÅnª§	äS~-‹È@º;ºJ
®~÷´¢",+e¼Áìê;¶½Ö²   |   5A›$ÿ ×[Ğ­æê.òœàÌE+ˆÏ]5 QıöÁzYzİ.m~7d\~,C    `A   KA›&$ÿ ‘ÌøÉÏîï-ÜVï‰»}ÏÿS¯ˆZ9áBå°BëØğDéT³ëQÆÍÙDï¯ïW“I ùëõT­y„       A›F&ÿ  gYc²Z6Ûæ§â§´Œpâù<    ‹€   A›f&ÿ       ñ  ·A›†+ÿ —”®±Tƒ¿ŠÁ~ÖPôÕP5ÿ§³ïÒCË‚Ş.tÎ°;ÿêçßFŸr3Gó—;¸Ö$Ó¸³mWE¢ı;˜¼Cæ%‡Äµ"£‹+së´Ï§®-zàÿÌşUò˜3’z>J8)¤ªÜÜqõ©·µ˜>iQ¦[ş–è*¥Ã²¾€T¡r	À%N§:º¨¸0úîV&«cN Ë=z#øÖQ¿Ëö!3ù	?A…Öøcª¥„Yˆ?.-‘Í ğV#»&x¤ìsÇî_£YÊW»“©k4%ÙÓ1sÇ§$È¡Ô¢ÕßÛRÔÖœÉ8pKôg„·@Ü0DhÍ—ÆŸHbuYZjceAZGP±ÔÃûÌp~9¬ÚhÊ9^È‰’,²ºà¸ \'Veö<v€®Z[»‚,‹aÿµp3nÁğkĞş´CH7æèŞØ ¾œ8]Œ¶ />˜yñˆ¤íJæ½ÏĞ ZÌ3µÍŒÚÖĞ•Â‘é{¤‡üœÃ¾Úó”qE|Ğüj f8fA4oµòñ[àC¯%{xC¦´÷´–Ü¯A¨}/İ)V[²¶š¶òÁ;YFT”úŸ³ê¿zjzûÅJŞÜæj-ÁÛ Y(ùg	É³<==Ì‡T‘»‰¨^Ü)—$XÃñ¦6¿÷1<ÒWì\µgÀómÖå¶n¸]y0‰¬8«è!zG”JZj½DÛ¼ıŸ°²´!ÛËã§<;ûõí ™?*M'‹TËb,‘ìà‘ÏüÛ7!qTídŒ€Š†š-gl%¼¨ûÇGmê®9¶ŸÆN*¬}]‘0ÕÛ{#æ˜¦g‰eùè–O1 ¦û¾;ô§çäÙB¬%ä·MàÎfh:D9âéAñ—Ù”ñı$i¬}£Ég	ÛíjÛÇ´Py¹´?¬ÿåwLTañ7xöÍÖÕóúõïİ +¨¸À; Î Ô4Ë=T8Gy^#;‚AC\¾â,º ÇZÀa[úÜ¾d“ÆTlŞ{ÙpLJĞì!€Æz F`ÈDó;ÒÎ2ME…^å®6½ò+ºu16Æù†XH xÜ2ÈJ°”	®¬IAyA—ñ¿/ÍÏr]HÎ'~~£ôRÙ×W¡~µû±¡É[]\v-¼åı´%xrhˆUw!‘™LäxÿÆœºÖË€_3Šƒ>njãšïÉtİìı!fØKxÃª9Çb¯Â\ô{ü‡Ö—‚ú†‚­êñcnÔO]Ø*>Áèæ&ïiÎ­ìm>Ò-”¦½æêâc4C%×”ß—Ğ‰TV„ÆïÿÇ/=1mm¡áüù;h²*0OrQ8UôK=î–<­İ@ EO¾Vg£¸9â`K£*côİ®ÃE_…éPYØ=2D²T^Yî)…IÃPz~·§Æ0aLM&c|Ét!IF–üı©ÿR>`J™ö\”¥€ÔŸ½¥	Q;‡UüŒ¢É0JßwâúfÏò  ôÈÄ«×,A›FÿÆ<ĞºsşÒòW.+ä-†´@ş:‹^µö–¸Y¹š:.Í«zó¿ˆcÂbZb®hº¼Y;ãÑ\°1 KªÏğ8I âü3Ê“&´ì>ãAUğµB¹6Ã¬äÇzçô”· ÒU-Dµ*DhLD8¼°FÜ€i²ªİQ”q7l‡R¢:ÅoàaĞ›;ÕÇE›Q|+BùÌ;Òõö–@ ÙáT<-ÕwŞ¬ë„AË‰Bvk\Ncj0\òs^Å )Az·n‹Ç5Q{±
rËä~¤ÕD ~P~Vã³ÌqÍĞ³2MğÈ§¹§ğz%¢ÿ}/tGfÒ.³cwä˜AÎàGmgEÉ·Ü¬ßô1´!z5ÃTŠ3ùÜœıLÒ»òÀqŒ÷ÄíâG6$ê¯ÿ3-İ=ìNXº•¬ı@ê f‘¹Ú[pÃ‘ã@%¯ºæDfŸˆÅM½¤Sâ…-dFÏÊy^•^£^ËûI­mt,~aØms]<ÛQ6_ûšş)„—0‹âCô\ÉXĞàí†È™°Ï‘¤A;“Z§š¶ò>Ì€‚òÈàÖEhf£Pz¿úÎtl$‹y¾ÄLİÄ dÀöKHØ£çÒEÁ»ï«æ‹c-@8‚Ğ—Kv“kK=+ùŸ—±İ’¿ñ°å)÷¬¨A‡‚¨F»F™‘äüô’Ao	†‘!!îì‰c_„mªM6#&—Ü)ıO+lŒ!ì ÄMá÷-ƒFãÓ“ÉëssÎÇ¤ÚPİ]%ø…ˆŠm£àg?o9à#"GLı JkæÏÉ†6”ğ±}™Š*b½’IZGkÍ@Ú[ºdÍ'G¹z(Êñè•®ÃÌ~¼È%@_L]õ-üj¡™o)á°]xUœ{ß"é>xCh*™]OŠæö¡z'V4§ê‹Ê´·È6†…ñ90ÈÅ¹Òå=&\óÿ©ME(
Ğ­ÛEá¸æ2;îw)ã Ş†ÇÙj¶­äxièHÂècpÄM”Û§0@5‘Å³è&İ¨Q·“í®X¢} Êi¿ú†YÆ”#qh°8*q3\vóğË5L®¦¨"f|yˆ@/•	#Û[e„Í9…ÜWæˆr›³ú°ÀÉY§
ûp	m#ÖTõ’b0¦¹ƒP
ádK›x¤V~ÜµşMºøZ>Zg\)|ô„ê5vI1@ğ€d‚Ã£`ÓËÃñ°
W`ÂKôeıÅ±;ı¦K±ø³?ß/Ù1düQ2šW,$³{ÛŠÁ®ÇwÇ`iß¿˜$NKı&X OØLëëÒ¼¶›PÀñİ?ŸèÍØP	×†Lu¾ M#»Ù4’Ñeìå
Æİhã‚Xhï3õ.äàš˜)_-ÿ™ğ-ö_²êÅ7í– ¥  ‡€   aA›¦$ÿ ›³Ê®‘ù Î_¤[åúI-Ùu5WM€à/æoyB'ğ”t|àq@hµ×$sà5	8AkWIâ`¹ª ßå¹GQU3ò¿ú8m,Á¶™NÇ:"Ë’æÔz€  Ÿ   †A›Æ$ÿ  4ªo'.]ºWïE)(_“ÿğ³·ÔTdô'ËE(´|€£6¥öÿ”±çB«ÿ÷,Ç
^‰6ÈT]n Âîo?Ùõ"=N2åĞa&ŞÚ”í“9kG´ˆQz”†[Â¤
o¸/¶×ÏlxåÓ9ƒ—´ÿÊ    ñ   (A›æ$ÿ  3sRlri'Ãû€¦%guTİó$®&ŞÃŞêŒ   Œ   `Aš$ÿ  2ÚN2
²_§h˜şM´›×ÀÀ†N»¡-xñí_ıí! Ô³ ”‚ï¹ -ü[ÕÚ+ôÌ­ÕÁòšl`@¥¨íZw‚ìÈCˆI‰ïsõğ   ^   BAš&$ÿ  0YĞ¨Éó[ÿ ]Š†”õòÏÈi'E³çH>‚÷ˆ€B}46Ç¤»»ÉäVN"?    ‘   ~AšF$ÿ  .GI…°BFLGâĞóx½¾ãav5–òšÊºŸñ©¥ ,ÎƒrÌ}¤µi ê˜:"ƒ©×èÙøá‹>ò`EÕ°á_ß1i'åß˜«4¢¯C4‘.ƒ,q,)ëÄ‰m	çà_€   
˜  ÊAšf$ÿ  {öVQl’½3ôğ²+‘~é¡¿mÚÈeÓvo†2¨üïv',LA†ş*ÚŸ-ÅtxÒìU´%LÎl¨gUú9ªğçv/Ö,üÿs{l s:âÎ~p«µ8¶AÊªhhıs±ïü€ğ+³Q+ 6$¶	×&Ôg3İØ=¬ª	Û 2T7´„ü(ØDZĞ‚V˜¢CÀŠô<gfÎµÎş‹ïõf 5áùÙ€º_éxu‰ˆìÜó‡1¨·¤Ddí4urm]RwÑvsïH^ccS$ìÕ<!±¨a•Š-´}•ÿ@ƒ%:HÛ-"Hq´ÎQâíAµœçV:º$Ä‚UÜÄ4FL8*¼[(à{.á–m­™›İÇipJëì¢M"ÜúÅ‡Ùâ¨    Œ’w«´š°$ô¸ıœ’5¹Å6VÙ†8Ï´g­å%PÀ§"`ZÍ)øôÆ/iNakíœànæg¦·%Iô§ZÈşt¤ÜÎ~	Â¾ää–˜£ôOŸO„ø¥(Ø~i%~`d˜Vs˜	#øit_µH`BnØõWS¼[ÿ\¦EAËPô‡Å£l`ù]ÿºÈpgÊ$†3×`½i![IIìá8ÌÊ¤Ñ”:]®±·ÊÛ’·×‚æd³­È]¨EZ—áJ…Ğ´oë/}ÖSä<­Üjêñ_ª¡¼V5Ù¿‰SS‹¢“3İúğÿãKw>8Ìê[*@1t,	+ÊmbGøÑÕáàzYUg×ÜFML5®êtï»-9éX½È¡íN<JÏáVdúd=Õ—0oBym°)p
ËËSÕ2”OÃd•:0ä¬µÈš‡zTU™PÃiĞ QâAL;Ëãe{Š¥ë6rµõ·0Ú›óùpÛ+©«İ¨+#¢¸Ò˜ÓˆIOLâ{ôCs.w‡^#Ó¢(ˆd*‚¬ÀÌ;^ªqT«ªR£Ïäi5Şu2Àm_ã°H‚ÕÂÍ©åXÈµ%F}ÿ.0‚à@«0 »Oi¦ò Ô)?Â¹Vœ‡­NA7;ññEztÈç#ßÚÄk®İGÈ‰Qsåªgî®¤AûçÈ¾&¦ ôğbsfkÄX)œ©± dyó’T†‘Zf°'#¸(„…ùÀ%[Õ=6A;µéRY4áÑçË¢æ”R@ynĞHçL³ãÕ@›‘Æ£òçj Ÿç*»²vGhiÏ~üŒP/ `\¨}ºÇË¹{ïIÚ:\‚'†Û¶^ƒñµ†‘¹ëj ……×vf>BŸìÎ\úÍeZ}|Lªõy²ãlù½ı+æáS«R\§ç‚5ó*Ùò•^ÌpÄSNˆ2ÿ1ÚtØó—˜“Ã%ÿè4ªï¤y(mMì¢¼0fƒú/ähe44ÃŠTôå¼‘T±˜|oI®uXÏ
W"à´FM’aÂ",$†µ{§p;Ã ù¥vç‡»‘‚Y²ŠªŠ`_µ­”»Úò3E±™dNTeıÜÚê+	¹¶ë³®Õ®+¸¯±§Ák×&ËàBãr”-¥¯8òñˆ„sSÅe7”Ì]{TVé–Hğ¡¿û¬¹Uõ$+ş‰<qÇ¾¨
$¹½è¤Û‹Å´8¦üj²Œè3©D ¬$‚^e$˜yê”‰™©È )‡ôSu\¯	¾ÇÒ²ñ¶’âÿ^­×ÄãÕ±úÀ$kR¾U2»®=ıMæ C¸_€xTc÷Ê»[m YÈ¥
İd[R	WÌëÌÂÂ:YUYûÿ“If·¸k})6ß¨C^Ä¬²F«şªhià–@½âJ7u&½=uèH§÷¬K†¶æåÈ%½$i'Ïh©ÆëÏÙÎ¿`“r–Èıè½\G%Ğ¯ïL	éo}à{éc6z€ó|˜õ²—êš|êUf4tÓî&q   ìAš†$ÿ  .GU`¤ük¨í´M_@Sû®,Rf¿ıq´Á8ˆêÆwİ<¹¶fs0à=_«îHDÌúÂqÈ·Şy._‘é8]¸d -7Æ z*+’‡Ú–ğk.).8º×!®.Ã·C;#IøóycÊg,}7±«ïIõ)$<=]L   ;O¸-Ò!àq¤ır(«~¯ZÍ´<e¼ µ„(¹QAã¥‘Ôı¸‚»¯
(ö¨·YÂ‚fZ+ÀÏ¤ìÁO¬JH+°.ÉI/`Åæ2èÁĞîb<Ô”&˜A´À   uAš¦$ÿ  +@S¿şó§<PİÍwˆ%`Mİd—±>Td§Ç"¿ÅŒû>ô!ş¨.'§Cºd.è_&’!§)pæ.0sEWN÷j\eQ``şØœÕò}$Š§0)”¸v—û   ı¾²ÎRàÁs  AšÆ+ÿ †!÷Ä~îKÁ3†Yä7¦X)Õ‚­+2àß‰Yp` ÍåÔã4R-#¥!kQµVøQñÎ¹¬–FzÚ¶C@m¡«}é}‡.ÿû2ß;áI'ÎÌĞD\ìo=Şš¯Fi³»Z|á_!+š’´AîeBáÇê$¶2Ÿÿ$õödF7C˜TTÖ÷\mÆIcE¦ôyÕ Bb¸§xhlyS–´«¾8äÀ   UÖx’ûL)ényÑÆBb¨^\ûzĞ›¸FÍ0¿Ë·ÏAÎvS‡Ô8DÆÿYöa’gqşŠë×å²4{¬!Œëæ×Ã‡^Ffû5äŸ/YUùÕµS#©û–êSÿŒàş~Ur X©MÓ\o   ]Ašæ$ÿ  +BñvTà€¡ "|¢/M*Ëøª§†éÜNã–5®Õ–šn@†:½l“t#*ƒİ7XAD'oÀ   :ÑE[£’CÀõ‘É,RE]B­²,   jA›$ÿ  +'Ä÷›‡£~Á9ÿ€zfÉü=óÉÇ¥€…%˜xs4Mÿ âıÍXàË.`¶úg4?Bİo²cb±$÷úÔL’A"Bö¬;¥£¶ıŠ@ÂRŸ«á*Z¶O    ±   ƒA›&+ÿ  ˆ½´®UâÄ»@ì…[ÏNÃ%ezÓÎE• ­m÷vi³^‚c.jï‰»‡õKÛ"ıûòXNp†&Z92^×ê;©–¼çü´_—ĞDT,øÕŞİe›t3ŞºÖ“xOh[İ,—ï¬º ‚ê©V«	à   2à   `A›F$ÿ  +#³ØÜ=®Oê~GœÂ¯–r]duŒéót„Hò:”ç‡m·mú~§5Ø	èUV;Ş€©¢ Ş u‹Y+şqCoÑ÷„Nf…è    î€   [A›f+ÿ  ÷Uáãu!?nn€"Î€ÚJ€{
bÉ¾Pu[œùó~yÑI„”4Ş}~%‰Ğ¬Ÿ‘ñêöAÄG’ŒùnV›÷»f¢ 	”7)‚?‚uÄ   å  =A›†+ÿ  BºÁØ"S( Ú¬Ñ¨€áó–»è z3+•í"®].Q6WÚ‚íÆz¬öãFÕÒËa·77™(PèÊX/İóon§Š-%e€äõBhà&¬M7UfoÔÕb@4„SG)7
'Âº3˜lzx®Òü±æ!Z¡“2y¶¤Q¥CcÉã,ù­ø
³|[Mv«O˜¦´nòÍä‰êÀMA^iÊªÅ¤0Ow‚¾}"‚FùXÀ!ÎøÔÈ\úÔç	™Fl[Õ¶÷Ùjò‹9z1Å#43gĞÎ­(ufnO2t¹j—?$™1lı'¨±ºÂ£Ï Ş•ä‘‚â)Â¡¦sË5u9–ÂÉ¸6¡EÁÏ¯,]dù2íˆÈ–µdR»±4l§
UDyòb§±˜–Î oû*ÌV.ˆ#¡z—ú–’îBbW	ã³ìêœ…XRÌŒşÚë_[¯–y\ò5á´\yZ2œõ$íF]r]a± ’­Ã¼ ¶ĞYK?¤.œÑ†:–M(Œ¹z*×EGÿ²ŒĞÙÓ(2i{ÚujKş[R†ƒ,vRGêŠñÔvõ¤Ø&g3 `—9)ĞÏò×oÓÔ5[ŠrÔ¥ÂZ/:FÅ×µÆÒ‚Œ²Ïx&oR;A]ñİ°ÈA·ˆî-	íê|M2jnÛHáhk²GD¤¢Áğ+•ğŞÜ\D÷;û¦‡|è²¬„€  ÙáÊœl>8ç“¢®§Ç9=½–Ùv‚’Èı˜[ÿÄ8Ë•Y²ÓvtêMø„q`aÇ_ëJH“ÔˆşÛhÍ5 ÃUå«¨@v÷J·"ÌüµÔ…k\PÈ×ş®c9—Xß"DŸıOz‚—H¶3»¹:¥‡3†ˆfÙ!ººIõjõMz`<\÷\µt‡¥‹5ŠVFH2º›†ú]Æ$Yƒ]×…“Åî.ªßTô%2g§ı
´iÛ®;‡?¤²¯£¿o¤©?1¶şEÿŸòíØ©=©a{ß¬œ'iQ¯ªñå;ï]Ã'DâÒğ™Ú½–ªd+’’º¹'@îÓæ.ã™ç&øÓ‚{mÁ­Bd,ñú×q¥Q,Qş­¨Ú~ñÜUë#óJ¬á¥B].£h(’¬sÈ*ænzÙUÃ¢f¸Kxªí´,+^:ÖA¿æø´ºìWP\Õ--ïÿ$)ráŸ|g¢fµpÁúdÎ£÷¿Šôƒ#‹UÃC93$SC§gv´êgLŠÄĞ(œÔ“ùVĞS·İ¢zz§ê§Gx=KÖ}ÌÙ-Y„õçíıòÃYá^Ã±:µôáıf2€	¯Ú(açÊ$JÏõÈl<9ÛLJK¾ÜİIiÎ_[0ZvŞ,¼ïW(Ï¼Ñ§»ã „¼ˆ¿»NÜÖh|µPX_bM3ª
{LmYëµ›ä¸;MKÁwpıö^n
ùp5}ÆP¦@Ñ¼i1†´ê1òa0ßDç5íÛqyXwŒ/”v}ëZióu½'Û¨¶8rØıd´)*ã>òF4ÇVŞ—=[Ê„°ÌàÜÆ`â! wÿ%¤nPÿ­iVÖ=ÀìÖ’,èáW>ÍæÚ:wfÍ#¯J@ì“ñâüWI+”oX£I/<úm	\ñ	“îX,'Îé ŠÀe¿—ì­İD,}Â4˜»g ÒˆË‘ºÄFöxT¥ìº×²š£úìíŒæ!ËäåÑEcn“¥.‡¿R`õo&E¥ez2Šf×a™gRéöYÛºK×bŞ­yğ3ıPpW—Ç’ÄòÇV±ã²Ænü¯2±b‰ÈÑ!HöKu®Áÿÿ¹ÂŒßÊÌ‰œÂå¼„7ÈÁk–e«SÚ«dâÒÛ-;1×š*ÄÚ& •ÉÃFÑØÍGÛQRpf‡ÚeyÊ#_£x@¡‡2æP‹§L­J	ö€˜Æ5êß}}}R\åô5Æ¿›'ˆ.wÉ\Î«!KŠËqJª>˜Ÿ1ĞªŠÚ&É.ôJ°è_AÚšü’²#ò7Åº¼Å\Më04ëêïq—©   ’A›¦?  
Ä
Ÿˆh­Å]ğ¦é¢}obmS1wëJ[9 òs   b_k]ÂDÖAéğè1¿o^y¾Â«”/ïäù"y”T4Æ5Şµ¡Æı¦¶õôušnaÕÙë4qŸ‡Y6¯;«nŞP¡Ÿá;6Û–¦õÍ²úaˆ?4L2“àq-†|()ËŒ@   {A›Æ+ÿ  ¶ÅVù^üŞo’q“è3C0ƒl?4}Ç3ïH	ºqòÀ‡q j+oV2:?Øt_ToA1E ¶î¯Hº¹5º^%Ëá-†à1äÅ~<*lÌ«æ Ù²xÅLåÓã€  O˜r.Ô“Yß-‚rËæ%6ï   A›æ+ÿ       &\¯skY   HAš&?  TO,ÓÁ>2’qĞ:ÎÙÜ÷ããİ‰8üã¬Ît€S˜’Æáy]’ÛMøãÃBËIÙò8$   ,   AšF?       ‚   Ašf/ÿ        ©   ¬Aš†+ÿ  ë¾ñŒ/ÒÌy NÍ‹ÒÙ¢-OÖc%h¦`ò”ÑÂ-o‰÷4!?‹24½:#¿bñnêï)ËÊú¬)àªÁ/k"PìÇí®‰]<ñ‹ìÒ°Ÿ¾ÒBHs#†@Í×Â^rJ8nLÿä;Y=Úè,whU¸‡Œ2^áéÅ-Ìmìï—ÓÌW#7¹wùev›‹êôó¦ŠCÀ^"81¥;º±€   :`   gM@4ÚCäˆ„     @<`Ê€   hïÈ  ?„eˆ‚ÿê#”	NfÎmÂlËî¼-«ß÷Yø`º=]¡ÏØ|Ç¥@˜ >ÓEÎ«ÈH;¤²ñ½ ØÚ)oÕì˜µ\8IŸõaÈYád—G²ôe)Xñ³´¿òº íÍ’æ­/¶µÕ8W–Ù7!ğ4ÔÁ=Šµy:%¶ú›d‚OkÊnÅóñÂt‚#Ò
|´=¹o«LC¸'/{ÌOĞ¡cG·d¹c‚UÉ£N¸åKÄï¸à](9û_HäN†	E¼ÓÃ‚:}ç-…‚èö–G”wç–@ß¬æÖîœÇ¾éÖO®Œ~:-X‹·8Q‡vá!ú ^’ga…mXÊÖ˜¼7ó›ß'ëjŠãï©+VT0ãöò‹Ã-6mÆçK¯rr{"ÂÆŸCÿïª?m<¡­ùé£ÕAÙÚŸuÖC›µ,‚ÿÊ¶¬¤s QŞkÊlğˆª€ğw‘È.Ì=õutÍH¼“T·y°!û%²yê¿â’xlå±/Ğ…µ¥T|’Á¶wu„gÎ1ÿÏ^ßä[ñ§³˜‘•®3úy›WìlK`=cùGKä±xQ³‡z;Ú$Út18õkÜ,É(dô§-Š´TS£}PÓîÓï§¥ôÜ«ŠÈ4ô„^£‚÷Ò³]j«÷Q0@"4±ĞıÖµOFŒTö]‹i”öÑÂ3ß¡¨ŠŞÙ‰QùîÖ!U4İ/?íP2+¶ÅŒ¶yi_á}I½£š÷6P:» RåØ O9Ü©\-nEI¤-FŞ4øCsfÓò7u	ˆoÈÚ“¼cÈßt‘°•H-şP®2E¯§”yE!ÇÏJœÛ\*BCÌ˜rşŞ{Æÿ8\©‰ĞEÇ>K9R‘/÷   .3îZ»Ù]ÑŞO—|k7ÈšÀk”Fq^„a°²kr¾[,ßİ“xAï$eÙÚÒÃìM^ca·ê;¼0¶-ÆšdR&¢H9‘€­K'ãáEŸlA¼+•y=ñ±ıÅ fÓ~µê}™²nÁ§£~«ó­A®õZéLOãc…ˆŸ¹2ø%~Õ˜–™\ĞÌŠó[hÓYÙÜ¿Ôw™£bƒ<:§§Öô«"p!Usü­O©	VmáOxqOc®Qcp“4áÚĞ?Ô	Ûˆ¿Ã5ªÔ`É:8I5²†ÉüÏ³ ìwè — ëûÑéÈg­-Qs-?¾“pïÒ©îGj+NP&èK¹½ö’±¬`T³™jşhú&Iw~k?°ljÅøŸÀbú‡%(¶ş—E‚7NàßnÂ”_üÕkÊÒHŠU"+z\²Q_1¨éñ@£eÂzıvë¤Ë€FIÏ&YÀäĞlÕ9§ÍÅœ® 9§ê&L­fM¿¾3Ú´‹ä|Qşutôr¥ŸŠÌ:!QİdA./CcM-A‚¬Û¢^ Å…AÚU•TTDæC#ÆE¬ÁsÎ×Î¢¶Ûa¶@_¡†ŸclÖAúşû<-îY§3èCD%o™~	@Æ	¶T³•«
û½$«¾°jW(Ó-íÖ4YpY/µ gÜ¯Á'O½¥…!o71ÈíºdÕÄ‚Ô›®[êÿÜÂJ’Ï"Ä„¡Hwœz¸ÄÆ*=h-ûŠ§‘y7^¶2`²ÓLW jüİ™ÛY•:WænÈJbQwÚ2øäôju×¦fGÅå]Ş©mÒæõaÓ·¶ŞÿÂÏó4ùÒÙÍÒLùÍ¤†»%%ı…rìÀÈÎ(­ªÌarìÛ¿„~{'5|b€  _…8ŸnR7‹¦`éåÙÕ÷<PËnl¾&¨ ØèĞô$6¨zõÇ^¸°¶gjXë Î'2¥,Ô3Ö€dİßƒqa~È‹ôlú…±äInn6Şã˜èHÖœndH9”áyí†¡Ã÷ íËÏÆ>îAÈÆ¾û«¥yNl|RîMó[9!Ù‚Ÿµå”åb)·/ì ön39¢ ï>8çô#¦„\;ƒmø÷pô‹¥€N´nÃ£·ïb¨ÓFíÙ†¤_‘,á…¹· b²VÓ
í=ş€ê"µëiùJ„âÇUŒ]ñ›÷Ë§ëf,Vè vç¿äó¤ì¼ì`KŠcÌØuÿ£íÅmÓrÏ’Ä?\ ¨
Ûi­’¿)go¿œ=ËYß“¬’bk‡™Y]Æo8É…¾İ®[(j¥ëÉbp<ÑÄ{~ÏjKËÙ2 :±MòïFİèıÏñœ?Ù~•€³IÏ¿Ò˜ Ë^Ş<"z~®H6œfÃHÄK2Ú€Y0Æ}¼öSü†A8ı)c;ÈĞ{éhXùˆTF‡2=ŞĞF<±Äôq$.ü®zÂW¥ÚçûÎ‘§Z‚UêStTGÑ¯^N°2m½DâÙ5N™†gà±w#4Æ¾xóÙOwvèáLğLÀº ŒHtÖ°Tk–c^ê‘à\Èµ!ãÊ-TªA¥§yj)DY?¾ª9¥€IáÏı-™¾.;åo¬Xe<’sÑ–$º;Ğ¡*ğ6Òà
ÔÊ@ßo:ˆÍ\ùƒã£ÂHH•—ÇĞ3ÀÆ?sşíHé+Vu1Gª:Êtæû»şï²*Ñz¬_íÄ2phâ
GªPpè…ÿ l%ş”œû›ßÊ£vQş¯¸´*³>Ôğ5õ8„BÏ}§mÖ¦M¬ŒfZÚ1!ÿú³†Péî¹0ı`°4­B<¯¦08w‚>“ı+lnŸØ®ä›F‚ªô—†0·L0Í"£$íÔ)Œ^Û{ÌCd«YÿĞ,TvÀÅ–Aéj—¦ïƒ¼Yh¾³M/#ª’ë~«‚J£YU#ÑˆQ·x ëÍzåÖ—´oşË(ÛÓ›Şš8+¨V05".½æO	÷¤ş«Ca™¾êÂ†÷‚±±!®x	2umrxR­jWŞğí§j5À¡€û^®ŸWáÑ™Ëcx÷!Çı‰£…OK=İikX—c…Ièœ‰Œ‰œC7İÀ İ,Ú;HĞ?jìœı™†¹[ş¡¹Àíæ«¤M—Şps"zÈçïŸïñD)êTdÄ;YÍZ|U*Àg-©ÆV?DåO€—h(¼Äa}ÏñÁÿ×m¢²ıİúŒ :Ÿÿÿı ú€Û|)Z Ù\?8×?z+9rb  #ÀÜƒ=ÆEEö|”¿ÄV¬mìyöåè.¥ˆ\5D„Oùt§Ğ»’+‰8åF»8‡s ;óùAº¤¹qåM¿.˜XêS4–}bÅ/î|_Ã³æ ÕBaÇŞ4\ªĞXj\Zô  $ ƒæ+ğ¸%RkåGğ ¯––…PŒG&ù¤­)†yí¾€ñ5Vzd¹L1’ƒ…ıÈÆß‘o¤k£%ÁôIŸT @µ7@²8/TXTZ^ÏQÌ÷Â÷ó?·0|„÷'¸ê&:¤í\•6Á©òŞª 6›Úñk­R
=Í”F0¬l8ÙdÓ,(Ş‚£WpÎ4Ğ5mÙv
’÷ò =ÖÈÑÎåÿÿniD8¶}úıRWâ'‡–ß6|nzP­™Ê¸Ì.nvhú&>ÄŞÊ‰şÆo(—ƒí`ı~oµŞûÊ=ctehØf’ìª4q´ıõLä*W|‘¢‚w/s£wr@[¶<âX5’xÉ^ÔT±¹Ÿ¬EÃ5Jp#ğ	G9¾Ï¼IÂ$}Z¼h±†ÒU`Ê€T¿ê„\ˆXƒù•øµË¯š€7!gËÄ<¿ó@YÉåœ7ñë¤ÉİŒi—½Ö>–êĞU$=Õ’ÓÔK¢‚ˆÎ–è¾W%ï¾.x{Áı—,‰	N{İ¬X›±éäÛ÷Ú¯©¾js³mÙGÂ‰CØL/!kÃºóÄgFN‡s@	ôİ~Ê-ÏFê¦˜ şÿ—"mVCwÿ6a”¢,ùC+ïº'8š•á•&.ïM¿dËLZÖ#+Ó æs£PR•æö£•ºH¾víîRÖL©tr”¾Ó\ö´)xè‘á88lã¼>cu'È‹æ•Õ7œô(ô£†rVÑjŒïîÔÖ£õ]§öï\Lsµ%øã–ávíù•çæ©q©a§ÄİÔ»70yuç›UxùxíÊãm"Õ‚“Îrtİ™MQ‰kÓÇÀÔÁ¼Ti ¾gµ2óˆšl³—v§ÖäT`¬†tÒ¢>+»‘ª‚RŸô²î Ø,X‰ÑĞ«¤g@Róÿß.eB_ÚZ‘ƒÚ›ñ¥DU}ú¼"ø7~oÁ¨éh›fdâ‰‹+ºŒh†˜1ü…•-¿F—D-o¢Ü¶#
´À©©E~JÁöºT\/ö†C
É¨|:ˆ
è©kú­Ü»‚ğöIB#ÙíwÕ:Z-½oğ=]ÿ®Èó°Œdµt£T}/Å³\åM_áÄt&|ãh~&®è¹a—;rg~h¸ñ…WlOß=íû2ØòÄèCÊæ=çHÛDJ›Í¹oÖ,z)¯şj ÿ"ÑmH7ùX/²E9‹úbv6ú0Ä*ŒûÜ¿×>’&Üú»ôv‰š}™¨üNå¬sÜA™5…%á„x‰§æ®­¾"ŸÍàü7D”p¢ 24ÅKpÇZY€¬¶É‘dÛÑ¤aNF3"Ÿë-Úøû#Ó­\´q¿Ó°Do1`ˆdQO£ÍYß£ªr”Ä«ˆì¸B—|xÓïJşÙĞÂ4¦ÒR¹D«"îGõÊuVÍ\³I’ºbiÆ£‡ÿ¬gÿğ*‹ÖƒÂ1k¾P#+àÀ¿åmY¶âë³#ß>c˜=éË.»ïß­0ÌûB*%õMñ<=BCÁˆŒÒÎ0şrQ‘×êe?&€ŸËÂpIißÙL„‘YZobƒ"ê¸Cö¨ƒwr›Zµ¥Óù ÀÒB!°yO¾Ë9ïùoR_(¬ï¹e
nuiàµ´–UéE”Z,:–näğ¿ÄŸQ¶r|@7È£Dù>kN%}UƒIûŞ~3ŠqF1xôVáyÀÔíJ<ó4»àŞï‡Â²ØÃ ÿï²<Q'‡ÑK<ÅìL¯ùµ=öIÏJëª»S!ÄáövfX?,¦­úMœnË/Ù‹»!¨³GI„Uf(	"pÀÀ·6ı#vAº©WæD™àw7 i»Œ&cÅ7_§pÔŸK,ÏÇQ@å'½WºÌS²ĞJóöë’jõâq†ùÕ½–³0é¨ z¿‘HVäêdvâoçAÒZ8 ·í7¹İ•ÌCc¾ê<¥İ\ˆêhü”¬ÌmwPÚ¥Ãgîhœ÷™`¯fT€·i@*/,ÏEÁìO!¹‘D,éy\ª)EÕš1$¾ÊÓO—¶còDLİ\D8—µ€âj†`ÿbšCj³ë„ã”ÌÎn”Æ1¿îJ9E‡ë1ñNØÌŠ),$±­¾‰=¼¾@À-Ùn¤#ßdú÷OßÃêÀâ`¢éÆšWgĞ¡ï’Äexä7 7‚-Ğu[·ËÜieû>vìÅxKµ–q‘Õy
Cc©%Òõ§\fåİ÷œE&Ê§héh¦BŸVâh#`YÈøâq£ã¶QÛ²†ù;Ä{ûìq´œ4umu`œß8j1üÚÚi'å…Šs–äÁmO&{†*U6×ÉœVdR)½(v!÷µø¶[#ÊqG•£¡	x<\¯ÂFÏäúšŞ¸°¶@]æ—µ
v]É÷­Ó5a<TªÂšu’©I´6çô*$	>Ó¦h™(dW4âQpÖ—ŠÂ~ñ¢NYòëLÄ¶~,fÑª“†bxçªz—¹qñÔùÇ#"Ü`Û¤´É¿Ï”-¢b:ÖhU#mt9ª‹Ç½o„Û-ÍÌ/Xÿ™t¾¢Ÿ[dİîq÷Ñï/¨Ğ›H.ÿù÷<W\³nMwíÿ¾j$Åùg^ª©]¯T›Š*uqrçuc&ãDÃM²$zDš%áh{+P÷¯šts_®ì™¤`ùVØõfW÷*ªjh«üòUsŒ¥´ë=·Ä_ìÉ­-äş,¾lƒG<ĞÌy}Ïo®éó¾\)çü*úØ–¿6ğ\h!
T{-ğY—ËwJ½ (Íæ¹yœóãô]-]•Ù/baR0 gĞÌÖï[‚kÆXÈ5×ÁÛ©Ëz©9§[PÜÛtó[ZªÅuF„O
i‘L¦KfÚsÈŞúE9Î0]r,g~äíøpØ3Wº:ø}ãÁNSH~³Rÿè7œ?ˆó“·efDW$TP‚m!4@ş…g^‡n‹7Ğ$`‚å© ²¹“~¤ºMYV'›•EÂ»“ÉıâûÓSrcr~é_Gâ?ˆI%¸Ş5ü	w‘6TÃˆNÉ‰Í©1Ğ¬Ë¯mgÑI^9UçˆaĞ2À¤‡Cğ¨QóÖ7Í“C/¿ÄÆ£dw„zrv= ÀÃ5“6•Ñ©=ÌÃÜw5i\jfÂ6NKúCõT‰™@8?>õ´<nÊ@êY€ïùœoœ@ê8"êß
>pìØt–£°ç„Ş²ãnZìNî…òöİ¶¯è„yãXEW‰Y×§Î‹Ug7Õ{]Üî2pëû­œ™6Ï7°»©˜ÒJiY¶cI	Ùn{l&´ºQB‡ÃxAêÄ—ß&š{GŸtBéşh·KØó(N§:©ëßøWøX^D9Pƒ>æ7`Ö±œ…—Ëì-­‚F³PV’ç£#¢oˆ'Ó†g»¾×¹Y{k~7~6é æ@ëUjTrÀò„1 Ğ¤\k*ÿTˆ€„Ÿı‘2¶œ
cÿC.i0õÖsË|6SrLú9¼„`×€ğşDHÍÆ±ÖøŸIş¼İA+µ6Õa›cá£ÿš•·Ãèõqå&§>Kè\y=~ê™–ˆp‘ì‰{\ÁH\#êI 'Ü°¯•s‘\fC‹tZÄ‰¿*Æ8ÈÏè‰p@®ÿì¼š—ºÊüÅ™8Òƒ­a†`!?Ş€zògWïgĞó‚^~\;Íài˜äxá‡ÅØBaƒdèç×è¤Ã¯dœ?Ö.R_?fÁLÄÇ/©®l"Ãê«ó•cyà‚,ÔÄPÓ˜E•Y¸ÌÌàì”ï•§h}¬)„®fısB[aA‰“ëTñqë:šRbÏÜKQ.KòÊ›. Øù&V6kŞ¼‚-~6árVBËt|2æ€¦=pu¯¢& º€']cª¬2‹¤àz-É°û<kĞŞÉŞÌV\=yš3œwV<+ş‘6x›=òŸ,ÍÀSáBEmšÚBwÂD¦gƒÌÂ7ß-ÈèaÊ¦¶N¹–o·&C—AhlÒ~êk‚ËÃ…¨•%­3T!ùìrÛ©à¢ÿ}J¿íŸ÷{rœÄ©Á¯³z4òç%;nÇ]{“W[H¥H#V¾ˆ!œıCåGiı	q¾PÄ~öÄ$]îÁ0ÇFäDı£œKmş…båäRäŞt¡Şh~¾òÂ‚B“ƒË€Óœ9-«L=ºVhbyr]"7ã¹hş¶¡Mº|Å@“jVá$úŒº¸–*nÑÍÿxøïàöS&œ)do¹.w]¬ù~wôÕˆjåÇıÀ­uÖÒ<²´à¹+VÍ·.¿Âà§c\¿FV¾Y¸˜[*16Şùòf=ZÅ6NçÈ7&Oï?†IİÛ\9(‰şª·©ñˆõz^§3P³d5…u!4ì|Ï¦B­ävßÿù¢Ñ¢-Ñ£{ÆV½à/Ş	Éò#ÚÅLî®ğrqijcÿ¼4½Zg]	ÃU]ô(Ã™CrïÀ½‘ÎA‹Y÷rÀj~x(Î5t,$ËÏ¯¥¿@ŠÀù<ù'8*ğWÃåõÑ·íôÁpw³<aš99LU<âŸgäˆ_ù6z‰1ßLæ¦ĞâaE³A¸ÆÜpıM¤q§¹núêèî?ÿZˆÕMô,ÂğÇÒzğ‚¨\ú^æV‡ÆÍƒş1SG= ¸\ˆ‰0@<4ß2'Vˆ ¼Ù:–5ÊPeäG¶·æƒasèI¥À*Í-xÕuNîælsÓÒj>ãÿüjÖú5§Ø%S—ÒÜ•Eu%iÑùÖ€F?ôl¶æƒI2ì›Aè:£Im v³M®ü"áú±MÌ³T)µ	³à*Ã®Ä,–Şês·ğIš;PKN +x,¶Üı9rá'h©(†şXİ=PŒqä\q—Å ïÉHÚVÀ³õßd1ÄE‘©õÀWtC&}Í¹¸BÏˆÓ¦,no@™÷™í.çˆ®½á@fíBæ]ªøôÆ„¨tè÷kòSƒ”™m¾SÖs= QA:8N¾™ú}Ö_vDUÏ‡ÛÖèŸv Pƒ¼İ»”—”ù·*o¤É]r¨dÒg"¤6(ç«ä]1ó»Ïo/àıâ¼<Tè±}IÕÑr—±Öw²9(‚7ÿæ”&ÛİXÜİèï«ú^÷b»¤¹–lbˆ¡¦¤å‰^à\Ş´ís_¿w^†PTî¡øáÊ-^vS˜Å5Î/9†{GÂc0½D¨‡jzÖıNÃTİJ¬¥’­¦·æx&±Rñ·zö9ù¢äÖÔÜuH°à}6Á„Ïƒs°Ş™¸qBY¿ìbİ;9*öyaÎ$‚A‘"-!×´ÒW+Á+•9Ìğjk½$J—Œ*87pÖPÇŒÜƒ7C`ş£¡µ—†%hkvp8N>Ë»~„Á=²K:¢e>yú=•ÚC\¼Héo)°Ù\Â’,*S–¤;)Ñ¡«Øn˜Ëá+æc.ıæüc„Pcc–]„X.­ß
©òÈŠiJjÜÛW!ùuœ°÷³ÙáxÙº—…,~Üoú¹ÊGGVosÖz¯zšÌ˜iRi1kş“)›Í‰9ÚgUZ06?Jˆ˜o>iæà©ÒÑ8ñcƒvÍ_ ts¼@{ÄMâ=>ã·ø	Ô µL'ËQÈ†KÒÁ±ôÒl¿ëh÷{TÂ±ì@ÇÖoı°eXm´^‰½™ «rE7d*‰RîLìfnS—£‡Ù"zñ-MÃ HzìD+]•QŞ“ãÚ¹t®KoL.Ş |åç–:ı:hú~ìfœ¡ÇĞ3¢É^PQ‰%ı&|³Ò¬²tŸÿ² ’   P­ç¢©+ò·¤ÈÄ¸â_…bpÒÁf4r€C7q¤'µ,R^>Ò<lX¹=+Ép‡†3‘?"&cdÙİh§Hš#:>ß €0­µYÅ5ĞèæS–ö»¡mYƒòâRJôÚ0÷R÷‹BWw¨ŒÑÁ]ı²/ØÈ^Ä!)±m_ÿù—Î;¾«Ç,‡ïG·9<‘gZªÆ×‘{Z@Ï’:Bµ"cyó¦Ğ¼;Ä[¼¾Ú™µ”O—NC´ô—Hx#ã'}ï=%H;dHKİ+õ½MûµßXİj!ãQ’NIuYóß#´UâùÒóTk¾hé›¸“„Â.ükêšNVS—'ŠêêS‰LşRóÅ[ªL£…€ˆÌi1	"õ…ã8}©2Í{—‘k«gN.CïğÕ‚Õri‡ 'Ö¡…–ÍoÆxt·K!/tõ»K‘çÛò	ì¨ƒõ8Ì‚|¥Š˜û/a7-1J=ÙÁ7š‘3¯ÇÛZ›/›/ºïr®¢™â³}¦òLr;ÊûqÑ¼Šî6¡yAX.ñ4<<ÜhÓH…ŒLPEˆ| ĞGÀzÚÁˆ½çgÎë\×ÃÎN)q·ûsA¿e}{Ìÿôí{>d¾RQoĞ‚µ‚ÖDŠ¶?Ÿ÷æ_C«-È&µî¾î)_ûuGJ  Nü™A(L„´ç¦§½goM>èa$_L•yËŒ¦W‹Ò¸”ŸXŞ©I1Dçæ”h8_Fï»¤ 0HqR,yÍçr§íArnñøÔ°ĞÜâµÈ~í£Ö+ø{aóM*1Fİ â~¾ÎƒkZ‚ÿ{Å\ph:KúYËıÖ±eh“/òh~A½Oô–ªš¹}`(n%í—ğ$`ë˜•”ş7¾$j{¾ˆ“6¿vë°Ô€;H¹ ÷¥¦ 8½’÷™ö] “£†ş+—ê½¸Ë7ÆP›ò¦Ø‡Í×ßó€Mk’½‚+ã/©z=lø¹£H qÿÖ5%yúqlbú'ZtùÑ>çÕÔä\Ø_:È†a¥d‚Õ7Ÿÿÿ1\Æìeí»§åB“|ÅŸI‘1@±„éÖw2°¯¡áÀ03ÀÈö>n''ÉH¯u‡F&ÛªòíH`y³®²‰Ã8)QYóÔ°÷Û ËøAÄ|çÑ-¢Û„Î;IÅB4
†Ó’Íã¸)íñshíTDï\j£ß£Ô%+oR•ï t¾uiY?`İ.cÒîÌKú5¯÷ÖKù-:"ITÛf×x’ĞènÆúM¯´“¤Ü¦¹,¬¢xl¹Æ„dMa¹¤YĞš{Œ%Zs¡Ÿ8|í²éíåĞ¢úC@un+V™ÊOÚ)D2RÂ§E¹p™(¦ÃnRgùMõpoùÜ™w¬7|ôíé5¹ÿõlEïèh¨C5ÜöŞ?±ûòşz¶ÊNB›E­c5Âv¡ÙŒPpĞ=Ùqt­˜Ïr¶E|h –I€™¬Ú"¾ö›Å
GÜí‘¨ºÒX›÷bœ:ĞÄÅÙuE·ş¨3ƒ˜Dä{ğ¶‡[ü·û$ÉÍk‰«Şì–!`PTÓ¢¹;ç¯ï¤ö#g`ˆ¢ĞØ:ÕÑüMhNüâ×x%_ã`´•ñyŠåpWCöšmn‡½#RŠÓ”xJ´dØòTèuøÈ!¥ò?"Õ×²6úëÁ„wAqº<n¿.&Ì5a>CÖ¹ëd>pìû°àÂ¸… £‰kí …Õ;Á@LwYá:Q‘€¸RœÍ¼åi­³¯ÄÌ;a"bQq¿±S—[m9oàÔĞÛù±aRªúó€‰¢†&]5—à´\K|kˆ¾‚&DÃƒÀ›#KD@älázv¬µìŠvppÔın®ilŠ“Ã=I¢¸©à¡Pìº„aÛ_;×y÷‚2–½ÔÔ¼]JÂ1š}¤„—$Ä‹¤Ÿ†ãÍ)z’¶Óåêâ³Ğ£Ç ®o¨mÕèñ„É»ùv¾‘Uj.fÂÊKãB½‚€ )ÅõEÒ9$şÉjk•„ÁQÊ1c}å2zI³ª‰(ÂªeAi~ÇrÓØS+SÙÌe>6ú@vgé„ËñÜ}·§u^TOÒáÿ°ÕŒ<RU7áÇ¥U3í•“û/j!Y•é×ÆÃ®YMEËhAGtlŞÏ~%L³Æ$DX6i¾à¢ÀÌ€Så0Î!2µÏf¹Ç³ğÉ%s-QùŞÕäí#G¸JÕ‰§M±æPŞzD/.ŞÁ*à:qÕ´£´ËşíoÛ¾ÚşÔLĞwØùş<(>ã{5AçÙkÎŒª¯Ø¯sÍæ–ÔÚ@È'³6ñóyjÕl*²8HR+Jµp²Ø´ëµÇ-Å’Ç³ÄÀ½gÁz«Íï‹éJ–MA­Nü¡w*Xò{€×ŞdôH&}"ì?Å{FÜİŠêPHÊtœ4¥íb5¢ĞKN]‹¬Öƒ×ã`37Œ»ïöØø3ËôË…­õŒØ}”;¯†N>Y¨iiËV¦ì÷+1ÿÕÿûRˆ˜òÎ`¹EçÙ<ørYÚGö¾ÇÙÉ\sD0Âè!È.K,[¿Ï-D-üâù	5ï/n‹ên‹GFxî¿‡À>@Jß¶_VÃLÇj®”u<Yæ€1O¯ci"õp—!óPşÖ½ûöZ´†¹SÄ¯ì¤)k„ã¶ÈuÍÚ_©¬-´—õ,p*xÊjƒù^HŒæH§bHy|ÍıÜT2.ãîH6±½eÑÄ¥¢	Õë=-­´ÅÌOºìåñö)bI\LË[Òw[»–íFàæ†9A;¨e÷#‡»]Ç,"Á3rËØ¤FX¶¥­Ìà[ ›äôÕ&S([’‡a:8¿J°+ox·” lQƒÖYWãw­¥ŸH—,Bè2¹”š¸ìËu„›ÿDíô¤C*‚3åöìğB4	=p¡ç’·s2¢³]M‰’ èªô“]D.¹_±ùú®ûÏ³ZU	œ¸X—^Ø&ñ’x N{SœjÏ_‘åA'ÿÿI˜ØT#Æ¦-Ù%SMê¬S„¥„ñ¡Vf*M
ß°´iô£SBÔvrW-Í}ÚÍµdY€J˜@+`/™‘ÛT—"„«¢î>CØ5øØoAÆSØ^Ó9wßz$(Ğç5Å‡(Œ…B«ï„ÀëSw…¦VAqÓcá_´ËF°÷†­d?b‘0'ûCk’æ‰±X¾s&§ª •[HÁ• "V1İMöëv2nôZUùíØ£ŠØbôßì´»ß/íA¹ªµ\
–SVÑî”·»½ğ7ËˆV&PåÊbôé³s[S˜™ò4Î$+üŠ7l³«pÃBBÉ7*O²zÁìy6FÿÎÑ®	kÜÃ4–2‘2ĞÕZÁğJ a­i.¾C
OœËxz å½…êÜ¶Y]Õ¹
PLİi&]¾ğa¶¼|Ú¨ĞÖÈéş;ÛÈŞÇÅ£»F	&cÌs}:ztìTEOk®zëöÀ™ìOkXƒ]ÛŠBSü·¥%œF#iˆÄtM¦Ÿáïÿyw±vâJÎ¨1(ÌZu¶Ï%’Â–’kYRb®†I"¬j¬£ŒIEVØ2áú¼-ñ\€¡Ú¬TåÌ"n’w×ª!*UX3«òÅL­¥Sw0×ñ¸¤òßYbW&ÖàlêMíÂ"4‡ñ‹Î‚@Á_:@I2§úÙßªÕôÁT\ÊJí:°ÍÊ0©êÚ+‡r$¾µL%¸ÕæüRñƒí¿âš¶OrÈEJçïºùó\qÑ^ÀıØxÁGŒ™¦Â³âRº'võE§®ìäf¨õëÃ#š’’vxãÁ‡¹×`ŞEÜÜuBø¸2aÁxÑb!¥œ­4N•ØRLfZ]$I­-(%‰@©‡SÉ;Õ9‡¥)ù%¬“H€¶ÕŸÉ`ÿiÆXÚöl’0W^-mn¸ªT–F*é=a911Ú
î¸uw…ï¹ƒŒ…‹\ÉÏSÄKÊ^Èæå»}KQ`Á†Ù7ûÂ…¦S$©æC)¸¤PdJö€d"xpEÜSW²ª¡Xd–µFƒš¯ì"‘üŠ÷b´ùû¸¸ûµ:ù4;Ù&*I†›ø)nhÄRi®h}Ñ½hcÏhûEÉ‰éÄÆMl·ÙÔLÙWÜ#ªÔÈìšSDç.%éäAuTÇF4Ùù©ôîa"àÁ{½øï¬L(ZL„i-^k<dìÔİÈ  Ø]Ï[†¯µè ¼¯IÌ7Å-AğÙÑØÃS«AyÔJÍöûÖÙdÆY¡6”ì6!/cÕ–Ùıp©ß¯>`~‘Xg@vGH0r.ƒÍúÚ¾©'€hÆĞ‚/ —Â¹LS.öBšpí·²&<Ù{š6‰Òf…›s]£p=m Ó.FÍ™ò­ŞŒG÷„*ì…Qh$BæƒCª¼1²\òÙiÆBã÷¬:0Z§,öA9.’¢ñÈú]r"VÈÈ¿Du/\F™Bµß%½e“DÉ·ÍÙr6òzâ „ûÿşÈ¯¶Uq¢¾ûÒ-–Ú°d¤àÜ¶C“¥81P0éõ•‡ÛdÎÏ·½kºÛÂõ »†ÛTœú%4êömn£ÿ,CCcäÎ]1š@#ª /ºWáKø:ïWH“ó|ş{Ì ã5l†NBÙÙÁáò•ñP·ß%ñÿXŸßÖêXÇ·ã¹ì[œwNS>Bv¹Úlö‹çx5hî’¾5À¹xÔU‘*¨÷3oİZ®ÄçñD0 <]Œ4°uÔ¼#8–)
ué˜ã”ES¸•5¡]b÷»j"JsO¦Úf…o€faÎ0gˆi*µ¤}`=jµ„Õ–dQa	é]ñ±ˆ¢°œTVZuSğ?ÿüáç]èÒc´[ßG‡™ò'Æ·ú¯)V#Ç~Jı¨Iß-C·"r¤ÂZ‰“/ÛÛĞ“üddèimD“Hqaå™§ùì´§d”ËÄÊâ»ôŞe)ÍA+"0)°ìäÓˆ‰ì48¶?RÖ	ëtbÖë6Ä$G‡ø^^·ÅĞ:‚¦¬º;W´ÏâdI^óóÊv¼—óAY;°/M÷Oî·çî³~wL£­Ÿ¦Êy$+àÎ8UÌ”ªòŒ<£¹ƒHhm7›­Ã¾_~d9Ã¢˜ Ÿr¿0úÇÚ¹Eßø*éW'ÕQK6G«ê÷~ÌªÓ!$ys“Ò0ç#HÂşÿ ¶sRºt®¯•–’6g7¶¨‰Â¯7çQ£â¡Á·”i*Ñd&ë×eÒf˜z–nós¦˜ª?’x@ŞP[ã¹\¢*úƒâ½ûeÀfu­õ¤Şå.ú¼öíÒ$Q)êÑ9!‹wD¨®›Õÿ•šäœ¹$˜,-í;W^9QtßÜ ·ĞÉOÿd|©oœ’»ÿV;Óî‚yÕ_›-¤e)A¨ú¦¶Aom$oq ¨N`M¸,Éï6LdñŸr‹oôT Ìto†ıŒ	,A†Ä„q#İÓnáŞËó¡zKWÎ>”Yç:4h-;ì°0‡a´Ë]ME¤â Š8Áu°_ˆéŠzŒDòÀYÌÊƒ—4P‘ÒPë·Ÿñ%ßŞµù‡4ÃÇ:qÕ«Ô¬KwÀ“öÛö:&}y—<-S=òŞO&èøõÁ±½²ÛùšÓuø­íµZñëÚ£À±qíÂªu*·-îÀDŞàÈÈÆ]sõSP^L–tGÏåËÄn0÷-ˆåS\´#94d“cëã 'VäO‰Yµ£$Ø²ƒ=ô­ï w%ºm¸¡ÉĞÀ.Ì>ïñÚ·á•?ËˆªÓ×ÿğ•ûO¡{¯%doh2Ï¾¸˜«‚¿Tòc}\¡Ñ€q†mòPÎM_­}GJù×êg–ÈÖ¿ĞÀàTm­ @¡Ş~î&ÕÚ`/a;ÁC¦v¾†Ö·£[,kOÚ3ücÄåT{4îÉŞ«ºô÷«MZiİ-……QÊÄôßí9ÿ1DË”„²`Q‚–™“:Œë’Â«*­ËåLÅ`<®_‰Æ›e¢ ´nõàoì¥Ø'à6º½sxëÙ€Ù€sÑÃÌ>Ëúó0
ş(¤Åãá—ïº½w\¯ÚæıÚàèç¹]0qãÚ©½¬„§®óõÜÒÏäÂÑ+Ş-8ûûıÙıqbdûä0Šª3HÑ—?9û÷ \hW°»K ü`yºOÙvÙ$È:h/TİƒèÛúïfìi•ì¶]ÿêÆŞæŒ+€åÉìC}È!}ˆOZmK>N#4è-+µm*øzÃCmd::Á*Õ4¶EÙ†iØñ:6LôT—e»Y]ó¨ ­/kÿnß$$-İ“?˜V¦Øû	„cÏ¤+¨\€W±áı‡ƒ®ü\\6Ñ¹5UûÚ±~µ1mj˜=˜("®;\gØ;’v€§1©ğÛI>UùåƒÅGDäûÂ“—‡W’æUÃ¦R©3$®n… ·¨I_‹%Y~±d>Å\uzùº«ÆĞ[³jH´ºDZ{ßa©¢t#À)Å‚us"úıã^}¯Ÿ¹³Æót½g¶5í¢»¹¶à´e`,v–o›¶q©ƒdtâÓ
>#=ÂZ=ÿÙÀ$«¦|“-r>.
úwı›)øºnç¶U’®aôlÛ9*
ß·6oÒ´ò,a.ˆÔK¢¥¸&d¾ä®\
ÿBJiŸRh$Vì+|qp¬nl»Vñì©Z%^°ÇU#œ²Ù­Tû†÷z¨K^øX7MîôÖC–ë¤ÏñªA®ã¦ 6ìA=/íÄ>úJ›Ïé€:-È™d^¯Ò/N“9N`—•.’Î¿.¶ˆ¶bÔ/Œò_ÖÕ^ız Xl¯I©©DA~'ÓûCôˆŞô+æö%O<‹>ğ…Q)a³Aãz¯†WÜoİİ*Ó|Ñ‚D!¢ØìaòÒÒEó1ìPi‹Öú‡pZ‰£¼ávKƒºø5‹ôl¢Œ&Î‡´/VgŞ]-Ÿ
¹ÎÃ:¹C<ŞäX‰+F}úô.YC…/ÅàÂ`4úÁ{CiO	Wó5í{²È—\£2Õq¼"«v5±³šÈ´}||] 6ÕDó3w}nòNÓÿn¶…xõScHğÅDâì9rÑæ½ä3Øg|ö˜ÏÅ?öà®}|‡‡ĞÛMàª&
y“†Åwş^ıOum;Èı“DËV»úë¸^›ëí‚ÏğóŸ¶/ìàÍø{~Ÿ}Eñ=¼TÅ‹t™/R4ƒŸ(6{2É1c¶ß’´GÉk!{.¥‹Yßºb©-ÇŞÂ<Òú¯Ğ*šJ ×´q®Çg½ô¨Â+j‚']õd? jVÌm‚nšÌÛõÙØ*sñ¯ÿ(e½)¼ï«]6#ë¡’w.maLÿÈ!QĞ³:à¼Pş¾Ğ–uNÃI…î"—Êvû`%ã• FGXdt/iš"€J%6eĞ+@·š-q³ş¡Ô°·)œ¾í±LmØ˜‰6ÆóÙ¸»Ş~GOióY*eèó¾KĞ[Ã{ìmÙÉ^µßÿÙbğI,æ»gíÓw‹åtwç)V€Öç}£áµwÈÕ«fR~	Qå‘a¨ªn¢l#6O'á6é\_Ğm„ılÂ·bÙMŞü¤Ú)›3¸Ü3©jÚÜ‘ÈÖ€"+»Oú½¢©í(q ï¢#-¶>ˆÍï²ñÚ#½RçfcéUÚ×æ]D“J¢[WÖ•a:<=I‹>HĞ±cŒ²÷øjîS_şÚÜ[B XÎRÃQXÿòm›îèş<ğ€œ‹:øç=Å»Ø¤  äÕ®Uaa€Ãø	êª…¶´Æ“AOqĞv£LFñ<rñãÓ2[<‚õÆ>¤ÔêOÿşÌßíøI9s=¹±V®ë¶Š
]zÿáÈ^bK?,Ï6÷,€  ÙR.ZŸš.©Ÿ¾Mé9ù<jYLÜÙäãĞ\İ²r6[Ãi‰0Rî#p¤dÓ5²¡G›r!`õÜZx³÷
ZÉ7cCø“lj5.€£‡€MÇS¦;ğ$ÃÿæóôR¾,ª¥ÇÎHÁêÑ”O_rX5ˆÃ±•ÏÊ/Ä“õ®@isÔŒ‚FªHfÁ¢¡*î‹üD ê¿©K—Ú9,hXEk½âİæÛ·6éõÅ”|ºªx8ÆÕáYw¼Ü¥º¯º2;^- §óÓéõ#z0P·å-p6GO¯`Z Vr¶9À*ê¡Äz İ¢Iû?5‘<³?HıÌÖoÁGô@TæFƒÇùJpTfjÆSˆ#4I¢°§»/ò$Œ(u|T¤Èru| ©QÏ]4(Ğ÷?zˆD¥®Èølàxx_deÔŞô¨ÎÓI†}ßË½à"uB] ÍêñŒèÄ¿ÿéƒã0N}$ícNÒ)<«îÛNî§ú^º«ÔuÜµĞØ.¾ç7[ünßñ§y&vøXİu°n4f¥ôx=R¨´
‚ˆAô&íëeçG‡™yêUËŸie‹6
¶=Dªm%›n!%±‚£~Â:M­¦U6=«İó5ì°Gr­òƒÆàyèÔôïù½L_€HTêàšÙDÀö„]ŠÈ°á‘ìh=ûZ´ş<oõ_|ı^Rÿ;«$ùD|F6 öbb^~#»K­YÇ¶ÇŠ?‹Ê5ßà1À[CÍ3$èËÊ2}áxP…«À—Ñ&’¾™F˜òóMÊ»öb}ö­çm{ŠGP‡š%¤¨›F_€Áâ^Ô%ˆT“'ı$¥¸ÈS@¯”¡ÂL¹®ƒ¯½<5–ÕÎ
İ„*Q)]1¸&$F–#½úc/@i°`	¶ÆUß‡%y‘çŞ”¾¼#¡SQ£¿õ§L(Ìg<SuV¸‹vÆLt9¨‹	¼J¾œ™Û@9\Ïm÷)[)<:Œêœğ@Ìé]©¬A`Y^TK9}7È~ì2%bi§k^Yì~ür¹¨ğâr¹×ï›1[H8¶æçu0õ5Nór9«Ü}
`¯Ìºz}òpKZSå=[æıïÃôt—¿o9s…1ŒùÅê-Q#ôö.¾å×t#ı¸nú³,‹(¹Û•”¬Ò™ãu(èàiÜq¬^ò2aé1Ğ0ŒF›+é‹cï2úsíË†öº—k"S$T‚£ĞêÑ†‘ h<õĞ}(Ñ¤bJ~şkywıøÃE¡œ¿ÎjD°Ï¦ò¨»ÉÃá»§k¡-¼¸œç×ç–‡tœeø@\û!¿Û“æ2N¦T)³/_µ‡AZÓØÒ2¢V¤Àf»ğİ©Oéÿ3÷`9<=^©¥ŸYxş-à|Â³TË•hi!¡3Üõ=˜1K[ø"A¶£zâë(Ê¤•:‚K˜‹šQÂdÔm¿G h.—ÛĞh•úx86ú‡?ö§Šr/ŞHŸÇß½À’……‹%`ñæ$'{FTzJmŸ†*†£¶WÅ‘°™ßÜõ#™~ş^¢oÑ 5ÛÃz–ïÄÿOúÄzßKOÆ	õ‹’¶7Â·§y“®GªA¼^"mšrnMaâ‡(90`áÑ^˜0ßLp…u½Ötmı°Âoµ«öù<†0ígD¾5OÖzü/»s2@‹PZÒ‰ò…uX…ìYk·TÅmˆê Â‡œ_J=ğdù½‡’6&ó$(7T—†f+²p›,“`¿èR| Çæµşå¬»ÿ
ñLù˜¶Ã`o’-ÅKÙf´y#¸®L]«È8(cã§)
ÂGÃ„'×Ûˆ4 ìôÆ’¸±óìÑ#)üµ—º+ ÍÅ{„?óWnøûO°m÷N±âGr˜É>ky9%+eãŠšûwT™,ãÈë}u7gı¬Dûtû£µGU¶òK§ÁQ÷”#»SŞ¥P¤m${I’{\Ç:â3Å[ßoV®»IŒõ—v”üuÕ6Ö=Ãÿ÷|
ËÛğ.ÆÃ&¬Ë8iVoo#âşW«)Ñ9D¿ 3Pœ€^´‚ş†÷ş÷ü›`x	ÂRâÖw%7‰Ÿ¥{M¡e=Ä|Ç&ıÉ…œ ú,Ca IÓ;_ÅÇÁ·Õø­ôö ÀŒ›Ù÷K³åâNJĞ?Á¯ûÇh¬š«âŒÌa¡d°¤¿`ıßÁmÇgû +ú4• 0’N$3­€sßJ²áÇ©u£3 ¢"£¹ä*lo^¥{mºosBAé_Õc»"ı`ñüR•·-è`Îxî¸cq¯ı{Ççfëñˆ[q!¯ÑTØ@1Y.·ÿƒøÿR†Šüj^ÁD	çb+Ã¬¸ïŸ@ÏîpJNnrôm©l{ì>–®Í´šY(.²ÒŞX«BX°Lé!¨Š	JÀ×û¨öÌTõO
2ıV:I_±â…”<¢ëñ–]¬eŸ%I½º³åWØ>³½ÜÖ3£0<³4kwl÷×¦1	h‘¶å¯Ò÷‚E¾cì–Šp)lüÈİ´`_[eØ}·hÆ²™7¹âC7^\Ñp>šßïHsFtÆ«‰mÂ£ŠZsüûdàùFû,¬:úxX¦ş¾3ßAnã·ª·?»%I¨	oø³ ûDÊímÅ[?œ2Šùõ5ô—óf³†™™ô®ˆ±`ªfåßI<ûÆ”¥’«BqÛ8È};)A±'±åáÇvœˆ´ˆîq|­x_<ìxêÏÎ¾ÓÏ³èóè¨«ÍÇÚ,ÑÍrÈ’äP¡;u/ã*V>02ÑN¦ñà@S} ˆxÓ˜]!ğÊéñ´xººÍ5Rz)Áõqg/Mº {¹0ïM„Õ×¨’0»Îø;ç3¨eqÓ÷¯r‰‡oU>0ia,Ön2Œ¦ZoT4>#æ?à¿@åã¥Ğç"rÁmæ„¬2ÑÈD1èbı{’^á9¡¢oÚÏ€Š@Ö¹äĞrB½WÓÇÉ»ßå÷:p	2ŒMÜW7ÕmZõjaS˜È}K²1HeÒ6¼Ë”ÿA¦Ğ¡ŒŸ°ŸP¸>-'±oöÙ”6Í‰–f½hù]PÍ (—ãœiÀïù½¹îÉĞHÓp÷+yeT…Ì£&¥q&ØÅKâ¿ìì<o\íq
-ˆt_õRÛ“HS}ŒJ­ğ+F>‘£n#©i¯EL—?¥ìíû­ €m]³á ¸µÛ®MÑxŸ
—²Ãrÿ¼VZè®hÒÙö£&jâUÆLüˆ×,³lòºğÅL©"O†fğ6’ñï|šŸwë€?¯Y æEèÿŒ78D¸íQ~0à­r¬Ş£k^îX=ŸkÜt5ı€W¿:4¯±Íé¤ö.zíö‚ŒŸozÌÓ…'Ñ‰KãVKùşş‹¸Ì‡Uj<¿|D¥l2ˆR€giÒĞ"—|‘:›ÏvLE5_Üú|5e;•=”Ü|#À°ææ9Ây~J¯Ø~Ã}	aaUì’f›vßùŸëF OßTÙ³%HºÀ:8v%»ş9ôLäğ¶l²ÈN|Ê,‡ëT¥}­f…şºö?>=\EòHu2L ¨Ÿß;!íO£dxbcÓë¬4l'şû¨uóR’£|Ù£uº¶Éy¿•rG@¤ø–~ZãjçSÓ ×;3Qn®÷ØAp_‰¹Ò;^£²òX +ITÿxâC÷œ´0]¡TrPı6u½xšØFn^ë¢ÎWìjÄìœ<R‘0?ñú‘÷ÕG|æå2Ğ ?J–I˜/Â Ò$X¸$'²vÙrSÆìøÃß
ºÅyãğ©»     
i 
p=t†åíRlbÇ€p@@zJ`Œ92©ÈÀ*R¬riÅ4Ş í`ßz%á™Ñ	¥…Úõ ‘¢còS´Â=¬±wº¨âÅ÷¸¸¡ƒ    eèÙÉÆ›aÅ¾ +t‰DğazÀ#ò¤Yä—¯ÿô±>_œÂ¿N¯ÍS.ø@c=)òù~QjÙ˜Ğ·J “zù“êüŠ†…e× há›° «VDà¥Øªê,¢³Ú‡ouÖSòæ4KğA)òĞu^ƒ=@8S}hGø½úéÉ™TæF@   AšF+ÿ  ºÈ€ñßä ~!À    €    Ašf$ÿ  ¥åÀš%\ªƒ´È›ZV‡Ä   1   Aš†$ÿ  Ï·!q€.ÖÄTgåÀ  {   AšÆ&ÿ  
=ÁŞÇú˜À¨x6Ğöê9`Vi@  #   {Ašæ&ÿ  
FB€?äîS±Ó“çßá€ ûB˜ùJ·rú(ÀéY£!¦F+çáøPÏZ
²lÔ„.â¼|]
+SX7|  ™T>a‡¢v[¢7‡îzæ€ØP¦:Â$‘ËÔeLeıVí¾]ÃğÏûíèÆ“~”    ‘€   "A›$ÿ  ÄôÒéU?‘#Æëjr   ‘   A›&&ÿ  	õşÔÎ@&z9`c¡   ó   ~A›F$ÿ  N«(Óaœ¡^AÒ<×±É;(”bm½ü™2éÍoş6cÀ¼o¥`qŞ°3™gº_ĞB(Nı3ó†½K'^è&åüBÄngWkmÔõë!´²¦-ò,O¸¼ï~dw”áñ*ØÁLq÷É–İÎ¤”qR"=t    >`   jA›f&ÿ  T~&_ZT2))®ÑÏÚ Q¶õOãvÎüêDÇüMª"§fae&¬Ÿn‘Ô6Ö’"Î„-	¥Õ—§¬µ“¸*à³İ=%†©B×.º÷t¶(“
½óÿAô;ŒŞx»¢    =    vA›†$ÿ  *ã5õËí†Ÿ®¹+A®*Z¹z9=péF¶—­ÃÏ;ú6C“|Ş6Ô,Eƒn^ç!3õ¡Á6]lè¨_2©ÌDd‹ÜzüV"ÜN­Rî°œ‡ICK	Ï®¿ÕKöÙUStä   W   xA›¦&ÿ  üEöˆ8õèGàı*šÒ]?xş\ËPIËt#+ıı<ÿí+’›ÓÛ4)…T< 'Ğµ@g, ‡ÚQ~ÈñZ÷¨„ü¡ùş…<Ìû©|›©Şš„ù—ÔÈ”¶5®
\X4ÊüFø˜   £    A›Æ&ÿ 8„JºÖVû¹€VÖài«Iö¦ æ…Ôs‹b{¥@T™ ²h”Ş¢
Që0Ó§Y¼ Ü·99¿Z€a\ÎšäsşÄJkçU©{3è”oÚs/ŠvÚfâXÔÔü7ñ® K­#×ßháNPDMÜ§C\å¶Tm'pœ¸“Ş ı)
Î©•<!<ı^'€   §   –A›æ$ÿ }ŠNÊ*sHhå ş£Ş-Šn¶?N/–ê‡ï6^Y˜\5Õ/Ç*‡·i5Mïù²7Ÿ!Põò$ısıË‹Æé Âi÷…ië4ÿ”Ín­¤îŒ6oˆ¿õÈ	â*t“` Ódé°ë”Ä¼GbøåQhÊ’²m¢óy­ıQªw#µM{€   !à   9Aš$ÿ ‚ßJßaœmãfĞ¾ßÇk|õñÅJ	¯,üÇÍKbîB#S'‡Îø   
™   .Aš&&ÿ ø!x=	Â—½d.OŸ×/×Ô70c±¥ÇÀ¸v¯“    FÁ   )AšF$ÿ ‹{õaËŞm\Hq#W;åú9s?I™7/ÀÌ\    NÁ   ‰Ašf$ÿ ‘·`ÂÕÛ.‘®ÅEµ±îî%XšjÛ-ïµÑØw"qÁRï2Ò‰*qXêù¸2\m]|‚Ì<í^oÁ‡COU‰sÊnò/¬­6³—Î)ÊfÄçó™íÒ€!©Ç¾š/ŠÎÕÖ¦ÚP°±y\i[iù»H    }Á   FAš†+ÿ  Øk4~ï­€€×BRôDEpïÑÙO ­ÚzøOL:„ÇèQkÿuJ¸é@«ES·¬ßÇ4Öà    ÿ   ŒAš¦$ÿ —w›©V|o‹MoÏg«ë,¾†¿E¬ú*±™.ğs”ãÜÈ|	{½æKMAB¹¥ù­uÑ‘ëDâŒKÔ
Eƒkâ¢ÿÏ
§¾)6•’i
çºâ7*¿àH#~¼;ëã°ˆÊÕBÓnY—‚æn»KèKÔE‚‹íï™p     P@   KAšÆ+ÿ }ô)ÛY©WŸ#´‘tÇ'ç4#?[Uo÷†¬'ëÈÓ«iM¤°oP%mVdaDd$[Ä    <!  "Ašæ$ÿ m^|b¢¿ÿ~²OEßÒÈM‚²´´Ü’?+áLLLŸlÃ-5s•cÒÖ¼şeüj“pI¤‚:ê69ìúå»ÖõÎgÅİ"¥ë“í†6ošôµ¤NkOzÔºğs7úè#oCµ˜õ¼+9ƒÅ±8¾áCÔj(É‰óîË8ä>lÌ¢¡¦_ á4Ì…M14íl—55ì8àuºØL%Nÿb¨Zà¦¦m„¨§«Ë¸…ëN\ÛË×€4_$¦€	{¼üe7¯âÃòä\'ğQÅ6–µØ`ì’Vœôæ´ÙVÅhŸµ¬–	â&	Ñ®ÏŞîqßö¡WA3òÓˆGu‚SkÌzšçf¡@…3Oç.ï²    `@   `A›+ÿ ¨×~²<½Êÿı€Jå¿Æ¿Ş´]Áˆ“SõCPxÃnå!h•DWÁŠæ“™Tp|Äë£,ıÄ«ö/úêcåÙAöÄÌ`³¬MAÙšT·1.ö+€    Å€   {A›&$ÿ º¼ÏÚ`ÈÙyÿÇ¥{s„»äfÔS\_*e´C cS()¨ ²¼òë¿o"]†EcÄp³ePğp3qO[÷S`n.‚ö²3.Oú°,ª£Ù•" N9Òÿ±ŒÔĞ0‘JOûø    Y   FA›F+ÿ —­» Õ2ƒé|ê»ìş¨fñi8Ë“Î€–KšüÏÔHµZáH58#B¾,¯Qí‡1ğ    ñ   xA›f$ÿ ×7Á Áãày–*Rr›²¡“¶m¼–ŞiíÂGVäH>ÿxõ×¬×©éBtĞcûÅzÄËÓVohoEñë_S1¤=·>ÕL\G£z€Òöt(°-eF»ÇïølG»İÔšuå¾€½À   İ   ¸A›†+ÿ İµ%·»¥U5¤ı44¸î¯ÍqëÑìş<YÙØIç ,¢}%Ô$î›]ñÜıòX	Şcç’Hîş2,´½²ÊûIfsKMÃ7¦T˜¥Œ[|Ÿ¯âŞ¹D‘Yìhªqï´Ygõ¢¯='o s7ÜÅöOÂÔîmÜb¤}^¿x¦×ñ^ ÒK«Ô€òÏÜ×Ì'V?«A¸zì­ALDÍ©È!‹97ã   #   hA›¦+ÿ İµğ%íğt«•ÿå¡?ÁŸÍ$Fåd—ä_v¦wGÕïç éÉÏ¨h‰0»G‘âˆšd‡TƒkîÍksÌÃTön&å‚EŸy}ƒ|8Ë?¢hU'hD    /   ÖA›Æ&ÿ zJÄ¼«ìn;¨t«F¿ç0Ÿshçªˆ®hé®z(úW™õ*iC§©„o£—Ô¯¡·# ±Ş‚ Q¨šD°åñÏb Lg?SZ?\^£[–ı~@CF'ÿÑ½%ÊT[`Ì´<˜”b¯5æ¸C‡ïP<I’llŒnöó¾àHyúŞSÍ…Ç¹'ŸÓRƒn˜µê½¼Ó'3É%dOµæüÉ »õÕèÜôd¦;YuÀŒ-6÷æ¶IiŒ)mÇÅ¡]”Hñ‹ Çc(…,C;4šéP4¾\ŞáôH!oäŠŸVŠAX½çNı39.`Ó«y·ùÖíş`t
ƒ›M^ıÙânÛy¥FğûâÕ`ŒŞ­&*kJ˜šó]Ë!€øX-„ÎŒæ÷Í¹ŞMÉšX6·Û&í„+¤@g¯ê'nvóúİ_÷äØ²e'QAıva.7tI;î‚n>¯e­mÿ#­HÑ2Y©N+Í šP8ãŞ’¢`4
li7S*¾¢Àf;Ì¬Yÿz•µ8iˆ4Û<Íh¨–ªå’kz‡óæcÍh·2ÖÍb··”]5}º¬N ­°íğ‚4,øÚ¢»Ş©ı|î^|ÄRYv©«Ê—®'Q—FäX¯=¦Ü—MÂ8:wvX-e÷­ŒRÌ÷Ä
s&àÖ®‘nÙëLR|	ÿô'Ï„Ü[T!øaÏ4\Û‹.‚téõ{ïB­Në@_4
÷úkõ¥Í‚·Å·ÛúÙ<	µß•ÕÁ÷ŠÖÊV(ÀG/@’k¡ŠPŞ10Z"¬Îwe”‘ÎFÈí2¬»#+bú¬Ğğ¨ä;ş`ùå.ïäÁÉ!8ÂŸöNùßPõÉ#d©Èı‡Ö‡Q¾ş`?šYq¨å:Iˆõ8E0²™^&Ñ2Æu]2Boƒ.r·#ğ@Å-(¯voÓT™J/ò¬éõQ~œ >¨bWvŞ´Ğh\t0>}ïrLà_¦¢¹Ô-N€ÜİM|Ø€Wì–Lr~Ÿ¼¢¹™3{Î{,mCeTWò½C””ZĞLw«E  µôëéÍ±ìaï‡ïfBì	Z±úV³Ê–#cŞIuÒ3ÌşÙı`9BÇónÚĞrYSy–wİZI±·£„UÖÏ9,LVöGÆÓ†'¢+Ì7üÉ`á0ıbC\@úQµ_ŒS¡àª,ajøÅ“èVM6ÍÜÿïë¿„$Y‡ğ¾Ù!Ï9Ã“HÑ5æQÁ‰%¿¶‚î5    }Á   mA›æ&ÿ zIÅaœr\ï×éÃ«‘'ñ>…ì!„—xá™Æ71së'ı¼I„m€WñMşb†GæaÁ† =&6‡‹¥V­‚B‘@¡©µöâ@sÂ+åúI r´¶"ïaäk¦   g   5Aš&ÿ 	`·ÈôA !Îµ»m¢6ÔşS›NBJOrô9ë!öõî`   \@   Aš&$ÿ º>·ÂF±1]÷Ù†ºÎ†øú)v,2Ñª/•~TêGğİ©~#s²Yøn–ıÖøiuõ]Ñä3¦¨†m÷‹ÇCZj¦jé|¦§inKp×¾ÒiEc	ÅÖ8Y´âçdNe0èÀ	¡íšç4   
©   ~AšF$ÿ Öë‘b¥1Ò¼ö©·ƒ*²Æù*ÙcZĞöğ‹a-ğÛ¼ËÏÔÎŒ‘	dÛ)ËØ†U¢©)••ZÁÇÏOğBôÛYÔ»I&•o/<ß'V3Í®ÃwÁl=E€0;«#Õú<Ñ¿¿±üæ6ªĞ¶§„vL   ¸   ¥Ašf$ÿ ºË0V9´è»’f×ªUK‡’lÿßÈ[xPP j»dúÙ>7éØE³éPÖp88ËÇ§m:ò®ş˜¦7Ù²˜VÍ¤SD"Tƒ&fx¶Ö¥D.÷FËäl"¥ïÛT…·IUŸî(EMnïÏò+š”$=-irV*\ıjìW ıG†ªõ¿.:ö8êÛÅ¨Ğ   M  ©Aš†$ÿ ·ÄWnQ¼yÔ²8•­¶D©B·'÷ÎÆ¾Ûp®ú©.Í'16\1í®İ¨µ‰l‰;ıDüSè6‰ºËG“íËj~ñßó18j?&†ÂW2ü	)Ç¼µÔÒ Ñmó\²ˆœ¯"”¾o¿šè„à×®ç`¦ë²‰…’ò÷Núr|ÂÉ¯ë
†ŒîÁàHİµ„Å!°¿ªçÔÆıãBYÊ´Á÷ëôñ.¯^pîÆ2–h/G&õ¤/yÏ÷1ş…gğ„–Øõî©k[Sİæ„ÍÔXh³.†HÄºqÁ. w“J½¡ÒûÆ<)êîG[XÂS…ÚPZÂÈy[â¾T¶"ƒ¼kÑ`Nı˜¾4 X–³Ê3”ö¦+©«Sâ^@“ıŠpxj´ÉŒáÇî·?S?¤C+C…ì¤L4ÏˆÈámğàª]7¸êãß-A{ÎU¬˜ìÃ†ø>ÙlÔËÏş;m´â_ş”A¢:|åÊ¸¿À2ığPğU×æró"~ …¤ÀƒZÄ€jñìTôÅ8,#‹ì¸   }   ¸Aš¦$ÿ ÷Êğ£]î„JùbäC­3Åp{ØŸS?jşĞãÓ³šîv$[K‘Öß½„Õ'#»ó'ü—DğMŠû±ÄAT.Vçò•>„É–=”e¼ôÆîááçŒøFòŒóÉ*;ó™³kó=?¥™ë“Sé4-F
+Ø/fì}d÷ÿárñ¾}Ì[J|ĞG/“ú©Ñj0©™f<›rŸ„ÈÛyà   Ì  dAšÆ+ÿ  ëC`¾Éï0ÿí’¿9—Tz_0£"FBQLÉM¯ŠÚ1	Ÿ“„eÍé)Ã}~½ıñÑc=[ûxÑ,ªsxP\¤aòÌÎ);?E"4Ù±çWŠs‚¢££½ÚÖeÎ.u¬2Û™selÕ2m:AÖx3Q5Zà]HÃ»òşoØ‡æbîVWÒhÆ¸êî‰äAAİDj»9È¼á*1	/jÙDË6R½›%§Ó¯u}®q$eæ¥* Ò‘¡€HáÏ¼Öë€oÕDä)@)/2L}~MR=5WF"&á¢v¦c ªº|ç†î_MåZN™¤øÎ ÷ ÀEñ:Kd¹ÈÏ2\	LQïr
.-'…Œ+à¦s‡À„û2WÜeOok•õ¯K^„1wéP´)J43k©Ë•ÄGqHo€½°5B‘€ÄYJ:]°Èvdµ~ÃÍ2º'ù§Õàt*B+v»äRIO0Ş­¶Iµõ/²üzşZH«V±.¸#ûÑ§Ó¿Ÿ…Ğwœ<ÿb5ÃñÎÙN-ÄPõu«şÙ‡QE­UrÛ?ŒväÀÙ¾%>œÄ0]”2Z¥úf5.4Ì}±şª.XRêpàXîÓ2MJS‡¾ÂG²Tõ»ZØŠëò¬~y¾S),É³ÎÒ™Ö|è'¿úhOë,Æ']ùÔVô(ù–XŠA*<—¾¿gk 	Mhk ëÓ„^½K›µ2éwßæ‰Œ¾Ë¢æòN){Çêz¥O¡å]fuds^<˜äf°u½dË    Ù  #Ašæ+ÿ  ëp€Å¨z‚érèÛ;‡e ôniÚõßçoeËŠÃ°_‘ »¯‡MT-¹ğÆm‡ëk„õ;¡Óü#™‘kM^t‡>} ¶M5„?¶3?ï7ú«¦6¥_”åòÙ ±2_ûÖõE½^×´*"HkÖå¤Òí¡ğjßm¾dz÷àŒĞãö²ŞR¾`ÙÃe±ßåvYu_ÀØ¥w²¨8gk·«¤û[’qL†U¨s›å„mš[Øiy…%Éë[½U_@ Œ–Ë”?Éx÷ãÀãˆõàó´óJz÷€kÊ‰ĞU4ªeFWûå=ëB>UFkênãÊçøêRÎ^ÔfpM^AÚEÌôªAMÓ,-RÇÅ-¬¬8&Ê­•qú¢ö/MŒ='e@UHß¿RÆÎL[´ÎÏwd¬qVK0tÆ)%`¨˜&ëÄQ7å0b€ø¥±fÆW[)ã”NM2l-'W$êŠ“p¥T’•¤±¤HÙ’éP¡µÅë1®O‡³¢>Ì‡ ‘œI<ÖB;E!!Adr4‰V‡†B[×›/ÑåU÷<şYjûŸVHñfá«¹ 6AµÖ=ßmæÃd¡G&+	¸o;·ø’qÓ1â¬76|ÜÍqıúìœõ 7å@p’¸±´‡È´ê7¦Ò­Ô()K_‹%P   7    ¯A›$ÿ ¯iÁ¸uû”—èŸ½ÚNÂ]
2KhËe8mÄ¡ßiËøÙKƒB¹V™Ì8VdŠßÄÆ¡eŒØØ–UŞÕõìë…¤übbN¿„Ê˜×?’t÷ôå¨Ü0’T¦çÖÕBa‚Ô¿ğ3¡ÛN¼.c?5Õçg(	SxO5®L‘weà8”Á¢î'BI.ÿ¥£ÜÈe½ÖP )&7Ú€  Ÿ   rA›&$ÿ ‚¾E(˜Îù·ÚãTø#2ıêŞUÈJ³6X¡cy}Ë·J¨ínTŞ|´œi$}„ª²ÙM¸^Ïú€.t¥¾öÇüÊ—ÉüĞ	šç†¬AF—¿ëµôA‘ëÖ!ãë€ç… @     šA›F$ÿ ‚¾NÂµZ,pJvh^X‹ûgÛL|ú]›DŸC’Ù4Â©:¶Óp=vH€dÏôø"X[n‘øoXo`ò…îRiÙï‰ÃIC÷]tQcĞaí0%hĞİ5'—®½Ñ\İ×–C»«‚åÀ(Æeh~ÊÈ	G*ÕÂG ']1(Q¯ê»@ie_à#t˜Øèà¼   %à   ËA›f+ÿ —Ï»ú42~¼…ıµ>€³MÄ t=C_ßrå"eÓ>:õ¸jŒG¤¶­‚ –£L¨ °R-Œ;aÖ›œ9³²âæUÏ–w€äP‰óùà©ÓiŒSÜ¢ÖÊ]òÓ¥­ÏhP¯‰÷Qv+ÖBÑE} ÍhWÖÇ€Ñ‹yêmÎNÒk1Ëv·ÅC·ï¥ën_(`û;e—&rEŸH—ÈYµ¶œz¶ñc=ïõ"„$‚    û€  ˆA›†$ÿ  KÎÏwÆÈD¹;£˜iD—ÈsMç°É1e¨5ï§NğÊÙï¦›¦ßQızÑã÷“~ÿ·ÃóZø"íØÂW„ó¤J}ĞÉbR‘Ş›¨¾Dêb…ÿfú‰‡ "Û(nS*Ó¸¬1tNSı¾§CS¢pº>ÔºsTı8A8&Mˆ3¶æç\{BxÑA•FÀÎ(3â"É¹ğé.FŸĞš· 6KKå “âåNMı+­Œ¯N?+œv‘9îeæÈ»ÔkHdÈqş¡‹eçñ@Ïm½aîZ82$Çw«›Ï†¦õ‰ÁÄJU	TÍV¼l9öªÒÁF–>u4è""…À4Ãw@áF»›9 j˜7v$L™øÖò(‚wks½+Ü'—ùš™…kÌ· ĞßFTÕàõA¼®ş˜¤¡Û{\ğj¹WĞŒŸ?Œ!H›[0wù‘ò×¸Eá¢¾ÂÈ ›³SÏL‡ €øÉÒÜQd`‹?±rÆ™Ù0ÿMËÆwĞ@ŞkÃUùeß°…kãÙ›|mtHwˆ{÷ö,y–Xt}Ûv¿„ÖM#İ)5\$‹åcÛh:Üø’Œ™`PN—3Ğ9íôï… ªè‡ÜØñ„ã†o)~Òå¦§B; Á_M`Óÿóq$T[ÔÚé;-Á“×åÂß:­:Ü'9gôòc¨º³+ÌÉÄBe±^(JV1Ş§=ŒO•4F€]¼yLó^âš®¢iæ©]©)ò}uac6á8ä7ÜW¸ˆˆnñ ò(ÿ¨|{àD¡²<¢TBøÆÏSÀø¹ Ow‚9+¦kCßF5ò)Aouêáì49§JnO¾qÀXôÑ/èp¼İµîÊ£YŠº¦£!Uà;j­i¦¶A|ıÌ§	àïğ‰`†hÓï8şwÛKU]¾½;•+âuaw­qbòpèoFñß$w¤œµsÁäN+|şM!ÊD¹éŒ×E¤ÿ»'w:¿3/şP¯ãw.%¼M7Mú•î%:ây½<áWîìÏşlÔ İèÛªô¡ˆND½c@ı&]I…Ù5¸$µkôòA[‰’î¯#Š‚ Uç‰³AcUs%÷zŒk1àÙ`‚#ZPru®¡‹K;šõZ>ê8`Œe_Úà.8F+"|8ôìœ\™şÛcÃ6unãxĞ¥Îš”„(¨w--Æ İİh„ÙÔ=·úĞ‡ºÂ^À`³ Û¾ÏkìÅ•¬h©v7 ï3“u|Ñ¸¦®Ïd2¤_@°:èæ­”Ë254‰ê>Î0ˆk£(ZÄ/€Äå‡ó§rïóIàaeTI•Ieö²Ïg‚Áh¥=’vm8Ò_ì‚¡-J‰aÈ†¦ÒhÇ€Aµ¦¹Öë‚ŸGöB¡ÿÒÍĞ#yˆ‘z›ÒÿîÛóÀL×%<ŞŞ\jO±ƒÙÊ~gÓ®Uïpò²ï°­d!&ŞÛç€I*mòë4*d/£?O$J}qÃ%èşÌb¸ŞÂ²&ùSá’Û"|)¥¶ª³3É•kÄó”Ì_TSÉ0¿iŞ‹óGæ¶i™Ÿ×ËÂØ®ÏL“½ğcy_0}×Uy.t+x®h?F£Y,“¿ş¬•DSk’"˜…¶Â¬+"éç[+é1¢ L•÷ºÚiºYDe —j ÷1ìÌÕ–¡ËT®­Êü:¹£y…œL!¢xÚŒyîª¯µöR¹¤£Bğ+º«“Æm¼ÂLØ­Útäí\"J„‰ Hšî•›´ûvM…ætU¸~ôRÒrÄ(qêæ Ğ/DSƒF*¼áSaŠmÅ*6ğ¨?ñ²Š°'*~Ûk¸õ×†1hä‘ª6ä˜:Z±<¼*  ¡   pA›¦$ÿ  Kƒs
ÎÈ*Â°ñU?¢=¨Å™ğ ¯r¾ÿùJ~ğl¨E»UôÇ¾5U´×Š:}Ÿ8ÿQ0UGB%¦…Ûr'úM±àíulbºİÅDæŞ[V;·§-(‰|.Ù©YÒÀ   ù€   A›Æ&ÿ ÿ|dD    Ó   .Aš&ÿ  wµåná,Ãõ?à*qØŸÕáñ%¨¨ÚÒY=ğ   Q   HAš&&ÿ  ”|ï9±=ÌöòÀÛŒ´Ï˜¬†IÕ÷r ı¡©w—~S:®¼ NşÂj–çÎÂPŞnÄ¤E3¨   0¡   XAšF&ÿ  €†«¶ôäšPÕvŒA¿i¶u[¶ÇÃ»âÕ¨&ˆ¡w—
Á½zÒ¹ÅŠHuıYªfğT¤šZ	á[WÀé»¡¸    2¡   ’Ašf&ÿ  wıZtŞ<Y²Û€ÒZ]²3Äzê_ˆÑ Êy#k«KŞ käàñ:•³6K¼ ÀÛ†ôvKÕıIhG}.«DBÒMêo9ŸÎa{G,ÕÙ*àqû&Ä:Jğ˜M;0‰ô^³f’ºÍ †üdÄY`—¼fÙ!oqÈ   #á   —Aš†&ÿ  EÔ‡-¡™6íàa÷:æ6_şD/}Æ“Å}%r;ºm——GAVzwÇ¬ã –Cq3‡ƒBİ#$ÿbÆj¤'ãU!'¹Jrô~éÂùø|º ØÎçª’?Ğgp7²6ê0µö)ÆÕYAG	EiÈ¢œ¬îb9‘T³ß©éœaoÌ¹EèQMÕ¿W(      †Aš¦$ÿ  F5÷˜K€ËeáYW:·ìû–4_=l3N~óù¡¨n8+yÖSØGÊOÂMĞ_Î£/8»c2l’èˆ·´ÛÀ>0YªK–SXSå-VÕ‰ÏŒ¼&
s  ¨ê]q…”ËÔHÂn”¢õÛöÄ#	g"ò§Ã   /   „AšÆ+ÿ  Dæ;1@~¿¹D=ˆñü•‡¥\)Õ5#l]ÚärGfPšœjç6<õÚÊ}9²œı·çˆá»~İ@xKÑæ26X–)I¤-•\[*—Z&rœhæÇµ7şb‘„‘kN„Æqh±H0Ôá5o¦/ÕP³@p   !á   (Ašæ+ÿ  %¡Å)!íğ]|"²'ëşpuFkÿ¥ğ   ,    ‡A›$ÿ  ã#üIÁB?ò%ª{Ö¼hXö	”ëÄì,âçp<Zèbl”™?(&°ÉëìÏéhqı±plKvñp<¬(k2Ç~ÿ°×ÇÈúØäú‹†Êdpû£õóİ”:v‡|£Yñà]l¤è-TÀ–![šGßµ•Å#¯Şsø   L   aA›&?  aÕ·„«‘ª;YC/Ô#my¥Ç¦yZş.úX2~ır4Å¤•Ç•Ò5¥šáUÙ¡¯€¯\]Æ:ùr>ÕTÕ|e}7¤Ô~‰-9ö%İÓşmÓş‘•²~ó   ™   “A›F?  •o@İuppj8Ğ»q/ Ò5VUg“{ê÷;šÆÁĞ@P³
ı½',¨Í‘Ü™xR Æ7X_J
.§9=.¨€;–ÏbéVGbCp³wÊİğÆêVıá3Ó"¿Êïœk-Q«	ùÎÍíæÀ±ÉyhV²>›hÒs€†ÔàÈ*Ó‚X   
I  A›f?  dïÍ¯ûS Ô_ëovÕA•Ì•÷•g¦-ø1—ÔßÿŒ¶µÍgı±ÏÆ¦ëïÌ ³`æÛKFÇ!¡	›Òc¥Øèø"è¯ßOĞI²º¹MğğÒgÇFF×–û›ƒ0„je3‡CQ·Í¸ëjí’róÆ¬ÿulXkFF•%zÉöU“]ÌËß¾ûïpFB„SF’@šØä¢ÚâÌ%"çÇïÆŸ½BWô[8ÿß´un¤:™?F~A|xADâ§mß¬_Ï˜[J:9‰\èåŠ©LÉã®J*Å9ÎŸòÆm©\|ÿ ¹ZÍ‚¿£xj`ÊÊXUTÅh…i&/„×İ¹2áG.Ë0gR¹à~w ÖS»Íi£›!v_oUN-°½°è3Ì¶h_`D  ÉPÖàÇ¦Ê“²9|TÃÂŞå«‡	ÇÚjŠ‹³LÀ„ÇÎ Ö9e9"ºŸÉgmqhĞGÔ˜fìÉÜóSh 
†\_š"Wô„ İ©$³Çõ:™<v]vÌ%yQ®ºd÷I´ª 'GÙ½
ÎÀfß~¹Şæ—±’™\°
'¼,W4€Æğ¢ ia~À™g‰TòÁ=ÙZuÀÆ^}C¸3282$¶á•<b¹à= ZĞìÂU*uã·Í ŞXî¸rUïÊd>úæ¦Yƒ>é²O§€~šmÑJô®l‰Ä:ÒÎ!ÙÊwh?ÂêG%‡±®í:Ÿ£}`Hà†bƒ×š–¶ÜŒ†—oš‘–!¼â½}é0 0÷@™»jĞ¨ *Æt¿R—}‘ÉğLàXfDó=Wš~¥<CHÉ>ñ‚on½¢iƒ„¼V$ÑªrLc¯LÕ¡&˜±¼T¹º-ª\F4|Ã¨7o¹—¡iÎì3ğ× P
£³õ„VöçÅt_…$Œ8A|ì…°-xÒZÆ½€yÍX!B>W ¹¢Õ¸'C8Îì9_Ok‹p@
¡­Fn4ù%ğf¶Äl~¨ú¦¹wS¹å·Ô¸ş<‰z½“…W@â´¤‘Rïg½cŞÌg!š“¡çù¯ƒØon4|$(­úQUy«&å£{)be¾±Å”\øŠìÊK=¹OZm‰+O3¦Iş©/rä6ÎFsø$İ‰Qs«Õ¦ ØÈmµÑÕô­Õ1›va`3Èdil, ìı8ÏÔ5–­ÛWluHœLšªä˜AÁe—à–®’ßÈË¨WfÔe-ÿ¤}U•ü1_+d£œ/ŠZ¹ıíÂëc€kÊFÕûâÈ]İ‚îşØFğv|äÍq!“së]A0/š¤8J~i6Ó¹åó.óÓ‰Ã1)è”üu†Ûë'Js÷<„dLy¾­
|ùgˆaÎ°æÔ°3£>ïábê¥*ó/)V5Ö¡×8p„ÕmN×ZÃ3ph9øu.¸3[¬R;ÖÆe#cğ%) áµ)‚ÁH)Y¼³ÊEqØ´Ææáö“éÂÁİ¨Æúà.ÙguÓ"ûÂ„¦ÖT_ò0Wsı™pÉ$ÀÏúÈ÷#LEÈpÄ³-ê )M/6?¿Z0˜ˆ`G2•'OGÍM\9øĞRÁ1“€4ÖCr9²ß7óyù1ÁbÒËs?é‰·c}ÉŸ€÷õËZˆÚAƒHˆ?ôã4äBE¨n÷W›ÁÜ™qm¾ê²ı<_¢°º§ê/>ÊUHˆ8ÿJ¸JDs-Ãé-†Éy‚Á^ú¢,éÀm¤ÉëH	ïš+,‡¬ÄÓ›=ÑFãQa‹" ız6rğ·H1”5§^ïıCXHãøí²`Ç–^Ïª*÷İ‰"Â”Ï÷E÷X/¢`û&–ĞM»#«‡[OÉCÛúILOÿšÖì€Î<;èÚÇÊ}<Nä¿C[Æˆ`«‡LS©‡'êçÉ!	%¹‰{¡„©‚Ä‡	å„ùñƒT¡µ¥w0„ô¼K“«qGlJİ:Æª?T<¼¨œQÆhÏ»lZæ‹ÙÌ$™º¥­¢~Ğ
 `QCñÄG¯ØÑ2i·ulŞ,FXÛÊ»Bİ1ïÃİ(án·çäú4&”Ì§£@(#ŠzÉ=
İ‡}µı‰]£½<jÿtŒÈÜŒ†$òú²ÑIAÊJrYÍwÕÛ?NæmüT6GØ8‰O>*ô4ÍrïºP‹ÄQ0r ¯9
mÔãUÊ¢ÌaA;nûæ±îÆwxÄhöŸÄ¶Òºy\¤ÒÅn/ñò‰#õÔñ€Œ5 ÜDÅŞCtÜ°qqí\/¯¯ WYòÄòĞ\ùL}½é=˜†¶š;XOÿ»Ü~SĞ‚xQv`éæhUC½ÒU‘  :A›†?  lÇÈv½5ó¨^N*X˜÷ı$õÙ©/~ı[g†7ÿÛË@ØTèî:fİècíÃıµJæ¿ º½ÜÌ-nó”=ğWËu6ş’ûÅRPÖ  Ÿ4Â¤4~¬É“]`¨™\Dİ—öÌÖ”º	†3&4ÖÌß~d]Ém5umÀfhjs”JÅwTùàñ¨	DH"a ıš:>¤   ’Lû&PŞUVo¶b;”ÖÿóıÆÉ,Şfù^€Å—Ÿ8ƒ­™‹hè‹ÕÈ6‹œOàBŸpÊ~^Íæsh©|!½mõ¯Ú€¾ÌT>I’0³ï¦Ò(ÖUÄÙ/”àáÆ¢o³fw)¹VÅ»Hz¶g3æÇò)ú6z–‰¥iWf!¸ù`ÛånŸm’İQì/u¦5    îA›¦?  dïßK¡™ÍSèI58LEÎwß
Lûê×Êu¡¶Tèo4;§ÿøÉğ§(.§SqNøılŠ\Ì±şÍ/g’áÔ|¸¤â)f“á4-³D¡ıQ/ÉÕÊÉ©å]Rİ“3Ğ,$ŠŠ[w¿CTÑ_™ È"r àb<tÎÈ
„Ñb>ß}á«/){ÛimwÂ]q$¹w¡öÉŞ›%4G?‚ZóÈ,gSIã¯‹I"ÁÔ%~~Tº+Œè›ZnµyL‘¯ ¡œ*^Ö
Æµ{qBî£î;–o…¸Ğ  ÔJ–Tæ‡6E}³À  A›Æ?  dïÍ®~^¨@…Ğ:ù@³‚×äôşüä0™ğÔa(r”Ãÿÿ&Õ"åÄp­yl›¨a zÈ7÷yH1áŒ 6gÍ5ˆ&3O5¸@LÑ_¡s°¼4¨úúœAóì@Ç‰{ç{WšQúë{OçâœÎÕ¬B>É7r†v˜nîÅÇà¤5´Å]b4å, sî #†m[v’ÖüºtİÜ&–á¤…2wz¨¶€8oázÜÀ‰BVø3‹ĞG·Ø*ndÈ+ø2±ì êÌŸ«_×:TSå:§?À0ä!¶ônLY¾­§ƒ0àhRê$   #Û+2c5¡   4Aš?  dïßK¡`ix*Í~Øg%õøÔ µ|pĞ²`~J…šÚ˜4û.˜  ,Aš&+ÿ | ò`ì?Aq—tuÑqŞ­ó3ş¿û¢"óDã­hÍNÛ†uÙ×‚ODPÈÔGşô,$bv§T@µñÈy$Z¥¿™£o;ÀIMSŸSñ‰Ir~qh 5ãdD%²$Ğç¼ ¯ë¨k2f´™ÔjèyÏHªÜ¿Çè2^õ1é‹EµMz =ÿ	¯–ö|8¤/Høì0fcO¼ÒÈ•ê‘ ö¾¦;ˆş€µáU#ÈeƒÆì°×^°;ÆN"FéÍÅi@™ìË¾îò¥bä|ƒMWd¾à ¢^š —Y.]¯BB
trı»•%Îş³s‰„0"Kœ¬Î5…‘p
Š…oŒ,=¤V×º?ç6w'û  ßê³ıfæ'05 ã   gM@4ÚCäˆ„     @<`Ê€   hïÈ  8¡eˆ„ÿê#”	NfÎmÂlËî¼-«ß÷Yø`º=]¡ÏØ|Ç¥@˜ >ÓEÎ«ÈH;¤²ñ½ ØÚ)oÕì˜µ\8IŸõaÈYád—G²ôe)Xñ³´¿òº íÍ’æ­/¶µÕ8W–Ù7!ğ4ÔÁ7XÅ‚%Ğæ4Ô71·EÊy[¨QcHı[ÊoŒ-”\£'uq|Œ,Û£ZR¼C‹$¹Rù~¦fÕÇCmJ}ä6 
S‚gñÂ~j¡Ñ!?òWÃÃz›Ï#Ê;ôcE˜£½–?ıÉšF»&èÉç7Uì¶aøEÛÀœ(Ã£ubÄ ºß—Hpã„xŸ€f*ùø¬Å²½TJ÷ÔgÄ^J„ØŠçtËÉÈ‰×®l°”,ƒ\Ù+”»ù	B!İîó°“Ó•;oŞ›’^Ïº·¥e›"vg§´(…TN:¶Gø
DU@n;Èäfúººf¤^K-Û¼Øı’Ù<õ_àä<6rØ—èBÚÒ©U¿É`Û;€ºÂ3ç¦€§ïxs ÷p.ó:‹àıÒêM«ö6%˜1Š£ùGKä±xQ³‡u½Ú$Út18õkÜ+É(dô§-Š´TS¨•¿¶J@`Ş|Y|`äšzB/QÂ‘iY®µUû¨˜ PÎëZ§£EşãÚ®Å†´Ê{hášNïĞ‚T	Åoioôo(ü÷k
šn—Ÿö¨Û?çjYyø_DÔ’èæ½Í”®À6ƒÂšnw*W[‘Ri
º·Ì	º$Q¡yİBbàr5%gò7İ$g¬%RD£”+Ì‘kÇ©åNQHqóÒ§6×
Ñ‡BÄFßó €ÿ·€Şñ¿Î*bvùdŠ/’ÎT¤L˜   –}ËW„r8üô2Ã*)\;EfS›ˆÎ+«Ø€#¬6MnWËeû²`¯=äŒ»;BºRyÔa0/`0U+®ê@ÜHĞx.Æ/]0)\Û'è™å9= ³[ÿxaRÇ+Y0]«|ítha)Òb†‘ª´ä€J/+9*4ckr‚7¤×½E'ô&™JÀ–ˆ=–šò½‚[¥™PW×ƒºˆ Äy<•“{nfVí»?ıKı}Ì¦yY³çkûPzÊ|§ôª³œ{+ŞÿP:$iÁ×ÁöÏH><û^òÆü}ø\ö×=Ÿ÷†üq¶xYº#<Äòâïg%Ïth%Û~¥-›5ù^H©Ê¯ÁşÖ÷[o~4xüÿUÿd¡ª´S È­RºwÀÁ¯=oH¼ªÛ… Ö?èç‚[%Äì•eY§g(Ú¨@¢c0Az]o# HwWÖj¹İ [Q„Y(İÑ›Ú™‡¸¹OÓˆôòÈúuÿ6	(x¶ßš—Wit¢ŞÌ9şY©¨1¬ƒÑ{üS»AÄi·<,£¢(íÒ¾Ë7.~;}Ôôˆ+w
ÿıê™€[`^Ë›êJØÒâ¡³û6˜˜¿À¯ë}^¦á+ph'Æ¸“}Gİÿœ`ÄŒïßJÒ/²v0šVóøJÿş=Ç2üo£ÊwHç¥7¹¤å¨ô²|“P ´ä¸Ó´`“iÆÎù·„Û‘Óü/aîE§Û6ğ³óB‡f¤òŒZAÅŠ¹,Š%¶;e‚Ã'âMï˜İ=í$5Š¾Ç<ÇòXF—3!%hSiÆ€“ĞXHIŒÄÊ   ªº#låy*9W‡DÍ’+vöı!ZM?¨ÏÍL×TxªAa¤‹F%éÒ)Cjârtc	º,ör™«ºj«‹¦äƒæ9ÓLù©ó«…°`ŸFi]"®—{)bî?ÿâ}T—/™şy«Õh
É»zÈ-ÓùğµV’&4òPI÷_ÅVA€ì<±•áæõîÎY¢ÜÒÁğ¢?ã\*Ø%d>%šäÏıõÊşZ[›¾wÉ:§Z­‚wrËŒµw=O
33ç>#J¡d×ÀËt
òOƒÑ’ô8Ë‚bÆByK¡- Ûê.O2l)+´R'¥Œ´¤6µ˜t>İ8ß9 ¢ps¯LŸR³œäü^ÁuI%¾*h#£ñ÷ËÊûÙéŠK]¬³¤„¹²Úrê$!ızU")Vözåo?J]í ,rpçv{lQš‡÷ä $„ÁJ|<[½
Û#ş-C)”ŒÉYè€7›T_‘i"¹ôù‡eJ¹Ä]ïZ¶X*OÙèšulş±.öU¯O&ğÊÕši:è¨5¥’É¹d
Ä‰š‹š¡½W6Ğîæï³,íMœñ(ö"‰˜ğ†2ZDm”ßD!«b«qYíw¤‡îï™Rµœ”÷VKMÙnfîoúiN±|Á@¬ç”ÔbSjÏ~+Ïwƒ¢ˆH·RÿÛ{«7
?·…]5Lš°õìƒ‡@¥Ø;ÁâùA¾-ºŞõ±Ä<jœó$6á|ğKú?‹Ã€ZêSşÓ× ¯[øHh±®¬h$Õ@áSk	tş§7ıÌ7v'ı°.ïÉy¨Ş,Y<<o:"g"wú’£Ş=qmYVúîJ</âu;ìb +Ñödëøiª²B~€¢ÜuŠîPÂ’éTª¦÷ãˆÙ=byX¦ZêG_“b¤0{Õ¨Í]åè‚;VöA¿­ÌñyæCE&¤!úò­Ú=¥™ĞxûƒLx³7Í[äDa^¨‡GÜŒğOï#§O0Û¬ôlt?ÑGˆK¤íƒ:J[ÁƒøBÚÎúâÖZFRóQgµÚÉÇBXU’0«Èˆ‡ï˜\ôøT£×¸ì„–dˆuİMäÖmN[eA"WşıDŒ     Éõ#“ş©®–ÀiŒ¦cÈ¢ı’=„FtËï(aŸU*tê"Íº ^vĞ  ëğõê¶t‰Åv$¤œÅªp¯Ã }Æu²Íöäš¥Plœûu9ñm>U"V`ÇÛŸÚ¾»ûAA?O×â9 brÃ“=Aš?I¤¢¥U#g>UndÎ¬YjÛ_¢®Ìrz–¬‘v˜×  "Š b¼š”fIÍiuÕ£çŞê¦›ÕÚ•æ•êj§Å›SÊ6›ãˆŸ§üğÏo˜bøøh1FLÑİÓÚd4@	|R¬‹k©&kÉ¶ûğ"!×ÇYÿs‡\ïÆ=}a÷ŠI¿t€·…xîDïÜW¿ì.æĞ(ÍaK´,g5•/Hû­ÍŒ&ü/è¬‘úêPÍ®Ü,XéÙe¸¢ËùE9qıd7;XsÆ½éz  ›L;Éqr†İ$jı”t‰ Ü‹ z0ÛšR®ç†kHÔå+Û–à¥ÎDEõ ±õ‘ ëÅ‰‘ˆb 8™Ó`@œ¶ß“HÕœŞUm[0ÿŞ¥şº!ƒˆxtMXjı–“»£oÊIĞ|h²ºçŒ5¾Güºg.q¥ä ¾êÚÜëæX&:£è+ƒ³q›Qj:h!àŠºñ=Fx„„Ş»Š¬!ûXIÈ§=BİPªÈ¯ÈŞº2ã4ë7Sî$×Z˜ÚøPìE:Rbİ—[-É¨Â³ë!)\<B_Xá­v´O^¬(Y‰1foAµ@Û?ÁÏV·xşàP|³I–[¹ì…Ê“¿µ.3¯O2ÿC[5¢fO§‚;®Ùk ÑŠhqŠõJòŞón˜ë£U	˜èÓíé6RÇœã/“=—°Ô04ñÈbŞ6ªôå	´ò°•EÔş!wOööÁœç/ÿùGG…ñ] SgÏÍ<„{Ç Šï†ßÖCJ¼,>u‹‚‰ıÑ¤Wc;óAiLù©¸q×¶ô$ã¬2Ò ,bÌÊŒ@Î˜ğJ`§Åë›P™ìRÏJ<ı¼£*Ú.q™İw[ZhÎD|›ê(uì=³²Ö*¼;¤ÚÁj€q €	˜ÏQ7|Ÿ¿ZÎ%½Flr›îiçö'Òƒ4uÔˆ/›ÿ€Ï°²JE^OyıÆ ï–‰ô{!Œ&§Ü4È˜c:—ü%ÜZ¾à…`®ºe}+¯ø0Y&õì“ÑA¤¤ÌòyÙ¶Ë‡%%Kä†sù›ò5÷o¬‚izÌ÷ÔÁ²oÕi­÷ò3îÛæùzV§ÿ»Çs“è«‹çŒ§äƒ1gíêk„Ğ{Áü¹¯‚¹åánIn¡£NĞğ=nÂS¥=UóÆnæ ÙQ™‰HÚéÏ`ÀîäÍt„™â(!×@¥ºØ<‘Û9%H¢Ÿ¦ƒj÷'Ï8I ©§&Cáù¥ü©kïøZï-ƒ¶†ÊfÔ% ¦fòË{]¢>æ2nIÈ>u]£õ(ˆE‹~ÛºIª”?¥d8°'å«uì´?™ğ"!'}úÎûØ{İgYÿ
;×¤<†3{+z¥ú¾/IÌo¾jÅ™ñ•9Õ=*0Ö­f¼ßÂ´ÚótL«‚%V`f ^;¦G‹õ„àeƒ	8RûaÑmÙPÓFÛ€ÆGL ^IûjÿÃ5Ïø“¥å® 5U"6¬İ¼|¢ñ¡WYµLÖ•i‚LOGe‡Ö#ï{øà˜);+şWÓ<N\ß>ğúH.aOÂ|âÈÉÓõğ¿D53ªï?‚Ä×Ç•Gh·Øáhœ1­|©£>-H-¾c,öïuâ‚U»t‚°”gı86‘ôï$ã•X¥KÑTSãx]ÂµA':òFRm&Ø%viÖ)w6uÃI¾¹h—}$W½!7¨‹Âö \H&édÏäÚ%¥² ;T%³Ûù¢ãGDÙQby÷Ğµ«³>šÜ¸Ï\³Â0ã¥¥gÎ,s‡µ¶Ğ®Köâ¹¾î§X¬˜ÿäÆ(ç¥=xôŒD¥è²ZÔÔ<5ÑîŠ•Hş¢N2•=›}•<`rps‰6ï¹bTêŠ	¥ÖT‹·§÷¡zdZ±:Öî1×?``Êã¿I…«éh"N·‘¿ûÿóa-KšIÑ=íÂ¡?Ø¬g8oÈÄwøÿH	MÈ«,E?
ø uôÿÊæa(Ê´õs¼”%@]J¹ğs½«m¹äU6ı'¹Æmğ¥~!àŞ¨àô¨»Gb¯ÿÒ³=¨\¬L]ÏÚ¦Ué9·¦ûíDöòpÖúN$e¿Ó$ì1>°~cSZO&‚Y?Y,
x^¡´0?d¶1
™Ó¯ÈË0”˜,³‡Dy®G“6¹§Êƒıì®ş!×TøvH×f3L¶ãÑ”ïCtèØ:ø4R¥àFÉ“ô :m€×şH™ŸÌÇî2©,9‚ñ«]şİ#?3—VsÏ
ı—’½vNLPá?k?Ìƒ@iQÍˆÇ´Ê‘
™É»R¡×‹ÍJ¯ù„ÜWìœ-\\	Ê€MÊqePÜRÕA¡ñ‚
Êä­¥N•#ìúú}Vñ@e˜Öi5>«¯då¯»•EeO²à±?£ö¦+­¶h˜gy„õ¯-)"P&:öoÜ@› ˜¼suZ?q–K—öØša¥pFö¹8Û0‰ğõQs_yÀ¢dŠRCwu–äÍè›gO«ş°4:°Îõš^†×=ûÏÏãĞ'ôšx#åİä|.ÿÚÃWÑ^Ğ@Ñê<ÎŸF†]ÏïguidŸÏğØ-•ç5gGÆí`y´ü¾r¯OtæS©øÍ˜!ÑâŒ%—èË#aÜäò¥“ìõfñ)êiåö±$¯ş£yÅ€µ×£~å¤
¢€Õ‡ù¹S ¨*ÅS©¼µÌøÃ	®Îˆ§°Aˆ³öC]¿î1fçîÄÖ~ãá8%œ½“^FE±¢—“I;|uõ¥\ÛMS?G’®çĞ4)ÉÜt>ƒÂˆ<XÖûå:ÙÇBLÀ®ìŠ×şOC'‘ú^ˆğDÚÃƒç|ŞGØ@§Dš¯?“„×}òÏÍ»vwhY)è°Rá,ö%‡d¥NDM9Ş¨°§5lH–0ÓÁ…¼l·|.C›Ÿ	~öí†~ÿ¸!6õû„kU{+B›ºcæ%M« 8ğÉ“@'½–wã÷˜£Á˜Ù¶Bòg¹í]˜b^ÿÖÿòp-0¤û‘I¶®t^©…uAºLTßï
³èı2áuªÛ“ì˜T>ÊcmÌR‰ám€«÷×ê¼‡èTÏñvr ß÷…µ·w·ôÇ‡ÕOºNËO@Èrğ]ÆƒmpŸ¨µro‘,,
2ûÀyBK.¿9éã?{$Y^áMÙšòB?8!öï	ƒqêæ¸º´QıËUÁwW³(V¬ÉÍÊb¹¨†?î)ÖÏ@u
u<Vé	&a‘ÿ?sÊlÑ‹Â¼!h8+œGo™t•éèO¶ág³,dàEÑ¼M›÷¤|ÇË0ó²F„ıGå4ß³Ÿp[úxÄ¾°È°í{lkœÿ™Öá¬õ`Z‚fl›ÎaP0MŞ2Úç…'`{,M¼ºw¼èäsbÊŒ¡,„@“oñ˜ƒIÓÉTpüö (¶¹+¥Eİï9«±è)§ôD$`m:Æ3½ííºÃAP4m-btòéİEuÈQ?6ì¯kEÚ§T10!Í™2§‹ÎV
(ò=r¼£ÊÃi™¿Ğñk“”>ìºt„Üh“höÄ¢¯ÿıHbÇ´K;©>ğ¡~ÊKX|bs{x"îK|÷ (!î”Î9xÓ	6 kKZŸûš 1’4=ê²Å…lr
B–EÑ·(s‚c7—ß£0£nçñ´ˆífœİÁ7„d§lH iéRÏŠ
Ô8í|Ó…±Í#oç{ß×LHÅ}·˜èWÖ©(Évtçsáÿè}[´ã5ôcÃú¸ô±Î)ûV½™}]‡ş˜jÕ¿Ä\_äÿÛ¹áóÂ£º¢f»œŠcºÙÔÌPpya›âL÷ÚOğóö-ä×(èõ´‰®ÀßßÉ×¦ÄÏÉ7!U{ØÕ@ğÍS^.1ÍŞLÙÌ¼ıbÄ+Ö—Çıºè±n+íòàëƒàdüWŞre£à°È»ÍÕ@­ËÖq<2F*ñ^¾ğ‰ÔëÒ³ƒROaŞ|ƒW§Ô][hÅm aŸ“Í¾‰Cc¯<é«^ÕÜÚQãÖG@Ú×ÙŞş­tUyªÅÿ§{õ¸2{;çJTÍxÃjùXoâÀQÚlR&Î5î’îÈ°¯2¶zôÇºl3+rùN…Â î¿tìØ*Åå¿À¾%šÍ«ŞS‡|™Dk¥¿±ºÛeæp¸‡É»ÌÙ‚gjÛá“k××ÜÒ–4\y„E í.¼M¹j$15 ©;÷^îP…VÆãbÃ×µ™›saÏTÈYİVvj%ş
6‘f›0À*3â‡(»®ôFí§EúëQ6éÂÔ’pÓ»®Ş•‹äÜ¼ªÇÙdbáÔyÂ—JXzI.UÂ[îwØùsàİK¹Ã&i%Qå“M -Oİ.é¸»GËışdxŸ'Ê7ïÜjû çµ›“p¿üÁO2 tÊuFö’ñjdg æ3şG™(ÏÁÑñßúŸöşÉùøÆ"õ)½£b	cc‡XìêD€!ÖÉÑ>C¦ÿ'¼æŒ`R9¨f¹_iÒÒ®p{Îâ“!qô-_éìæÒÛÉ'iC¡ÙÏ€Õ¼U¿ß×ú\}€2=b¬ò­–sL´«ì}ÖÔšy-Ä¬²™nbS3ÂHlæšqï-†¢í?'·]u]æÚTJ[}şÜã¢İÿ€o@)ÇE¤ôà¦k>ŸFà‰Ô‰EÃ !ğ=Ã)avj3áyY¸û¼„ÿæŞåáõˆJ¹µÎ€KRóŞš¸rÕK¯õ,€úÀÃ‘Âíï\ŸXÿÌ^[Ö¢‚ë§à~W¼:™“z†–ã³‹Ô­Ë„‹®g1ÙBö¿Ãñ¢V*Éª•şò+—Có¼â#§ñaw±?J„Ä“{U*à½eŠ/TÍƒe]à‹;¤mâŞsé»h€Å[n[º‡Ï|Í"‘†YÎDkÆîÑ4_¾›Ñç8[^(#&arly]È’ñÖ7GZèêK‰|JÀ6*SñmàÆæ×ö<y²¢¶Ö1B>9×“ÿ¥«½
Œ+úy‘}ËÅÇ¼àû`¶] ÚÃÅÔS_†¬'4UÊßóñ#Äˆ¬ Àº<Æ ë}NNú>úƒ“FjY¼ILŒŒÕ_ÕMÑ“ÿ\qºôKO^H-ïğîşd|oNtĞIŒWBÔ 9•¦F+C°Pš‰ğv®îòrm+ŸzşÍ»Aån÷ï|3„Àğ~û‚ ›Q†yò5 ËªÆê*¹nÙû[‰Œú· sQx†Õ–R8´áKáÚ¼ªT\1‚4ïğ‡ÔÎWCÇK¢ô°"›‚Í
§O'yFDªŞnƒÇ~’Ù9æd÷GÉÕ´‹¾BÓ—j–wpJ­ 6lw$¥¯öª¥Tï#ÈÁ8Âó~×;Q~KàR{ê’j»@L¾·]iÍ(€İ!¸ru^
è£ù†õ=œ™=Ë-g£eğ@ÿ;94Úƒ¦ÊXE?SydŒı5IŸ¿â¿sòtØÌ~9#¥dTòaİËÊ·æ?‡Mo´1p´ú7zit™ÁØƒÆ8Gˆpµ˜ü1ú 4Ÿ/êf³ãQ¥K—{&ì¹C”bLˆØ,5E
ùõ`Î½†YSøãg7o†ÌÈ‘€±
Æ{6ğyõóïì(_>yâ}¦ó Ä ƒg–Ù¡ Z×qÌšçÒµ@è?<9!BŒÅ¡-NÂº;m_¡õ½†ÁÅn7ƒ	¶·Ò#‰ÛO6®’Øâ­IaZ»Úš†óz¡RlAŒfv^ZşÃÄCñÏÆÀÌBÇ—½kÈåfi‚ô ²ƒŠPBøâ`J¹§üDİ^×«\­×~„ÍeVbşÊA†š±“£±6¡€üÌwôI6u5T×“‰."Pºâ÷j·{SÙ@ÜÙ‰.BnBÏ&Å¼l~´árå¾»À‹v;°U½i©û·k
„n[ÓmZ• Ğ¬ Sš¿£Ê?ÔËØ„Q5şŠÃXAõ¹ÙGeA4TáJ5ÿó}•a‘‹±†©´,!®¹÷}ÔŠ¿&­çeôwÈŠ÷=£Ks7^İnÚA÷*ä›i0 ú½b³œ’Õ8•øàOMÄÍäÓÉÀc¸ÊœùŒ:‰WôúêïèXéóDË•¼:Õ«6Cd¯kb6.«eŞ›¹ÿŸMÕö'gu°Àèp˜ùÿÚTÛt¯3×©€yá’¬h­²6Q·#/….€¡•~<œŸø²Ö&-ú™*‘—6Âæ«§ÕÔÍ\QÆô ñ	¶™„ù).ú.”¿2¢r¬Í }€
5<ÒdûFDDòÚÖö–ÓÙİç~ÆGä}²ÑBF’Nùâp.k/ù{³>©¿0z—ßãgZçM‚¢ ÈzY·µä ƒVq#³GŸÊq.´\†t!ÈØK‡E\†ñ˜Šœ‡Š’ì3".ÍèñsçÇŞêØN»6şÚuŞ`Øã§¢iÍ«kœ$RN„ŠÔX²yU>ärÄµ2aşáTKõx PŸóqL5İQæ£–£ÉDöğw•6M}ŸÓrÖNl}*õ~£ˆ%01û}¸Zd†iR3‰!IkQ.Iê€KZÆé{D¹wE?c²dÖ:ÕI|íUG¤Ë…Kd¡pš–?»Xƒ…¡Â5J?ínáàO6ö ı8ÎîøÏAáW«àÖq§?[»ıÔ¦¡è !ÃÓì²‡÷Ú®·oŸá¶lşéaVögº%¥6iò?>é\q qÔŒe#	AõĞ­nÉ¬,p»$¾‰àşE¡ıÇÎ‹W3ÜÑOÂfŒ!Æ`M8¬s 5¢Üš¹6ÿ˜J´™g|¥5{Tm= cxkn]vŸÜ4ïÔÑiU:”ç7zœk+&Ñ)“DcäZzœnCò·2wïÈk®z´’Q¨ŠpwÚvy™ö¸ëA?‰ş$æ,;ĞÂô!¢1*Ã> ¨pØAÆÛ¦öÑ§7CëgÜtºZæ§©]¾,ïbY„'[H¹!ZÆtxîì7„H1R¹È# ømÅ”›òÿQo†¶ö¶I–ÖYeÛ‹U<u	˜¼(™éwB³ßÓ@§Ÿ˜bÎ^„µ»Šïåìà²Måû¿òÀ€Dœ:Æ€“¯K®œW‚øê<Ñc &ë(DASh &Un_„1ÇFŞŸ¯à—À²_\uÉvÚîxş mÚ5lÛ£Š”*¾¸ÒÏÕı$VHò!3ÏÑºò˜@	Ğ‚&öYÀbÚXëı$Xù„_4_¢2û–ŸÉKpuíX\bKã££ Şÿyr~	x¤ÊÈ8ğïZ´Ñ¢×Mãç(ç¯nWÔO×fâWhhÂ>ŸèDJm —0 e8—Æ–L%7·éÕñhÒIğ|)¼–ªŒ9ó÷o/ááEZ1ê$ä¼bSèşå“§£ç^é‹¦Â€ä~zÌ4-…nÖ±ì¿÷cŠd›0ìó
ÍtYôG«|ùÒ¸ş’½lèn!ú®ÅIØ q/¬Ä	•B‘76¸4·ÖvÀÒCÀÓÍò¯›Häp¤á9ƒéİëíé¦ğÍ	êü¹½˜"v¾×wg@kú\ÿõ@ÜĞ°>sĞéní À¸ß¬å~qÕ®Ÿ5ü«—ÜÇ¢ŒçrËÃ<@H‚›g`òàè-„Ì(ÖéÅ4Í2‚`ÜœüÃ›ÑaŠ÷#‰ø’;ı ãV£)5l>§tå”)L¶bã€ò9ZÄrKf1¸…¾­Õ&Ğ>~9çík/6²Õ˜ŒX"õMo»_ãrİ{Ty¬2¦óÄ¿À‚d5²­Î\½Lc-tOªTJèßPiòĞ•_³©&×İ74ß‹
•şWZÁjT¹ÔËÏ¯ÓiaÇcµ_;2e¾uüO³%­ÓäÓXm+4ÉSÊÍáRr_ûLuíÅ³¬8ït¿_©<}í3HÌ)V%[Ç»%n¾|‚7MYpt&J6Ÿc‚¾ë	à”áqê Ê©
êb—±t}†áèÈ¹£“¶qÜçœ%]L‹p‚4Æ¥“¸(E*$QzŠ¢İ§ëz|Ñ‘î®¿é4€8›BZÌø:fîĞçÂà6ªæüëã~8;×EøÙF	)ía"sˆ¥]‚ùÄÈFhi~ 	l8âÙˆ¯^¨‹Æ]EºVšŞå|,<Ãì]íÁ“Ãò‡k`qÑ°Ä¤Œg–3¹aWL©qÿ^1MÇmÃ‘ì[ÀšÉzÌµ‘ ­’Ğ'Sl|Flë ˜;#ÌË]œ‚m²¶ÜªØTõ4šéãÉäZ0Jô¡Ê‚©©ÎÇV•\§±¸Ï·%Y×”C×’ô
p³j‰XÒ1¨(Ã,mš™ÚˆızÁu%iêIk“Hû™Å*à?]|8yk÷±D’b‘`YìtÅzÛ¾â¤ìcÆhìµÁüÄº[}$ÛŠ¹»»ĞeÌ—Êslƒ®—£ãl­©˜ËMÙƒ‡ƒÂ@ÿ)7÷e}c™şòÒv0}Ä|^I¶]fxAš•tË8~òİeï±šªÈ@¹Â- _gòÍ«
[†v2ìÅ¢µnÁ‘¾U9s\Îƒ8ö jh°LÁ“Û#°Ü(và„=ÜÉŞI¹æ 	±tÿ*SE¸›‡ÆWŠÚ÷c çTîû„Oêü”28bk)ıqŠül¸yûŸèâò¾Á°*í8»¨Ù:¢Qâ´~R ßb!kUùÁ?õÚB–äüŒVéî e9qt½é“ƒÙ€åQ¬]‰kIYuæ}“i¹ô÷ÕŞ¡>GPXà!"Ş“ç¢õàOÉ*4@U¹Ì?õ"AæyÅOÑBuö#áÚ×èèd~1OHOï½ÊÒQVK”n,‘Ÿ
ÏùgªM	6^„¦T§‚p˜ğÀ³ÍyV£Ì'†~RA‡—<E‹O¨)ş‰¦ÇñnA-åÚæ¼†ù]¾¤ruO.*kßs¨h5°Mñè.µà–ÄP%¡r(Ï9©~HwíÅc˜jñãïØW5è4Ñú?”!Í‚õÙV•ŸuğË´ÒJçOh]§
©œRçãdKê*ß¥QaíëîwG"=gú#ôçZM.üásrW©ÃìÔL´8¥¯‘ ~k£ïj×ı¤L5”zŒÊr_¯D® qèöò° kï/<Ù^^H9“$kÇ¯Ñ¾&^[¸p%$Œ)ñµÖBy8ùçX1w˜ù½VÄP§-¤aèH¯ ²J‚+ÜM`d§–ŒsºŠä'úÓµ 'º]úWSÜWJ7*1Îk¾CÒÙ q{>›|…ş=_Åß­ÙŒÆpm.N/üdğ"åx§N5Lğ-Úv=ÎYkK+LG#) ºÌ_Õ¿lJîFÈ1®ÄŠH	Im1ns\2ÚivØF;õŞötˆÊ¸şÃÊ@—®¯¾Cò+–x‘<DNe;YcšVãÀÅAÜaÿå@yÛ¹:U‹]Á“·fÆ]_ÁMÍ·ÿ7Y:jR…Q¿ã'şŞdú ¤U^ß­ómÀUnÀÿÙJúèit¹ö”ùãêÌN(¾ÓÏ‚]®@ºXo
gÌÔÓJÀ’ËÌ²ûTï¯™üYG-9”¡}òÑÀºÂ:³—x*ÑœÈ”6+
in%+Ÿ]’SóÿÅq¤Ov®Ğ‰•å¼8`PÑiUF“Š€Ş4qt€Í(Å™í‡W MÀ#¥É¥©–ÖşóX·ÿ—]tsv&ÑÌü1®Œã ¬D‘˜²4fó–Ãˆœr7Ÿo;öş•‰1aS¹ÕNÛ(ŞLMBÖØ„k6ë²N.Xİ4?zöMp¯Bñ+ğ*Ò¢ò‹È,V]o²²°…ï\‰•õõ8†ÉHÒ³õ„F=Ñ6è;Ö˜âE©ÃJ¢—™—ğ\5ª*YíÕÚƒ XÒ«g Ù·…QZéÌ,õe£2c5°èØÇÏ––
Ä•\mö²˜—èÙ§ÆDø)¥¬Áa[4m'X.°±ß|%·‰ˆå¿ùùYn~¡\úèæ´,0ª)|C<·õ™®ßû›¤97á§{Š8Ü¬œÎ•v½W¢ş¹ôá dÉ˜.“ĞŠ…o ı+"ßÔÆË·*ÆD#:H(¿Õ°$­h"A?ìšÅÈ“Çğ`†ŒÀ¬Ñ+*üZÆ²2°FŠOìøN¯;Ú2§g‚7jÀ?¶x™Â<Èå_ïšSF%¯u„Ñ¾#L0l”hPôÚÄQ@2i$õÜ¡:_¥*š«`­p„ÒÅm Ò²™Gd~ÍÇßó¸ú‚7h2YÖ+;«)>”Ô…£ÁØío³/-#ò•“!x³
O2æ¨m0¤ˆ¾õs™ğÕU8Tééò}xõ`B5çpæìqé«ïØ³åƒâÑ–˜¬¥´òëD#1?ìß=N>¨q—2W…CÈˆKàº£*IjèÅ­e_úİŞ‹¼øÌÓÌ¨ğ”>¯&aÑÅv€õÌç_>«¾òW¡1ÆK÷K’ÅÀĞØMh›MRb\:äLö”1ieÊ`;®P
›mS {_õÔHce‚=|ñmµı@A“½D“P;dXŸÓõò·ƒñ­@èHßÊĞ‚æ{ãvyO iæÀ¦t)¾eËR Å1ı$Ë-“Èš«ãş÷¿/>…ÎrôñatÑU«g¡|Ç§˜ØSzÊ}y4Ş¾ÊÇ¾>Ër}õX\W9¹]É¯«•¼“<@£¹Flı^GñyÒéz+²Ã[?E¨5™şå¤Ë”¼7»ïÆ™°¼t¿,ûë…8ºø`ä-hğì¾nr¢TÕ¸Ônµ‘¬¤èêû
~ÁpßJ\îÌ¤Åo]=À¥˜™«m¼3„Ôµ­÷D‡V	ÜÅî:˜œÓûŸÏö³ìa±Ò±N>Áæcwòµ©Èàóá¥ù.ıÆ·(¥B-İŠÍŠLëÌN¦Áú×xôŒä¬5u ªÒrkuW¡'[m¡:í`¡)’qßŸµÇçB}Ö#á…‘Uƒ)àG¯@äÕ”C»Ì ‘Ú MÎZ…Œ[VD˜$Æ7¨z]İ^\{ƒp Q¤±/²:j±Nˆ1bíI¦şÙpİ«y_êï>Ç–¦îç{¹7ì/mÅ€¦âoöğ,Ø3¸ázŸË‚x ÉWYíj÷ûÁšz# iHÏÀáO²„X7~@§Ï[ø»ô<&«à@èøO.‚; ÷Şú¬pÍ•FÏj"ß«œÄî×ïZWë,bòR›p‡ÜY.åÜ™MüÛ†4êÃöè¦àHÊ:5¾É›O»ğ‚¥Î*UYtÁpãèPeòU?ºó(ÿpã¼AèÈùş¾FÉÛœ ƒ,”_•ˆDÕŒ±j—Œ”¸3.P ,•cô;…ßm-Á+,Ã÷¿ÿıÊÊ›ÄÎ5á»ò}zC}”…:„º…}àk("ºDô@ ãÿXV ¸$“ÔÁ91Wõ“œˆr-ã´ØH[ËoÜ>éÆ¬Pí¸; b!«¹¤nıÚöÍ:<Î4°y )ÖRSo×„x%ø6X4%6ºxÖâ¨W8‹O£ŞºŞ¾ş,m‡xú‡¬`i"=“m:uy‡§Áç‘ÕÂÒ¡Ï½èsô`â_<Şí
ÈiÇv¹,DÔ.qE³ZM#Qê‚Ès¸)Ù–¯Üó­ ÎR´²¨z#acÿŒCÓ6÷-W3êyü>T0Àğ~ñ-½h>[¹G6°ı/}wTÒ\£±BQÃb¯,t2F+Ÿ„À2yî$JVôÙ†:—MF„¼»Î_åyLWÊäeÊµ®÷Ço‹¨j£pp¸?ñ;"¯Ô¾Öéá‹İÏ)œS9í#-$0ˆÏjbä?K”âwğz°åıD::R„Ìâ÷Ò·KÙr&Ú’#ÊFêvá~D¸%uÈİ·dçÉCf¢ñf÷+¾†6Ç	­T.2†Î™¢–yş Åû`ÂVn	µÖ^¨’‰Åæ6?T{˜áóê¶• Í¥!ä§ÿ8dãÍNWä–’çk‹µ¢ïz²B×À³‰R.ÓQª">±ğ8 “¡g÷´£š|ò³n¬€*ä#æÕ^_Ûp^í3î`†ÎZğ¾±Æe¥É€6HkİBÛ_-÷ŞEˆT¾kfa­àûxªœ®NÅaxÇ%ïùÕ”êI /âïÏGK&×a~ÜÃüWX­ù~…å=ñ˜|É14ã¶·â¹;É<®5%ŞX2TÙ všøñòkwçc€Õº¿cQÂâÄM¾ªpwt)Ñû=dhÒÖ;ÜDF¬ %ŠÖ~©ÄÍjãäddo8]’-_³a©¶ãµ§Oç —Eö¬Ño;1Zj7Áu2¹z”…ò ïQÖJğõøŠ3/»s‹Ï`zİ"şEºÑßÿ®yÄl·ÿŞö'çòø‚[##tº-ú)ÊûÌí¿=•{pÛÎÿ¶¶E•›¹u¦S*­¨ªß§==(JÿÍRË’|FºšÿoæçNiùĞæá—&=ñ­]uzSìÕ¤<%jøräWào@—åOŸî[/¦ŞùJëK#]#¥*h';7m‰,Ìø'
^xd$v	©W¹ÆuÕM´¾|æ¼/2}†]E®l'µÅâ{ü|«yäfÕœpS“hßòÚ<á°ç8’®([—ıí(°;æHãşeâDn_ÛŒ[Üù¼Ã#0ñ™²‡]‘¾rzjIÑƒ#‰Õ;HĞtñqÇ\‘ŞL '±GÚ	ß"ë%^.[æÑWÚ~#Œë)ÂŞ)5‰1'Ô‰#‘¬î¹(‰±çÂ6ùOª+ºÖŠ[Í»cp!½f¦x>6L´G UŒúbÃÒ' Qó,adw5:RÉŒ¨K‡«ó"UMw©¬ÙÆ‡„uÚŒù>2{0-Ûq‹£{7Ê%CÍ¼â|j¬g$œkå·Úæçv§¸`ÉÏp£ßo[×·–záGéÎæC¨’ĞF}bZhÇ–›š‰û hÉ£¦2UWëËŒsaR¥¶ƒŸÃ¥ı¨øV—¹8èUéÇ„&ì÷¢÷©š«­ ¾V‡Ö,Ä'ÏNïCj°¡é<ÍÙ9HÅj†T½Bóñí[1–füXsáÌƒìÏX†ÛÄ¤'µÙ 2RIó$>Ššƒ±Ö 'ëÔ-Ø"ÍºPÍMª@å8Û’_XTÙìÆ”qÃò×uÎ,Öbsfæ˜ª¸Bü0*4z ğ±ÂÏq!¡”™úR6m;UF-"‚cI¦ÕWZüùˆT¡NI­Ì­Â“ÔwŠ\œQù º='@n”=*=UÑ ½ø¦€ :”‘<à*_ì­…=S±ˆû@„m¨Ò¡Ó˜ÁZìP˜%x÷ÉÑ?¦L¡]IL¥¾Ç>æwS›èÖ8~İè!Á´”Û¨ ·eäâ´´ÍœğÃ—®Õİå_Uåù¥u•544Öª'J‚œ¸³ËÙ	Âä—PTãR¢X“[5sl&§8.Åoxówå2ËGP¾>äã¼(qË%hÅ7Óz6Y™÷æ3`ãò€–SÂŞ@µÉÕ…rõ¢¾‰dä¯‘á£c<]{äÈN°œ8|ÁÎì	SJ/–'Öm+º%s½“fm$)X¹Ğ×ƒª¥¦gâJ’wØ•a¶1Ğ¯È¡e¿æKÍ¹xMä“@®½ÛyúÕgMË
  ‹Çô´·!ø#ãöf|ÏíãlK®Œæ·USØºè¨f–WáÜ9G´È@¦§@HËSåÖ+ZívÖBs/™ç•zÁu0Wô£“‰>p‚mF<Ã½ÿøC)P`.ë|íïE½wé˜†C¨œÊğÄ~M {« UØ<MÊguĞÑ<ËàÒ¢vı’eB/Œü|’Kû‰!¡cx.¡¸X“Y|½*¦c‹¶uXåxÈv¥íQ¾•ı1RÙb´õÆj‡ì~ıĞY=2'§¨$†D­œ!íË Š›’Í™z*²5×\ÂŞ%òë¢)ÄP#mi"GR;¾ø\x•nàÇ&¦á† ^İŸplU•dıußÆîbDŸ¬<6ê¤22p˜ÓÃû	¢ƒiÈÛ2²ã¥¾ô¦E=sç6]÷ÚT#¿†=¥âPOìMŒ¦3f9Ø-şÍ¡{8Ó`QÙ{íº	i,ò”cvõìfà[~ìO;„51øLú½€ßÖn½(ìôÊò›QNPÛ“¼É9Ÿ?Øî¦1ÜÚáH½€‡Içtjî¤¢kîìN<Çøó“BßI_i;$zh Ûˆ¹ imöøär—+>[—;Â˜6-…~şj‰´V¡Ó¿ÖgÂ–™Ë»ı_d=ƒ]9&iZò%-QUx@˜¸ñÑ´!ÍTÂ*Äá®•E °²+…zã¢_Îç D©‰ÂZÉaÉ€xTP¤“Ùÿ–1o­ea^)TÉ[#óËÂ€Mº¬‚²—¢üŠµp¸ÈàøÉ!í íîÊ_¤àhKÃ›jD%À¢Ú¼õ £‘iÏ+·¿MR÷2O¤ı?A†°gêU™0]¸]ê$‰9Î†¾'‚Kx±±tòŒ$’Ûé¯©¿í§_úâfeü“l×ê›>ëóáõ="XEÇ÷Ô	Î–óínN)ÂƒH¦w¨Xl?ÿ¿¸ó“•ı×`«h"3¹ì´ ïüU°Åä˜(+á
ğ@¹~í%/+Å ÷oº)£Œş™Àê£)“ÂËºL¹Xİ£ÅraÙ¹lÆd Ui…#¼ÃˆÈòR`½éYÄïø÷œå›dğ)$İÇ³¶Ebh
È¬é´¹Î*øÂ¾å…[Ù¨4ëŒİ‘ÂW†’ñkGAfàÈ,È‡üŸ9bD7P– ÊÍ4v­xBû¤bVÄxXd æ˜’’+¤œ‚TÛûÕ4AB@jÈ»ÍŸ<ô›ºTB3l‚ëL®ââ(ÕU!‡ØD:–­E=Ù*‡Yå™BQk´0f’¼ªñZ¦Øv´jZ›(€Ó	H^˜AŞšDâpu9c<Í¹ÅpR?
jîå+IäÂN{,PÂQ“YÑ®|9ê°ƒÎë±æŒÅ#`u|tJN­çz%‚¯,éG,oeğ˜Íÿàf7'nëÇ@Ñ‚mJùä2»=êÕú@››§#4şëZk¢{ßæ#2§i£
G$’×>‰™ñìÖNWe†ÛZ|p#'RˆàqC¾	¿+¨lqrä«£½Yé‡™pĞ®Nj¹Ú`åQ4JY–{"œê¹óH5NNW‡_ÌI«4¤ïÏ¶Bh.}bƒŸD"ì¯÷åÍ€ù›Ë¿Ú-ĞîşÈÁ­¯éPW»§ZÂSÆQ%Ğ×‰ÍOü³qÃS˜¡9 ¢ı~†ÉÑÒRÉ³8'˜3Nÿ×wóYA¿%[¯¼5†qzSvÇ–¦*,Xøòá{n6AvK#öäÍài‚æõÅ÷ùÚjNó&ùĞkpŸgØ®uYhèEn´ÈÿP *†=|øvéÑvwË—'gÄI@  ü:/'Í ¦Lxc3K‰œg4,²¬Ûá0ç/nªâ/*Å½’¼ğ»ë¿Ôq)3Àk‡W¼X©2æ`W]8¡»aäÄò­YV»ô_!'ÑÉY‘yå@Ës  ¢9! yq1ŞT
ÿÍ¨–ÂêÈ»;ÀÓïˆõ0"J´ú]—şe0
dÑ°YË¢   AšF&ÿ  	Ëü@p…ğ   1   mAšf&ÿ  
GÄq¿FßP.ÑdñúóòÕéÆøqX~qõî\HzúR©vŠE“Çªa”6­"”-Ú/¯¯ø6Û¤(†¢ŒÆÂÿ„å :Xª°E~È3”ºèyW¿nımÇ\¤û3—0   Ğ   mAš†&ÿ  
Äq¿FßP.ÑdñúóòÕéÆøqX~qõî\HzúRƒ´}ƒÇª`”6­"”-Ú/¯¯ø6Û¤(†¢ŒÆÂÿ„å :Xª°E~È3”ºèyW¿nımÇ\¤û3O0   1   …Aš¦$ÿ  ›ó{ƒ	ıM®¤G÷ÀáøÂoï˜âu?±	ŒÙß”IÅŞà+A¿_4‚LU×†-«ß¯n2V´ìX+ºœÄ¥	LZfÌ@[rë—j°Rù§dXûts©2°İ³Ê˜Gúˆì­-¾Ò'võyZgÃ2î™4oÀ   VÀ   wAšÆ&ÿ   ß0€û¨)Õ?×k–'cL†ÏÕg^¾>M“6·]¥D?"ß‘[\ÊFº·yQG}õŸqU$qi¬2YÖb´™+Ğ
â!*­ñGuùæl-*‰nĞuƒt…ÿ]yzåÍ±ÕÙ!ò   ™   Ašæ$ÿ  ŸÔEJ˜:ÍìŞª§Ï7v…ĞnIßÍıZøXŞ~qÉÏ`Y¸€öáˆ©GtìÂÛ¢Eœè01^â¤[¤Ú$8Âş]>û3'/ë•§ÆñJ~Û’YbŠy”…·*NDÜÖå™ ƒ ù¾”êgG²%¸Ú   gÁ   A›&ÿ  g~(B4ˆLIW¯D0œpø'üã¯Âû^~!Êÿºõ~á]ša²j`Û˜¸g1Ô$ŒSdì½ğ€6×éjymÑÜA¾J©Ã0—‰‘Fo‰î»³úYe0İ0ÏÔ‡ïrklÓˆî¼!´iXC\|äårÉ0´}°•6	W5$   Ü   A›&$ÿ  3ï€¼å¾ k%kR§?    >`   A›F&ÿ  hÑTÄ«çx’ £S€   SA   A›f$ÿ  ˜ïb"ç!)÷Qí_±    rÀ   A›†$ÿ  šÑ9ŒU0ø¿Osag;á¬òL‚ZÖÿğÀ·Àü<„¤á—|d¤'X‹¾§ÉÏÓ„é3“!À@s‚qœ_ıÆHÄymßáÍ	ğÅ®¦ÆÈ«¡-µá–Z%Ü—Œk"ë“ıc¤¬Ã©)EÆx/Î;}Y·‰NÌI
§bU?D§¦|f&   ©   eA›¦$ÿ  šĞ'…—‘ê]ñ¹AyCÜeØ?Ò€;^ÿü$Õ„;=¢ĞÔß£ø!û¢ÔS¸Á&k¨…‘1YÅºæÙ®BƒäŠOÿâs	’ßC{Êüé~‡    ;    1A›Æ$ÿ ¯–JÇ#¿ò—ôÉÍ"Ÿ&Tå£Y …à¡?	Iz˜pyá¨   —   RA›æ+ÿ  ë	àNĞ‚F¡ÿRÖá+£~ÕÙñ•VòŒàıû¿şHö51ÿs&…aä¨.?ôÄÖıwãù#v3ÎÀ«zÈ    —   PAš$ÿ ¹¼•b×R(~uC…9
“æn]†æ|ùHp‹Æş}Kâ‡9[SĞ“gÑMqíÉA-9fá}{T=‰§laİ°ôƒŸßÊ   /   PAš&+ÿ  ë	àG›~
@	»¢•e7h}¿ÿ >ÔÃ+Éù·„ÿ?¨Ş<vF;ón»¸êä}¶9¢óş+L~¢®Áğ    3!   |AšF$ÿ ·rk+Üˆğ^6Î¨¬Ğ·»ÁÑı`Õˆ~H•I–EÅ'6VğhbÂFGÅ˜içÿ(’]\ÁÕ½j÷nI¬v¿}¯U|‰LU¬è'Â¶ğw¬@HĞ=¯yİ	aû)bXTYÎ¶¼eŞÿ¢ vˆ/öˆ5ÛĞ„à   Ú  Ašf$ÿ m^|b°ñ—¯GÂY«Ó`ƒ‡“ò0ıx¹#(ØYD;u½Ëœú¹OVŸˆ•×CÇ<-'¶Éï"ñ§~¼T6y¬0Gùq@"‹I*–ÿìÊåÕ -Üó.ª¦˜¬ô-o%¹hÑ¯qÁë¸ÈÜ°pnÜ8=’·0È€Yi4‹@BÇ$è7ıñ.êNÉù‡u}®_ƒ»£ŒYDõ‡€‘¸x>eÀœîİt'6æAu²—ŞD£°#ÏŞèó ²X#çµóMÊi®Y%w€ijŞ©) ÒÜô=WmõÙæ.…ûñ]ÔÁhÈ|©ßï"*àÊşÔûŞR+[”€   ¬µS°¼HÂ<©°   Aš†$ÿ öÎ}E]ÄœEK‚Æ71®‰Qù6æŠãÜÍşTø2˜U€-Ï"è‚É+á~EµÇRÔÇ@nãœQ"è)º'@,QhS<Z	x®¹ØëSëˆMGTD%J;Ù®RT<ñÅx:õâÎõ~´£lÿCº´èÂ5ÏíŠ õi—_°"'z±—ƒ|ë±€   •   ŒAš¦+ÿ 	†¯1©’Ã>1s×`sÑ)=•ÆĞğ¥‹1fÆ5“Ã³ÒÀ  dlËi×7YûU	ZGV+!wØ¨@)\·ÔãäË‘=»ï§?r§,F)Re8ZIƒge<ÚÉdÙÍùn"Ç·Ó<µ­£ pLÔU›1ºeì(é 4èŠ´µqÚ€nß€   ˜   hAšÆ$ÿ ×6$é~üRªwù«S´Ã~îQoK]I_%‹§‰Ñ•Ôø‚óg¬?ú¾€hyóÀ«YS¿t$CÇdy<õÎY­‡tz5]Jâ+ÔUKŞcÀ8Ã2Ï'@3X    ¦  7Ašæ&ÿ 	Õy[îË¡èæˆß3©Q¹Çø!–GÁèş‹Ü?Üd‘sT	swoŒÄ@ÍsêÑgP&¶>¾©"ÁÉ Øá!…wë/Fr}ƒïÛÊ6ğMºFT¹m°’‹eæÏCş˜/ª‡Èû©»-µ¶{ª-…{É˜HR?AìØ¼Ô ¦æô÷—T¥Ñtfİz"’ğ†º×^hOìlÔlöGBQÓÌ´¤jÂ•E«—˜3ĞW&±Sëa¦9ÓS”¯©\Î÷5î3nåv¤öºDìG©7S¿6Ÿæ­>–F²ízáˆ;cy‡(ğLĞa#Óø#8ó×wMY¤]ºó›™hd¯úJÏ4ÏËs{B?ÔI€3Şçäk(¸eıı™qï°TÓEüİ1Êï-”AHÊvÉ-<è|–N±iDNŠ0AâÄÚ $Çb23¤ÏEâÅOåÇHM9ÛÚÃ<tE#í9TPÀÎ(‹~CÉ:°Ö¹—„ÍxÔàÂqåz›‡8Pg&æ3¸}GuXKDÁoælêá¦Ô×½ÅäÅ½ãÛ%şÇæ“MÓØó~Æ;,G¹&£ºÄ=Q¾’¼"„ùÂùdrÃ¥‰Ë
põÍÄ?ÃB¤°Ñ†ËàtÏî(HÔ2öQ¹“e: ì7—wZ3î
dÒşcĞ¢¯ª,[uÀ'¨Za5ˆĞó^7µ4˜_Ã‰±œW ¶ı“<¢^Ş'öää§¾†w™WcÏÑŸm[_Ô!ÕïfdÒíúÖsM §&yç‡÷­“](ZÃ0‰¶® óñé"`¿€oCrº&t4	¯`a#ã'ÊD”«şè\ÿ(ÿB,¡ŒéÀªµ´Àñ|‹Ë¦.,õ}¨3áÉ£L*½GHEÄM#ã‚VkÓ@®¼d”r°Ã¢;ÄWèLÉ@8üH)Õ#‚‚±Ù½ˆ¶7µQäÂ9Æ¦qlõ‡àd3ö˜0r[¦şëa”dæÏ—ÓÄÙ°²Kq	|I«ìNN™	]û~¬şÖ|5D‚6ò…½î<2V
×UÒ.¹¾ÔÎ%üÄåñÜÍ{Å÷AS‚›°óX„®’” Ã)3é¡v2µYˆ]À¨Ö<´bƒ?–EVúæŒSj*ğÓUWNŞæÄ«g¡Eoùéx€şÿn2.ŞÙ^`às±ÂÔ,?¾~^&3tï‹ÖÚóÔ.õ5#Ikúfªf»%ª{:ƒ8'‹Ò‘Š—_XM'wµ¦ds_©&ëc&D³ğ“cJ#ÁGÆ¡·È€·Â“ ÂŠÙ¦ïfŒœ .Ñ×*§ˆ öJÒ³Ë0–
Ü’$+ ÌB`í¤† Í:²kef,Ô0‘À?Í7Ê5qÚÙæXØxˆTV'[\÷ •õD^qu¯ë,Š‚†®7 ’ƒıœSG<_½Í‰ƒ`óñdˆêËÔœ™(ÓŸã¢-¥$øUrİÈöÃû–“°ƒ4ÉÊóÕwĞ ŒJÜ:"%*'¬‡ªaÄæŒíKÿÍŸoŒm1j¨õJ##nóõ:¼nØìGèÇ+*ÓA€¸:è	"ÇÎ“ı’kÑ!kùNX»&Âwµ\wøcËâ!&õúG¡±¬+)	OOÌZà}ÑH©—²úTÅ+òWTt6KªNÔÚLy{ˆ	Ü“áĞf‘ÿÿ÷\s,½?ëPDqÕGl.>ci¿WòËŒŠ\i_ANşd÷´œ_`ÊXÍvÑ8Š@´$ÔU‡cºãòµ„ +×³bğ€   Å   CA›&&ÿ 	˜Üj[Ÿø\?µ¸½odĞŞÍ<u$¿›œGæÅÿÚG)¢e.ûÇ‹¸~‰0b°    á   „A›F&ÿ 	˜Ü\š³?š†>Zy¹¶`§€Ê<šÑ|êd?÷ê€@æ©-Öf+^ÛáK$Ğ¨$·ì±Nƒ¸ìQ²˜øıáö~¶[GúûLõğJyƒrç´M&È«k3­j~û™µ>Ñ±p³ƒµî'°ÜñìjXÎ¶úN‰Wæ4«€   ø   }A›f$ÿ ×<fkªîıVµ×Vªî!ó¼N.±W·èOzf%z`ßj[¢7˜æ×$¡&ûÏŞŞP—ƒûZGëìÛÙÚ¿Ä]oH#•aPZvÑÉUw˜Ç¾„Ë ~Z§¥_šªŞñõ¨K±U£eÃ#¢9è¯p   S  ¬A›†&ÿ 	ZæÆ6C‚V³õ~%)9²Ê¡2sœ^hç@€7‰$8Œ¡FóC¾Ã:"ı8¸À3©ÔËÚ–ÒÔj#z£ğ÷ª§…lŠ(¸L†üšL¬•v9bÍKIŒo°Âœ‹·Î‘ßïÆ.lö¹íTL ìT“ll”ĞBöm¯£áı‡Z Uo0!UqTõQUÌ:ZÂoŒ¥G½“PK/Ÿá–A4y‡½‰PÒÊöÕ¤%«Çb¼–Áşöm¦ªJyê´Ş‹ï;±O“;@şèMzã€Ù)Rñ–_QÔo4p‰rA4bÖ¤Fş†Ã<0ã›ÀTd_	‰w.}ß+¨†æÉ×I‡ôù¬,Qv',O·…«m‘©Õg5¡ÍoÒÙæw»ã’Yƒ^ÍÄÇùÄ!&V!iğÀ:Ó×ÁWZö—ÜX’!¤@3ÃıÛ¦®Uä˜¶c½®`˜ŠÉ RXØ<äçS!håò	ëÔ¼‚ºr!hßşQhNö—×ÿÄTÛ•ô©l#ğu2½ûè`1Á   ó   ÀA›¦$ÿ ×6pNEâEğQYš¾ ğiÄü¼eâå"[ğ øw¢šïÿ À‹x­ŞƒhØÔµTUú 6BŠW.Ş8—¥ïo	]¢RÿÔš€}Í+éÓ¨tg]ç§¥~G	šşØQÌË‹‹ÿ {Î¨ö"xnßk¯R6ğSF„§9sVi‡a…‹ŠŞj@´QR÷şT*özR/5HmŒq¶àB¹š.ñcÂÃµKÙvä    €  hA›Æ&ÿ n5@XPhÿÌÎæîĞ¤ÖU\Bw.nî¬zìÇÙGOyø¹„ÜtT‡Ä[íí?Ì›W0´c±'Æ.È+áE‹¿§,x_ï»uı¬gá¬õ-‹V%L”iƒœU"'M„±‡Xf"dÓĞZgŒœÓUÃlFaâ?¬sD½@ØRÂTß +Ö^rÙ-{·Cğqk.˜şlR9à%x’†Íb”²N‘áoF%ûXóX·8â`1‹Yı0R‡ Î]Åsië9
4Aed-®|éf÷•ß¯ÉÄ­*<ÉM 
­D/æHĞègK)ÜÑ€Èç`G>B>¤ĞbØR•¸œ¿½qr÷Ë¿A‚Ë}#â NÁ…|¯5ûMJ…=éŒh0ñZ±—cs‹œ•É¾š£n%_ÌÜÄ	©ê|É±r‚VrRUªCto|Ì•ŸşXô¦÷¡<»E|¤`¤§ºÊÙÕ7µbGÄSH%‹Ö“oÅ&•qßt?†lqf=9<<CúÏù\‚ó.fŸ´%è×xúozZ‚Z^fp6Z ?2ì˜’RóyEØJun¸É‹³°£¸Åqí~ó`Ò×kƒ×ËÇİñİœº¯ĞÄbŸş„ kÖ_¬Fùı’Òs5ˆÖ8T¦M™ı's•[e¬™ò»&nÑ›²ë!ÉÇ5xÀ7Näñg¦•/(ğ‘o&1™/!S–XC¦,Œi®Ú,†ĞĞt™¼´°­ÏÖ¿TTÊÉ]­§†˜O~nÀûœZX|Q)ém˜Ç1Q"İ–í\ÉqjÄBU3m7    ğ  KA›æ$ÿ ¹*ãšMÁáÇ?¬'`ªí‚FIídõq’ ÃËš9bwÔ­8$•>fø{•Pb#˜øÂ‡g3í+Jpz¸µ~èâ²Œ…ëèÔáòªku£«p¢ùìÜh"Ô¯L¹F øOJFÜ¬pÌ+Ÿî+É¼kŒòÛ“6 ÷#DäçèÔŠ×y)q^mdg©*Õ;Ç
cŠßúà_¡¸‚6+q‚ø–EŠ<õ¬*ö½(ªÇ–ìõnŠ¦¶!ìÜàXüeóh#ó€¦-zûü ¬ƒı~5°è7ô$NåM&aSÖ&óàP¥ï¿7ù¹oğ×ˆš*]gk;e-’#ÃãAÔr(éíG±¬•ŸDX§Duë¸¨©`¤3Ú{(bçÄiPÿ2-gZÕÑm=•HÔ@@H<y¹íqr®º]>Ë_®¸¿bRà/(ŞI\‹àäşôÇLPø¨ÅJB» wF
úo?dßåÓ*|¥Â.£Z—-ÂBÇé2/ª‰“`î_42nÏ1†´Ux]yöÆÃ(•T9Óä$úFŠ‚p$w0Ò£¶ò±.ŠR4İG7¶Å1Õx	Ö‘ôÿ C/Ôø7>¬øIòó¸ĞÖ¿_4BW­¬jğ}7îˆ(&e3¾›ó ØŸLoáÕ¯ÃG?[œ)–Á€Š4éÃjÄ$}˜ÏXéKueôõ™2ã¢ _â¦'yÄqk0Ërmdtù î Áë6¿¸tÚiY˜Uá<@Ì¼¥³„   -   ¿Aš&ÿ E›œ°°B1Ã>˜aVÿC5ö!>
¸Ğş² ˆ}\æ(Ïg^È5Ü s)RÁV>•‘¹øşÆºÅ+{:„Ûl¸a<ÕÈ\JbÌMà•Pc)	¹	Ì¢ ÷øè¯WüÛn_4/Sg;_ôZm`¢0œÊÚïªª
ò^Oi‘Ûåzê•ò$µ{5·
_÷"ÀÊ„õ}µ*\k)<C¬Y‚|CSáQº	Ö‘B!û¯#€  E   jAš&$ÿ  -bÇånR‹!^“!Ú²{ÚuT4EFì-ªx‘]KƒxÇªÏ4µı;¨Ÿ;¡A¶œãYÒZèüè4Q›c ©¸Ö!f
ìÁEŒp-œ’©^·ãĞö‚¦ÅÒ¶U@  ¯  ÏAšF$ÿ ¶ó†r¨ÎvM×¦·˜ªù(I	â«×İàŸŠ"” !·BÆhÚS.bˆæLõĞòTÒ|öÁ}±;L‡qô2§)•*°ÿë·ì³¶`+ñ2˜Ù¼T¥tÓÖ]Fb‡Ó+ô,PE)Ÿçó8ÀG'„Éê!A¿¨¬’y‹œ’í_^“ÿ&V4ÛCK”õ¬8'„†œwØæH‡¿¿.ÅQp‡kşi‘ƒcôÇN\?²ó_!Œd…T•E\_2i±EÒfS³5T¼‚ö:³”yÁâÉÄtj‰ÚS‹è„,Ø&B¶ì¥KÂ­p ½,ßgúü6Î:eäÈÕeÃ/t<şdø0İ;…è¿F[z#åè
=ÁPÄüU+Ä¾?uùY·Ø+1ªuü‘ZwcLq÷}M‰ƒNPOmÂ‹ãüå—½µvİj/¥fŠŠ“¸(ÚÙ8ùW<†Z÷rË%p­{}£É‚D¯¶â¸¶šúŠ»[2GI-ñ–²â‹\Ø§›£ì“ÅU5k¿¥d$äv$©Ê¦O/€Aÿ€ƒÖSzö‰®İõhD“…!¹$˜œ²Iík6á®|ìQ<íEù>      $Ašf$ÿ  -oÙBm¼Ó`ÍÊ\•£YÜ›_âÑ   æ   Aš†$ÿ  (¸œk$_Ô›CÀ   —   <Aš¦$ÿ ‚Á™&î´‘:ÿ3ÛîÁÏAÎHÍe¯lÕSWşô&Z¯L8æKÚĞ.e}^@  Æ   #AšÆ$ÿ ‚Á˜âM«dà¦’Ó§•>s¡æZâ   ñ  lAšæ$ÿ ‚Á˜ü
óËõŞË˜éIzƒOƒQIî©ã O*öæö“äZ¢h´Ï%¿ÿ?9_ñ[ŸCèRşäÍZ)xâ¯}‹<ÛŠÁ5yJø“ã†	Ñœ=‚qÍÀEæ&¶2‡k–Ê²ç¬¡4%Dq(õ•>ó×Œq¤†p²lâ£û¸ü®€‰ËÀÄr§·ãRw@¹o›”ÁtËÏâŞû¢å]«RõŞœ´ÈMKIğºJÃòçæ«·í•÷PÕªğD6ê§óOĞQm?a‘7[’øğè4¡B‰¥ìö&¼¾æ<’ëºúú™t
1Ú„¯ŠBGy´‰Ÿ@‘õFnÑœ€š°p·pÄNØÂ „Z`[ˆÊ]2s°øòl /¨Ì5¹º^}ğĞtµzY»Ä]Œ@”X=÷.\Z†2ÏF¬pE“@(€ûVE¥ :Ğ[dø.Å•@  §   tA›$ÿ ‚Á˜‹ÈñÍ,—}§!Ö†úŒ¶X;'Q9Ò°º	^µq†áF5s¤U“äÑ€YmU°+§p^ˆi–…é›¼&åšRÅ>BJåêŒ5ˆá±Ÿõ—£©8åÜ?Ç‹ã­°L3R_À  š   cA›&+ÿ  ë(e÷í×6½£·g½›Üš_¤¤‹t†ĞnÚ	¤°&H°^DmkÿÊ=`¾ ¡ ·©BøÂÀîÍšzƒ
–à4ËûzlÑX_}aP    `   ©A›F$ÿ ‚Á˜ƒ‰2åE2Õ¿‰¡óğâötn_mEÿ"’‘ŒÕu4ÙDÌXG¢k	ô*‰Õ„˜o®qéâ4½Ğ“Xî"’¦
aŒ%Á•´;p­¼UÁÙ²À¯.Ûî¥­Õ@+\0|µ+æQ¦¸óï¿ÍDEsäMïwÚ=í@‘ùÔúÿ÷üU£¹H=crM<:5Kç´ƒ@d«“r¬¹m€   õ   µA›f+ÿ  ë‘•¡öÓzªğãz-&¶ÒÚßóP[‹ŸzÊå OõWOx°¾™N—2¶Y¹£Øµî€@X  0(ÿiQÏåy ØK022+0ãüf	‚•İÈaîò.°ÔX–|…y½¯ĞÓÍa?ü
@?£|ƒv Ÿ²–×c—ƒp0OÚ,O<«‚%Òâó…ö¶İ4õ˜}ùê…ĞÉÊm`½Ÿ½+ŠåO²ëUŠÂ€   VÀ  MA›†$ÿ  /÷z­jòA»¹#st{*ôú_]±ı%r¶ Jš¶K˜	=Å½nJVÅvee™Ú?EpÉš"Ù?ÕÓıçqúè1úş‰ÃmãH9
‰ípÚàéâ…ß{*Ö7TäÔ.y?¬?ïgÑÒ}9„3	ºrßÚ“:HÔlµ#<ålŞtâeêûüEş¸FÇÚV©åãKò×‘mı^ˆò…V7ñù;;=+ş\¥i‹ü'‚jlû0åòü%Ù«¦ä?P<ıv,Z§®sxbüô¶Ï¬m¤ìmÿÕX!ü++a·Èr,º¤i¦sTÚLj®¼”±`€3è¢:gømº JæQzõò~ñà!@MóuH§W¯¤<Ğ8RÇÑ0Á”·å¼¸&è.©¼”¾qôBà‰ƒba‡äÕÛ‡8ûÑ2$êŞ²ÊG}	Úe6|‘4¡ŸÊOå¿6ê9¶×ÔLªåCG«‰E cÂUb}¡7â~Ç¨o,?ØïqŒñ“U·Ç,cç—bºI˜J¾°Ø"»é”§w ]äô'Ÿßîúué–ó»)YTÇ¥üÆPÔ^Å¸ğìÜ|ò°­ŸM[ùÄl(V€Öˆn>°;Y0Á|ï'}ç~vëŞ½ÁNÄ¤ü¥ï¦Êï3=dÚğkNÈlafT+9Ã)ÂÙŒ“mn
ÑsFg4E=ÕcuBR~“X;ØaVqMe›¤!ñ#e_øáÚQÎ`X·§S©yÂáF«.j øÒuv#ßµ8ƒ§¡“ÿ§‹ÒŸ[é³©®	İÕ(GCf0öYhã÷1íã4Z^ì³›ækÙa%"›7Í°á“›ŞÉà6¢õ´¹'™OOØ8oü”ÉV
GIa#`Óemï‡N› ‰u×ö®nI…Š·¼—oä÷Å7'	şÂÌá@öúQ)™"OFÖÎH¯ae1‹Œş×ó—O–µ“£àb­ù §£:Tñ Còó¹d»‹=qÀhUI&¼nı¯? jÿ‚£òk÷íÃ9åÇ„V­¸÷œ‹gJÇ*¼Ùí¯Mß¹Ÿáí—ƒBxJ-™‰ÄN:›álÈùƒøÂÎèAFÏ+¥\ÏVï~ò+js“šÜÓõöÙù¥#s1“rªbL¬òÉh¾±R2<Åô¼„Aæ7y·q¨ï—µ3œà¶cÍa2ûà@¨å^^/1Õ'Ì(Ë¿:–i9–…!µ×YÎ~Œ•(¹¿ùyÚÊòé©İ~VmV§¾ƒ®¢¸¦vu
©hU1i	&ëtašm“CĞ7Øl—M7H{š¶+}­æ¦åÑÕ-j¨¥kz(´Ó 9ŞoõZçzøÕn£jÀ¬ŒLÙóÊœK}Cï,ÀGYÍ‘5:p=@ÂÌŞºá:‚¯´N÷(DúdW>v©Šày,d¯d±’]jŸ‡g&yğİ©•Çíç°£uI›ö€¦G÷=nA­ Æ Õ˜ÑøšÊ*l3N|âfflCòç~¢­FÇo†R<í‘¨îâÄç\‡şd£2'óê„‚pdûOì"Ç“ÎwDVHbCRwhÒz½{ßç`ºGE}ù%š‡`¬`Iô0ÎœÕ,œ[[8û'G‰èÉL‰¿OPëãËjbÿy&ĞlÏ“+¥PEd«3¬&Ñãi]ô{ŒàWf‹xE]œ7€5}´¢Ü@2àÙ¼§\­(åÀ6m·f,±™Ú£ÿş‚¸îz¼…–o  %   aA›Æ$ÿ  ##`ƒbzlå²”˜I/V£.#øêSò¨†„Ç}D¾&HÖÇÙÄ°2š}½Ï8à!‘ÅwjzàÔx kö—•Íy“On]Å>>Å2ÓÚ<ÏJP    á   A›æ&ÿ  à„Æ9Eeà%ËOüpq9¬¸¨ÌÏ÷u8Ÿ…±Ä«õbİ®'ÿ(%K¯ê¼î§)….B]AàŠJŸkÎ½xó÷òy• (…ÑÕÂ¢ŒUÄ;Ôâ.IŸƒî&Y|bÈT/nøÔºŸ7Î”²é v]Œ»„?E;bì¾A×9ø¬%IH‡+*õó³2U¸“;ÏP†@   ÿ   ‰Aš$ÿ  ö†*|ïƒJ§•c=Ux§ÊrĞ¶{ñ]~3[›­×#Íb'’µ“Nu‘´ISƒ––Ëú ÷”>û±Ô½çÛ&İ|ZºvÆì3S¹_2bˆÒAÄJ
 ;xÚ@tÒò½ìº°5(H¬¶8Q,;·ğ¶X¾À   ¸  2Aš&&ÿ  fKjäRùÍSÚ
	7üz]{±Ññ(7—L™t·K`ë’6Á²à‘şÔú?–ªËÑfVpèîOõ\‘^I6J<˜„t¨ä¹4ÖŠZĞî‰0“ÜKYâiàå79’ÚÄóøµ‚7¸Kéfã¨Ş(X+µ¡x+¤é Šøû:»šfTf‹î‘½Åvér6ü·Àğ$è]şº¬èÉ
+IĞÑNŠíÖbEºãç‚ø±KYÖ ¯Ó¦å­¢u‰ÎõÔóÿÏ¸3 ~Ş-µÃ}Ä6[:ƒ€«½xoïC<©1	tËòÒ*]-r7Ä0¬Î@…sÏYÍR„Ï‡2Û'1=÷AP§‘,ïBL•Êík€OçbCşeaÖ’–£ö«ñŠ_p t­üÄ¬¨V;íe·y|pù•Ã*š)ò·´âîhuš°q©”Ò2	±ÿrMºt€  ›Â¸ßRQhÙ8E’‰0•tP
Äœ
Ö<´ bötml†­¡œ îÔËÂW åå$Íˆ	¤o 9ÒìPĞÏ§¦ü:Ä±Èt‘<|Ô¡Øsj˜y[Î«@lZj-«€µ†¯OR¿úz¯èM´Èê‘™B±·–¢§Y	ßOlÓÎ8´¸IcVc=tÿ›¶+bŒhte0QtYWPCI)Z9rÈ<æ©Bh\¾/–½\„ŸÃùyLûxëf`Õ ó_Ûû³$ÿ<F¥f„#Ù|ÃƒïÀ5Ê¥ì¾p[Gg)y'á0r»#•©ÒÊ®¤¢ÿÕ;x(sŸ?múvtºÄE=_ÇA81æâ•ğM²>CRĞÔTš7ŠZU`u(˜"}V¨<‹ò·AØ¡ı·BÛÂío£;¾9¯–Ã“ÿ—÷0„,·¤AGö5sÙD@…¬’>óŸÖÔÚ˜ÿÂWÿ9=å¥ªØwß©‰çĞ¶@Kï<fÁ…8»£^š_ÿğ— û°íå§ø«6ÿVdØ%<şm"mîcOveû~T›?0Åú¤øsãSaWH¹Ş;-—-à|âÕ%‘®]u±#®´Îbìƒ‰—½ûàøÃÜÄ'2+£}:œ> ïİŞ3Ô‹­€ãVOÁYÓp;·g€"ÊhD—v!“pœËü>°¤Y½êÂ4œ t$"fV"}5bpîDDò
xß›Sø±õ&fªÌbè6pävÀ™Ï†è¬„ØÃÊ^pßàj‘ıeÁ9
-Ö–.ë<fpD×âıíÔCe9_T`DE.bĞ¢_×árC¤È¬ë(‡ÿ}µ·¥qAy6Êî¨­%çQl;cãŠËç#ğ°"OüJ!ŠË¨<Gëÿà@+sãË(‡&ÈÌeì •@~¶Ó™qW–m–m×Zµ…ip]5*%õ—_AÒ8óµ¿	J’á7e¯ı6³ø`•¾ÿ áòôÇ;~(«:$4ex¨¿E¡ãô'…3fÔ]¼	¡A¦ô€¶)z`\ı•‚>.
Bç)[8™8ı¡—Ø#–G˜ö¹R‡äpœßiÁÖâÊ¾£$²çşL6`N›NËÈ<Ó/&7ôùÑ‚”sß•1ÒÊ¤€`ËXuprø>‚"G_ª8ÏŞ0>w‡}¾Ş’Xâÿ¥NF(EÏ?U'65ºe,7z k“<]g—@á˜üê` 32¶¾¥º×š®yèph:ëæq’w¿@2¥/Æ£CÓiäKÉ¥ô½Ôüt'Ã8•4x’Ÿ9kª‡ú¨g<½ÆFv	b§\x÷ç˜d‘!ár›§ö»¡ÎæköhùÜNq½DµÚ…O²BÌNÜÀ,É—¼éè”ÒÒêubĞ§ã ´ÉÀ¡	òªGW7-`f<pwÉiè×ÍDçÊå/µµÑDb’×ÅŒDÁç§ñé5ÉjğòA™'CMèî¶ÏçqÎS¯‡ÂEOáiQ®Ç“…^6â!£olùÎ\-`¾‰7®´İNÏ,ÖvÓ?šgõ—îô+ŒÛ¤€‘Ef!'³ä<6Dƒ©ã^€D§»ïÏ0ä I†7ó™É§P¶ó‰Å  :AšF&ÿ  /5.1@æÿº ;È#(Ã:ÓªÀÖ@wòÀÊY‰úàƒ¬%d&Êÿß¨ş$À›¢'êù^È!ÄQ·öÓyŸŞıá¥$@Usƒø=ŸÑJTÁrö£yPÊÁf{Wsú[¼^è§¢f¹‹©iL
íU$ #ø
¿›Ú£u,•Dõ÷ª´c²°Ë´ğQ‡wÇ•Š9öËübVRJĞùDû—?H›³ÑÅq¥GÖÊ>Ò,2 ”/Ft.‚äi õrK`2­:öl‰@»(e01ÇpG&$ÇH=îø»Ÿ@  NTgE¢3éN aÜÔBó‹¿é/1$æB™'5š8:Æøï´%¯S@œMEÃ6=¨Ğ16œëšãö†2«™ãíh(M›g‡€   øAšf&ÿ  là“ûÕ 
Z¨+½/0EDÑkçM2të{=8İÓ€.0ÄiÕ•É$7ÿ¶«èÛ5ŸİòÑC;MÎêÁÙ3â‹œU^~­w¶$æÀ«Ø›Ç‚	W}ÿŒƒàv'Ì‡ªÔQ…©hMÖiçÖ/Æ³$÷&ÒPO‘ñ½´ë¯2N‰´sºlÇFK NècDÜÆIŸÈÉ™¡£çÌ-“úp™İôAıN¥âŸŸQŠ€QÚpıö
Ùš\R2˜O½7ó0Wr wô› ñ(ó§¹°úı	šÀ>5Ï´"w,ó`ìmåÔ&È`Z&€  Flüö@   FAš†&ÿ  	ŸïûùiU™ßÅLH;¿rmåV9ø°I&ı6®ÇĞ#)Ç2À÷‘ØÔÚeŠõªÏ)]X"   	™   vAš¦$ÿ  %&æŸàM?üúçÒøC{V¶—k—ß†wKøÈjqi)¢û±…=-±6V[€ø<ïH&†Ëône‡Ò¿BıIJ>î”S9E˜züºÌØÌy¾ÁöIíıHx-wAìxIÒÌ    •€   zAšÆ+ÿ  à<•ÿÂÓæÉUn¿d&å`|Èù`?–cÜäw~“—öfG®Ê ÀÍçÿÊ2'Ewƒ¨?]”£,îxôDæµÿ.ùĞ–%%ˆš¿•Ç›‚Cv 6‡e’@  zoiÀ!s™'¶ËUÆQ  Ašæ+ÿ  Ï'–ÅŸŒ…¦&³ÿz-Ë’÷/ô,u -HÈµÔÑüÃ3¾Ì?ğ§Ú0:‚İ6âqˆÉ¸ƒöd+µÜ4BĞ£]FĞ-ú–fÌc*Ád€§›.°¹p_\|TÛ³'Ì³eböã…ö‡SñM:½|1oE$¤àŒB, hâ¸îÚæ¤À#·XÑéÏåòñLËß;oÜ"6C¾.Æ–¦2eËÚ¶©”?ï5g†] 2d[x¿¤å_Æšåg”<˜½…£ï—š=€‘´š×¶È*1‹ëœI'…;¾p—ÙlË<ÔmıfQBöQ<‹‘•ß_VÎ¯³V(4>\½gke|_©¹Ä¡û…·3Ü2oUÛwı	¡‡óà'Œök%”J¸åò;Ê@â‚dÍlñ4£xJbàp±­h€Mhé“¤ßZš˜©@Ša ù4ŒÖĞd~t’Í6¯ch§ÚZ¾@	™Ps [Şfk_¯S %)k¡Sæ-şÌòb€Owİ°²Bø… ½ˆØı_½gÚ†¨©L<Iø@G0<9¯K]æ¦JÚÊ\kö”'”¼‡ğ˜˜ƒF„0gû\‚>\}Ôı~©æ  ÅVOŞ¿¡ÎJv b»:R¦¨JopÖ@;­ñaÀ$Ñâ£¼»cÁ1ÂtC­®æS4å:N™ÀvÄ‰ şR!è$8ø÷µ©¥<•–X)½1ßj}§ÛfU,9¤äˆcF{ú¡N˜ò Û×Ï ˜âãßn[^Qc‡¤¡÷IxMI)’h,gLĞøZ>q6®ğë&•FİÌFùh
‡ƒáØİŠepT]ÀŸË‹ìB5ƒËÏå×æ	˜÷‡=nÓğâ±²¶ñsİ„®æ@m^nº\_ &—ç¿şÿî’¥¶@ö!yÑøx:*§Ÿ×QÈfXCä?¡&Ó³«Š¬ıâĞüòoÀv[Æ­³eı‰ÍÃ[¬¯õ°ëã'Ph{Ä}y§«ZĞÕ'ÀáA~º·ŒŒIòBÖ_i§kGnVÜ­Áê0fsgöİ½^‘k.H·F«*ëW¤Ú±ú%<èõøe ½ñæ)@VÁÅ:œ:ˆááñ"½Ç1‡%ñàÒ‘e?XõK|]šßîœz¨äï­¥…Ô^^ŞJwoğ²#ŸÂ •ëÈ º°+Û¡.Q ½a¿'Ñ~¼´€ÍòĞıòˆ?ÚY‘¼“w»0…8Àä)Ä¡êÒ(¬Y™¥~É×shc´Ş­¨Ó½Ö1¾.šTDø¢BQDÔwç€#I˜ñ;(P+{&nUú’øŠÇÎ.4ZgÖ1M˜ÒP^YY’Ñ:Ÿ~îV! ÛÈábÏWMJPßÉgué²TÚ_ÔşXIó Z}JÉQCp
y®xûy1†Ñ7ñOkù&À6…†Æ}å7êh>Ö“]Ç>OıµaÁ+g¢õ#öx\€!ñP©@¿Ä6®Äÿi-z·£Bµ—úÿö<œ†úDõüca¨ğMu¸H^3¬>€(‹CzñdtN¤æ'cí«ŸëGÎ4¤ LÜ´`N‰&º…äèup'AˆŞ¼Á­sÜSG°%1i©˜‹h#Æz#† ÛÍAÚîŒ=4YÃt×úáàïº3É‚²v¦? aÑ;•î1W?™¸´.z°{ØÔ*¦‰R ÖpÂœ
ş·¡vıøáëDF5¶µG5ÿÿôUÜÜ0ÍŸãRp¨J{ÄÂxO–ó+ 5xÍmjVÊ:.½½x‘ÓŒærÖÀ"RIJ¢iuà©Æ[«¯0¨G™eşõ;¯¶¯ß9ÅŒïTb@ı%M^ÍPµ´ç@%ì
Ï´ã11©Çê,eQ°*«o¯¹dÃ«¿"`+Ië¦’Œ±;•Î‚Ãe‘–Ò½{™QÆyÊ 6uøSc¶LÇºâ\ÎŸ43pLbkŠù€ÿ¸†¾ƒ¨Õ(o\A¶f¾œ¦YİEãTKæšàsÃc§K	šyì¾šÊ¹Š%¿ÛWz‹{3ø¶íš"|Á>m$üóoá•-€RR >"l}öjq+Œ¡·‚Á“<“ö†ÿfˆæGÛckCÄèCDÿ,a>¹ä'WOûd¾¡Ç(ˆñ!g3ÒÖÚ~:§#§Öÿmw))§éÜLwÑ‘9‹[™÷ÊcdæÃ«ñ$Š/bßt…Í;ÜÆ“w`yê–Ğîy•‚N/Å°ZUs¾{3îå~mS
YÏ.®ó¿.`D”¼¿WºzHbp>n°`jı”îKJ…îÏğ	']=Q’TU©E=zNL°-G†£   àA›+ÿ  }4"Şe[õ.¾…pª*TUìKÿå|^–ãÕ	«¶dW¾ÕÈ”©t"hó?læjô W6NCwÜà¤¥“Ejúu$u·3ˆˆ,]tİò} ¤Ô©3–Şü¸)ÏWS ¨öû&ùÓ™ı1)SŒNÓô  XœºÜŒ,„ÚÊa¨À’7 ”“ñp¤ä+,…,¹˜|³Ìì¦(o*!. 6?}Çñÿ—epÊ(ó*ÿĞ™¡Ÿ‡O†j½¨µ4Ùnj ”È&§{J1  ÕA›&/ÿ   T^_É€şyk¦ÚüwşBÅÖ’/N<#P(›rÊ’#ò÷~Hí–ƒºm“(‡VÏHÕ9Æ<Õ5J È&t/•{üZ”a€Ú@“Äb‹PX…P&ÈKÎÈ9°}åúLË$i(ùç¤ÍiEA	–èVRVÄÙÂ%›¤ÆÃò¯ŠÀÖpCS’˜—^CŸ •ˆ‰b Ç&ñ¿ô›å¿Uƒ+@¯´(0<>m ±%=ÒƒË.©Õ>Á=vA’ËÏ0˜@ÊÜ¢µ)TÛ=Ù9õğ àÀ,bG#Ü¢e?®'ÆÀËÅO°èi.÷–G³÷[#I*©¯Yİõó ä6ñóR>x‰àÓ|¤³(Ë“ió!9$'‰åÔÒ@N{ÖÚĞæykcf#MÖCÊ	œó7¥‘zëYbd÷á}•a
{™ôIî/âßÍ¾LÜÔªcÚ[q{3÷ø´ÈÓÿ*‚r÷_<@0Ïsã·šH³à›GKôŒ
tæOgë¾—ÖÒ¶ÓwdTN×t°Á‹ÔFÏÏñ#wi!±ÈÃeÇVWŞ„Ã²hÿ›ƒö”-CÑUæ”¢Ş!¿²‘Pç6¬Ê\øÃØ£ÂÑÿ1ÁL†Y©ÑöQ.qCĞvUPøq
-Äó „Ï@
øîl‚`~ÃB`…	²Åca¦¨Ô¬qãPl|Ù*—§ÊÆ®±ˆçLø6éQŞ ÇRØÀ kŞôıì0%ø4ŞêÄöÒ-½>`v«Rí8ÏécÜ‘#såş'üˆ.‡IDV;İ,Û;êJóşz2›‡²f©Óáú«Æv	n9ß¤"C9‰?ÕzïŒÂS A!0­Í¢ùX˜‘÷+òº›èùOê:!€+«)ìkv&ûÑŞÏXÄ¿ôW6ëVõ?Ò)å5×^Îêr¶8IPÅÍA
@­ŸübWEú­ÕÔUç/Ş%^Æ:Ä-K{Vn‚Ëı4w &"ıwƒ¢ÍÓGçSˆÍô#Ô¥ô©Ÿ½|D ®IN#‘ZËKü‡kÜî3Í·,õÅOñ›ä^sà÷=íæÿJg©¬œîM¤‘U]qÈ…o/_M…y¿1°-—øûlô?syÇá-Š¹
@ç•¸›t>,;I›yÄ9ôÕÇQTÀ…X%ÍÚj·àAÊŠş&Ë­)ë 	kŸ§Vé6'ˆrMo2X™èOË—gŸI«­`'.¨ñœŒEaÙ†XÙ{PÇñ©¤hçÛ„óX£~oÜaÓ®FI   µA›F/ÿ   døá@ƒQ"»·+Î\‚1ˆaD`¥ z-“põÅ± gÌHnŠElÒJ´q‘Ô´ÚL—¦pˆ-y{ V'+ÓÎ±dê›LıÿàT¸›­ ^¦ÙÔ_ãg—uzÁkGÛ@)å‹Cìí·àÕúOØï	™}“|Ç€  -F‘ À[‘õ)np»‚ÕÁÔ–Á÷X}³8ÄL†	µ»¸‘»ÀØÅ_¨îô4lÜà   ĞA›f/ÿ   ’“¼b’9  k¢Âåw°šõûœß(œ„\ì3tPÔ2¡m÷w¶~+…¨¯KšÎ^Ío£#´Y¶õò~õ°¤ôDz’F]ñVh¬ÏUhëè˜§¿²ÊÖ¹S®¬iÛØ¥p6ÓPÂ)XyÃí}¢»µ¾gZêÿ³õİNd_êØjñdRÔú™¾¼õ?š¬ÆfdB>O¦:Š¯g}‹rJ`+'{ÚÈ
ÄGéX  Ö‰µ²µ §¯a1¿¬À  BA›†/ÿ   ‘ã‰˜1„ÉZpA §Ù*o”s`”·?İÿâQcÉ”„÷§@GÜºªà­1S(1Ò=Ì~}ÓZKÎËÀîŠI:´) Ÿ=ªĞŠ÷©¨ò,zÊşÍ](ÌH³%š¯@ûÅ¢‘Á¦SÎ˜5ƒOˆº²$yä]P?d{.Åå{„WrÊ2S=V  73€C»˜õaM£H`v€N“Ã€³÷°#RÜ#×E7ƒ/Üšşc©ËiÓl;¹~CFLÔ
ªÙ±WP~	âØYØ•z
Y¥W­‘ÀYªMTÓ}Tò¼¥è®½ÆG"†Í¯oFÓ±Şb¹kÎ/£9Ój¤ˆãyz—ºÔß‘4 #ÍY¦MKe¨hOE£X<[‚M9ä=¾Qÿ”o™×3K²­NŞ4ÚİÀ‰Y¸Â>áÄJ4>€¥úÿÃÆ¼Ÿ»\@óô…j´$‡êhK®9š£‚¸ÇW§.]ıõË;¨	„ªôŠ?;ùn”\$š³ßØL¦’1F°z®„ınßÀ?öªRURàIÑ¦É‘¸İšŞ¾«¬ß¾@”êÜRïÆ4Z’TÊ•¿IQÅó&Ñ)ã"‘Ù¯Ï¬Má	ûK®‰-AÇ³ÈÆI¾¼hí··ç`©¬ºóY}dÒ±­†ê}„#C±^Â>#Ì¯~°ç6¬–ÖÈÉ·=™¼X§ „@í¹æØ¯…+ßs(B  ŒQ€ïšo½æGª:‰²0ıuºÇÊñ*ŠËüIí1ñrQPt•ü‰€ß€¿‰yH)úà™
Œ™ãyÂ‰;{X~d94İh®ì…1ñîÛ3?Dòï2_¾‚¡ÄÑ-ö(´ŒM\’ñ¹dïCÖ‚Ô¶£[«€ ©[Æ’z0Õædù|Ñì+ìò®/e!ô¶œ›oúq^@¥f”næı‚ØILjß?í£Ô+jô[\ƒ7]Ş\ùÏ|ì8f$Fµ¨`»ìö—¹@ñm¡%Ò^BòŒúÉé$¡e~% ÄH…tú‡¯7ùGæ+oÃÜnÕßyõÒM-1=ß¢\Œ·ù½bíŸú³À×ÉWè;ëƒ•lEÏÇ©áƒÔw~µ¥&'x°u­Ó“¨ŸÅÅ §õÒ™şëCoåÂJ1ìËô^¶9+2Kªà×–M7}m¿ÿ¯òHæàªµµ~µ]A_ûùbUNå^r†ÓÊk_ÈZú6ı!·Æ3÷
ÁòC …h²ËÀ}µyÛpºëï4ƒĞWY¡ïäîóê‹SPü§A"n£+ªheÁÜMö!Èª%
Y^KÖ&Ûu¤'(e•»‘Æ“°íKÄR.ye¼ñz£NÈëªĞÀ³0\Õ[KŸ.vå2[İ½Üá¿®-fÎ#Ô?Qc¼u~eQó0õ'WÊÑ!   §A›¦/ÿ  ~q#÷ñ"VæhëºrZŞÎ“EOP…l¾”–!Öi2­¹ûß­íŸx}U¦Z©X’ahCø'¹ç—fâ*‘Â¤¹U*>k]&à…Ã•(Úê™Ëré…Ã'-¿(mù\!à’•G€ “·ÂÇF°H5 ã
÷a,vç¸Yw²ô¸QZA›²ZÖÆ‹»M‘ŒšÛV“ğpAv8{ıcğ   dA›Æ/ÿ  ~n6 `Õ´Ğc[7®}ö™ë)±ä™ØFª¿Uo¾ÎšuÛXR²äø›<³Š•bKeUÈš  Ù	û91ÒCwi\›[$d×ÂCğ'sX«eë6dÀ   {Aš%ÿ‡ ÷5q` ¤«  Pû½]‹¯ É-ß.”ÊÚÜ?!)I6\ì,ÖïBE£¼¦'¶‰½bªAœâGÜ2Â1ä{â«º¬ñÿg›%ÿØŠ½,)viJp•¹õ—`tŞ+ ©Z2Ğ¼é¤!uD(Ó>úN¡  OAš&/ÿ  ñß% d«OÀFGäÿ•JÇı¯Ér1Ú›õ±ç¸n òW"1ÃÌğö,OÚ+´‘p.UfaE™‚{3Ü(’¸ – ±ßì	ÍC>	½6!™D­nuç ¢û"Ôû#ıÈ«VÖ¤9§vlË„~â£°œm™&Ì•/Œ«ã~°CÓ~bP°†ÕòÃº_KÀ8!òõFÁÆú¥ÔÁ6tïÊôÓ7x×éW¶ÏÅ
D¥{®ø,½ŠÎévkÉV„o[ª|t¿@SZÇäçœS ¢Nü!ÁãÒh^ä¿€u±9cTè»†ù÷g¼ÉY|MK;“\JVà˜«ë@d`‹¼WZ[²ó×È›Vk¶§¹XĞ? 2¯AÚ¹¹ªë®y?'ïøTzÊ;M×‡^•3ËA"ü­ZÑ@ OWö¥ºËç¶)W©n	Y   gM@4ÚCäˆ„     @<`Ê€   hïÈ  H‡eˆ‚ÿë6lìÈÙ„!CÊˆJ4| ûÄ)CßÒ)ÿ)«@nRnËÖ0“š`!~Qğa{Ù;Óébp9¯y‚hHÂB¼·¼·,Øe”uòŒK§Ø8Ã\üí‘"<+ÓG~_ƒ&“9WŸ¸¥ê(ÆßÊCîtHŸAËebüş¼:1D°ƒJ„ª2ı´Ù9]¿·#¢sJØÁeş{ Çà34%n_¡wŞ57][¶ôÆ“7^ÖC:ÚB¼0Ès}jÇÖÀcgøıró›…F8ëk- †Ñ~Šğuh«—$.éª²¡:Šî9©IÍ}ÔÒ ‚µŒGîà¦Cö¼0Ÿ³ÚCzx1;p‘Z2î°n<„_¢H
ÀO–«Ûşl1RËu7y‚Æ£*y0Zßl´rM×í“áîîz5ü’Èd¾F	ÌÊ_®˜ñèøÅ”&éòtË<£¶^jüPæ#ôl“0òÂeI.£¡…Ê«z¯†ùcéå~(Ö3ÃüL~ÁJI,µ"v¥q`°ÎlŠõvõó_Y¿ÚõÂwœ¾‹ÕÜõıï¦)Ş²<‹d»ˆ#ç³Ez…g‚PcÀÚı
=ı™ÑŒC†¯äÚª<¨—1Sº›áâğÈ¯DM¬Ô¦R;œ eD~CnïŠ†úDr®¿g±£ï
ÇIˆÒ²ïy‰ÅÌ½°"“+úXSb$çŠQ¥¢¹ıˆ#/e“ÀÀ\—øÔ—€±”Ş¹€‰-w’>B
^â ¥ƒ”ÈúLøƒê)\¿dn?£eâ³œÏó’UÛåi$€6Ö÷¥¶Gi»xsÍï²¸•`!É§^\<Í£qé®PH•‡<ğÍ™ôŞ®ÿJõ›LnX=©MäÚ#ÑHQÓ‘GÊ÷:„8|¿»áTøÍˆ›İ%hyO|:ü0½Ô Ñwğ´‚ÇÌëÔz …#–Ú{q%	^á*z¤Ó]YÃ`´md”[JdVˆ#;S:    0Ê.23êßÏ›3¸AèNîªi¨Dé›_ñü7òí,„`Û¢fîëã¿–Lx¡*ÂåY¾dÄ¤$F¯ ylÅXĞT:„ñ¸æ5…€§ÚÀÚµT¶,	y"=sÿK&”ô<÷¦ÁzhîÜ´ ²:x¼‰†Oøç_ı£ ILŒÂàFïÿ­-·í,ß÷ÚÁè\oãB?‡T•í¤à"_·ÿr¦hå·õùfRõº—<ıb!¥`Vh^İWLİÄK£‘lÿåìhÍÖÅ3ÆÙ™;œõ÷	„öŸz'¬ˆk´ÔQG«0æßÿ§ûšf Øœ,ÊäÄç8¼©ø9İæ¨qùŸK`¥x‚WŞolK¾1e¹NÆşrš³Ğ‹j­t¼P99;\î¾>÷Ğ”-ÙË_L>sQş½•‹™|`R&ÒD’ŒÿLİÜ{§$hd¡ŒE>M÷t¾™º“ö¤çûºÔÀîŞR¿‚¸±–±–âpAp5ú(àÒL\.w;ñ= †l!œWq°¸Â}O‹J–ÇFî}9(Ä:Là„EÔ±„ªÀÇŠr›²Ò€‚ÑZLcm6©ÿ¾5¬ş¾4¶ËÎ…­İ
mâ%/^u±±ë‡-–Æát]O×S½[AÈ…Oô„Õ´„i×$g AíŠ¥3÷ìèZÔ‹:Ëâ€÷á$c<ãfB‘Në‹Ù»ƒ™Ëu2ô‘^Sòæä˜«¥ókz­÷ËªVçÊR÷œ.¸	O5÷Æ°Ï8AÎœ›‡ˆ˜yÔtw'–P›¤0]<¡\œ‚Pkåƒ¸¤ûõ<˜*Yk¹$šöBt¯L+.GÄdßEş"«”:1¸§Ú°EWE„L ®÷.±V@I¸ø0S®~am'kZU÷§·¼o{ ¨8NMë?©´è<İÇjF6îÖëI<ˆ¬Ÿğ—S$›sZN¾î8Hkì2­q_¯7   HDÎ§XÔZbïÅÏEN™tŞZ xl,gëLñª:§oÎ÷½è|·=.‘Ñ·~ƒP^Ê½8>ù¯´èÄP¶ÿÚ$%ã†Õ®^ÓÕœ Ñ¨Ñ—v%mNC†ïÏ€>&d_*g‚‘Ê„Ëo>Ÿ0ÿ²æÔè{èö)~KÃkĞ0#œ–~IëYÂÄ ‡ƒ,k„ğŠ'ôpÈkNÜn&oÅá  OÚÇù´jÃqrµ¦÷Ã@ò¨éÚñ	+ìk½†j’#ª%Î¹ëæ¶şz²Ÿ||IEÁ¦Y:î‚8ûÈ«ƒäìBŞ‹´ÉkQóò©r®Cø!¥òVÔ)%ù`‚|È¦˜Yûè…á.8šv“VøÇàFÚ.¿ÑîAË^ ö¶TªseÎ¿?qÖK˜ue©	­wà&k´P	åËL×¢Z(~+•³leNª¶1É4W>Î	}’úÃ+õ¤¦:®‹ŒãŞlkVğé•\óMñãÔ¾'GÁªiæ,ÇaÌVñyõv•ÄhŞ;ä$íşI Y<C@Ëb—Ø©\ş=ùXÖ'¼S63¬øû«!æÚóW6¾¶và½—T„Eíš—v$Ö­Ù{`Q]vÈ</3‚jäiIÄWÑ¾Ş ş¡Ó§flÕú–Ù-`>!€ü{î‚^ñsÁV/Pó5ØgÕvº¼|lZú‹$¯Í$§é;Ø0œcòrcı±r•³¯ËeƒôÅ7Jf•ªğàM¿	Ø>Ø»Aşà1Bä˜ØeÎVÑA°YåçÖÿÛÂ°ØgjSŒ³­-'\Tà:©‹ì *Á Ô=Æ]Ş?ã´ÏC~„kFu÷Ï\_›ÌÆ•Ùâ…·ô`µg]œ82ÇrK»Ó=`,É×ÎÍHıcÿGÖ8ÎfĞCĞÆá{O3Ë!H¸z¦ğW«é
r«Eˆ›ıVæ9ùR(Ÿê¬/7‡?ìÅä(@6åY³œsRV!9|ÜÇGÍbÎ‡QÚøÚ“ñb³W°=¦âÄ?œÙdµ›éø”ÍÂ2Q†=YŠ.Âş¿ãàî¸q*ıšª‡˜Jú£'êm7IÃĞ
å+˜fÑõ?=¬ˆ´$·”ÌàÎE^bˆÓ}]R.—‹Y.¾§úu
4×?«¶‘·¯"ãò!ó‡¬ènöJ Ş5˜gî¬„šïf)ø'ãã¡0¶ 0ïUÿ½6Äİ•AíU	/É.”Sñª’•(¼²î <ñ;üBGbIß#ç7/ğÄ¢²ïŠZlÈ\@0.Òˆn¬é–¥-\âCgÄ6–eu,‰&º[);¥«j¥…„¹ãåºİöÿ‘÷éÖ7/q	˜Yê¬%d	uC#!7HrÊ¶€G²ÉŞY¾Ü²s‚6Ác¯h "—b=í§˜Ä¤©*³¾³3±C™ñö÷v‚òÄ\ÿf'è	&j¼XÁJüÊ§FeÁÏ£«#¶‚@(Ù&Ó4³W©V»¡Yl=½Š0Ì*ú‡´‹éƒ£t©¦{rAøræR°2Ì®K´®{àøjDC©gãÃ ƒuu¾dÃ?¬³‡ÃÇY}?‚qİ«˜@E‚{í¦Šø$÷'.åİ¸\ÊG²±ÇV˜ŸaØ-m™ùÓ£/"ÁJ*yGO*[G¦®´¢Å‡Uò(¦O¤‘óng–ÆOí=¬Ã´¬XaÎf4ÓòjO‹ïKXMş&,&¬´d«Ô@}'˜S %Óná:Ù¶“Ä!À[j™GôŸ.¶İı’]å|HBLÑg¶ĞáËÒñË Íƒ¢ypZyğ {ş¾RäÃ œˆö„±x3‹ÄKqäù/ìHî©zÏíšKŞ	FVÅ„¸Pğf0   £w£Pªãp— íã³œpäÄáÿõVs¾Ş‚4|×³4üAè¿´¦CÍ³P ¡03¢™*Í7iÔ%w‘şLùá¶6Y.!ù$w'_ûÒ“ÿVx„5ÂKó/¾‘nŠ9bµ¦?KeÛ_'fo>ĞE£NjÊ!ô½¾*-ÏúüXÇma›—ñÛ1T7V\?{éêşYöËŠ÷öáå»ã³:q
æW…(3ˆ™¿¨7(1@ Zıe–©ë @&DFAñUÛğÍT ÍY…¢Ñƒ|NniDû€Ìœl‡«’‡ùúí2ØÛŞá3„•[:î¿DˆºÊ3ü¾Cğ¶.dE¤ŸfrÏÖJ0sêa*.÷ãH‹¿U3Áeo|xóï%í”Œ}n†Ùïé>|:ÊZ¢³ğãüãzøU Ö¸˜Â X•x/ÁçbÕ\>Ÿ?#vÉ£ÇR$Ó“ËÈ
BÕmAwç˜Ïzõşï
cwÔ¿@*‰¦)¿ŠDrC°Ï9…xìÌ.€İë³¿!¶NP	öÄNÚÕ+ZŸ#Ùo’üf‘*ÁÜ\ràöÁ®`eN«áE_#û·Î0
|ù¶Ùê28i…’O³¤HÂ™fNqW)>éc7ÜänKnºøßIÄ	B8÷„I}Ò{ ÎİëÙT3Øƒ—KOEç§ÊŠQ]÷ruëòJJF)«[ÿªPW@–²¥¥ ¼"ºÏ@¬ƒh˜>{2QEü‚T]	şù
WÎ5bÌ8‘Œaˆ{íÖ]Èwö'öš›Œß@ÒÆV™‘×KĞ¼Ñä˜lİùÍ.ÏXàßª~xcŠ·+1Bxr°ïı×Ãq¶i-ß­Psæ}
ÔL›BùÁ>(±)(ñ­z
5ïuÌ×GÉº<½ñ©àŞ0s÷ô@äÃ*İÖĞwŸècS¤Æâ0Ú ı¯ni™\!çĞ«BÆøMÕ\ØHKâ§J)ÂÊù¬Ù„Øxˆvå³Á¯/o_’RF¹É“%•Yò¦?1«UMmtà‘öøéü7—Hå¹SÁ2‘w3¿*}“#	Ø8ºä6 *DS÷½¡´Ë¿Ö¾p‚Ğg	Â{©–â|îÓïEÛ@^ÍSlª] XT2†¸+¾p
i· Â´³ñÄ©…¤§öê8Åé–‚M¿õèéVe›´Õ'ÂğG>Ãªcxjìí>8)üŒ´&hèq>ı>¶­Ú*Ş³äøgîˆ¸_÷½ùÖ2õÆçğ:}å] Lc6¾owatäD$ƒ4ƒ7³ÔÀDëAÏz=¬WŞlïáŒ*Ë×‡İŠó°D9:çr˜ Ò0®ì"‡IÈòÙ0¶=ÉÀIÖo–¿İy|&ğ5õÃî^Ö/”0IådºæÈ»šÎVæ¡í¶ÅX1-å¥×ñİã(›¥…/ÿÿÿùuÔá)D–äfM‚*Á1fÒìÎX%ïàƒj«”dÌÆ·èü°ÌªÓi…ìÌ@ÙÄZz’K)§B‰åN®†ƒcÒ"à|«îÀ†™	b7ÃÄ›YYş½¬áÒÇ6Ñ¿Û”ïÿÚ:)*oÔD˜®øÏÍ/LÃÌÎ;–µ‘è›¸&4ùÿÆÿ ‚»G¢ğIÁÿ„6O„İWÎÅ­Ñ:LÊ==h5ğÎ"1ø)`±1˜¾Å*yÕth¼Â»3ÈzA€/ÁºÈ· ügo…6‚Á,*Íê“nÚˆßsø<IÒ(9Q3•å¥Xy>5ñèY|ì’åp%°ŞÜ$‚	—K©Ziòå^0

Â¸“rr‹QÁoÂ7%¿/çÒ@ÔS¾­dÛ ÆÁé€ó‘Q´éé]hÙDNÇ½fŸfgŒÏºŞVûÓöma8³jû•6jHl8µı;µ°#¢í±¤QüÆ:Rrî„¶]ÔZåŸ°†¤­<!;{!qº[Æò#ò)""ÓéÚx)‡_±Ã-ªiûãíKn·,’¨7%CÛéªÛÇÄÃ?xwEÎñ39”¥Q(€Gåz%¡¢SäÆÏ© 
qã:[vón¤)ŠCÛ¨Æ2,@ŞãDI õ½Ì³>_Cçx86/-µ:§!*”Oq#¥½(È‘J®ßq‹Lg¸£Z‡$µÿ+{~XT¹¸àî–B£ª[š¢™Ya'=K)Ê.Šl 3Á
Y‡uöğ6_İ&€Uù
™tÑÃ@”+h„ÜF×ÇéÜáàiªòÅKˆ¦f'\ö+^Å™KşyN¿˜¿3¢‹ÂÒêHâĞË×¸üŒÉ¥şRiÃîyk/ß«û&;ú†ôø…< t·O±—?np’ã˜>ùaÂÔø7Sb%˜Ì=t5šD¡ábñÂ€x7Zøêt
§¾>åºV¹û½\l\^{ú[Õœ åoJúò’ãòp³‡¢,3å”›c”UÌ»FQåí¸Myõ†X¿6”ê#‡Óÿôµ/2§H%¨œXzHç¢Àz}~LµGv£3Èp÷,;ÿq‚ayÔüppó_ëYÇs4jVÙın4ßìğ½]’²º;QüšœØcâ²¯ÅaŞ.^ Å7PV Pmÿ¯ÄÿsºO@·à×¹±Ğ¸{–#$HŒ÷TŞõ©øÿ³ç„~,;±Û3KÜ¡©\“ç[÷‘t²ªd^„ şâ¸ªÁ+Eu0‘Ğ“ÃºšôÔå#Ÿ™üÅ†KT¾Œ±›niÇˆOj_„bb¿ÿÿ İÈ•¾ ß¶¿$ÆhÒ/ß=É¤j&ÇéÒÊHÍ‡@›ß”†m¿ñĞ1’-ÏûÁ5rNìu¯Qdß^d&Ãìé“İ·ËÇ,˜ô‰Ï=ÃìÛÛñi¼¼±8£]”—”ÿ©8®_í„µ@DÎ(«Ûd©æLª¯f+ánl€nÿ‰¾íVªÈÃí/Í½&«„m³u^î›Í,ü¬ç9™ükÓüï§håY¾1,%×+Ò”èl6ïÒÓ> •²a]?²<Ïw&TÄ)ÙË¾P9œ
¸	‰ÜûE3@×„‡`l
¹òîz5w–™C*Ö9‘¶‡º­<1Ôì¯;@:32Ó¼ôÄ£°¤$¤à«ĞğÆ¹?aAb„‹âó^‚óüë÷•°á~K'ækgÕ7:ÈÅbé(s“í–*ÌqšœçıÙÓ#nËhæhBó°€’e5;O9mj-
	ÔŠ©ììÄ”‘‰‰}ºy%5™íµÊ¼J[i`úÍz˜³ˆbˆxo Ø’ÿÎËe»1—Éıµ‰½à~­“Ìyöä™ÍÊtc¤ÜkÍ	9in„÷š³Ÿæˆ‚á”czfsô	Uµ¯où“ïFY››/z’	ôA%\c,g/üët L*®O¦ÁæCDR›¸Çó¶æîYë c8¾­PôŒí€Ü« 	NŠä‚ï¦O]ƒE}²}e!ª,¼"Ì.…3ƒSˆ{0>ëæu'Åd…l£x=ïU¬5‡Û?Û÷rßT¦ğu¸QR±go ºM‘c´ÂÃáÒ€ú{P
öÓV=Æò×û  ¥@¡6R#ÈœÁİ¨¿àÙtz.êî3ğ«ë½BœI%‡¿ë!‰$®¼ØÄÉtªÕ]×z)ßÔ’$O.:Ò~®>”zppùağÕ7Tu%)›Ô;EYa×aÃ³]9‹s§>İ¥EFŸQ»å›¹|O‹Ş´Šrğ,üÀ6Y%Có)cş¥XË÷|5à×ó ŠÑ7$˜oQ\ÍUi'É¿évŠf0G07îğÊë}T­Én–;|R}!›Êp#"ìÅ*y©Å—Úq4f4´KaËúQƒ2š¿e<õ/ãÒgù3ĞUrõIj"æp­‰XÕäBJ
áÕ;w’:y·NÅ(ruÏÇè¶µåBä‡S€K·.Û1ª&æßKa0^¹Ú§KkÎ«Éú&	«2bÆƒ¿ÿÿì:¨EµL%ŸŸÙ/•^$yzÎ¾öû	†ôƒ‡İkLA't…ácËü
a,4×ûª[[Õ÷Wà~ğ£;và'^è­ ñàñ—‘Ô„t_í|Iœ™T Í^,`ÙêÛìÈ™EnylfcûœxQOÛxßşiD.íá‡CÒ¯ñÜÜæ´‘Ş¢#¿G¤©^éï+}¡Ö—76?»ò¶ª×pÙ!ö!\>"çìïiÕ£'x`Vømš!”ÖœIË°ò(”£ê¦±†q„UİÌ®`ÎÔ|Û”HJ&DºĞş¯ÇÛc$‹ÏòQ¥ÆŒáæĞwGzÏmúçg±¯$¹õö>–!a>WQÙ/zØÈ¶Z…ì“k™ø‚äZ!ı|‰Ãğİk¸ÏÑ·æ•EàÂk€‘19„mªtÍH…~«fe`&V	}l…LÍüeŞŠÈ•‰Õ†‚ŞŠ	öw'Ô!çåÚê•ªÆÃCÃmPŞûQ]/V›fÏ=÷dIPee'qÆ­ÇÜ~`µO5‚v]ˆ®ÙúŒÂÈ)µFAu=Å*jR‡å‚ÆÌ´™@&ñ·ü³-IJ1Êªåİ§f-İ¦& h«¤‹"Lß*Õ3ßÔ¢HİEª–ÆéÛnÑæÿH…>8(ÙØÿK2É~,CÏ»µ— *¨‹òïÚ@
;“
RöèO³+3ìE•ÂšÎAY87Úê„ÔıÌîÿÿ¦„ëjüº³LæÜƒT}¾\ãG‡ÒÛÒ*…¼8Ú*‚°WzÄÍry€¸!÷ÑZpaS(,0‘U ¨­WFQ“¬ïX-¥ÉcÚpÂãÁ`ÈãğE’ÜCeKkA½W2­&ò	X2	ãf±–W*¿FU­=3ú3•µXÍæHöYĞ¬ox;'è\:ÅÈTù[‹W™g!JTFš[Œi˜·«×Øq>–æÖ~õP†T¯M©Küí/ÒÕàåÀiLFÉZ 4Â^û¶r{<¦ˆI¶IÏê¢µDñ:`Ä]
Ds¤LuUğåÔ
<Ÿ€u íP!‡VéÚè¶f‹]?\põj:=Øé›ò³G‘¨‹Quï[­İûœ¯­Ê•–Æ¨+øÕŞ8šõ0l7zìhêÏ;WÛ®a?°{§Ò0­G0˜9.@´˜Ñ–y7fÖ‰gÕ…Ü*ìôT`@cô×Ô\ÈˆD÷Ò™Âä¨bÍ'mª_?ÍümÄ£^€ò^¸¥\.PBÆvD}ÑbñIF%»÷ÿäqk5„dUüAX¢œ¿ôh{®ê*OxWœÇ´SÎVòaÀ·õÕc€İ­X<ÓÂw¨\&ŞÎ¼’•èf#JZ:œ7—4ú4¤é’ó§«(æ!VA~Ëô]İ¸œï%œ|œ5%rÿ½<‚¶H] {'n™á¯Ò–-Ñ#™›NwuTÇfyän6®iÜˆmO˜¶Àh2NŒ èqHŒª$ÃÌ$¢?Èÿ|·Ö«bX]a’	¢ú3Àã°¼Éæş¤ï•eˆ±H÷EşÕ³§¦n„‘ÚDá`à'‰·€†±åDI,j>zøK•ĞˆÌ^áÎ ‚ÒÜÈ´¬¹8K««Â~¶~¸â!MFÚM‚ËÒÏ£ó”M©Ç–ÖV–¢¸…ŒİeEi+M˜ã¡ ½a¶6bäš¨ªNAtü
I7(VäÏ†§qw!ÁK¤Oíïÿûş-ÖÓÌ¤±Eî™»€¿9r8K?Ù£%uAfåf@í¡qÌ—Õ9Ş}/ô1"Ÿù|ÍïÜ˜	£q¿]qÈñŠm]¯Sn¬et¾b~œšıëVhò° öÇ!["¾ÕÇ?×lõÇ<UFGí!]î´r†&Nœ1‚ŠìabÙı™>GÄ5¾J€ô¹õüA—ı«Ë¸güœaï[çkÜŞL­ÿ§Ùµ ³paŞ$‰±´I¶X`‡Âÿ„!rîo`ÁÆ?e’
ô,¯jV-V0ŒÀfıËaÁqšÖ³¬<˜i‡W#—N´ù…Èü¯ÀºkÎÛƒî—pÇë9«X{¼ĞUp6ãc't @ E°ÿ@RÄ”ÎFZC¯ÜhÀ4ØäıL^•Ä“i°cwv8O\ğpj<¢J´÷ğ1]Ì™Òi;Î`8g	9ƒ•Œ-³,¿	ğ$9 9xÍë©v8ó5P¡Ú˜{7Ë.Â¿”şDş©õ'‡°ñZ=f ^½8ı¦ƒ<3å²nçå™°ºù¨¯®ÿ3;Ô\¤MRP?òASyà]5¾îİş<üGgk‰*øĞVê§?úFK‰°ç;mˆ|€N—º0ÿ<¯µgî,ïUÅy-3éX%¢0éé"(§~Ël¢ê’v³Wk!«í×ëûa…¿Ó—0‹<²O@Œ
(Ô’.Êõ/~è…UÀÚ~ÛÍæ(¸Å–éS!¤#øì«ğcŠ\Cå°“Òwaq!àc‹R×rd}¥Ã^·©½ğW,1ãI™üö]‡	'ıPØ$<ú3HŒ„Ed°u(¹îrÆ”?-·ÕÚÏ®PÇ$äg?8I…Å‹Ø©ÏT¤…7¿°™ĞşÏ¨%¹`[Ë³0Í¤°®¼T{øI²Y‚Î„ğLr2¢„ ÈÏÙ°™*¿ÄAØ­€”#Ñ±ªÈ…ëæŒá³9	AËèòªX4Š¡+ß†&ßXš„ò½:¢<Ê³æ¤C±À½˜HWÃåis38xaÊ…Üûr!8MJˆl|”$ûY§ğûoª;X_jMFÆÍcÈÉ
åoğtV\áÀ¤’­©œOut¥ïà«ó@wÈÔ¿êy›_ùùŒ¦º¼¦sË}¼ì/ÑoFQ8$Ñ­·L¦ÀÆyçl‚ÛÁ¦àl6síBS[ï.ÒÃâIHûõÜêÒ/Ç#Ä[–(_´LĞ«ŸEæQoûyxVº+exÖ½ aÚÓ<F€ÙwÒ›®-dílf©õ¥š‰«lE+vtÎCõ{BÒd`/ˆè¶7”:4y³ï§ıOo'â'Ç’oq9vUx¹Š•S2j
¢¸–ä|xŒ&7|Î”‹¸0ÇIâÕ¸ÏoÿÿÿìüïšÒˆçrø ô5è^†à³rÂÓ
z«ùfÁ\pï…Å³Àwó\ÂG?±nÖx};¶nÒuíxÒ:ùÒâHj@¶AƒÈK½çiˆzõİM0½)z¥İ‹ı0²¶Ü[­BzŠ”?¶–í¼ÂDPĞNY“w…Í0»+xµÓŒkíã$ZªAC¾ÿÒ zÉî{Ã-éßB¾´Œm­	à6Üáƒ[ùÕZBmÔD^° Ï¥˜‹VéÆ°†êeıƒ˜>XğTºh¥ZN/')êÆ÷Â1‘2åtóÊøûÍÊ'
ò?ı‡#ô'´Yœ`ñ+¥Ó	P—Œ-èYT¥û™«§¦ó`7?¤	Ãğd¶Uğ×Õ*ae£#"Êx…®I,¨áñp‚uAŞŞïŒòÔ`˜Ûir­	ÀQ1aø5õÏ‡àbœC¬œ¿ù$¾Ær{³p¾Z·l€ô©n0hÚ#ğ.`Û¬™@ßÿ
__ı ;'önÖ¯
0Áñ{8*¢Ê>[læE”¤nÇú®ÃATÎ±œ½®‹$˜8ç|šãºkÏ‘T&õ¨$9”Î7Ó5FËŞ±ÈM²ØÙI­•*õÚBZlSÙ²iÜéÖÓ”\9 R¿‚„;ë­ü"kÅ=\
ÈøÙu«ºP%~‹„Í\°œ"Ãà“6‹~³ë·™_”)à©”YgëìxŠ±RQ}46¼|$H]^ÈüÃut ‚êxë¶ş¬5X(—å2Ğ²òÈT‰õp_ì>ıh/úqaîŒçîsìÖ8­i)™Ë@nµŒ•™½ÖÀÔqŠî¹4©ÓæÊg¥çşş˜¼Û` C0èúÂµ3$ur Gê¢‰õÂÏÀBµŞğÁÍ•ÂßİËGÔœ\½ÿÆ‹)ÂÁ¢VHMm"ÿû‰Í ‡PmKl‹(k­Ï`Î¡DKÖÑJ¸_Æÿö]eÙg²fó¾ßH¿E€ŠÛ;XŒEÀs·IN­Az÷ø;X!ÊqU‡üé8çëÛ‚HB6^ŒARLËfc§Fˆ¤jµœ²Ïsèäş:û+-èMæì"šI!#‰Û» ^„|Óº§ıĞû·P´²€CØøĞ*±ŠzŸúyrs#®7Äzá¥C2€Ô[ÕÔ“Qù~ÈÏÔVš1î\£‡Zÿ¯|—Aÿ•'pîöúl¹öT²ı#,ë™?b½(˜mÄãõ–:|³ö*‘ğVK?åñ¬ÊQ©WŸtWqÅrö†Î_‚X3yËWØ*Î=F‹®3æËgtÜÓ¸¦¡áÁ…ª²hŠRäÒ’w+ x?¡—Ø'¨Ÿ}¾qèQ)©MíÕİ](]/Ö¥š’m·£ÌˆH=3±^Õ3¬?ƒüOŞaÊ#ÿä“ òÚèiè~` ãDƒãŸqçô‘Š‹´ğ”NQ1o”ÔvØ¼<Â^Ø¯¨hj¦;g]gúp¶<$—ã`
]q@Qü ùğÇgJ2¾§¡²eç%t…æj?j[cE2–4ÊÚìxÎ†‘£ÄÈqË˜vvµÎ¸ÆÜ„t‡}±Å›˜"§º¸S…ÎŸŞIÚ†i¸|{52˜]G´UØ¤Y}KÓ.Ù¡A…1j„Û²ÇkÚ£³£’6ä«w.³·r¡b%Ë”F„(‘•5Ş¨|¨=å)<r!—–CÛbó’³_AxD?/SÏ¡iäM6ORó3.!JÊ½wöÔñãábÆÛŒmUK·vµŠô’&‹x)Ø†ë?Ë”ùâu˜°óƒÀ”?ëQ‹)Õ,ËqŒñ¹ZZ]¸(!¿ªƒ…¸ôÁêøË8÷ï¼¨"ZgZ9Aœ¡Í5ü>ÃÆ½Ç÷Öî—Åß¦Âe_×xZøÄª–ğH1ìÅª‹ÈZÖä#/ü‹EÙ~ªY;®ÿi¥!íG…kËJÙ'?7°Ê†ğNM%S	¼P682iƒà†ĞÚé˜á9×b³2Û›Cˆ fdU5ºó4¡ÿş³·ƒĞû/óe××(_‹uçs°ö	ğ†OFrìü#g€mâÎÍMïº
é¨Ö‚œä°"¾EÛ w˜³KËì^òR§ÂÈUtçí¥ºŠ/¢Ÿ‰±l¯ôö®jl«×3Ù†Ã‰1X¶™~¬½G<ïº‘Õj<ß_ŸÂ|s†İüÀ0¿êxÑÈ´mA©A½Œ¥5±ğÆrP©Í””™LâÇlşé9@~¼·+ÛpòÈ—¡«š–ÍCÿQÄ¥¾Ş®cçöí»®ëÛÜàc^–Ô7 eFÚıŠ0˜å*¯¡Ã-°KÒNãÁVìk):ÀµYGVÿÖf¾ôA£Ğ
JÓI‘”ÓÇ	fW½¿Sºc—Ûø 5ÁDİú©¿‚m2‚¸İKèûÙ•¬°­Õ;[’œ(¼Ëü=×!ß”å1‡K{ÿÑ3fQ†:¦…Ü9”Šáš(3æ1‰t·`Ú=P;Ó›ßÁ	aV&GZUGã_¹L•LŠË‹¶··¯{ö¤x»xË¤W‚¿"E¸Ö€³™2z:Á›¿qÿjùÖ‰×»*>ãgÜ<ûÿàZj;éøs‡½¿K¥fT[V¼#0J¶nk©Çd»ü—:Kã%ş×!ÍWğ(œìØëX¹V-ÂmÅ™ù,,Œbçİ²[ş}zaJÔ 54jøiv•
%’¹_–ÚãÔÅ¥|$ù+›±ÒÀGa¬¤ë$mˆ5ùxñÄÓ2pş«EŒRKÜgù–/YˆBï}ânş`;Ğ®?]z<¼çchgê í¶Vah9¾4¥ş€˜·.,©c_O‚ÚªÈ­ä…ïõ±Oí¸¨Kk¬í½'UÁ\?Cß¤Ô•ŞÎºb²‚İÇı7¼4×«Tš‘ây·Ö„¾êlñQ+Â/×}ùå-–„DJjÛø°Óšñ—ğåÌcé@6C2;YúaAè7	emtÄ7@'y\‡#;ÛÿÜS¦Â²p¢°õÑ¨c3Ù6Qı²˜¿#*ü"ïŸ‹âŞ—O0ìÂ
åŒy]Í9bè±Qn”HÛ0àJô™KÑe‚ïÏÖ¶â”ìÇ×,Ş‡tø‹Ó|0¨”²‚îÑf0À}l‰‰~(×ü²Ÿb^ò5r¼ß"†Èº?ãš¾fÁm’´NlïÄMÍ¤nmö…t8¦+hÃ²ğL±¶RV	œl3EŠE3]íTgşßw{`+–™æ?ö¹´WHfv=,QîIa*­Ù¢}²½‚}úµÿÿço7‚ÉÎRyå—'#—­ŞÚ©RÅ£"¦èjƒ›nGS£±~’Ó	´o:qh³çşmdè!Ä çqB¯7¹ÊÉÕşpj$Eò¤eKÔ´1á0gÏôFóÉ8Š¿ä`ıA#­ë¿Ùöà37Ëğ|(¨ÁÛòŞ2Ê’şZÃ¾êªKqğÒİHeŒGŸê9£öÀYHD¸ÓsUğ­R4%3‚M»ß;Å u…êÚäõÄ¶uÍ¨x‡gÃ·OÍÂæ43üôÛe ¸/¸^r5üs+ØAò)T!Ã0	£9à>»!}ëïa‚Ì/E“{¶Ø›H·®«ĞDÃ§1Dá²ñ®î€G0¢^´ôï"Şƒ:eê€KÒİ8qĞÍ· )WÚ`•”“2‡${˜Ğçc(9ÿ£„(ã?½ÈŸÙ~/™&µœÉ6»v\£æ»bò­¿ÑCnC{ß²<‚•$›Ì…ÔªÅÙÚìàAK5ô±Ğ¾‰ù8åù(R§Æ\Š™åÉqïBçji7JkÎ¢Àn(n37ˆ¥0TYÖˆê¹ß_“ÛÚ:ÈÎtMÆÉ ,%×Ö<à€*ÖY.¯ñkj‰?¬OÁ_ùÜ¯©'òÜC(>ÿh]bÕ0»v!—F9^ /Eôû•ô‘ CzÇ­Øç+áÚKïWHÅ¦‹¦ÚŸRıÈ„Å7eY<İ5ÊG”²=Î<°ŒT#°)ó„*³Aeœ¤º'féÔTL©À f„b9ó½,ZÏ ¥…ÂÇ0§«³JšJüÔÓs—DÜ4“*$;ÊDFå%¤Ç]IGæ›‘§ø¿Ûá¢kä­½Üç›ŠA5lÀƒüZ*fqqõx8NDF oÿï)çÔ4x»"ƒoˆsrWMªÑ^("pTÌÆÏG´c0l ‚±ğnu\‰’­Àš^º=qĞx›]2ün™fíîXû®¸œ¸Ùâ…Kê°´§°İØÕî!KA\êÙªóÑÀhÆjÁö€©yŞæ£t„œ  KCEàÚĞ(Ég
õµàÑñnó’ïõÈ»²ß`× ÆÎæ´Âkù_£Ö¸QÂ+×°®Ñ|º}¶‡âº-RĞš'ÿ0Ó„a¦‡İ£HÌË‘ªÕÈ+ı¡ÎY-
|çxšöàßM¢ÖO—`T€hX‹`}7SQûEã®öó®H‹ÿÇ%éØŸÅr%ÉÑŞÿÎ±wë®·#TV'3@a†C°ÚTÄúd‰çó‹:ê¹Q¼7èR,M¸"kÒ:ô‰Ó-ïŒë›´å—[¸ş¢XEåQñ†Iİ¶æöÛ»Øó–„¥išQ’‡i- ğ¶¬¨:û‡tÅp¿#Ó[Œ•4ÈuüTÓ³uÄÔ?4j’‹RüXå
.l=®ˆ¨O¨‰P[Zë®»¯ƒS,G­åK8¾Ò¤ª3JÁÈÒË¼şÂJ(6†I3ÏcÃò#½-HƒPĞ%v¸ä2MºS‰şŒJ¤Œ5167ÕØ5ìÏÁa% İOÍê-]É°GÑP,jŒÑì77cW/Dâwë®~>6 ®İ‘à2»PPdúØ¶«ôñõ;ÇÑyÈ^u sN#î×²”é|çìF;½æHÉôã3Lq'œ˜Z©Gyáe’…Qü)äFDôªÆ©–rS¨Í3’j“ªŒz[–Xo±3FI 1±‡ë–|em­‚à@â(#ÖÖ-pb¼›¾{ûPüLÑEa‹nn)!pÅ%U¨Ç-µ¯Dæ(ÌWS'·‡½S%§	5ë>ÀÀpëİ9—w‰Wæ>rŞ¡”»L÷x–Ãà3ˆ}D1ÿÌlŠXv˜½.¶èélÎ}¥Ü¦wŸşv¬:À¸„n¬8bVİ„zoø=j¶Ò…o$ ïÂLçÀsÂŞ® Şß”c’R¨qúJY±¢’.“V>­:„ãWÒå¢Ëé¶½ÕföÇã1.Â8¼%±kõ©cØæ}:Ê¥Š÷T9¥o=îo1Ë:^6Ûà\´7ÌÖi¨AT}gå1èé@<°Ê³Ú>÷^ñïŠ
&rª¿ŒP²DÕ³H]wŠÛ¢ôw,½iå=¸ ’È6;Âèñ*S.¤¢ÛßøHÓÃq›>•“ˆqâÁ·ş¯…ĞŸVI7æ®ÿ«Ïª79ïÅLè”óÚÌeh-°†±:ÿÜaîyúm;=ªCâT_½j0ÁPGŞŠŞÌßq´p5·ÀsâĞ<læÉdş[0æ—Éš³?AÔS‰L)—ëj-_òı]U÷}N_e ·RS¡É4ƒ†û­Øç }°ÕLõ£MJÛ¯ÿ:+§±ä>ÖÊv DÇˆ¥ÂI€2’µG6d¶å9¹÷ÔD/ÏŞõüŸ×±TìMO'm˜\1± ğÏ™Ô%ÒD¥İ€B±}ªSA¥ÚHì6‰0ó¤*°@õ+†4 w:»ˆ¨nMR3ºÑ6{ÚÀi€İ”X÷/´—3ûœ(R?S}û¤“cŠ&»“GŠ ©Kù%
\åî¦^§÷IXÏîMÉãïÇmßé4ĞÜµßqÒçÑùİÂ»H•}Ûıˆ„°ÏÁšéOÎõaà$:Ç§]‘1ã²xè¬1£qÙ©Ø¾hµ*n‡wŞá†çÃ¢ÊÃ)ÊsƒjîÅK¹ù«øÎà˜y­”\½c®¸Æw‘tê~¸$×h¢w1ı‹J¬©x—n>À.Å½)ÑWÓú­Şğ»-qBD'º¦yı:¡C[á[ß†ñĞUBÕØy8³ê%ş5H'˜[I©ÿih|4x®ì£Œia‰¨lqÛ¼&7¡à›"pÂ¯ı­=Ğ[Öc¨.ÛO\üúÚPŒU‚ûŞ½°/bvªªå=SÆyÒ^_ÿÏ¼^—)™Y)hå«6ñtfÁ|i²:êÃÀŸş¦Ámî'D!ÿşj|„”‰ßF(%À°(Ô£F0Ö}:XíöÂš7”êşxYóƒi^4v©Q‡ÍÅÑC=§†@ø°×¡ò{å‹F‘‰oNMLØ[±å:›œ{Bq'oN”„á3²cÜq_oT¼Üv/ÛÃÓ–è5ƒúc#hh[ŠÚpÃ—ö*%¸öà§)j%ïêØà"WBpFÇ(‡x"V®
ø<ss¡„í;•½UnÇ_çÿ>@ü•èé•¿x_nû¸”£¿	{^Ëvş°¨‰¸'ºİ¦ nu¬ş@³*;•¹©h¢¤çvÁb Ğ†$-ˆ!ñ¤±)t4†=2•j|PŞ1ohø_ò…şøˆØÕwÓ’t%ÎÏÒ[ŒË±ªfù~<àâîş\†ûRş2å* à:»Ãç½*/Œ/çJùdáß¥eİô‘:H-|‘ò€#Ğßùç²†fh9»¿%jh‡œåN-ö¨(x¦@Xä…û
 «6ˆaØ.ŠT‹d¸Xá^Î+:ÇcºP<—Ç#–SZe•ÀWë¸ôğİ@LXÚ)ÔcèÓ“§' ½z’ƒÿÿ/Ì Í…û¶]úærØUf:ÕzHğ¥[ï×4î5ê9é¿3Åc9€ ô}ÓG6ËOË^X:êG3kø|g‘'nˆ¥²¥3”?ÛÒb hlmÖLy;i½Fè´ö†šÙ”Œìp[™
DöA$¶-ßs·ŠƒK!®ŠŒ£éâı;Ã#}É¢³nRR’Ü
Û¡£D”¹¹(FØBaPF•ˆ^T£59X&×¶ ¤¿í5ÁK÷ÇKS»ÔÜò¼Ï}»ZÒ/†@[ı4:½şQön–TŞLÃ™-šF8ÊWx²ò•·àq>Ÿç&…-“‚Ê+:ŸìŠü˜Ùò›uâA}0ú z%Œ.ü-¯Coâå%°­>&íG.eqOkQ“Í˜·uÈËéYÙv‹¸'´[Z’ñëØ” ÕÊò”*éÑ .5Ÿ­_²çQºæùÚÑ1ò_ç´¾ÒÌolãWG“ÒûüÆzš·gº¤]ÅnĞEO	´ØtÚš¢=ôe S†Û½j?2/4æ‡Ê8(â‘%Q$Ä_ô{_Ü¶à(rôğïeßÇ…Ğ"Tjİn’¹·QKİ— ¢³¼ îX	øB õğ)ºË”‘R–^ –³jbU{<CiË‹÷B±˜ÂşC,„òXÚV*fô!İã9ÏşÛ¼Óm]‰ÜM«C¥,¹L2<FÜ"¸ZÚmŠµ%Ã§Î¾Œab‰B;¶º^ê…¾‡ñÌ\W#Ç›ò»`¥êJİÏóáqÊğ#ìÌ½Âl‹¬‚-]õ€?TãÔ\ÜÚ³K£ÒáéOª
½O÷Æ²Ò=Ş—51¾4áyk5Š„®Î0o°ÅòGƒÈiËØ
¤ß¥V¨ã…7e¬óÚÌBpñˆn8.
›"Ñ%óØApÖÕ›=Tz­®&ï$iò÷Ğ$ß‚';SÖ[€yĞs{u§ğ|¼•²õÆë¨¬n 27×ewĞ±ÔôO-ï×ûïLMÀ#+àÃğã°Ø6aÓÁŠ³SÆJSìÿ ÖÍ‹_éäEw2tCŸS¢æYx8×†±ğöì5›W;C1åÿbW.v7¸À .-j”ëé¢(véô{bĞlî5ËIóüÎ°k€–èûCÄù_(^O¥¢ñæ:Cm1VôàşÄe×ünNØ…õúad×şfN@;şÛÔñ"²æ¿&‰€•ÎAıb§\ù-­Å+µøöß~èu¢kƒsÀø0<1“`Ñ­™ VÅH O
£óásÆÌí)…1È>ÈŠßƒı^LÅùÊ ?²oµW5–ğƒ½„ÊóQ´7XGÈğsQr ·
l~– ›0£‚tYŠ„’Ä SoÉ¶¿(Z^‰C…TºyC¿)ûâ0;ù…7Z¥@Sx<já` €õß‡é²1~nv>›ì©v†?$¿nùxá<ì¿¨c„Ó>±à¹Jm/Æ ÿœßğn[g 1û	ÃcJš£CiÓ¼è†ÿğÁkÒº›íK:Î±«4M÷OŞİFfm-âëM’-fqPH¶njmÑùÍKÊˆh}ñ8ÊçÁIs¼îÕJeŠbR²
‰øÒ:åèÌ±÷AƒfyAœ#ï™wãÕ9óâ¿¥ÔÛÙÍ\«M{Ó®eæOÛğ_8ƒbI˜N7ğñ·Mé«ü»ThÙTNT‡Ï4(¬Ù™êØš®Å‹ÅñrI¯†5æãSısÚNúµ”
ÙÏ—4è·¯“ÂÃt+˜æuVñéïˆ
’XòiºúW×!1åø5dåÂßşïñ¦qaIÎà§S-3w#GÊ`ÕÕP—ş‚YNQ ·ùTOçQi›‘Î(qµƒ`³å‰)T9‹ûm¬9£og.7ªÀ½‚I²aŠÈñÍÛ%`L¢f–Èô‡µr©-r;Ş¼È¢øë74GòeeĞJ’wı­”°dwâÓÃk=
•Q/ı6n•Ë
íLsµÙ	p/Râ·7oAùHAWL,Ş¯Äò¯°z^öÔNš¿z½ìMkÉ†©fÔókS«p{ß~÷÷çH1ª N¢Œg#œeŞ8;$lÓŞ“LYÑ¬õ…rûÏsæt#¢ì˜ óIš8})„Ö©Óş­¨¬°öU<„¦	mŸóÄ&,eW…ù@C¨8øü2n³Ñ/Kh¨}ÙbpVÃ%Ó‘÷Á@fT•‡Ò„.>ÜSe/T§RƒF/×hP>ÇY,ÈGNWĞ/:ÔS$Q ü"­‡)Ö •½ Æã\äÅÄäIùTùxÇl©¨£³„¥ÑEcÏé]](ÖÈœP*dK`¬‘t¨[Æ_Ú(xñÉÎèl`)´òî¦±í¿Ã‚)”±EØ¨}ßÆèì&¯Ôr)×Ÿª4ÒŠÆ 4¼B´Øcwsª;båÕ)Ê»ÍõVƒ`şŞPy—,ÀW bµ·F­ÀD”h±ÃJôHŸøËR Äv¶òÖ¯u1sÇŒ@±¥Æá¸mo¿È3´<@ºJ
väI;FŠº=05ÿÿU¦m\oK³´Df^²iüW‘Ëàó—”8@Ö• ï}>º8Îÿ¿è¡+¡+švW“r›ÃÙ6çqNÑÁa´;t#?}.{¢>Îèıd>aû'Í;Ï€ÚêJÇ¶ßªíI†“Í-i½”(Ù4[à¾ÿ{ØÃÌ"È
$6íà]j•eÈñ·– 92C	Á´{övRiÔdkVbÀ(ÃGª€5µMúû–¹€;`æ	®Sœë­f·Š5†‰´eìõ|[7|{‰CÔ¡Jãò-ŒüŞ5¨¬¾²Ï¼m¶VÚ™)MÅ²Ì»ÅfùŠˆ¶ˆÎÿÔ,ÖY0ìû§,£«š&{è6p»î5ÿZ„<h‡_P`e1µ¯ŒúñŠö¤q‹ïLªÔ-´?ÓÌgÀŒ|ó‘ùß$@Şê‰á,vâ‚;ßu«n{Ï1—ãÇ^§>ÑÔng!k¢=LúxŸîÇ±³"Y„ÒDíj?%4” š@ƒDiHÄ]XF›æò88¯ËèHFúPÃF¦ ”´ˆø¥Âd­³NÖLò^D`¦JĞör¬Şğ^n¥ƒÙ%&¯¼v.vÎĞó¨¿õ+ñ]"qá64´óÍÄƒ^ÛüÈV¤q¢d Üé®€õŸw qĞ’áôúì}®ógvxõ÷ô-¥:½Íƒt~Z½†ÃÓ²q¯CóŸÀ[t>µÅw‚ ›pÿ'$Ë}!uà†Ô?¼QÁ¹&¦+'VÔù…ÇüYæCÊ6ùAg<ái¶pÊÕß¨¥W]±Í,'¸@IKŸİ#XfÃöınÂ¥m Õ Gÿã{Éç—3çRŒf“tX"Œ{á.”F~QWIÑ‘a¢ŞØ@T¶¢é—îˆY>å€£7P8™ÕÄ{È,E²eºyàÖrb_°55Nîcº{¤e!”³‡ûšu+eQ¯óPÓp†\ÑëB7›÷¨½£hB¶LI:Á'J´²iÌNÕ’§Çô…k«	áÄwiŒa9aúİ3sç=ó(êµÀ9ÂÖ¶~HZIÂhgH™K-ò¶F	i³ @Hj­ØTûû®ÕÎUvøÎšƒxáX
¾<vd&ƒû0ŒMßÀî«	$pzVe=Û¢}FMà1‰ı¼@€¯k0ş!{Ğ>¿š7½‰|ÕQ}-7sİi›Ey|€ ÙLDeÁ
ë?ö°„„ïO]%±™EpUJØ/V]!,ÇÜ	àìS¸šŞ[É'›(ãĞ’şìV\Õ±91}î‹í)ÍˆŒm({Ÿ!çX… àz»ÄdÌøÉ`Ë1°cÔAuêb'û	ó@OäÒ,´Å–Ö„&í-@%»V^={¿ßmD·YÊ;y·Á·»òOcS*
9!Õ«_şµãñ»À±ÒÂ^Eè‹_d.¹,‡Ñrü?ÃP{‹ùçcôº¦_Çj†{™¼á.>Phv9LsĞJ‡m9¥øM˜û4SRû]í@‚©ÔÛÖ€’øo¯ùÃñIùzóÏßÏ¯&vĞÄŸ´ÿùGRÍÕN¢˜sÇ`0ŒZ4åû¸òˆÜ‹
Wò±Ç™¨Q=›uŒàxĞp	h^Ë÷îÇ,Ès”O;ŒÑc*°Ä¾èñ\%€
±[¶ãÁ<nxhFà,ğ>bIñ†ù¢õGHYØ#8ş‹òqÄˆFOb¼Ém¯–Àªiç¤n´ÿ_Ë¡U,û¿¡Ê:(µÌwlQ#Tôø'2ÖR`ÄlQ˜k…Nşrw9‹=÷ûÀ+“,á˜p°¨$oA\‹ƒOrÛs®™yp.[öü‹ÔåjÅdAº:_ßğèĞxƒ>"J<¾iÊÂ¢’¤¿?…6/ä÷ğ‹Ï\ú¶<]¦xSê_×–Ğø¡ôârç
†Î˜!ßÅt¯¤°÷KOHúb…øÀ"åı¶œ;eğ‚ä=ıØ(‹•Z²†¨D'˜kj^_ 5ü½Cù­Ã-­
`#Ÿ÷€¤›ãğÛ‚şn:òÑAµÊÓ1bnøøû<taáGz¤ğŞS?z[Lz>Gÿ´àüXœ{ÃãOÃÔI€ªnaÕ8ô`\X(n1óJ-S–†š-çj½ñi¹yi…ˆ†§ĞŒçaôÉpÂíµüÃK‰Æ®-óP> ö4âKïÇ90æ	“^bR !7J(È!ØÃ)CŠğ¥Bšå.‡^5Ø‰;EC˜v~E-›JÊÎşÂğ{ğ5_‡ƒ )ê¤´ùYÄ4·O}äÖTÿÚ¾œv5\P€ˆXÏS"—Gû÷gD ‡Ò—`ƒ…›ç§şPJOÃ•<…!ë¿Ékt¤\†é¥E¢ğZê-êA¼WHµ<Wšî1úi)a˜©õÜ 2š9á»¾,SyßÎ³ËŞ²³ô‡¶CÀ£‰Ùsf^õâN:§hl[üÏjïEª¸Ğg'‰î¹ŠqñÃ3XÎÀí)í!\'­Ø…cøÂĞkNH âKRõE›d&ß• CÉã‘Ã'C3)2_Eq½e8fÉô·z?.¢êÛ|¸WOXsQŒ—}X¤ı©eF&1701oû ¬­TíÂ(V|UL•Ï¯ğim}Zü÷ZŠeªI…	ÊŒ¾_æBj r¤Çc=n™ªƒŒ,fÑ0™oÂşx“˜yZsxöcD×
?‹uËî›ÿ*ˆ‹3¤1ßóí……w!d“0è]r3Lk„WÇiûñÄŠï{YÖˆmBúºç­Õ›f[]Ş¶3ˆÔ`º†ÎTŞBÒÌæ–á(²ããJÕıš\)¤:?éNbÉ´qA·]j+«m_¹÷ùœàöÂÏ¸+z~+_*˜)
QôÓWVv,Ú<İ)–Ï*z$7PÓŸLà… ş¤c·°9î4xµ€›"ËiÀ>h2ä‘ëbÁ–éT7Ğ¿§m9«˜ÓTZé¯GXJOÁÑ¹ş6»6¦±ÂÏózáëôĞÛÓµó0\®»Mä¶‹A“gÄÎ ¿aĞsÂü‹ÚÑy@O¿sÂ°OÁÃš0õöy=ƒ“­R¼€şIÀÇ¹(ÄnU²%››´ÛàËtQ‰9«-?H„c‹7é9À£H¸”$Eº©¨>æç¥^ÁRtÌ—IÏ|Á#uÿ˜‰®ÿoÌ¥9yÔæ-N‚ÕË_à*Ø”$,5L¾–µ{Â¡2sZŞëÇ«|­œ?±éó•„QS"Å/)ú>€›†Q²x¬EıÚ¨,­}u³#†!ËI¥0/ÇVÁGÛè³äÏ;³7jˆ)#°Ö†ĞT÷µ+Ó¯e£Ìï3@?‰#´ÄâSwîˆûmlõÏ`•V¤†ƒ:ufÆÆ«1âùDF<S4Ü*Š±ğch¡rğN¨àe!!<áˆ­şQÃ;úìÀvœs(u¥äGƒL#Ó×ÅÓãK|‡5É°q˜X!ÛÄùKèS
‹Dš|XÑ_\–²„ÉÔêQ.:Ü£`~	DÙ“Z]ÿÙôß†À„¡èÕÔŠ’T¤’ âv”D_¡AAäŸ~ª0ïçï¯%QÆi­­¤:\HSÚ¤B*iûï÷è-_L&yh‚å¦Ê/²ÂÒİ~İ˜¼Ğ…‘(ÀT°eçÙÁíTåm¶«kˆ 0@$s•¬éí€hFRª­~åB©¿291·z"¾²lë€¾æ^ç¼°c`QD$ƒœùÆæ,Øoš?ÿşjgY=z³ó ƒqE›W1ˆ?ßxÚœ4€ŠÖäİÿ]@Â·¥bÚóûşúHÛÈPÊHÏ-¹Ù¢ÍÁŒS™2~¹>š¥"Êä§¹ãüÁïf¦°   1Y”·ÿ•ãD|QTQ³ıX{¤Ao™V!‹ êÍz,	”IaË{×zÂŞ…§{c*Ñ;«àâôŸÁ   AšF+ÿ   héö–›H}  ó   Ašf+ÿ   	ş<h Ø5Ğ  |   Aš†+ÿ   	ø?µÙœÒæÁw  •   Aš¦$ÿ   FÈW—h÷«k  <!   Ašæ"?   DÀp{|q­   |À   jA›"¿   ›h
 2ˆVš^höKÿg1¬ÑÓØèœV5Â¸#ù3áôL—Ô7l-÷}¦&fK¦m~îÉú­@ô@70mÔá0î{.‚¹ŸI½rÎ$œâË;¢	AJÈ…¿è  Y   A›&"?   C³İ !ğ¤ÛK_æ¶ª“v}Fj £sÑwÃaåoùüY?¸úïÿËàªCìÂV¡q­dNëi+HÚÛŒ»—v’>¿(¥ í=Ãõü‡s»æ²‰ÉíÉ«PùpøeDÜ€:Ò|€\/ÜÇ7JKt;UÏÖéCÇö÷’jrP·»à     }A›F#?   Ğ_% cU=f~Âm’!ıË}z<ãx“?‹ÿZs~T>cwŠ­ëTŠúTß5¶u]ÒOÿvò>×ïGJË…Î§.e ê'‚oz—C™ë^_BĞÌsoıÃ•³íså²6ìn“g„¦X·u âş¼  ²   {A›f#?   >·É@ÕQÙcş•MÉÅ{Ì…··˜ úK
\4ôúè¾oÆí44ï·ù¤IF4l¿äç0PŠ&n¯±öFs7H0ˆ ¦peº¾Úén,¨~"ËHb4.áÓ°î©zù–Ní.?—*ü@  Ğ   ©A›†#?   :—É@>Ë€Ö–^Ã¿×‹¾×zf„³‚ˆ¸¼w+Sà.‘—Ìym=£¥§… 8®bê:¶Ÿ ‘¶½¶cšRÀ4_Ëìó!ôq^äôî†é£5 ‡T2ùæıÉj*õíŸ1±{ĞáH 6u%*g)ã[^i}½şO3Ìªú·k=ÕSSÏqÔq—’Fz¸Z…7_E@4BÒ/‚€ õ   ”A›¦!/   èàø >‰¯s¸(18Èqİ;^mlŸ]=Ñì“±Ù”½¹J=]ûøîÆ“+ŠÜ'Bó´ ±ôÜ’x7®?L&}¶È&«P‘oYƒ_âM‚Š´ÿHEq¡ë…ø (Ö¦×"9–=ï!Â©Ç*ùÏˆârÖÊb5%¥zUsíD¾2Š¡Îóö¥`ø:›d A   A›Æ!o    Ú¡@›¯R—À  ¶  »moov   lmvhd              è  2Ã                                            @                                ætrak   \tkhd                    2Ã                                              @   Š       $edts   elst         2Ã         ^mdia    mdhd             _ Ø‰UÄ     -hdlr        vide            VideoHandler   	minf   vmhd              $dinf   dref          url      Éstbl   ©stsd          ™avc1                       Š H   H                                        ÿÿ   /avcCM@4ÿá gM@4ÚCäˆ„     @<`Ê€ hïÈ   btrt     ˜k      	Xstts      )          .Â     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ô     š     ú     š     ú     ”     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     ”     ]„     ú     š     ú     š     ú           :¶     ú     š     ú     š     ú     š     ú     FP     4     ú          š     ú     š     ú     š     ú     š     ú     ”     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     :¶     š     ú     š     ú     š     ú     š     ú     #(     4     ú     š     ô     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú                )"     ú     :\     ú     ˆ     .     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     4     ú          .Â     ú     ”     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     ”     š     ú     š     ú     š     ú     š     ú           #‚     š     ú     š     ú     š     ú     š     ú     (È     ú     #(     ú     ]Ş     š     ú     :\     ú     š     ú     š     ú     š     ú     š     ”     ú     š     ú     š     ú     š     ú     š     ú     š     ú          (È     ú     š     ú     š     ú     š     ú     š     ú     .     š     ú     .Â     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     4¼     #(     ú     or     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     ”     š     ú     4     ú     .Â     ú     š     ú     š     ú     š     ú     4     ú     š     ú     š     ú     š     ú     ”     )"     š     ú     š     ú     š     ú     š     ú     š     ú     š     ú     š     @V     ˆ     ”     4     ú     š     c~     ú     š     ú     š     ú     õ   (stss             J   Š   Í    I   stsc            U     hstsz          U  0    i   +   Œ   w   »   ¤   Q   j   n   3   &         '       1   s   (   e   F   /   ¿   I   M   J   Z   ^   _  H  +   k         .         t   c   u   i  µ   t  m   ê      Z  Ú   ¯   —   ‚  M  ÿ   /      C   ›   l   c  Ğ   Û  /   C   I   l   g  Í   Ë   z   r   g   #   è  8J   ¦   9          K   \   r   $   '   <   l       .   $   "   J   G   X   L  ˆ   œ   ´   ß   œ  c   S   ¢   ¤  Ä  i   t        a   O  ‡   a   ;   1   j   #   ^   D   N   p  µ   Ÿ   Z  	Ø  #   â  ·     Ë     µ   è   i         t   (  k  2ú   K      %   #   N   d   k   ‡   Q   D   >   <   +   %   8   F   7   ü   Ò   |   ‘     ±      =   \   a   š  Î      i   x   l   f  î   S  Ó   C   9   O   $     »   e   Š   ,   d   F   ‚  Î   ğ   y     a   n   ‡   d   _  A   –         L         °  ?¬      $      #      &      ‚   n   z   |   ¤   š   =   2   -      J      O  &   d      J   |   ¼   l  Ú   q   9   ƒ   ‚   ©  ­   ¼  h  '   ³   v      Ï  Œ   t      2   L   \   –   ›   Š   ˆ   ,   ‹   e   —  	  >   ò     8  0  8É      q   q   ‰   {   …   ‘       !       ’   i   5   V   T   T   €     ¢      l  ;   G   ˆ     °   Ä  l  O   Ã   n  Ó   (      @   '  p   x   g   ­   ¹  Q   e   ¡     6  >   ü   J   z   ~     ä  Ù   ¹   Ô  F   «   h     S  H¯                  n   ’         ­   ˜      stco          0   audta   Ymeta       !hdlr        mdirappl            ,ilst   $©too   data       Lavf62.3.100---------- end ----------
-------------------- ./tests/Test_CullendulaAppBootstrap.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

#include <QtTest/QtTest>

/*!
 * @file
 * @brief QTest suite for the GUI bootstrap helper functions.
 */

/*!
 * @brief Covers environment setup and main window presentation helpers.
 */
class Test_CullendulaAppBootstrap : public QObject {
    Q_OBJECT

   private Q_SLOTS:
    //! Verify the helper sets a fallback Qt platform plugin when none exists.
    void slot_Test_EnsureQtPlatformPluginForTests_SetsFallbackWhenUnset();

    //! Verify an explicit Qt platform plugin is preserved.
    void slot_Test_EnsureQtPlatformPluginForTests_RespectsExistingValue();

    //! Verify English is the default application language selection.
    static void slot_Test_DefaultApplicationLanguage_IsEnglish();

    //! Verify English intentionally maps to no translation resource.
    void slot_Test_TranslationResourcePath_EnglishIsEmpty();

    //! Verify each translated language resolves to the expected embedded resource.
    void slot_Test_TranslationResourcePath_TranslatedLanguagesUseExpectedResources();

    //! Verify switching the application language updates the tracked selection.
    static void slot_Test_SetApplicationLanguage_UpdatesCurrentSelection();

    //! Verify invalid language values are rejected by the low-level helper.
    void slot_Test_SetApplicationLanguage_InvalidLanguageIsRejected();

    //! Verify the low-level helper rejects calls without a QApplication.
    static void slot_Test_SetApplicationLanguage_RejectsNullApplication();

    //! Verify translator load failures are surfaced cleanly.
    void slot_Test_SetApplicationLanguage_LoadFailureIsRejected();

    //! Verify translator install failures are surfaced cleanly.
    void slot_Test_SetApplicationLanguage_InstallFailureIsRejected();

    //! Verify a valid auto-quit schedule stops the event loop immediately.
    void slot_Test_ScheduleAutoQuitForTests_ValidDelayQuitsEventLoop();

    //! Verify invalid auto-quit values are ignored.
    void slot_Test_ScheduleAutoQuitForTests_InvalidDelayDoesNothing();

    //! Verify the helper shows the main window.
    void slot_Test_ShowMainWindow_MakesWindowVisible();
};
---------- end ----------
-------------------- ./tests/main.cpp --------------------
#include <QTest>
#include <QtCore/QByteArray>
#include <QtWidgets/QApplication>

#include "CullendulaAppBootstrap.h"
#include "Test_CullendulaAppBootstrap.h"
#include "Test_CullendulaFileSystemHandler.h"
#include "Test_CullendulaMainWindow.h"
#include "Test_CullendulaUndoStack.h"

int main(int argc, char* argv[]) {
    if (qEnvironmentVariableIsEmpty("QT_QPA_PLATFORM")) {
        CullendulaAppBootstrap::ensureQtPlatformPluginForTests();
    }

    QApplication app(argc, argv);

    Test_CullendulaAppBootstrap appBootstrapTest;
    Test_CullendulaFileSystemHandler fileSystemTest;
    Test_CullendulaMainWindow mainWindowTest;
    Test_CullendulaUndoStack test;

    int status = 0;
    status |= QTest::qExec(&appBootstrapTest, argc, argv);
    status |= QTest::qExec(&fileSystemTest, argc, argv);
    status |= QTest::qExec(&mainWindowTest, argc, argv);
    status |= QTest::qExec(&test, argc, argv);
    return status;
}
---------- end ----------
-------------------- ./tests/Test_CullendulaFileSystemHandler.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#include "Test_CullendulaFileSystemHandler.h"

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>

namespace {
bool pathDoesNotExist(QString const&) { return false; }

bool pathIsNotDirectory(QString const&) { return false; }

bool mkdirFails(QDir&, QString const&) { return false; }

bool mkdirSucceeds(QDir&, QString const&) { return true; }
}  // namespace

//----------------------------------------------------------------------------------

QString Test_CullendulaFileSystemHandler::createFile(QString const& relativePath) {
    QString const absolutePath = m_tempDir->path() + QDir::separator() + relativePath;

    QFileInfo const fileInfo(absolutePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(absolutePath);
    bool const opened = file.open(QIODevice::WriteOnly);
    if (!opened) {
        QTest::qFail("Could not create test file", __FILE__, __LINE__);
        return {};
    }
    file.write("test");
    file.close();

    return absolutePath;
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::createImageSet() {
    createFile("alpha.jpg");
    createFile("beta.jpeg");
    createFile("notes.txt");
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::init() {
    m_tempDir = std::make_unique<QTemporaryDir>();
    QVERIFY(m_tempDir->isValid());
    m_handler = std::make_unique<CullendulaFileSystemHandler>();
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::cleanup() {
    m_handler.reset();
    m_tempDir.reset();
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_FromDirectory() {
    createImageSet();

    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 2"));
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "output").exists());
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "trash").exists());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_FromImageFile() {
    QString const imagePath = createFile("subdir/alpha.jpg");
    createFile("subdir/beta.jpeg");

    QVERIFY(m_handler->setWorkingPath(imagePath));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).absolutePath(), QFileInfo(imagePath).absolutePath());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QVERIFY(QDir(QFileInfo(imagePath).absolutePath() + QDir::separator() + "output").exists());
    QVERIFY(QDir(QFileInfo(imagePath).absolutePath() + QDir::separator() + "trash").exists());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_GetSuggestedImageExtensions_IsNormalizedAndBounded() {
    QStringList const suggestedExtensions = CullendulaFileSystemHandler::getSuggestedImageExtensions();

    QVERIFY(!suggestedExtensions.isEmpty());
    QVERIFY(suggestedExtensions.size() <= 10);

    QSet<QString> seenExtensions;
    for (QString const& extension : suggestedExtensions) {
        QCOMPARE(extension, extension.toLower());
        QVERIFY(!seenExtensions.contains(extension));
        seenExtensions.insert(extension);
    }
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_GetSuggestedImageExtensions_AppendsAdditionalSupportedFormats() {
    QSet<QString> const supportedSuffixes = {"png", "jpg", "avif", "heic"};

    QStringList const suggestedExtensions = CullendulaFileSystemHandlerDetail::getSuggestedImageExtensions(supportedSuffixes);

    QCOMPARE(suggestedExtensions, QStringList({"png", "jpg", "avif", "heic"}));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_GetSuggestedImageExtensions_StopsWhenAdditionalFormatsReachLimit() {
    QSet<QString> const supportedSuffixes = {"png", "jpg", "avif", "heic", "jxl", "pbm", "pgm", "ppm", "xbm", "xpm", "cur"};

    QStringList const suggestedExtensions = CullendulaFileSystemHandlerDetail::getSuggestedImageExtensions(supportedSuffixes);

    QCOMPARE(suggestedExtensions.size(), 10);
    QVERIFY(suggestedExtensions.contains("png"));
    QVERIFY(suggestedExtensions.contains("jpg"));
    QVERIFY(suggestedExtensions.contains("cur"));
    QVERIFY(!suggestedExtensions.contains("xpm"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetAllowedImageExtensions_NormalizesAndDropsUnsupportedValues() {
    m_handler->setAllowedImageExtensions({" PNG ", "jpg", "JPG", "not-an-image-format", ""});

    QStringList const allowedExtensions = m_handler->getAllowedImageExtensions();
    QCOMPARE(allowedExtensions, QStringList({"jpg", "png"}));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetAllowedImageExtensions_FiltersFiles() {
    createFile("alpha.jpg");
    createFile("beta.png");
    createFile("gamma.jpeg");

    m_handler->setAllowedImageExtensions({"png"});
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.png"));

    m_handler->setAllowedImageExtensions({"JPG", "JPEG"});
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 2"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_FindsPngAndUppercaseSuffixes() {
    createFile("alpha.JPG");
    createFile("beta.png");
    createFile("notes.txt");

    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.JPG"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 2"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_InvalidPath() {
    QVERIFY(!m_handler->setWorkingPath(m_tempDir->path() + QDir::separator() + "missing"));
    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_PathWithMissingParentDirectory_ReturnsError() {
    QString const missingPath = m_tempDir->path() + QDir::separator() + "missing" + QDir::separator() + "alpha.jpg";

    QVERIFY(!m_handler->setWorkingPath(missingPath));
    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
    QVERIFY(m_handler->getLastErrorMessage().contains("could not be resolved to an existing directory"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_FailsWhenOutputDirectoryCannotBeCreated() {
    createImageSet();
    createFile("output");

    QVERIFY(!m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(QFileInfo(m_tempDir->path() + QDir::separator() + "output").isFile());
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "trash").exists());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not prepare 'output' directory"));
    QVERIFY(m_handler->getLastErrorMessage().contains("non-directory"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_FailsWhenTrashDirectoryCannotBeCreated() {
    createImageSet();
    createFile("trash");

    QVERIFY(!m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "output").exists());
    QVERIFY(QFileInfo(m_tempDir->path() + QDir::separator() + "trash").isFile());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not prepare 'trash' directory"));
    QVERIFY(m_handler->getLastErrorMessage().contains("non-directory"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_RecreatesMissingOutputDirectory() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QDir outputDir(m_tempDir->path() + QDir::separator() + "output");
    QVERIFY(outputDir.removeRecursively());
    QVERIFY(!outputDir.exists());

    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(outputDir.exists());
    QVERIFY(QFile::exists(outputDir.path() + QDir::separator() + "alpha.jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_TrashCurrentFile_RecreatesMissingTrashDirectory() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QDir trashDir(m_tempDir->path() + QDir::separator() + "trash");
    QVERIFY(trashDir.removeRecursively());
    QVERIFY(!trashDir.exists());

    QVERIFY(m_handler->trashCurrentFile());
    QVERIFY(trashDir.exists());
    QVERIFY(QFile::exists(trashDir.path() + QDir::separator() + "alpha.jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_FailsWhenOutputDirectoryPathIsBlockedAfterLoad() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QDir outputDir(m_tempDir->path() + QDir::separator() + "output");
    QVERIFY(outputDir.removeRecursively());
    QVERIFY(createFile("output") == m_tempDir->path() + QDir::separator() + "output");

    QString const originalCurrent = m_handler->getCurrentImagePath();
    QVERIFY(!originalCurrent.isEmpty());

    QVERIFY(!m_handler->saveCurrentFile());
    QCOMPARE(m_handler->getCurrentImagePath(), originalCurrent);
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not prepare 'output' directory"));
    QVERIFY(m_handler->getLastErrorMessage().contains("non-directory"));
    QVERIFY(QFile::exists(originalCurrent));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_NoImages() {
    createFile("notes.txt");

    QVERIFY(!m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "output").exists());
    QVERIFY(QDir(m_tempDir->path() + QDir::separator() + "trash").exists());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SetWorkingPath_ClearsStateOnReloadFailure() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(!m_handler->getCurrentImagePath().isEmpty());
    QVERIFY(m_handler->canUndo());

    QTemporaryDir emptyDir;
    QVERIFY(emptyDir.isValid());

    QVERIFY(!m_handler->setWorkingPath(emptyDir.path()));
    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
    QVERIFY(!m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_GetCurrentImagePath_ReturnsEmptyWhenCurrentFileWasDeleted() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const currentPath = m_handler->getCurrentImagePath();
    QVERIFY(!currentPath.isEmpty());
    QVERIFY(QFile::remove(currentPath));

    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_NavigationWrapsAround() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QVERIFY(m_handler->switchCurrentPositionToTheLeft());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QVERIFY(m_handler->switchCurrentPositionToTheRight());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QVERIFY(m_handler->switchCurrentPositionToTheRight());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_MovesFileAndUpdatesState() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const originalCurrent = m_handler->getCurrentImagePath();
    QVERIFY(m_handler->saveCurrentFile());

    QVERIFY(!QFile::exists(originalCurrent));
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 1"));
    QVERIFY(m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_LastImageClearsCurrentSelection() {
    createFile("alpha.jpg");
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(m_handler->getCurrentImagePath().isEmpty());
    QCOMPARE(m_handler->m_positionCurrentFile, -1);
    QVERIFY(m_handler->canUndo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_TrashCurrentFile_MovesFileAndUpdatesState() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QVERIFY(m_handler->trashCurrentFile());

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "trash" + QDir::separator() + "alpha.jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 1"));
    QVERIFY(m_handler->canUndo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_UndoRedo_MoveFilesOnDisk() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const originalPath = m_handler->getCurrentImagePath();
    QString const movedPath = m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg";

    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(QFile::exists(movedPath));
    QVERIFY(m_handler->canUndo());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 1"));

    QVERIFY(m_handler->undo());
    QVERIFY(QFile::exists(originalPath));
    QVERIFY(!QFile::exists(movedPath));
    QVERIFY(m_handler->canRedo());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("alpha.jpg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 2"));
    QVERIFY(m_handler->switchCurrentPositionToTheRight());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));

    QVERIFY(m_handler->redo());
    QVERIFY(!QFile::exists(originalPath));
    QVERIFY(QFile::exists(movedPath));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QCOMPARE(m_handler->getCurrentStatus(), QString("showing 1 of 1"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_UsesUniqueNameOnCollision() {
    createImageSet();
    createFile("output/alpha.jpg");
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const originalCurrent = m_handler->getCurrentImagePath();
    QVERIFY(m_handler->saveCurrentFile());

    QVERIFY(!QFile::exists(originalCurrent));
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg"));
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha (1).jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
    QVERIFY(m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_UsesNextFreeCollisionSuffix() {
    createImageSet();
    createFile("output/alpha.jpg");
    createFile("output/alpha (1).jpg");
    createFile("output/alpha (2).jpg");
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QVERIFY(m_handler->saveCurrentFile());

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha (3).jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_WithoutLoadedImage_ReturnsError() {
    QVERIFY(!m_handler->saveCurrentFile());
    QCOMPARE(m_handler->getLastErrorMessage(), QString("No current image is available to move."));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_SaveCurrentFile_RenameFailure_ReturnsError() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const originalCurrent = m_handler->getCurrentImagePath();
    QVERIFY(!originalCurrent.isEmpty());
    QVERIFY(QFile::remove(originalCurrent));

    QVERIFY(!m_handler->saveCurrentFile());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not move 'alpha.jpg' to 'output'"));
    QVERIFY(m_handler->getLastErrorMessage().contains("rename operation failed"));
    QVERIFY(!m_handler->canUndo());
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_TrashCurrentFile_UsesUniqueNameOnCollision() {
    createImageSet();
    createFile("trash/alpha.jpg");
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QVERIFY(m_handler->trashCurrentFile());

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "trash" + QDir::separator() + "alpha.jpg"));
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "trash" + QDir::separator() + "alpha (1).jpg"));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_TrashCurrentFile_RenameFailure_ReturnsError() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QString const originalCurrent = m_handler->getCurrentImagePath();
    QVERIFY(!originalCurrent.isEmpty());
    QVERIFY(QFile::remove(originalCurrent));

    QVERIFY(!m_handler->trashCurrentFile());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not move 'alpha.jpg' to 'trash'"));
    QVERIFY(m_handler->getLastErrorMessage().contains("rename operation failed"));
    QVERIFY(!m_handler->canUndo());
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Undo_WithoutHistory_ReturnsError() {
    QVERIFY(!m_handler->undo());
    QCOMPARE(m_handler->getLastErrorMessage(), QString("No undo step is currently available."));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Redo_WithoutHistory_ReturnsError() {
    QVERIFY(!m_handler->redo());
    QCOMPARE(m_handler->getLastErrorMessage(), QString("No redo step is currently available."));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Undo_WhenMovedFileIsMissing_ReturnsFalse() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());

    QString const movedPath = m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(movedPath));
    QVERIFY(QFile::remove(movedPath));

    QVERIFY(!m_handler->undo());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not move 'alpha.jpg' to 'undo'"));
    QVERIFY(!QFile::exists(m_tempDir->path() + QDir::separator() + "alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Undo_FailurePreservesUndoAndRedoHistory() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());

    QString const movedPath = m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(movedPath));
    QVERIFY(QFile::remove(movedPath));

    QVERIFY(m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());
    QVERIFY(!m_handler->undo());
    QVERIFY(m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());

    QVERIFY(createFile("output/alpha.jpg") == movedPath);
    QVERIFY(m_handler->undo());
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "alpha.jpg"));
    QVERIFY(!m_handler->canUndo());
    QVERIFY(m_handler->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Redo_WhenRestoredFileIsMissing_ReturnsFalse() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(m_handler->undo());

    QString const restoredPath = m_tempDir->path() + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(restoredPath));
    QVERIFY(QFile::remove(restoredPath));

    QVERIFY(!m_handler->redo());
    QVERIFY(m_handler->getLastErrorMessage().contains("Could not move 'alpha.jpg' to 'redo'"));
    QVERIFY(!QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Redo_FailurePreservesUndoAndRedoHistory() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(m_handler->undo());

    QString const restoredPath = m_tempDir->path() + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(restoredPath));
    QVERIFY(QFile::remove(restoredPath));

    QVERIFY(!m_handler->canUndo());
    QVERIFY(m_handler->canRedo());
    QVERIFY(!m_handler->redo());
    QVERIFY(!m_handler->canUndo());
    QVERIFY(m_handler->canRedo());

    QVERIFY(createFile("alpha.jpg") == restoredPath);
    QVERIFY(m_handler->redo());
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg"));
    QVERIFY(m_handler->canUndo());
    QVERIFY(!m_handler->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_RebuildImageFileList_MissingPreferredPathUsesFallbackPosition() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    QVERIFY(m_handler->rebuildImageFileList(m_tempDir->path() + QDir::separator() + "missing.jpg", 1));
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_Redo_MissingSourceIndexUsesCurrentFallbackPosition() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));
    QVERIFY(m_handler->saveCurrentFile());
    QVERIFY(m_handler->undo());

    m_handler->m_currentImages = {QFileInfo(m_tempDir->path() + QDir::separator() + "beta.jpeg")};
    m_handler->m_positionCurrentFile = 0;

    QVERIFY(m_handler->redo());
    QCOMPARE(QFileInfo(m_handler->getCurrentImagePath()).fileName(), QString("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_CreateOutputFolder_HelperReportsMkdirFailure() {
    QDir workingDir(m_tempDir->path());
    QString errorMessage;
    CullendulaFileSystemHandlerDetail::OutputFolderHooks const hooks{pathDoesNotExist, pathIsNotDirectory, pathDoesNotExist, mkdirFails};

    QVERIFY(!CullendulaFileSystemHandlerDetail::createOutputFolder(workingDir, "output", errorMessage, hooks));
    QVERIFY(errorMessage.contains("Could not prepare 'output' directory"));
    QVERIFY(errorMessage.contains("creating the directory failed"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_CreateOutputFolder_HelperReportsMissingDirectoryAfterCreation() {
    QDir workingDir(m_tempDir->path());
    QString errorMessage;
    CullendulaFileSystemHandlerDetail::OutputFolderHooks const hooks{pathDoesNotExist, pathIsNotDirectory, pathDoesNotExist, mkdirSucceeds};

    QVERIFY(!CullendulaFileSystemHandlerDetail::createOutputFolder(workingDir, "trash", errorMessage, hooks));
    QVERIFY(errorMessage.contains("Could not prepare 'trash' directory"));
    QVERIFY(errorMessage.contains("still missing after creation"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaFileSystemHandler::slot_Test_CheckInternalSanity_FailsForOutOfRangeIndex() {
    createImageSet();
    QVERIFY(m_handler->setWorkingPath(m_tempDir->path()));

    m_handler->m_positionCurrentFile = m_handler->m_currentImages.size();

    QVERIFY(!m_handler->checkInternalSanity());
}
---------- end ----------
-------------------- ./tests/Test_CullendulaUndoStack.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

// own includes
#include "Test_CullendulaUndoStack.h"

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::verifyUndoItem(CullendulaUndoItem const& item, QString const& expectedSource, QString const& expectedTarget) {
    QCOMPARE(item.sourcePath, expectedSource);
    QCOMPARE(item.targetPath, expectedTarget);
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::initTestCase() {
    // qDebug() << "Test_CullendulaUndoStack::initTestCase(): called before everything else";
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::cleanupTestCase() {
    // qDebug("Test_CullendulaUndoStack::cleanupTestCase(): called after myFirstTest and mySecondTest");
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::init() {
    // reset with a totally fresh item
    m_stackPtr = std::make_unique<CullendulaUndoStack>();
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::cleanup() {
    // reset with no new item
    m_stackPtr.reset();
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Create_CullendulaUndoStack() {
    QVERIFY2(m_stackPtr->getUndoDepth() == 0, "CullendulaUndoStack was initialized and is empty");
    QVERIFY2(m_stackPtr->getRedoDepth() == 0, "CullendulaUndoStack was initialized and is empty");
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Push() {
    QVERIFY(m_stackPtr->canUndo() == false);
    QVERIFY(m_stackPtr->canRedo() == false);

    m_stackPtr->push("a", "b");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 1);
    QVERIFY(m_stackPtr->canUndo() == true);
    QVERIFY(m_stackPtr->canRedo() == false);

    m_stackPtr->push("c", "d");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 2);
    QVERIFY(m_stackPtr->canUndo() == true);
    QVERIFY(m_stackPtr->canRedo() == false);
    m_stackPtr->commitUndo();
    QVERIFY(m_stackPtr->canRedo() == true);
    m_stackPtr->commitUndo();

    m_stackPtr->push("e", "f");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 1);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 0);
    QVERIFY(m_stackPtr->canUndo() == true);
    QVERIFY(m_stackPtr->canRedo() == false);
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Undo() {
    // undo on an empty stack should not return something and not fail
    m_stackPtr->commitUndo();
    m_stackPtr->commitUndo();
    m_stackPtr->commitUndo();

    CullendulaUndoItem const foo = m_stackPtr->peekUndo();
    verifyUndoItem(foo, "", "");

    m_stackPtr->push("a", "b");

    CullendulaUndoItem const bar = m_stackPtr->peekUndo();
    verifyUndoItem(bar, "a", "b");
    m_stackPtr->commitUndo();
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 0);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 1);

    CullendulaUndoItem const item2 = m_stackPtr->peekUndo();
    verifyUndoItem(item2, "", "");

    // test with 3 pushed items, then undo them in reverse order
    m_stackPtr->push("1", "2");
    m_stackPtr->push("3", "4");
    m_stackPtr->push("5", "6");
    QVERIFY(m_stackPtr->canUndo() == true);
    CullendulaUndoItem const item3 = m_stackPtr->peekUndo();
    verifyUndoItem(item3, "5", "6");
    m_stackPtr->commitUndo();
    QVERIFY(m_stackPtr->canUndo() == true);
    CullendulaUndoItem const item4 = m_stackPtr->peekUndo();
    verifyUndoItem(item4, "3", "4");
    m_stackPtr->commitUndo();
    QVERIFY(m_stackPtr->canUndo() == true);
    CullendulaUndoItem const item5 = m_stackPtr->peekUndo();
    verifyUndoItem(item5, "1", "2");
    m_stackPtr->commitUndo();
    QVERIFY(m_stackPtr->canUndo() == false);  // should be false
    m_stackPtr->commitUndo();
    QVERIFY(m_stackPtr->canUndo() == false);

    // pushing one element shall allow now some undo
    m_stackPtr->push("7", "8");
    QVERIFY(m_stackPtr->canUndo() == true);
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Redo() {
    // redo on an empty stack should not return something and not fail
    m_stackPtr->commitRedo();
    m_stackPtr->commitRedo();
    m_stackPtr->commitRedo();
    QVERIFY2(m_stackPtr->canRedo() == false, "can redo on empty stack: ERROR");

    // test that this returns an empty item
    CullendulaUndoItem const foo = m_stackPtr->peekRedo();
    verifyUndoItem(foo, "", "");

    m_stackPtr->push("a", "b");

    m_stackPtr->commitUndo();
    // now there should be one item on "redo"
    CullendulaUndoItem const bar = m_stackPtr->peekRedo();
    verifyUndoItem(bar, "b", "a");
    m_stackPtr->commitRedo();
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 1);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 0);

    CullendulaUndoItem const item2 = m_stackPtr->peekRedo();
    verifyUndoItem(item2, "", "");
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_UndoRedoLoop() {
    // testplan:
    // push three items
    m_stackPtr->push("1", "2");
    m_stackPtr->push("3", "4");
    m_stackPtr->push("5", "6");

    // check if undo would be possible three times
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 3);

    // redo should be false
    QVERIFY(m_stackPtr->canRedo() == false);

    // undo should yield last item (5,6)
    CullendulaUndoItem const foo0 = m_stackPtr->peekUndo();
    verifyUndoItem(foo0, "5", "6");
    m_stackPtr->commitUndo();

    // redo should be possible
    QVERIFY(m_stackPtr->canRedo() == true);

    // redo should yield the inverse move, because redo replays the move action.
    CullendulaUndoItem const foo1 = m_stackPtr->peekRedo();
    verifyUndoItem(foo1, "6", "5");
    m_stackPtr->commitRedo();

    // The original move is back on the undo stack.
    CullendulaUndoItem const foo2 = m_stackPtr->peekUndo();
    verifyUndoItem(foo2, "5", "6");
    m_stackPtr->commitUndo();

    // undo again
    m_stackPtr->commitUndo();

    // Redo should replay the move for the second item.
    CullendulaUndoItem const foo3 = m_stackPtr->peekRedo();
    verifyUndoItem(foo3, "4", "3");
    m_stackPtr->commitRedo();

    // undo again
    m_stackPtr->commitUndo();

    // undo: is now (1,2)
    CullendulaUndoItem const foo4 = m_stackPtr->peekUndo();
    verifyUndoItem(foo4, "1", "2");
    m_stackPtr->commitUndo();

    // check if canUndo == false
    QVERIFY(m_stackPtr->canUndo() == false);
    // check if redo would be possible
    QVERIFY(m_stackPtr->canRedo() == true);
    // check if redo would be possible three times
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 3);
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Undo_OnEmptyStack_PreservesEmptyState() {
    CullendulaUndoItem const item = m_stackPtr->peekUndo();

    verifyUndoItem(item, "", "");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 0);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 0);
    QVERIFY(!m_stackPtr->canUndo());
    QVERIFY(!m_stackPtr->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Redo_OnEmptyStack_PreservesEmptyState() {
    CullendulaUndoItem const item = m_stackPtr->peekRedo();

    verifyUndoItem(item, "", "");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 0);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 0);
    QVERIFY(!m_stackPtr->canUndo());
    QVERIFY(!m_stackPtr->canRedo());
}

//----------------------------------------------------------------------------------

void Test_CullendulaUndoStack::slot_Test_Push_AfterUndo_ClearsRedoHistory() {
    m_stackPtr->push("1", "2");
    m_stackPtr->push("3", "4");
    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 2);

    CullendulaUndoItem const undone = m_stackPtr->peekUndo();
    verifyUndoItem(undone, "3", "4");
    m_stackPtr->commitUndo();
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 1);
    QVERIFY(m_stackPtr->canRedo());

    m_stackPtr->push("5", "6");

    QCOMPARE(static_cast<int>(m_stackPtr->getUndoDepth()), 2);
    QCOMPARE(static_cast<int>(m_stackPtr->getRedoDepth()), 0);
    QVERIFY(!m_stackPtr->canRedo());

    CullendulaUndoItem const redoItem = m_stackPtr->peekRedo();
    verifyUndoItem(redoItem, "", "");
}

//----------------------------------------------------------------------------------

// uncomment the following line to make the unit-test runnable
//! @attention Moved to main.cpp
// QTEST_MAIN(Test_CullendulaUndoStack)
---------- end ----------
-------------------- ./tests/Test_CullendulaAppBootstrap.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#include "Test_CullendulaAppBootstrap.h"

#include <QtCore/QElapsedTimer>
#include <QtCore/QTimer>
#include <QtWidgets/QApplication>

#include "CullendulaAppBootstrap.h"
#include "CullendulaMainWindow.h"

namespace {
bool failingLoad(QTranslator&, QString const&) { return false; }

bool successfulInstall(QApplication&, QTranslator*) { return true; }

bool failingInstall(QApplication&, QTranslator*) { return false; }

void removeTranslator(QApplication&, QTranslator*) {}
}  // namespace

void Test_CullendulaAppBootstrap::slot_Test_EnsureQtPlatformPluginForTests_SetsFallbackWhenUnset() {
    qunsetenv("QT_QPA_PLATFORM");

    CullendulaAppBootstrap::ensureQtPlatformPluginForTests();

    QCOMPARE(qgetenv("QT_QPA_PLATFORM"), QByteArray("offscreen"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_EnsureQtPlatformPluginForTests_RespectsExistingValue() {
    qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));

    CullendulaAppBootstrap::ensureQtPlatformPluginForTests();

    QCOMPARE(qgetenv("QT_QPA_PLATFORM"), QByteArray("wayland"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_DefaultApplicationLanguage_IsEnglish() {
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::English);
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_TranslationResourcePath_EnglishIsEmpty() {
    QCOMPARE(CullendulaAppBootstrap::detail::translationResourcePath(CullendulaAppBootstrap::UiLanguage::English), QString());
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_TranslationResourcePath_TranslatedLanguagesUseExpectedResources() {
    QCOMPARE(CullendulaAppBootstrap::detail::translationResourcePath(CullendulaAppBootstrap::UiLanguage::German), QString(":/i18n/Cullendula_de.qm"));
    QCOMPARE(CullendulaAppBootstrap::detail::translationResourcePath(CullendulaAppBootstrap::UiLanguage::Croatian), QString(":/i18n/Cullendula_hr.qm"));
    QCOMPARE(CullendulaAppBootstrap::detail::translationResourcePath(CullendulaAppBootstrap::UiLanguage::Chinese), QString(":/i18n/Cullendula_zh_CN.qm"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_SetApplicationLanguage_UpdatesCurrentSelection() {
    QVERIFY(CullendulaAppBootstrap::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::German));
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::German);

    QVERIFY(CullendulaAppBootstrap::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::English));
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::English);
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_SetApplicationLanguage_InvalidLanguageIsRejected() {
    QVERIFY(CullendulaAppBootstrap::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::German));

    QVERIFY(!CullendulaAppBootstrap::detail::setApplicationLanguage(static_cast<CullendulaAppBootstrap::UiLanguage>(999), qApp,
                                                                    CullendulaAppBootstrap::detail::defaultTranslatorHooks()));
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::German);

    QVERIFY(CullendulaAppBootstrap::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::English));
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_SetApplicationLanguage_RejectsNullApplication() {
    QVERIFY(!CullendulaAppBootstrap::detail::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::German, nullptr,
                                                                    CullendulaAppBootstrap::detail::defaultTranslatorHooks()));
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_SetApplicationLanguage_LoadFailureIsRejected() {
    CullendulaAppBootstrap::detail::TranslatorHooks const hooks{failingLoad, successfulInstall, removeTranslator};

    QVERIFY(!CullendulaAppBootstrap::detail::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::German, qApp, hooks));
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::English);
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_SetApplicationLanguage_InstallFailureIsRejected() {
    CullendulaAppBootstrap::detail::TranslatorHooks const hooks{CullendulaAppBootstrap::detail::defaultTranslatorHooks().load, failingInstall,
                                                                removeTranslator};

    QVERIFY(!CullendulaAppBootstrap::detail::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::German, qApp, hooks));
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::English);
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_ScheduleAutoQuitForTests_ValidDelayQuitsEventLoop() {
    qputenv("CULLENDULA_EXIT_AFTER_STARTUP_MS", QByteArray("0"));

    QElapsedTimer timer;
    timer.start();

    CullendulaAppBootstrap::scheduleAutoQuitForTests(*qApp);
    QCOMPARE(CullendulaAppBootstrap::runEventLoop(*qApp), 0);

    QVERIFY(timer.elapsed() < 100);
    qunsetenv("CULLENDULA_EXIT_AFTER_STARTUP_MS");
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_ScheduleAutoQuitForTests_InvalidDelayDoesNothing() {
    qputenv("CULLENDULA_EXIT_AFTER_STARTUP_MS", QByteArray("-1"));

    QElapsedTimer timer;
    timer.start();

    CullendulaAppBootstrap::scheduleAutoQuitForTests(*qApp);
    QTimer::singleShot(50, qApp, &QCoreApplication::quit);
    QCOMPARE(CullendulaAppBootstrap::runEventLoop(*qApp), 0);

    QVERIFY(timer.elapsed() >= 40);
    qunsetenv("CULLENDULA_EXIT_AFTER_STARTUP_MS");
}

//----------------------------------------------------------------------------------

void Test_CullendulaAppBootstrap::slot_Test_ShowMainWindow_MakesWindowVisible() {
    CullendulaMainWindow window;

    QVERIFY(!window.isVisible());

    CullendulaAppBootstrap::showMainWindow(window);
    QApplication::processEvents();

    QVERIFY(window.isVisible());
}
---------- end ----------
-------------------- ./tests/Test_CullendulaMainWindow.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

#include <QtCore/QTemporaryDir>
#include <QtTest/QtTest>
#include <memory>

#include "CullendulaMainWindow.h"

class QAction;
class QDialog;
class QLabel;
class QPushButton;
class QStatusBar;

/*!
 * @file
 * @brief QTest suite for the application's main window behavior.
 */

/*!
 * @brief Covers drag-and-drop loading, theme changes, menu wiring, and dialogs.
 */
class Test_CullendulaMainWindow : public QObject {
    Q_OBJECT

   private Q_SLOTS:
    //! Create a fresh temporary workspace and visible window before each test.
    void init();

    //! Destroy the window and temporary files after each test.
    void cleanup();

    //! Verify the window starts with the expected default widget state.
    void slot_Test_InitialState();

    //! Verify version metadata is documented consistently in the intended files only.
    void slot_Test_VersionMetadata_IsDocumentedConsistently();

    //! Verify the light theme is active by default.
    void slot_Test_LightTheme_IsDefault();

    //! Verify the theme menu can switch the UI into dark mode.
    void slot_Test_ThemeMenu_SwitchesToDarkMode();

    //! Verify the theme menu can switch back from dark mode to light mode.
    void slot_Test_ThemeMenu_SwitchesBackToLightMode();

    //! Verify the theme menu can switch the UI into the separate purple mode.
    void slot_Test_ThemeMenu_SwitchesToPurpleMode();

    //! Verify the language menu exposes all supported runtime language options.
    void slot_Test_LanguageMenu_ContainsSupportedLanguages();

    //! Verify switching the language updates the checked menu action.
    void slot_Test_LanguageMenu_SwitchesCurrentLanguage();

    //! Verify a real translated action label is applied and restored at runtime.
    void slot_Test_LanguageMenu_AppliesTranslatedActionTexts();

    //! Verify all suggested extensions start enabled.
    void slot_Test_ExtensionsMenu_DefaultsToAllChecked();

    //! Verify disabling every extension blocks the next load.
    void slot_Test_ExtensionsMenu_AllUncheckedBlocksNextDrop();

    //! Verify resizing without images keeps the fallback label text.
    void slot_Test_ResizeWithoutLoadedImages_ShowsFallbackText();

    //! Verify resizing a loaded image reuses the cached preview path.
    void slot_Test_ResizeLoadedImage_ReusesCachedPreview();

    //! Verify invalid image contents surface a preview fallback error.
    void slot_Test_InvalidImagePreview_ShowsFallbackError();

    //! Verify drag-enter accepts URL payloads before drop processing.
    void slot_Test_DragEnter_ValidUrlsAreAccepted();

    //! Verify drag-enter rejects unsupported payloads immediately.
    void slot_Test_DragEnter_InvalidPayloadIsRejected();

    //! Verify drag-enter rejects URL payloads that contain no actual URLs.
    void slot_Test_DragEnter_EmptyUrlListIsRejected();

    //! Verify dropping a valid directory loads an image session.
    void slot_Test_DragEnterAndDropValidDirectory_LoadsImages();

    //! Verify extension menu changes affect the next dropped directory.
    void slot_Test_ExtensionsMenu_AffectsNextDroppedDirectory();

    //! Verify loading an empty directory clears the previous session state.
    void slot_Test_DroppingEmptyDirectory_ClearsPreviousSessionState();

    //! Verify load-time directory setup errors are surfaced to the status bar.
    void slot_Test_DroppingDirectoryWithBlockedOutput_ShowsFilesystemError();

    //! Verify unsupported drag payloads report an error status.
    void slot_Test_DropInvalidPayload_ShowsErrorStatus();

    //! Verify dropping an empty URL list leaves the current session unchanged.
    void slot_Test_DropEmptyUrlList_LeavesStateUnchanged();

    //! Verify dropping several URLs only loads the first entry.
    void slot_Test_DropMultipleUrls_UsesFirstEntry();

    //! Verify navigation slots tolerate an empty session.
    void slot_Test_ButtonNavigationWithoutSession_LeavesUiUnchanged();

    //! Verify navigation and saving work through the main window controls.
    void slot_Test_ButtonNavigationAndSaveFlow();

    //! Verify trashing works through the main window controls.
    void slot_Test_ButtonTrashFlow();

    //! Verify the undo and redo actions move files on disk as expected.
    void slot_Test_UndoRedoActions_MoveFilesOnDisk();

    //! Verify failed undo operations keep history and surface an error.
    void slot_Test_UndoFailure_ShowsStatusMessageAndKeepsRedoUnavailable();

    //! Verify failed redo operations keep history and surface an error.
    void slot_Test_RedoFailure_ShowsStatusMessageAndKeepsRedoAvailable();

    //! Verify failed save operations update the status bar with an error.
    void slot_Test_SaveFailure_ShowsStatusMessage();

    //! Verify failed trash operations update the status bar with an error.
    void slot_Test_TrashFailure_ShowsStatusMessage();

    //! Verify the application About action opens a dialog and updates status.
    void slot_Test_AboutAction_ShowsDialogAndStatus();

    //! Verify the Qt About action opens a dialog and updates status.
    void slot_Test_AboutQtAction_ShowsDialogAndStatus();

   private:
    /*!
     * @brief Create a small test image below the temporary workspace.
     * @param relativePath Relative output path below the temporary directory.
     * @param color Fill color used for the generated image.
     * @return Absolute file path of the created image.
     */
    QString createImage(QString const& relativePath, QColor const& color = Qt::red);

    /*!
     * @brief Create a file with an image suffix but invalid image contents.
     * @param relativePath Relative output path below the temporary directory.
     * @return Absolute file path of the created file.
     */
    QString createInvalidImageFile(QString const& relativePath);

    /*!
     * @brief Simulate dropping one or more local URLs onto the window.
     * @param urls URLs to place into the synthetic drop event.
     */
    void sendDropWithUrls(QList<QUrl> const& urls);

    /*!
     * @brief Find a QAction by its visible text.
     * @param text Action text to search for.
     * @return Matching action or `nullptr`.
     */
    QAction* findAction(QString const& text) const;

    /*!
     * @brief Find an extension toggle action by suffix.
     * @param extension Lowercase file suffix without a leading dot.
     * @return Matching action or `nullptr`.
     */
    QAction* findExtensionAction(QString const& extension) const;

    /*!
     * @brief Find a theme action by its visible menu label.
     * @param themeName Visible action text to search for.
     * @return Matching action or `nullptr`.
     */
    QAction* findThemeAction(QString const& themeName) const;

    /*!
     * @brief Find a language action by locale suffix.
     * @param languageCode Locale code used in the action object name.
     * @return Matching action or `nullptr`.
     */
    QAction* findLanguageAction(QString const& languageCode) const;

    //! Find the currently open dialog owned by the window, if any.
    QDialog* findOpenDialog() const;

    /*!
     * @brief Find one of the main control buttons by object name.
     * @param name QObject name assigned in the UI file.
     * @return Matching push button or `nullptr`.
     */
    QPushButton* findButton(char const* name) const;

    //! Return the central preview label from the window UI.
    QLabel* findCenterLabel() const;

    //! Return the window status bar.
    QStatusBar* findStatusBar() const;

    //! Temporary root directory for filesystem-backed UI tests.
    std::unique_ptr<QTemporaryDir> m_tempDir;

    //! Main window instance under test.
    std::unique_ptr<CullendulaMainWindow> m_window;
};
---------- end ----------
-------------------- ./tests/Test_CullendulaFileSystemHandler.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

#include <QtTest/QtTest>
#include <memory>

#include "CullendulaFileSystemHandler.h"

/*!
 * @file
 * @brief QTest suite for CullendulaFileSystemHandler.
 */

/*!
 * @brief Exercises file discovery, navigation, filtering, and move semantics.
 */
class Test_CullendulaFileSystemHandler : public QObject {
    Q_OBJECT

   private Q_SLOTS:
    //! Create a fresh temporary workspace and handler before each test.
    void init();

    //! Destroy test-owned resources after each test.
    void cleanup();

    //! Verify that loading a directory path discovers matching images.
    void slot_Test_SetWorkingPath_FromDirectory();

    //! Verify that loading a file path resolves its parent directory.
    void slot_Test_SetWorkingPath_FromImageFile();

    //! Verify normalization and upper bound of suggested extensions.
    void slot_Test_GetSuggestedImageExtensions_IsNormalizedAndBounded();

    //! Verify suggested extensions append additional supported formats when preferred ones do not fill the limit.
    void slot_Test_GetSuggestedImageExtensions_AppendsAdditionalSupportedFormats();

    //! Verify suggested extensions stop appending once the helper reaches its hard cap.
    void slot_Test_GetSuggestedImageExtensions_StopsWhenAdditionalFormatsReachLimit();

    //! Verify invalid extension entries are removed during normalization.
    void slot_Test_SetAllowedImageExtensions_NormalizesAndDropsUnsupportedValues();

    //! Verify extension filters are respected during directory scans.
    void slot_Test_SetAllowedImageExtensions_FiltersFiles();

    //! Verify PNG files and uppercase suffixes are accepted when supported.
    void slot_Test_SetWorkingPath_FindsPngAndUppercaseSuffixes();

    //! Verify invalid paths fail cleanly.
    void slot_Test_SetWorkingPath_InvalidPath();

    //! Verify paths whose parent directory does not exist fail with an actionable error.
    void slot_Test_SetWorkingPath_PathWithMissingParentDirectory_ReturnsError();

    //! Verify setup fails when the output directory path is blocked by a file.
    void slot_Test_SetWorkingPath_FailsWhenOutputDirectoryCannotBeCreated();

    //! Verify setup fails when the trash directory path is blocked by a file.
    void slot_Test_SetWorkingPath_FailsWhenTrashDirectoryCannotBeCreated();

    //! Verify save recreates the output directory if it was deleted after load.
    void slot_Test_SaveCurrentFile_RecreatesMissingOutputDirectory();

    //! Verify trash recreates the trash directory if it was deleted after load.
    void slot_Test_TrashCurrentFile_RecreatesMissingTrashDirectory();

    //! Verify save fails with a detailed error when the output path is blocked after load.
    void slot_Test_SaveCurrentFile_FailsWhenOutputDirectoryPathIsBlockedAfterLoad();

    //! Verify empty directories do not create a usable image session.
    void slot_Test_SetWorkingPath_NoImages();

    //! Verify failed reloads clear the previous in-memory state.
    void slot_Test_SetWorkingPath_ClearsStateOnReloadFailure();

    //! Verify missing current files are reported as no current image path.
    void slot_Test_GetCurrentImagePath_ReturnsEmptyWhenCurrentFileWasDeleted();

    //! Verify navigation wraps around at both ends of the list.
    void slot_Test_NavigationWrapsAround();

    //! Verify saving moves the file and advances the session state.
    void slot_Test_SaveCurrentFile_MovesFileAndUpdatesState();

    //! Verify saving the final remaining image clears the current selection.
    void slot_Test_SaveCurrentFile_LastImageClearsCurrentSelection();

    //! Verify trashing moves the file and advances the session state.
    void slot_Test_TrashCurrentFile_MovesFileAndUpdatesState();

    //! Verify undo and redo rename the expected files on disk.
    void slot_Test_UndoRedo_MoveFilesOnDisk();

    //! Verify save resolves destination collisions through a unique target name.
    void slot_Test_SaveCurrentFile_UsesUniqueNameOnCollision();

    //! Verify save skips over several occupied collision suffixes.
    void slot_Test_SaveCurrentFile_UsesNextFreeCollisionSuffix();

    //! Verify moving without a loaded session returns a user-facing error.
    void slot_Test_SaveCurrentFile_WithoutLoadedImage_ReturnsError();

    //! Verify failed filesystem renames surface actionable save errors.
    void slot_Test_SaveCurrentFile_RenameFailure_ReturnsError();

    //! Verify trash resolves destination collisions through a unique target name.
    void slot_Test_TrashCurrentFile_UsesUniqueNameOnCollision();

    //! Verify failed filesystem renames surface actionable trash errors.
    void slot_Test_TrashCurrentFile_RenameFailure_ReturnsError();

    //! Verify undo without history returns a user-facing error.
    void slot_Test_Undo_WithoutHistory_ReturnsError();

    //! Verify redo without history returns a user-facing error.
    void slot_Test_Redo_WithoutHistory_ReturnsError();

    //! Verify undo failures are reported when the moved file disappeared.
    void slot_Test_Undo_WhenMovedFileIsMissing_ReturnsFalse();

    //! Verify failed undo operations keep history intact for a retry.
    void slot_Test_Undo_FailurePreservesUndoAndRedoHistory();

    //! Verify redo failures are reported when the restored file disappeared.
    void slot_Test_Redo_WhenRestoredFileIsMissing_ReturnsFalse();

    //! Verify failed redo operations keep history intact for a retry.
    void slot_Test_Redo_FailurePreservesUndoAndRedoHistory();

    //! Verify rebuilding the image list falls back when a preferred image path is gone.
    void slot_Test_RebuildImageFileList_MissingPreferredPathUsesFallbackPosition();

    //! Verify redo keeps the current fallback position when the restored source is no longer listed.
    void slot_Test_Redo_MissingSourceIndexUsesCurrentFallbackPosition();

    //! Verify createOutputFolder reports mkdir failures through the helper seam.
    void slot_Test_CreateOutputFolder_HelperReportsMkdirFailure();

    //! Verify createOutputFolder reports missing directories after a reported creation success.
    void slot_Test_CreateOutputFolder_HelperReportsMissingDirectoryAfterCreation();

    //! Verify internal sanity rejects an out-of-range current image index.
    void slot_Test_CheckInternalSanity_FailsForOutOfRangeIndex();

   private:
    /*!
     * @brief Create a test file below the temporary workspace.
     * @param relativePath Relative path below the temporary directory.
     * @return Absolute file path of the created file.
     */
    QString createFile(QString const& relativePath);

    //! Create a representative image set used by multiple test cases.
    void createImageSet();

    //! Temporary root directory for filesystem-based tests.
    std::unique_ptr<QTemporaryDir> m_tempDir;

    //! Handler instance under test.
    std::unique_ptr<CullendulaFileSystemHandler> m_handler;
};
---------- end ----------
-------------------- ./tests/Test_CullendulaMainWindow.cpp --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#include "Test_CullendulaMainWindow.h"

#include <QtCore/QFile>
#include <QtCore/QMimeData>
#include <QtCore/QRegularExpression>
#include <QtGui/QAction>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDropEvent>
#include <QtGui/QImage>
#include <QtGui/QPalette>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <algorithm>

//----------------------------------------------------------------------------------

namespace {
class TestableCullendulaMainWindow : public CullendulaMainWindow {
   public:
    using CullendulaMainWindow::CullendulaMainWindow;
    using CullendulaMainWindow::dragEnterEvent;
    using CullendulaMainWindow::dropEvent;
};
}  // namespace

//----------------------------------------------------------------------------------

QString Test_CullendulaMainWindow::createImage(QString const& relativePath, QColor const& color) {
    QString const absolutePath = m_tempDir->path() + QDir::separator() + relativePath;
    QFileInfo const fileInfo(absolutePath);
    QDir().mkpath(fileInfo.absolutePath());

    QImage image(24, 24, QImage::Format_RGB32);
    image.fill(color);
    if (!image.save(absolutePath)) {
        QTest::qFail("Could not create test image", __FILE__, __LINE__);
        return {};
    }

    return absolutePath;
}

//----------------------------------------------------------------------------------

QString Test_CullendulaMainWindow::createInvalidImageFile(QString const& relativePath) {
    QString const absolutePath = m_tempDir->path() + QDir::separator() + relativePath;
    QFileInfo const fileInfo(absolutePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(absolutePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QTest::qFail("Could not create invalid image test file", __FILE__, __LINE__);
        return {};
    }

    file.write("not a real image");
    file.close();
    return absolutePath;
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::sendDropWithUrls(QList<QUrl> const& urls) {
    QMimeData mimeData;
    mimeData.setUrls(urls);

    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    static_cast<TestableCullendulaMainWindow*>(m_window.get())->dragEnterEvent(&dragEnterEvent);

    QDropEvent dropEvent(QPointF(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    static_cast<TestableCullendulaMainWindow*>(m_window.get())->dropEvent(&dropEvent);
    QApplication::processEvents();
}

//----------------------------------------------------------------------------------

QAction* Test_CullendulaMainWindow::findAction(QString const& text) const {
    QList<QAction*> const actions = m_window->findChildren<QAction*>();
    auto const match = std::find_if(actions.cbegin(), actions.cend(), [&text](QAction* action) { return action->text() == text; });
    if (match != actions.cend()) {
        return *match;
    }

    return nullptr;
}

//----------------------------------------------------------------------------------

QAction* Test_CullendulaMainWindow::findExtensionAction(QString const& extension) const {
    return m_window->findChild<QAction*>("extensionAction_" + extension.toLower());
}

//----------------------------------------------------------------------------------

QAction* Test_CullendulaMainWindow::findThemeAction(QString const& themeName) const {
    return m_window->findChild<QAction*>("themeAction_" + themeName.toLower());
}

//----------------------------------------------------------------------------------

QAction* Test_CullendulaMainWindow::findLanguageAction(QString const& languageCode) const {
    return m_window->findChild<QAction*>("languageAction_" + languageCode);
}

//----------------------------------------------------------------------------------

QDialog* Test_CullendulaMainWindow::findOpenDialog() const {
    QList<QWidget*> const topLevelWidgets = QApplication::topLevelWidgets();
    for (QWidget* widget : topLevelWidgets) {
        if (widget == m_window.get()) {
            continue;
        }

        if (auto* dialog = qobject_cast<QDialog*>(widget); dialog != nullptr && dialog->isVisible()) {
            return dialog;
        }
    }

    return nullptr;
}

//----------------------------------------------------------------------------------

QPushButton* Test_CullendulaMainWindow::findButton(char const* name) const { return m_window->findChild<QPushButton*>(name); }

//----------------------------------------------------------------------------------

QLabel* Test_CullendulaMainWindow::findCenterLabel() const { return m_window->findChild<QLabel*>("centerLabel"); }

//----------------------------------------------------------------------------------

QStatusBar* Test_CullendulaMainWindow::findStatusBar() const { return m_window->findChild<QStatusBar*>("statusBar"); }

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::init() {
    m_tempDir = std::make_unique<QTemporaryDir>();
    QVERIFY(m_tempDir->isValid());

    m_window = std::make_unique<TestableCullendulaMainWindow>();
    m_window->resize(640, 480);
    m_window->show();
    QApplication::processEvents();
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::cleanup() {
    m_window.reset();
    m_tempDir.reset();
    QVERIFY(CullendulaAppBootstrap::setApplicationLanguage(CullendulaAppBootstrap::UiLanguage::English));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_InitialState() {
    QVERIFY(m_window->windowTitle().startsWith("Cullendula - v"));
    QVERIFY(!findButton("leftPB")->isEnabled());
    QVERIFY(!findButton("rightPB")->isEnabled());
    QVERIFY(!findButton("savePB")->isEnabled());
    QVERIFY(!findButton("trashPB")->isEnabled());
    QVERIFY(findAction("Undo") != nullptr);
    QVERIFY(findAction("Redo") != nullptr);
    QVERIFY(findAction("About Cullendula") != nullptr);
    QVERIFY(findAction("About Qt") != nullptr);
    QVERIFY(!findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
    QVERIFY(findCenterLabel()->text().contains("no more valid images found"));
    QCOMPARE(findStatusBar()->currentMessage(), QString("no more files"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_VersionMetadata_IsDocumentedConsistently() {
    QFile cmakeFile(QStringLiteral("/home/mpetrick/repos/Cullendula/CMakeLists.txt"));
    QVERIFY(cmakeFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QString const cmakeContents = QString::fromUtf8(cmakeFile.readAll());
    QVERIFY(cmakeContents.contains("VERSION 0.6.30"));

    QFile readmeFile(QStringLiteral("/home/mpetrick/repos/Cullendula/README.md"));
    QVERIFY(readmeFile.open(QIODevice::ReadOnly | QIODevice::Text));
    QString const readmeContents = QString::fromUtf8(readmeFile.readAll());
    QVERIFY(readmeContents.contains("This is version 0.6.30."));
    QVERIFY(readmeContents.contains("* v0.6.30 adds repository-local Cppcheck infrastructure with compilation-database input"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_LightTheme_IsDefault() {
    QAction* lightThemeAction = findThemeAction("light");
    QAction* darkThemeAction = findThemeAction("dark");
    QAction* purpleThemeAction = findThemeAction("purple");

    QVERIFY(lightThemeAction != nullptr);
    QVERIFY(darkThemeAction != nullptr);
    QVERIFY(purpleThemeAction != nullptr);
    QVERIFY(lightThemeAction->isCheckable());
    QVERIFY(darkThemeAction->isCheckable());
    QVERIFY(purpleThemeAction->isCheckable());
    QVERIFY(lightThemeAction->isChecked());
    QVERIFY(!darkThemeAction->isChecked());
    QVERIFY(!purpleThemeAction->isChecked());
    QCOMPARE(m_window->getThemeMode(), CullendulaMainWindow::ThemeMode::Light);
    QVERIFY(qApp->styleSheet().contains("#f6f3ee"));
    QCOMPARE(qApp->palette().color(QPalette::Window), QColor("#f6f3ee"));
    QCOMPARE(qApp->palette().color(QPalette::Button), QColor("#efe2cc"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ThemeMenu_SwitchesToDarkMode() {
    QAction* lightThemeAction = findThemeAction("light");
    QAction* darkThemeAction = findThemeAction("dark");
    QAction* purpleThemeAction = findThemeAction("purple");
    QVERIFY(lightThemeAction != nullptr);
    QVERIFY(darkThemeAction != nullptr);
    QVERIFY(purpleThemeAction != nullptr);

    darkThemeAction->trigger();
    QApplication::processEvents();

    QVERIFY(!lightThemeAction->isChecked());
    QVERIFY(darkThemeAction->isChecked());
    QVERIFY(!purpleThemeAction->isChecked());
    QCOMPARE(m_window->getThemeMode(), CullendulaMainWindow::ThemeMode::Dark);
    QVERIFY(qApp->styleSheet().contains("#0b0f14"));
    QVERIFY(qApp->styleSheet().contains("#79c0ff"));
    QCOMPARE(qApp->palette().color(QPalette::Window), QColor("#0b0f14"));
    QCOMPARE(qApp->palette().color(QPalette::Button), QColor("#16324b"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ThemeMenu_SwitchesBackToLightMode() {
    QAction* lightThemeAction = findThemeAction("light");
    QAction* darkThemeAction = findThemeAction("dark");
    QAction* purpleThemeAction = findThemeAction("purple");
    QVERIFY(lightThemeAction != nullptr);
    QVERIFY(darkThemeAction != nullptr);
    QVERIFY(purpleThemeAction != nullptr);

    darkThemeAction->trigger();
    QApplication::processEvents();
    lightThemeAction->trigger();
    QApplication::processEvents();

    QVERIFY(lightThemeAction->isChecked());
    QVERIFY(!darkThemeAction->isChecked());
    QVERIFY(!purpleThemeAction->isChecked());
    QCOMPARE(m_window->getThemeMode(), CullendulaMainWindow::ThemeMode::Light);
    QCOMPARE(qApp->palette().color(QPalette::Window), QColor("#f6f3ee"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ThemeMenu_SwitchesToPurpleMode() {
    QAction* lightThemeAction = findThemeAction("light");
    QAction* darkThemeAction = findThemeAction("dark");
    QAction* purpleThemeAction = findThemeAction("purple");
    QVERIFY(lightThemeAction != nullptr);
    QVERIFY(darkThemeAction != nullptr);
    QVERIFY(purpleThemeAction != nullptr);

    purpleThemeAction->trigger();
    QApplication::processEvents();

    QVERIFY(!lightThemeAction->isChecked());
    QVERIFY(!darkThemeAction->isChecked());
    QVERIFY(purpleThemeAction->isChecked());
    QCOMPARE(m_window->getThemeMode(), CullendulaMainWindow::ThemeMode::Purple);
    QVERIFY(qApp->styleSheet().contains("#110d1b"));
    QVERIFY(qApp->styleSheet().contains("#63d5f7"));
    QCOMPARE(qApp->palette().color(QPalette::Window), QColor("#110d1b"));
    QCOMPARE(qApp->palette().color(QPalette::Button), QColor("#372454"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_LanguageMenu_ContainsSupportedLanguages() {
    QAction* englishAction = findLanguageAction("en");
    QAction* germanAction = findLanguageAction("de");
    QAction* croatianAction = findLanguageAction("hr");
    QAction* chineseAction = findLanguageAction("zh_CN");

    QVERIFY(englishAction != nullptr);
    QVERIFY(germanAction != nullptr);
    QVERIFY(croatianAction != nullptr);
    QVERIFY(chineseAction != nullptr);
    QVERIFY(englishAction->isCheckable());
    QVERIFY(germanAction->isCheckable());
    QVERIFY(croatianAction->isCheckable());
    QVERIFY(chineseAction->isCheckable());
    QVERIFY(englishAction->isChecked());
    QVERIFY(!germanAction->isChecked());
    QVERIFY(!croatianAction->isChecked());
    QVERIFY(!chineseAction->isChecked());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_LanguageMenu_SwitchesCurrentLanguage() {
    QAction* englishAction = findLanguageAction("en");
    QAction* germanAction = findLanguageAction("de");
    QAction* croatianAction = findLanguageAction("hr");
    QAction* chineseAction = findLanguageAction("zh_CN");
    QVERIFY(englishAction != nullptr);
    QVERIFY(germanAction != nullptr);
    QVERIFY(croatianAction != nullptr);
    QVERIFY(chineseAction != nullptr);

    germanAction->trigger();
    QApplication::processEvents();
    QVERIFY(germanAction->isChecked());
    QVERIFY(!englishAction->isChecked());
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::German);

    croatianAction->trigger();
    QApplication::processEvents();
    QVERIFY(croatianAction->isChecked());
    QVERIFY(!germanAction->isChecked());
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::Croatian);

    chineseAction->trigger();
    QApplication::processEvents();
    QVERIFY(chineseAction->isChecked());
    QVERIFY(!croatianAction->isChecked());
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::Chinese);

    englishAction->trigger();
    QApplication::processEvents();
    QVERIFY(englishAction->isChecked());
    QVERIFY(!chineseAction->isChecked());
    QCOMPARE(CullendulaAppBootstrap::getApplicationLanguage(), CullendulaAppBootstrap::UiLanguage::English);
    QVERIFY(m_window->windowTitle().startsWith("Cullendula - v"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_LanguageMenu_AppliesTranslatedActionTexts() {
    QAction* englishAction = findLanguageAction("en");
    QAction* germanAction = findLanguageAction("de");
    QVERIFY(englishAction != nullptr);
    QVERIFY(germanAction != nullptr);

    QAction const* undoAction = findAction("Undo");
    QVERIFY(undoAction != nullptr);
    QCOMPARE(undoAction->text(), QString("Undo"));

    germanAction->trigger();
    QApplication::processEvents();

    QString const germanUndoText = QString::fromUtf8("RÃ¼ckgÃ¤ngig machen");
    QVERIFY(findAction(germanUndoText) != nullptr);
    QVERIFY(findAction("Undo") == nullptr);

    englishAction->trigger();
    QApplication::processEvents();

    QVERIFY(findAction("Undo") != nullptr);
    QVERIFY(findAction(germanUndoText) == nullptr);
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ExtensionsMenu_DefaultsToAllChecked() {
    QAction* pngAction = findExtensionAction("png");
    QAction* jpgAction = findExtensionAction("jpg");
    QAction* webpAction = findExtensionAction("webp");

    QVERIFY(pngAction != nullptr);
    QVERIFY(jpgAction != nullptr);
    QVERIFY(webpAction != nullptr);
    QVERIFY(pngAction->isCheckable());
    QVERIFY(jpgAction->isCheckable());
    QVERIFY(webpAction->isCheckable());
    QVERIFY(pngAction->isChecked());
    QVERIFY(jpgAction->isChecked());
    QVERIFY(webpAction->isChecked());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ExtensionsMenu_AllUncheckedBlocksNextDrop() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.png", Qt::blue);

    QList<QAction*> const extensionActions = m_window->findChildren<QAction*>(QRegularExpression("^extensionAction_"));
    QVERIFY(!extensionActions.isEmpty());

    for (QAction* action : extensionActions) {
        QVERIFY(action->isChecked());
        action->setChecked(false);
    }

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QVERIFY(!findButton("leftPB")->isEnabled());
    QVERIFY(!findButton("rightPB")->isEnabled());
    QVERIFY(!findButton("savePB")->isEnabled());
    QVERIFY(!findButton("trashPB")->isEnabled());
    QVERIFY(findCenterLabel()->text().contains("no more valid images found"));
    QCOMPARE(findStatusBar()->currentMessage(), QString("no more files"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ResizeWithoutLoadedImages_ShowsFallbackText() {
    m_window->resize(800, 520);
    QApplication::processEvents();

    QVERIFY(findCenterLabel()->text().contains("no more valid images found"));
    QVERIFY(!findButton("savePB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ResizeLoadedImage_ReusesCachedPreview() {
    createImage("alpha.jpg", Qt::red);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QPixmap const beforeResize = findCenterLabel()->pixmap(Qt::ReturnByValue);
    QVERIFY(!beforeResize.isNull());
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));

    m_window->resize(900, 700);
    QApplication::processEvents();

    QPixmap const afterResize = findCenterLabel()->pixmap(Qt::ReturnByValue);
    QVERIFY(!afterResize.isNull());
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_InvalidImagePreview_ShowsFallbackError() {
    createInvalidImageFile("broken.jpg");
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QCOMPARE(findCenterLabel()->text(), QString("could not load the current image preview"));
    QCOMPARE(findStatusBar()->currentMessage(), QString("could not load the current image preview"));
    QVERIFY(!findButton("savePB")->isEnabled());
    QVERIFY(!findButton("trashPB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DragEnter_ValidUrlsAreAccepted() {
    createImage("alpha.jpg", Qt::red);

    QMimeData mimeData;
    mimeData.setUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    static_cast<TestableCullendulaMainWindow*>(m_window.get())->dragEnterEvent(&dragEnterEvent);

    QVERIFY(dragEnterEvent.isAccepted());
    QCOMPARE(findStatusBar()->currentMessage(), QString("drop current load and let's see what you dragged?"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DragEnter_InvalidPayloadIsRejected() {
    QMimeData mimeData;
    mimeData.setText("not a file");

    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    static_cast<TestableCullendulaMainWindow*>(m_window.get())->dragEnterEvent(&dragEnterEvent);

    QVERIFY(!dragEnterEvent.isAccepted());
    QCOMPARE(findStatusBar()->currentMessage(), QString("no more files"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DragEnter_EmptyUrlListIsRejected() {
    QMimeData mimeData;
    mimeData.setUrls({});

    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    static_cast<TestableCullendulaMainWindow*>(m_window.get())->dragEnterEvent(&dragEnterEvent);

    QVERIFY(!dragEnterEvent.isAccepted());
    QCOMPARE(findStatusBar()->currentMessage(), QString("no more files"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DragEnterAndDropValidDirectory_LoadsImages() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QVERIFY(findButton("leftPB")->isEnabled());
    QVERIFY(findButton("rightPB")->isEnabled());
    QVERIFY(findButton("savePB")->isEnabled());
    QVERIFY(findButton("trashPB")->isEnabled());
    QVERIFY(!findCenterLabel()->pixmap(Qt::ReturnByValue).isNull());
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 2"));
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ExtensionsMenu_AffectsNextDroppedDirectory() {
    createImage("dir1/alpha.jpg", Qt::red);
    createImage("dir1/beta.png", Qt::blue);
    createImage("dir2/alpha.jpg", Qt::green);
    createImage("dir2/beta.png", Qt::yellow);

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "dir1")});
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));

    QAction* jpgAction = findExtensionAction("jpg");
    QAction* jpegAction = findExtensionAction("jpeg");
    QAction* pngAction = findExtensionAction("png");
    QVERIFY(jpgAction != nullptr);
    QVERIFY(jpegAction != nullptr);
    QVERIFY(pngAction != nullptr);

    jpgAction->setChecked(false);
    jpegAction->setChecked(false);
    QVERIFY(pngAction->isChecked());

    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "dir2")});
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 1"));
    QVERIFY(findStatusBar()->currentMessage().contains("beta.png"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DroppingEmptyDirectory_ClearsPreviousSessionState() {
    createImage("loaded/alpha.jpg", Qt::red);
    createImage("loaded/beta.jpeg", Qt::blue);
    QDir().mkpath(m_tempDir->path() + QDir::separator() + "empty");

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "loaded")});
    QVERIFY(findButton("savePB")->isEnabled());
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "empty")});
    QVERIFY(!findButton("leftPB")->isEnabled());
    QVERIFY(!findButton("rightPB")->isEnabled());
    QVERIFY(!findButton("savePB")->isEnabled());
    QVERIFY(!findButton("trashPB")->isEnabled());
    QVERIFY(findCenterLabel()->text().contains("no more valid images found"));
    QCOMPARE(findStatusBar()->currentMessage(), QString("no more files"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DroppingDirectoryWithBlockedOutput_ShowsFilesystemError() {
    createImage("loaded/alpha.jpg", Qt::red);

    QFile blockedOutput(m_tempDir->path() + QDir::separator() + "loaded" + QDir::separator() + "output");
    QVERIFY(blockedOutput.open(QIODevice::WriteOnly));
    blockedOutput.write("blocked");
    blockedOutput.close();

    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "loaded")});

    QVERIFY(findStatusBar()->currentMessage().contains("Could not prepare 'output' directory"));
    QVERIFY(findStatusBar()->currentMessage().contains("non-directory"));
    QVERIFY(!findButton("savePB")->isEnabled());
    QVERIFY(findCenterLabel()->text().contains("no more valid images found"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DropInvalidPayload_ShowsErrorStatus() {
    QMimeData mimeData;
    mimeData.setText("not a file");
    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    QDropEvent dropEvent(QPointF(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    auto* window = static_cast<TestableCullendulaMainWindow*>(m_window.get());
    window->dragEnterEvent(&dragEnterEvent);
    window->dropEvent(&dropEvent);
    QApplication::processEvents();

    QCOMPARE(findStatusBar()->currentMessage(), QString("The load was not usable! :("));
    QVERIFY(!findButton("savePB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DropEmptyUrlList_LeavesStateUnchanged() {
    createImage("alpha.jpg", Qt::red);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});
    QString const statusBeforeDrop = findStatusBar()->currentMessage();

    QMimeData mimeData;
    mimeData.setUrls({});

    QDragEnterEvent dragEnterEvent(QPoint(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    QDropEvent dropEvent(QPointF(10, 10), Qt::CopyAction, &mimeData, Qt::LeftButton, Qt::NoModifier);
    auto* window = static_cast<TestableCullendulaMainWindow*>(m_window.get());
    window->dragEnterEvent(&dragEnterEvent);
    window->dropEvent(&dropEvent);
    QApplication::processEvents();

    QVERIFY(dropEvent.isAccepted());
    QCOMPARE(findStatusBar()->currentMessage(), statusBeforeDrop);
    QVERIFY(findButton("savePB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_DropMultipleUrls_UsesFirstEntry() {
    createImage("first/alpha.jpg", Qt::red);
    createImage("second/beta.jpeg", Qt::blue);

    sendDropWithUrls(
        {QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "second"), QUrl::fromLocalFile(m_tempDir->path() + QDir::separator() + "first")});

    QVERIFY(findStatusBar()->currentMessage().contains("beta.jpeg"));
    QVERIFY(!findStatusBar()->currentMessage().contains("alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ButtonNavigationWithoutSession_LeavesUiUnchanged() {
    QString const initialStatus = findStatusBar()->currentMessage();

    QVERIFY(QMetaObject::invokeMethod(m_window.get(), "slotButtonLeftTriggered"));
    QVERIFY(QMetaObject::invokeMethod(m_window.get(), "slotButtonRightTriggered"));
    QApplication::processEvents();

    QCOMPARE(findStatusBar()->currentMessage(), initialStatus);
    QVERIFY(!findButton("leftPB")->isEnabled());
    QVERIFY(!findButton("rightPB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ButtonNavigationAndSaveFlow() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QTest::mouseClick(findButton("rightPB"), Qt::LeftButton);
    QVERIFY(findStatusBar()->currentMessage().contains("beta.jpeg"));

    QTest::mouseClick(findButton("savePB"), Qt::LeftButton);
    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "beta.jpeg"));
    QVERIFY(findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 1"));
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_ButtonTrashFlow() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QTest::mouseClick(findButton("trashPB"), Qt::LeftButton);

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "trash" + QDir::separator() + "alpha.jpg"));
    QVERIFY(findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 1"));
    QVERIFY(findStatusBar()->currentMessage().contains("beta.jpeg"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_UndoRedoActions_MoveFilesOnDisk() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QTest::mouseClick(findButton("savePB"), Qt::LeftButton);
    QString const originalPath = m_tempDir->path() + QDir::separator() + "alpha.jpg";
    QString const movedPath = m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg";

    QVERIFY(QFile::exists(movedPath));
    QVERIFY(findAction("Undo")->isEnabled());

    findAction("Undo")->trigger();
    QApplication::processEvents();
    QVERIFY(QFile::exists(originalPath));
    QVERIFY(!QFile::exists(movedPath));
    QVERIFY(!findAction("Undo")->isEnabled());
    QVERIFY(findAction("Redo")->isEnabled());
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 2"));
    QVERIFY(findStatusBar()->currentMessage().contains("alpha.jpg"));
    QVERIFY(findButton("leftPB")->isEnabled());
    QVERIFY(findButton("rightPB")->isEnabled());
    QVERIFY(findButton("savePB")->isEnabled());
    QVERIFY(findButton("trashPB")->isEnabled());

    findAction("Redo")->trigger();
    QApplication::processEvents();
    QVERIFY(!QFile::exists(originalPath));
    QVERIFY(QFile::exists(movedPath));
    QVERIFY(findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
    QVERIFY(findStatusBar()->currentMessage().contains("showing 1 of 1"));
    QVERIFY(findStatusBar()->currentMessage().contains("beta.jpeg"));
    QVERIFY(findButton("leftPB")->isEnabled());
    QVERIFY(findButton("rightPB")->isEnabled());
    QVERIFY(findButton("savePB")->isEnabled());
    QVERIFY(findButton("trashPB")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_UndoFailure_ShowsStatusMessageAndKeepsRedoUnavailable() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QTest::mouseClick(findButton("savePB"), Qt::LeftButton);
    QString const movedPath = m_tempDir->path() + QDir::separator() + "output" + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(movedPath));
    QVERIFY(QFile::remove(movedPath));

    findAction("Undo")->trigger();
    QApplication::processEvents();

    QVERIFY(findStatusBar()->currentMessage().contains("Could not move 'alpha.jpg' to 'undo'"));
    QVERIFY(findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_RedoFailure_ShowsStatusMessageAndKeepsRedoAvailable() {
    createImage("alpha.jpg", Qt::red);
    createImage("beta.jpeg", Qt::blue);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QTest::mouseClick(findButton("savePB"), Qt::LeftButton);
    findAction("Undo")->trigger();
    QApplication::processEvents();

    QString const restoredPath = m_tempDir->path() + QDir::separator() + "alpha.jpg";
    QVERIFY(QFile::exists(restoredPath));
    QVERIFY(QFile::remove(restoredPath));

    findAction("Redo")->trigger();
    QApplication::processEvents();

    QVERIFY(findStatusBar()->currentMessage().contains("Could not move 'alpha.jpg' to 'redo'"));
    QVERIFY(!findAction("Undo")->isEnabled());
    QVERIFY(findAction("Redo")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_SaveFailure_ShowsStatusMessage() {
    createImage("alpha.jpg", Qt::red);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QString const outputPath = m_tempDir->path() + QDir::separator() + "output";
    QVERIFY(QDir(outputPath).removeRecursively());

    QFile replacement(outputPath);
    QVERIFY(replacement.open(QIODevice::WriteOnly));
    replacement.write("not a directory");
    replacement.close();

    QTest::mouseClick(findButton("savePB"), Qt::LeftButton);

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "alpha.jpg"));
    QVERIFY(findStatusBar()->currentMessage().contains("Could not prepare 'output' directory"));
    QVERIFY(findStatusBar()->currentMessage().contains("non-directory"));
    QVERIFY(!findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_TrashFailure_ShowsStatusMessage() {
    createImage("alpha.jpg", Qt::red);
    sendDropWithUrls({QUrl::fromLocalFile(m_tempDir->path())});

    QString const trashPath = m_tempDir->path() + QDir::separator() + "trash";
    QVERIFY(QDir(trashPath).removeRecursively());

    QFile replacement(trashPath);
    QVERIFY(replacement.open(QIODevice::WriteOnly));
    replacement.write("not a directory");
    replacement.close();

    QTest::mouseClick(findButton("trashPB"), Qt::LeftButton);

    QVERIFY(QFile::exists(m_tempDir->path() + QDir::separator() + "alpha.jpg"));
    QVERIFY(findStatusBar()->currentMessage().contains("Could not prepare 'trash' directory"));
    QVERIFY(findStatusBar()->currentMessage().contains("non-directory"));
    QVERIFY(!findAction("Undo")->isEnabled());
    QVERIFY(!findAction("Redo")->isEnabled());
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_AboutAction_ShowsDialogAndStatus() {
    findThemeAction("purple")->trigger();
    QApplication::processEvents();

    findAction("About Cullendula")->trigger();
    QApplication::processEvents();

    QDialog* dialog = findOpenDialog();
    QVERIFY(dialog != nullptr);
    QVERIFY(qApp->styleSheet().contains("QMessageBox QLabel"));
    QVERIFY(qApp->styleSheet().contains("#110d1b"));
    dialog->accept();
    QApplication::processEvents();

    QCOMPARE(findStatusBar()->currentMessage(), QString("Invoked Help|About"));
}

//----------------------------------------------------------------------------------

void Test_CullendulaMainWindow::slot_Test_AboutQtAction_ShowsDialogAndStatus() {
    findThemeAction("purple")->trigger();
    QApplication::processEvents();

    findAction("About Qt")->trigger();
    QApplication::processEvents();

    QDialog* dialog = findOpenDialog();
    QVERIFY(dialog != nullptr);
    QVERIFY(qApp->styleSheet().contains("QMessageBox QLabel"));
    QVERIFY(qApp->styleSheet().contains("#110d1b"));
    dialog->accept();
    QApplication::processEvents();

    QCOMPARE(findStatusBar()->currentMessage(), QString("Invoked Help|About Qt"));
}
---------- end ----------
-------------------- ./tests/CMakeLists.txt --------------------
#
# Test sources
#
set(TEST_SOURCES
    main.cpp
    Test_CullendulaAppBootstrap.cpp
    Test_CullendulaAppBootstrap.h
    Test_CullendulaFileSystemHandler.cpp
    Test_CullendulaFileSystemHandler.h
    Test_CullendulaMainWindow.cpp
    Test_CullendulaMainWindow.h
    Test_CullendulaUndoStack.cpp
    Test_CullendulaUndoStack.h
)

#
# Test executable
#
add_executable(CullendulaTests ${TEST_SOURCES})

#
# Link against QtTest + the library containing the app code
#
target_link_libraries(CullendulaTests
    Qt6::Core
    Qt6::Gui          # needed because UndoStack uses Qt GUI types
    Qt6::Test
    Qt6::Widgets
    CullendulaLib
)

# Allow tests to include headers from src/.
target_include_directories(CullendulaTests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

#
# Register test with CTest
#
add_test(NAME CullendulaUndoStackTest COMMAND CullendulaTests)

add_test(
    NAME CullendulaMainSmokeTest
    COMMAND ${CMAKE_COMMAND} -E env
        QT_QPA_PLATFORM=offscreen
        CULLENDULA_EXIT_AFTER_STARTUP_MS=0
        $<TARGET_FILE:Cullendula>
)

set_tests_properties(CullendulaMainSmokeTest PROPERTIES TIMEOUT 10)

add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS CullendulaTests
    USES_TERMINAL
)

if(CULLENDULA_ENABLE_COVERAGE)
    find_program(CULLENDULA_GCOV_EXECUTABLE gcov REQUIRED)
    find_program(CULLENDULA_GCOVR_EXECUTABLE gcovr)
    find_program(CULLENDULA_LCOV_EXECUTABLE lcov)
    find_program(CULLENDULA_GENHTML_EXECUTABLE genhtml)

    set(CULLENDULA_COVERAGE_OBJECTS
        "${CMAKE_BINARY_DIR}/src/CMakeFiles/Cullendula.dir/main.cpp.gcno"
        "${CMAKE_BINARY_DIR}/src/CMakeFiles/CullendulaLib.dir/CullendulaAppBootstrap.cpp.gcno"
        "${CMAKE_BINARY_DIR}/src/CMakeFiles/CullendulaLib.dir/CullendulaMainWindow.cpp.gcno"
        "${CMAKE_BINARY_DIR}/src/CMakeFiles/CullendulaLib.dir/CullendulaFileSystemHandler.cpp.gcno"
        "${CMAKE_BINARY_DIR}/src/CMakeFiles/CullendulaLib.dir/CullendulaUndoStack.cpp.gcno"
    )

    set(CULLENDULA_COVERAGE_CONFIG_FILE "${CMAKE_CURRENT_BINARY_DIR}/CoverageConfig.cmake")
    file(GENERATE OUTPUT "${CULLENDULA_COVERAGE_CONFIG_FILE}" CONTENT
"set(COVERAGE_OBJECTS
    [==[${CULLENDULA_COVERAGE_OBJECTS}]==]
)
")

    add_custom_target(coverage
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        COMMAND ${CMAKE_COMMAND}
            -DGCOV_EXECUTABLE=${CULLENDULA_GCOV_EXECUTABLE}
            -DCOVERAGE_OUTPUT_DIR=${CMAKE_BINARY_DIR}/coverage
            -DCOVERAGE_REPORT_FILE=${CMAKE_BINARY_DIR}/coverage/coverage.txt
            -DCOVERAGE_CONFIG_FILE=${CULLENDULA_COVERAGE_CONFIG_FILE}
            -P ${CMAKE_SOURCE_DIR}/cmake/GenerateCoverage.cmake
        DEPENDS Cullendula CullendulaTests
        USES_TERMINAL
    )

    if(CULLENDULA_GCOVR_EXECUTABLE)
        add_custom_target(coverage-html
            COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage/html
            COMMAND ${CULLENDULA_GCOVR_EXECUTABLE}
                --root ${CMAKE_SOURCE_DIR}
                --filter ${CMAKE_SOURCE_DIR}/src
                --html-details ${CMAKE_BINARY_DIR}/coverage/html/index.html
                --gcov-executable ${CULLENDULA_GCOV_EXECUTABLE}
                ${CMAKE_BINARY_DIR}
            DEPENDS Cullendula CullendulaTests
            USES_TERMINAL
        )
    elseif(CULLENDULA_LCOV_EXECUTABLE AND CULLENDULA_GENHTML_EXECUTABLE)
        add_custom_target(coverage-html
            COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
            COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
            COMMAND ${CULLENDULA_LCOV_EXECUTABLE}
                --capture
                --directory ${CMAKE_BINARY_DIR}
                --output-file ${CMAKE_BINARY_DIR}/coverage/coverage.info
            COMMAND ${CULLENDULA_LCOV_EXECUTABLE}
                --extract ${CMAKE_BINARY_DIR}/coverage/coverage.info
                ${CMAKE_SOURCE_DIR}/src/*
                --output-file ${CMAKE_BINARY_DIR}/coverage/coverage.filtered.info
            COMMAND ${CULLENDULA_GENHTML_EXECUTABLE}
                ${CMAKE_BINARY_DIR}/coverage/coverage.filtered.info
                --output-directory ${CMAKE_BINARY_DIR}/coverage/html
            DEPENDS Cullendula CullendulaTests
            USES_TERMINAL
        )
    else()
        message(STATUS "coverage-html target disabled: install gcovr or lcov+genhtml to enable HTML coverage output")
    endif()
endif()
---------- end ----------
-------------------- ./tests/Test_CullendulaUndoStack.h --------------------
//----------------------------------------------------------------------------------
// description: Cullendula - small GUI-app to pick the best shots from a session
// author: mail@marcelpetrick.it
// repo: https://github.com/marcelpetrick/Cullendula
//----------------------------------------------------------------------------------

#pragma once

// own includes
#include "CullendulaUndoStack.h"

// Qt includes
#include <QtTest/QtTest>

// std includes
#include <memory>

/*!
 * @file
 * @brief QTest suite for the undo/redo stack primitives.
 */

/*!
 * @brief Validates history push, undo, redo, and state bookkeeping.
 */
class Test_CullendulaUndoStack : public QObject {
    Q_OBJECT

   private Q_SLOTS:
    //! Allocate long-lived test fixtures before the first test runs.
    static void initTestCase();

    //! Release long-lived test fixtures after the final test.
    static void cleanupTestCase();

    //! Reset state before each individual test.
    void init();

    //! Tear down per-test state after each test.
    void cleanup();

    //! Verify default construction of the undo stack.
    void slot_Test_Create_CullendulaUndoStack();

    //! Verify that push adds items to the undo history.
    void slot_Test_Push();

    //! Verify that undo returns the expected item and updates stack state.
    void slot_Test_Undo();

    //! Verify redo after a preceding undo.
    void slot_Test_Redo();

    //! Verify alternating undo and redo operations over multiple items.
    void slot_Test_UndoRedoLoop();

    //! Verify undo on an empty stack leaves all state untouched.
    void slot_Test_Undo_OnEmptyStack_PreservesEmptyState();

    //! Verify redo on an empty stack leaves all state untouched.
    void slot_Test_Redo_OnEmptyStack_PreservesEmptyState();

    //! Verify a fresh push clears redo history after partial undo.
    void slot_Test_Push_AfterUndo_ClearsRedoHistory();

   private:
    /*!
     * @brief Compare an undo item against its expected source and target paths.
     * @param item Item returned by the stack.
     * @param expectedSource Expected source path.
     * @param expectedTarget Expected target path.
     */
    static void verifyUndoItem(CullendulaUndoItem const& item, QString const& expectedSource, QString const& expectedTarget);

    //! Stack instance under test.
    std::unique_ptr<CullendulaUndoStack> m_stackPtr = nullptr;
};
---------- end ----------
-------------------- ./scripts/run_cppcheck.sh --------------------
#!/usr/bin/env bash

set -u
set -o pipefail

readonly SCRIPT_NAME="$(basename "$0")"
readonly PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
readonly DEFAULT_BUILD_DIR="${PROJECT_ROOT}/build"
readonly DEFAULT_REPORT_DIR="${PROJECT_ROOT}/reports/cppcheck"

BUILD_DIR="${DEFAULT_BUILD_DIR}"
REPORT_DIR="${DEFAULT_REPORT_DIR}"
VERBOSE=0

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [--build-dir PATH] [--report-dir PATH] [--verbose] [--help]

Run Cppcheck against the project's compilation database and generate reports.

Outputs:
  - XML report:  <report-dir>/cppcheck.xml
  - HTML report: <report-dir>/html/index.html (when cppcheck-htmlreport is available)
EOF
}

log() {
    printf '[INFO] %s\n' "$*"
}

warn() {
    printf '[WARN] %s\n' "$*" >&2
}

error() {
    printf '[ERROR] %s\n' "$*" >&2
}

run_command() {
    if [[ "${VERBOSE}" -eq 1 ]]; then
        "$@"
    else
        "$@" >/dev/null
    fi
}

parse_arguments() {
    while [[ "$#" -gt 0 ]]; do
        case "$1" in
            --build-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --build-dir."
                    exit 2
                fi
                BUILD_DIR="$1"
                ;;
            --report-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --report-dir."
                    exit 2
                fi
                REPORT_DIR="$1"
                ;;
            --verbose)
                VERBOSE=1
                ;;
            --help|-h)
                print_usage
                exit 0
                ;;
            *)
                error "Unknown argument: $1"
                print_usage
                exit 2
                ;;
        esac
        shift
    done
}

require_command() {
    local command_name="$1"
    if ! command -v "${command_name}" >/dev/null 2>&1; then
        error "Required command '${command_name}' was not found in PATH."
        exit 1
    fi
}

extract_finding_count() {
    local xml_file="$1"
    python3 - "${xml_file}" <<'PY'
import sys
import xml.etree.ElementTree as ET

xml_path = sys.argv[1]
root = ET.parse(xml_path).getroot()
errors = root.find("errors")
print(0 if errors is None else len(errors.findall("error")))
PY
}

main() {
    parse_arguments "$@"

    require_command cppcheck
    require_command python3

    local compile_commands_file="${BUILD_DIR}/compile_commands.json"
    local xml_report="${REPORT_DIR}/cppcheck.xml"
    local html_report_dir="${REPORT_DIR}/html"
    local cppcheck_build_dir="${REPORT_DIR}/build"

    if [[ ! -f "${compile_commands_file}" ]]; then
        error "Compilation database not found: ${compile_commands_file}"
        error "Configure the project first so CMake generates compile_commands.json."
        exit 1
    fi

    mkdir -p "${REPORT_DIR}" "${cppcheck_build_dir}" || {
        error "Could not create report directory: ${REPORT_DIR}"
        exit 1
    }

    rm -f "${xml_report}"

    log "Running Cppcheck using ${compile_commands_file}"
    if ! run_command cppcheck \
        --project="${compile_commands_file}" \
        --enable=warning,style,performance,portability \
        --xml \
        --xml-version=2 \
        --output-file="${xml_report}" \
        --inline-suppr \
        --library=qt \
        --cppcheck-build-dir="${cppcheck_build_dir}" \
        --file-filter="${PROJECT_ROOT}/src/*" \
        --file-filter="${PROJECT_ROOT}/tests/*" \
        -i "${PROJECT_ROOT}/build" \
        -i "${PROJECT_ROOT}/build-coverage" \
        -i "${PROJECT_ROOT}/.localPipeline" \
        -i "${PROJECT_ROOT}/reports"; then
        error "Cppcheck execution failed."
        exit 1
    fi

    if [[ ! -s "${xml_report}" ]]; then
        error "Cppcheck did not produce a non-empty XML report: ${xml_report}"
        exit 1
    fi

    local finding_count
    finding_count="$(extract_finding_count "${xml_report}")" || {
        error "Could not parse the Cppcheck XML report."
        exit 1
    }

    log "Cppcheck XML report: ${xml_report}"
    log "Cppcheck findings: ${finding_count}"

    if command -v cppcheck-htmlreport >/dev/null 2>&1; then
        mkdir -p "${html_report_dir}" || {
            error "Could not create HTML report directory: ${html_report_dir}"
            exit 1
        }

        log "Generating Cppcheck HTML report."
        if ! run_command cppcheck-htmlreport \
            --file="${xml_report}" \
            --report-dir="${html_report_dir}" \
            --source-dir="${PROJECT_ROOT}"; then
            error "Cppcheck HTML report generation failed."
            exit 1
        fi

        if [[ ! -f "${html_report_dir}/index.html" ]]; then
            error "Cppcheck HTML report entry point was not created: ${html_report_dir}/index.html"
            exit 1
        fi

        log "Cppcheck HTML report: ${html_report_dir}/index.html"
    else
        warn "cppcheck-htmlreport is not available; skipping HTML report generation."
    fi
}

main "$@"
---------- end ----------
-------------------- ./CMakeLists.txt --------------------
cmake_minimum_required(VERSION 3.28)

# Silence Qt Creator MaintenanceTool provider message (must be set early)
set(QT_CREATOR_SKIP_MAINTENANCE_TOOL_PROVIDER ON)

project(Cullendula
    VERSION 0.6.30
    LANGUAGES CXX
)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt auto-processing for MOC/UIC/RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Allow configuring without tests if desired (useful for IDE/GUIs)
option(CULLENDULA_BUILD_TESTS "Build tests" ON)
option(CULLENDULA_ENABLE_COVERAGE "Enable gcov coverage instrumentation" OFF)

if(CULLENDULA_ENABLE_COVERAGE AND NOT CULLENDULA_BUILD_TESTS)
    message(FATAL_ERROR "CULLENDULA_ENABLE_COVERAGE requires CULLENDULA_BUILD_TESTS=ON")
endif()

if(CULLENDULA_ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-O0 -g --coverage)
        add_link_options(--coverage)
    else()
        message(FATAL_ERROR "Coverage is only supported with GCC or Clang compatible coverage flags")
    endif()
endif()

# Find Qt 6.10
find_package(Qt6 6.10 REQUIRED COMPONENTS
    Core
    Gui
    LinguistTools
    Widgets
)

if(CULLENDULA_BUILD_TESTS)
    find_package(Qt6 6.10 REQUIRED COMPONENTS Test)
endif()

find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(CULLENDULA_DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/doxygen")
    set(CULLENDULA_DOXYGEN_CONFIG_FILE "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")

    configure_file(
        "${CMAKE_SOURCE_DIR}/Doxyfile.in"
        "${CULLENDULA_DOXYGEN_CONFIG_FILE}"
        @ONLY
    )

    add_custom_target(doxygen
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CULLENDULA_DOXYGEN_OUTPUT_DIRECTORY}"
        COMMAND ${DOXYGEN_EXECUTABLE} "${CULLENDULA_DOXYGEN_CONFIG_FILE}"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        COMMENT "Generating HTML API documentation with Doxygen"
        VERBATIM
    )
else()
    message(STATUS "Doxygen not found: the 'doxygen' target will be unavailable")
endif()

# Build the application code
add_subdirectory(src)

# Enable testing
if(CULLENDULA_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

set(CULLENDULA_TRANSLATION_TS_FILES
    "${CMAKE_SOURCE_DIR}/translations/Cullendula_de.ts"
    "${CMAKE_SOURCE_DIR}/translations/Cullendula_hr.ts"
    "${CMAKE_SOURCE_DIR}/translations/Cullendula_zh_CN.ts"
)

set(CULLENDULA_TRANSLATION_TARGETS Cullendula)
if(CULLENDULA_BUILD_TESTS)
    list(APPEND CULLENDULA_TRANSLATION_TARGETS CullendulaTests)
endif()

qt_add_translations(
    TARGETS ${CULLENDULA_TRANSLATION_TARGETS}
    SOURCE_TARGETS CullendulaLib Cullendula
    TS_FILES ${CULLENDULA_TRANSLATION_TS_FILES}
    RESOURCE_PREFIX "/i18n"
)
---------- end ----------
-------------------- ./worst_findings.md --------------------
# Worst Findings

This list is ordered by engineering risk, with emphasis on user-data safety, correctness, test signal, and maintainability.

## 1. Loading a new path destroys the current session before the new path is validated

- References: `src/CullendulaFileSystemHandler.cpp:106`, `src/CullendulaFileSystemHandler.cpp:122`, `src/CullendulaFileSystemHandler.cpp:282`, `src/CullendulaMainWindow.cpp:245`
- Problem: `setWorkingPath()` resets the current image list, selection, undo stack, and last error before the newly dropped path has been proven valid. A bad drop or unusable folder therefore discards the existing session first and only reports failure afterwards.
- Impact: a user can lose undo history and the active review session because of one invalid drag-and-drop input. Senior engineering instinct is to stage the new state and only commit it after validation succeeds.

## 2. The pipeline is not a pure verification step; it rewrites source files and still exits successfully

- References: `localPipeline.sh:448`, `localPipeline.sh:475`, `localPipeline.sh:493`, `localPipeline.sh:678`, `localPipeline.sh:691`
- Problem: the pipeline runs `clang-format -i`, which mutates tracked files during validation, and it reports `WARN` rather than failure when formatting drift is found. The final exit condition checks only whether the formatting step ran, not whether it changed files.
- Impact: CI-style tooling that rewrites the repository and still returns success is a bad contract. It hides drift, makes runs non-reproducible, and creates exactly the kind of â€œpipeline passed but the worktree changedâ€ confusion that should never survive senior review.

## 3. Drag-and-drop path handling is brittle and manually platform-specific

- References: `src/CullendulaMainWindow.cpp:246`, `src/CullendulaFileSystemHandler.cpp:290`
- Problem: the drop path is taken from `QUrl::path()` and then manually massaged with `#ifdef __linux__` plus `remove(0, 1)` for other platforms. That is not the robust Qt way to handle local file URLs.
- Impact: this is fragile around Windows drive letters, UNC paths, encoded characters, and other platform-specific path shapes. Correct path handling should use `QUrl::toLocalFile()` and avoid ad hoc string surgery in core filesystem code.

## 4. A missing current file leaves the main window in an inconsistent UI state

- References: `src/CullendulaMainWindow.cpp:389`, `src/CullendulaMainWindow.cpp:420`
- Problem: when `refreshLabel()` sees a non-empty path that no longer exists on disk, it only clears the cached pixmap and logs a debug message. It does not update the label text, disable buttons, or show a status-bar error.
- Impact: the user can be left with stale controls that still look actionable even though the current file is gone. That is a correctness and UX boundary issue in a file-management application.

## 5. Test registration is monolithic, so CTest signal and parallelism are much weaker than they look

- References: `tests/CMakeLists.txt:41`, `tests/main.cpp:22`
- Problem: the entire test program is registered as one CTest case, and all suites are multiplexed manually through a custom `main.cpp`. CTest therefore sees only one coarse-grained test, even though the pipeline asks it to run with parallel workers.
- Impact: failure isolation is poor, reporting is coarse, retries are inefficient, and real test parallelism is unavailable. A senior engineer would usually split suites into separate CTest test cases or executables so the tooling can do its job.

## 6. Release/version information is duplicated across several manual edit surfaces

- References: `CMakeLists.txt:7`, `src/CullendulaMainWindow.cpp:34`, `tests/Test_CullendulaMainWindow.cpp:160`, `README.md:166`
- Problem: every release requires synchronized manual edits in build metadata, UI strings, tests, and documentation. There is no single source of truth for the version.
- Impact: this creates unnecessary release churn and an avoidable inconsistency risk. Senior engineers usually centralize version metadata and generate or consume it everywhere else.

## 7. The production bootstrap forces `QT_QPA_PLATFORM=offscreen` when the environment is empty

- References: `src/main.cpp:16`, `src/CullendulaAppBootstrap.cpp:15`
- Problem: the same helper used for tests is also used by the production executable, and it silently forces the app into offscreen mode whenever the environment variable is unset.
- Impact: that can mask real platform/plugin configuration issues and may produce an application that â€œrunsâ€ but is not actually visible to the user. Test-only environment shaping should not bleed into production startup without a clear opt-in.

## 8. The bootstrap tests mutate process-global environment state and do not restore it

- References: `tests/Test_CullendulaAppBootstrap.cpp:14`, `tests/Test_CullendulaAppBootstrap.cpp:24`
- Problem: the tests directly call `qunsetenv()` and `qputenv()` on `QT_QPA_PLATFORM` but never restore the previous value.
- Impact: this makes the test process order-dependent and contaminates later suites with hidden global state. That is the kind of subtle test pollution that keeps a suite â€œgreen until it isnâ€™tâ€.

## 9. The project still treats branch coverage as informational despite it being the obvious weak spot

- References: `localPipeline.sh:384`, `localPipeline.sh:633`, `README.md:162`
- Problem: the pipeline gates only total line coverage, while branch coverage remains around the 50% range and is not enforced at all. The tooling prints branch data, but the project process effectively ignores it.
- Impact: the current quality signal overstates how thoroughly control-flow and failure paths are exercised. For this codebase, the remaining engineering risk is much more concentrated in branches than in raw line execution.

## 10. The codebase still leans heavily on ad hoc debug logging and TODO comments instead of structured error handling

- References: `src/CullendulaFileSystemHandler.cpp:184`, `src/CullendulaFileSystemHandler.cpp:196`, `src/CullendulaFileSystemHandler.cpp:410`, `src/CullendulaMainWindow.cpp:13`
- Problem: core logic still contains TODO-style comments around return-value handling, many `qDebug()` diagnostics, and no clear policy for logging versus user-facing error propagation.
- Impact: this makes operational behavior harder to reason about and leaves important failure semantics implicit in comments instead of enforced in code. It is the kind of engineering looseness that compounds over time.
---------- end ----------
-------------------- ./translations/Cullendula_zh_CN.ts --------------------
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>CullendulaFileSystemHandler</name>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="53"/>
        <source>Could not move &apos;%1&apos; to &apos;%2&apos;: %3</source>
        <extracomment>Error message after moving a file into a named subdirectory such as &quot;output&quot;, &quot;trash&quot;, &quot;undo&quot;, or &quot;redo&quot; failed.</extracomment>
        <translation>æ— æ³•å°†â€œ%1â€ç§»åŠ¨åˆ°â€œ%2â€ï¼š%3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="58"/>
        <source>Could not prepare &apos;%1&apos; directory at &apos;%2&apos;: %3</source>
        <extracomment>Error message after preparing an application-managed subdirectory such as &quot;output&quot; or &quot;trash&quot; failed.</extracomment>
        <translation>æ— æ³•åœ¨â€œ%2â€å¤„å‡†å¤‡â€œ%1â€ç›®å½•ï¼š%3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="206"/>
        <source>showing %1 of %2</source>
        <extracomment>Status bar message showing the current 1-based image position and the total number of loaded images.</extracomment>
        <translation>æ˜¾ç¤º %1ï¼ˆå…± %2ï¼‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="231"/>
        <source>No undo step is currently available.</source>
        <extracomment>Error shown when the user requests Undo but the undo history is empty.</extracomment>
        <translation>å½“å‰æ²¡æœ‰å¯ç”¨çš„æ’¤æ¶ˆæ­¥éª¤ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="248"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="285"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="474"/>
        <source>the filesystem rename operation failed</source>
        <extracomment>Low-level filesystem failure detail inserted into a larger user-visible move error message.</extracomment>
        <translation>æ–‡ä»¶ç³»ç»Ÿé‡å‘½åæ“ä½œå¤±è´¥</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="262"/>
        <source>No redo step is currently available.</source>
        <extracomment>Error shown when the user requests Redo but the redo history is empty.</extracomment>
        <translation>å½“å‰æ²¡æœ‰å¯ç”¨çš„é‡åšæ­¥éª¤ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="346"/>
        <source>The path &apos;%1&apos; could not be resolved to an existing directory.</source>
        <extracomment>Error after a dropped path or selected path does not resolve to an existing directory on disk.</extracomment>
        <translation>æ— æ³•å°†è·¯å¾„â€œ%1â€è§£æä¸ºç°æœ‰ç›®å½•ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="415"/>
        <source>the path is already occupied by a non-directory filesystem entry</source>
        <extracomment>Failure detail for a managed output directory path that already exists as a regular file or another non-directory entry.</extracomment>
        <translation>è¯¥è·¯å¾„å·²è¢«éç›®å½•æ–‡ä»¶ç³»ç»Ÿæ¡ç›®å ç”¨</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="427"/>
        <source>creating the directory failed</source>
        <extracomment>Failure detail for a managed output directory that Qt could not create on disk.</extracomment>
        <translation>åˆ›å»ºç›®å½•å¤±è´¥</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="434"/>
        <source>the directory is still missing after creation</source>
        <extracomment>Failure detail for a managed output directory that still does not exist after a reported creation attempt.</extracomment>
        <translation>åˆ›å»ºåç›®å½•ä»ç„¶ä¸¢å¤±</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="452"/>
        <source>No current image is available to move.</source>
        <extracomment>Error shown when the user tries to save or trash an image but no current image is loaded.</extracomment>
        <translation>å½“å‰æ²¡æœ‰å¯ç§»åŠ¨çš„å›¾åƒã€‚</translation>
    </message>
</context>
<context>
    <name>CullendulaMainWindow</name>
    <message>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <translation type="vanished">Cullendula - æ‚¨æŒ‘é€‰æœ€ä½³é•œå¤´çš„å°å¸®æ‰‹</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;å¦‚æœåŠ è½½äº†ä¸€å¼ ç…§ç‰‡ï¼ˆå›¾åƒæ–‡ä»¶ï¼‰ï¼Œæ­¤æ ‡ç­¾å°†æ˜¾ç¤ºå½“å‰ç…§ç‰‡ï¼ˆå›¾åƒæ–‡ä»¶ï¼‰ã€‚&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;è¯·å°†ç›®å½•æˆ–æ–‡ä»¶æ‹–æ”¾åˆ°æ­¤åŒºåŸŸã€‚&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <translation type="vanished">æ‹–æ”¾æ–‡ä»¶å¤¹æˆ–æ–‡ä»¶å³å¯å¼€å§‹:)
 ï¼ˆä»ä¸» -&gt; æ‰©å±•åŠ è½½å¯ç”¨çš„æ‰©å±•ï¼Œä¾‹å¦‚ *.jpgã€*.jpegã€*.pngã€*.webpï¼‰</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;åˆ‡æ¢åˆ°å·¦é‚»å±…ï¼ˆåŸºäºå½“å‰ç›®å½•çš„æ–‡ä»¶åˆ—è¡¨ï¼‰ã€‚&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå·¦â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†</source>
        <translation type="vanished">â†</translation>
    </message>
    <message>
        <source>Left</source>
        <translation type="vanished">å·¦è¾¹</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;å°†å½“å‰å›¾ç‰‡ç§»åŠ¨åˆ°æŒ‡å®šçš„è¾“å‡ºå­ç›®å½•ä¸­ã€‚ å°†è‡ªåŠ¨åˆ‡æ¢åˆ°ä¸‹ä¸€å¼ ç…§ç‰‡&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå‘ä¸Šâ€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>save â†‘</source>
        <translation type="vanished">ä¿å­˜â†‘</translation>
    </message>
    <message>
        <source>Up</source>
        <translation type="vanished">å‘ä¸Š</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;å°†å½“å‰å›¾ç‰‡ç§»åŠ¨åˆ°æŒ‡å®šçš„åƒåœ¾å­ç›®å½•ä¸­ã€‚ å°†è‡ªåŠ¨åˆ‡æ¢åˆ°ä¸‹ä¸€å¼ ç…§ç‰‡&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå‘ä¸‹â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>trash â†“</source>
        <translation type="vanished">åƒåœ¾â†“</translation>
    </message>
    <message>
        <source>Down</source>
        <translation type="vanished">å‘ä¸‹</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;åˆ‡æ¢åˆ°å³é‚»å±…ï¼ˆåŸºäºå½“å‰ç›®å½•çš„æ–‡ä»¶åˆ—è¡¨ï¼‰ã€‚&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå³â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†’ </source>
        <translation type="vanished">â†’</translation>
    </message>
    <message>
        <source>Right</source>
        <translation type="vanished">æ­£ç¡®çš„</translation>
    </message>
    <message>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <translation type="vanished">è¿™æ˜¯çŠ¶æ€æ ã€‚ å®ƒå°†æ˜¾ç¤ºä»»ä½•ç±»å‹çš„ä¿¡æ¯ï¼Œå¦‚å½“å‰ä½ç½®ã€æ•…éšœæ¶ˆæ¯ç­‰ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="202"/>
        <source>system is up and running :)</source>
        <extracomment>Status bar message shown once after the main window is fully initialized.</extracomment>
        <translation>ç³»ç»Ÿå·²å¯åŠ¨å¹¶è¿è¡Œ:)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="231"/>
        <source>drop current load and let&apos;s see what you dragged?</source>
        <extracomment>Status bar prompt during drag-and-drop after the payload was recognized as file-system URLs.</extracomment>
        <translation>æ”¾ä¸‹å½“å‰è´Ÿè½½ï¼Œè®©æˆ‘ä»¬çœ‹çœ‹æ‚¨æ‹–åŠ¨äº†ä»€ä¹ˆï¼Ÿ</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="271"/>
        <source>The load was not usable! :(</source>
        <extracomment>Status bar error after a drop payload was rejected because it did not contain usable local file URLs.</extracomment>
        <translation>è´Ÿè½½æ— æ³•ä½¿ç”¨ï¼ :(</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="326"/>
        <source>Could not save the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;output&quot; folder failed without a more specific message.</extracomment>
        <translation>æ— æ³•ä¿å­˜å½“å‰æ–‡ä»¶ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="345"/>
        <source>Could not trash the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;trash&quot; folder failed without a more specific message.</extracomment>
        <translation>æ— æ³•åˆ é™¤å½“å‰æ–‡ä»¶ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="417"/>
        <source>no more valid images found: work maybe finished? :)
drag&amp;drop the next folder or files if you want!</source>
        <extracomment>Center label placeholder when no further images match the current extension filter in the active directory.</extracomment>
        <translation>æ‰¾ä¸åˆ°æ›´å¤šæœ‰æ•ˆå›¾åƒï¼šå·¥ä½œå¯èƒ½å®Œæˆäº†å—ï¼Ÿ :)
 å¦‚æœéœ€è¦ï¼Œå¯ä»¥æ‹–æ”¾ä¸‹ä¸€ä¸ªæ–‡ä»¶å¤¹æˆ–æ–‡ä»¶ï¼</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="423"/>
        <source>no more files</source>
        <extracomment>Status bar message when the current directory no longer contains any matching images to show.</extracomment>
        <translation>æ²¡æœ‰æ›´å¤šæ–‡ä»¶</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="430"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="432"/>
        <source>could not load the current image preview</source>
        <extracomment>Error shown both in the center label and the status bar when Qt cannot render the current image preview.</extracomment>
        <translation>æ— æ³•åŠ è½½å½“å‰å›¾åƒé¢„è§ˆ</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="478"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="640"/>
        <source>Enable loading of *.%1 files when opening the next directory</source>
        <extracomment>Tooltip for a checkable menu entry that enables a filename extension such as jpg, png, or webp for future directory scans.</extracomment>
        <translation>æ‰“å¼€ä¸‹ä¸€ä¸ªç›®å½•æ—¶å¯ç”¨ *.%1 æ–‡ä»¶çš„åŠ è½½</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="484"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="646"/>
        <source>Light</source>
        <extracomment>Menu label for the light visual theme.</extracomment>
        <translation>å…‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="488"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="648"/>
        <source>Use the light application theme</source>
        <extracomment>Tooltip for switching the whole application to the light theme.</extracomment>
        <translation>ä½¿ç”¨è½»åº”ç”¨ä¸»é¢˜</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="492"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="653"/>
        <source>Dark</source>
        <extracomment>Menu label for the dark visual theme.</extracomment>
        <translation>é»‘æš—çš„</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="496"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="655"/>
        <source>Use the high-contrast dark application theme</source>
        <extracomment>Tooltip for switching the whole application to the dark theme.</extracomment>
        <translation>ä½¿ç”¨é«˜å¯¹æ¯”åº¦æ·±è‰²åº”ç”¨ç¨‹åºä¸»é¢˜</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="503"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="660"/>
        <source>English</source>
        <extracomment>Language menu entry naming the English user-interface language.</extracomment>
        <translation>è‹±è¯­</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="510"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="667"/>
        <source>Deutsch</source>
        <extracomment>Language menu entry naming the German user-interface language in German.</extracomment>
        <translation>å¾·è¯­</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="517"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="674"/>
        <source>Hrvatski</source>
        <extracomment>Language menu entry naming the Croatian user-interface language in Croatian.</extracomment>
        <translation>èµ«å°”ç“¦èŒ¨åŸº</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="524"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="681"/>
        <source>ä¸­æ–‡</source>
        <extracomment>Language menu entry naming the Chinese user-interface language in Chinese.</extracomment>
        <translation>ä¸­æ–‡</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="532"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="693"/>
        <source>Undo</source>
        <extracomment>Edit menu action label that reverses the most recent file move.</extracomment>
        <translation>æ’¤æ¶ˆ</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="534"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="695"/>
        <source>Revert the last file-move-operation</source>
        <extracomment>Tooltip for the Undo action that moves the previously moved image back to its original location.</extracomment>
        <translation>æ¢å¤ä¸Šæ¬¡æ–‡ä»¶ç§»åŠ¨æ“ä½œ</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="543"/>
        <source>Could not undo the last file move.</source>
        <extracomment>Fallback status bar error after an undo request failed without a more specific message.</extracomment>
        <translation>æ— æ³•æ’¤æ¶ˆä¸Šæ¬¡æ–‡ä»¶ç§»åŠ¨ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="549"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="700"/>
        <source>Redo</source>
        <extracomment>Edit menu action label that reapplies the most recently undone file move.</extracomment>
        <translation>é‡åš</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="551"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="702"/>
        <source>Redo the last file-move-operation (means: undo undo)</source>
        <extracomment>Tooltip for the Redo action. &quot;undo undo&quot; here means reapplied after an Undo.</extracomment>
        <translation>é‡åšä¸Šæ¬¡æ–‡ä»¶ç§»åŠ¨æ“ä½œï¼ˆæ„å‘³ç€ï¼šæ’¤æ¶ˆæ’¤æ¶ˆï¼‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="560"/>
        <source>Could not redo the last file move.</source>
        <extracomment>Fallback status bar error after a redo request failed without a more specific message.</extracomment>
        <translation>æ— æ³•é‡åšä¸Šæ¬¡æ–‡ä»¶ç§»åŠ¨ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="567"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="712"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="803"/>
        <source>About Cullendula</source>
        <extracomment>Help menu action label that opens the application&apos;s About dialog.
----------
Title of the application&apos;s About dialog.</extracomment>
        <translation>å…³äºå¡ä¼¦æœæ‹‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="569"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="714"/>
        <source>Show the application&apos;s About box</source>
        <extracomment>Tooltip for opening the application&apos;s About dialog.</extracomment>
        <translation>æ˜¾ç¤ºåº”ç”¨ç¨‹åºçš„â€œå…³äºâ€æ¡†</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="574"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="719"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>About Qt</source>
        <extracomment>Help menu action label that opens Qt&apos;s built-in About dialog.
----------
Title of the Qt runtime information dialog. Rich-text body of the Qt runtime information dialog. %1 is the Qt version, %2 is the Qt installation prefix path.</extracomment>
        <translation>å…³äºQt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="576"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="721"/>
        <source>Show the Qt library&apos;s About box</source>
        <extracomment>Tooltip for opening Qt&apos;s built-in About dialog.</extracomment>
        <translation>æ˜¾ç¤º Qt åº“çš„â€œå…³äºâ€æ¡†</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="614"/>
        <source>Cullendula</source>
        <extracomment>Main window title; the version suffix is appended separately in code.</extracomment>
        <translation>åº“ä¼¦æœæ‹‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="618"/>
        <source>Main</source>
        <extracomment>Top-level menu containing application settings such as extensions, style, and language.</extracomment>
        <translation>ä¸»è¦çš„</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="623"/>
        <source>Extensions</source>
        <extracomment>Submenu listing the enabled image filename extensions for directory scanning.</extracomment>
        <translation>æ‰©å±•</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="628"/>
        <source>Style</source>
        <extracomment>Submenu for switching between visual themes.</extracomment>
        <translation>é£æ ¼</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="633"/>
        <source>Language</source>
        <extracomment>Submenu for switching the user-interface language.</extracomment>
        <translation>è¯­è¨€</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="662"/>
        <source>Use the default English source texts</source>
        <extracomment>Tooltip for switching back to the original English source texts.</extracomment>
        <translation>ä½¿ç”¨é»˜è®¤çš„è‹±æ–‡æºæ–‡æœ¬</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="669"/>
        <source>Load the German user-interface translation</source>
        <extracomment>Tooltip for loading the German translation file.</extracomment>
        <translation>åŠ è½½å¾·è¯­ç”¨æˆ·ç•Œé¢ç¿»è¯‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="676"/>
        <source>Load the Croatian user-interface translation</source>
        <extracomment>Tooltip for loading the Croatian translation file.</extracomment>
        <translation>åŠ è½½å…‹ç½—åœ°äºšè¯­ç”¨æˆ·ç•Œé¢ç¿»è¯‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="683"/>
        <source>Load the Chinese user-interface translation</source>
        <extracomment>Tooltip for loading the Simplified Chinese translation file.</extracomment>
        <translation>åŠ è½½ä¸­æ–‡ç”¨æˆ·ç•Œé¢ç¿»è¯‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="688"/>
        <source>Edit</source>
        <extracomment>Top-level menu for undo and redo actions.</extracomment>
        <translation>ç¼–è¾‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="707"/>
        <source>Help</source>
        <extracomment>Top-level menu for About dialogs and other help-related actions.</extracomment>
        <translation>å¸®åŠ©</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="743"/>
        <source>Could not load the selected language.</source>
        <extracomment>Status bar error when loading the requested translation catalog failed.</extracomment>
        <translation>æ— æ³•åŠ è½½æ‰€é€‰è¯­è¨€ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="801"/>
        <source>Invoked Help|About</source>
        <extracomment>Status bar trace shown when the user opens the application&apos;s About dialog from the Help menu.</extracomment>
        <translation>è°ƒç”¨å¸®åŠ©|å…³äº</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="805"/>
        <source>Helper program to sort out (&quot;cull&quot;) a collection of pictures in a directory after a nice photo-walk or event.&lt;br&gt;Should work cross-platform.&lt;br&gt;&lt;br&gt;Developed by &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;Source code can be found inside the repository at &lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;Feel free to use and share: GPL v3 :3</source>
        <extracomment>Rich-text body of the application&apos;s About dialog.</extracomment>
        <translation>å¸®åŠ©ç¨‹åºï¼Œç”¨äºåœ¨ä¸€æ¬¡ç²¾å½©çš„æ‹ç…§æ•£æ­¥æˆ–æ´»åŠ¨åæ•´ç†ï¼ˆâ€œå‰”é™¤â€ï¼‰ç›®å½•ä¸­çš„ä¸€ç»„å›¾ç‰‡ã€‚&lt;br&gt;åº”è¯¥è·¨å¹³å°å·¥ä½œã€‚&lt;br&gt;&lt;br&gt;ç”± &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;å¯ä»¥åœ¨å­˜å‚¨åº“ä¸­æ‰¾åˆ°æºä»£ç ï¼š&lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;éšæ„ä½¿ç”¨å’Œåˆ†äº«ï¼šGPL v3 :3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="818"/>
        <source>Invoked Help|About Qt</source>
        <extracomment>Status bar trace shown when the user opens Qt&apos;s About dialog from the Help menu.</extracomment>
        <translation>è°ƒç”¨å¸®åŠ©|å…³äºQt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>This application currently runs with Qt %1.&lt;br&gt;Qt installation prefix: %2&lt;br&gt;&lt;br&gt;Qt is a cross-platform application framework for building desktop and embedded applications.</source>
        <translation>æ­¤åº”ç”¨ç¨‹åºå½“å‰ä½¿ç”¨ Qt %1 è¿è¡Œã€‚&lt;br&gt;Qt å®‰è£…å‰ç¼€ï¼š%2&lt;br&gt;&lt;br&gt;Qt æ˜¯ç”¨äºæ„å»ºæ¡Œé¢å’ŒåµŒå…¥å¼åº”ç”¨ç¨‹åºçš„è·¨å¹³å°åº”ç”¨ç¨‹åºæ¡†æ¶ã€‚</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="23"/>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <comment>Main window title shown before the runtime version suffix is applied from C++ code.</comment>
        <translation>Cullendula - æ‚¨æŒ‘é€‰æœ€ä½³é•œå¤´çš„å°å¸®æ‰‹</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="55"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the large central preview area. It accepts a dropped image file or a directory containing images.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;å¦‚æœåŠ è½½äº†ä¸€å¼ ç…§ç‰‡ï¼ˆå›¾åƒæ–‡ä»¶ï¼‰ï¼Œæ­¤æ ‡ç­¾å°†æ˜¾ç¤ºå½“å‰ç…§ç‰‡ï¼ˆå›¾åƒæ–‡ä»¶ï¼‰ã€‚&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;è¯·å°†ç›®å½•æˆ–æ–‡ä»¶æ‹–æ”¾åˆ°æ­¤åŒºåŸŸã€‚&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="64"/>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <comment>Placeholder text in the central preview area before any image is loaded.</comment>
        <translation>æ‹–æ”¾æ–‡ä»¶å¤¹æˆ–æ–‡ä»¶å³å¯å¼€å§‹:)
 ï¼ˆä»ä¸» -&gt; æ‰©å±•åŠ è½½å¯ç”¨çš„æ‰©å±•ï¼Œä¾‹å¦‚ *.jpgã€*.jpegã€*.pngã€*.webpï¼‰</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="131"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the left navigation button; it shows the previous image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;åˆ‡æ¢åˆ°å·¦é‚»å±…ï¼ˆåŸºäºå½“å‰ç›®å½•çš„æ–‡ä»¶åˆ—è¡¨ï¼‰ã€‚&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå·¦â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="134"/>
        <source>â†</source>
        <comment>Label of the previous-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="137"/>
        <source>Left</source>
        <comment>Keyboard shortcut for the previous-image navigation action; use the standard Left Arrow key sequence.</comment>
        <translation>å·¦è¾¹</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="164"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Save button. This moves the current image into the app-managed &apos;output&apos; subdirectory, it does not write image edits.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;å°†å½“å‰å›¾ç‰‡ç§»åŠ¨åˆ°æŒ‡å®šçš„è¾“å‡ºå­ç›®å½•ä¸­ã€‚ å°†è‡ªåŠ¨åˆ‡æ¢åˆ°ä¸‹ä¸€å¼ ç…§ç‰‡&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå‘ä¸Šâ€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="167"/>
        <source>save â†‘</source>
        <comment>Label of the button that keeps the current image by moving it into the &apos;output&apos; subdirectory.</comment>
        <translation>ä¿å­˜â†‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="170"/>
        <source>Up</source>
        <comment>Keyboard shortcut for the Save action; use the standard Up Arrow key sequence.</comment>
        <translation>å‘ä¸Š</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="197"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Trash button. This moves the current image into the app-managed &apos;trash&apos; subdirectory, it does not delete it permanently.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;å°†å½“å‰å›¾ç‰‡ç§»åŠ¨åˆ°æŒ‡å®šçš„åƒåœ¾å­ç›®å½•ä¸­ã€‚ å°†è‡ªåŠ¨åˆ‡æ¢åˆ°ä¸‹ä¸€å¼ ç…§ç‰‡&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå‘ä¸‹â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="200"/>
        <source>trash â†“</source>
        <comment>Label of the button that rejects the current image by moving it into the &apos;trash&apos; subdirectory.</comment>
        <translation>åƒåœ¾â†“</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="203"/>
        <source>Down</source>
        <comment>Keyboard shortcut for the Trash action; use the standard Down Arrow key sequence.</comment>
        <translation>å‘ä¸‹</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="232"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the right navigation button; it shows the next image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;åˆ‡æ¢åˆ°å³é‚»å±…ï¼ˆåŸºäºå½“å‰ç›®å½•çš„æ–‡ä»¶åˆ—è¡¨ï¼‰ã€‚&lt;/p&gt;&lt;p&gt;ä½œä¸ºå¿«æ·æ–¹å¼ï¼ŒæŒ‰â€œå³â€é”® ç®­å¤´é”®ã€‚&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="235"/>
        <source>â†’ </source>
        <comment>Label of the next-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†’</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="238"/>
        <source>Right</source>
        <comment>Keyboard shortcut for the next-image navigation action; use the standard Right Arrow key sequence.</comment>
        <translation>æ­£ç¡®çš„</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="277"/>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <comment>Tooltip for the status bar at the bottom of the main window.</comment>
        <translation>è¿™æ˜¯çŠ¶æ€æ ã€‚ å®ƒå°†æ˜¾ç¤ºä»»ä½•ç±»å‹çš„ä¿¡æ¯ï¼Œå¦‚å½“å‰ä½ç½®ã€æ•…éšœæ¶ˆæ¯ç­‰ã€‚</translation>
    </message>
</context>
</TS>
---------- end ----------
-------------------- ./translations/Cullendula_de.ts --------------------
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="de_DE">
<context>
    <name>CullendulaFileSystemHandler</name>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="53"/>
        <source>Could not move &apos;%1&apos; to &apos;%2&apos;: %3</source>
        <extracomment>Error message after moving a file into a named subdirectory such as &quot;output&quot;, &quot;trash&quot;, &quot;undo&quot;, or &quot;redo&quot; failed.</extracomment>
        <translation>â€%1â€œ konnte nicht nach â€%2â€œ verschoben werden: %3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="58"/>
        <source>Could not prepare &apos;%1&apos; directory at &apos;%2&apos;: %3</source>
        <extracomment>Error message after preparing an application-managed subdirectory such as &quot;output&quot; or &quot;trash&quot; failed.</extracomment>
        <translation>Das Verzeichnis â€%1â€œ unter â€%2â€œ konnte nicht vorbereitet werden: %3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="206"/>
        <source>showing %1 of %2</source>
        <extracomment>Status bar message showing the current 1-based image position and the total number of loaded images.</extracomment>
        <translation>%1 von %2 wird angezeigt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="231"/>
        <source>No undo step is currently available.</source>
        <extracomment>Error shown when the user requests Undo but the undo history is empty.</extracomment>
        <translation>Derzeit ist kein Schritt zum RÃ¼ckgÃ¤ngigmachen verfÃ¼gbar.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="248"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="285"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="474"/>
        <source>the filesystem rename operation failed</source>
        <extracomment>Low-level filesystem failure detail inserted into a larger user-visible move error message.</extracomment>
        <translation>Der Vorgang zum Umbenennen des Dateisystems ist fehlgeschlagen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="262"/>
        <source>No redo step is currently available.</source>
        <extracomment>Error shown when the user requests Redo but the redo history is empty.</extracomment>
        <translation>Derzeit ist kein Wiederherstellungsschritt verfÃ¼gbar.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="346"/>
        <source>The path &apos;%1&apos; could not be resolved to an existing directory.</source>
        <extracomment>Error after a dropped path or selected path does not resolve to an existing directory on disk.</extracomment>
        <translation>Der Pfad â€%1â€œ konnte nicht in ein vorhandenes Verzeichnis aufgelÃ¶st werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="415"/>
        <source>the path is already occupied by a non-directory filesystem entry</source>
        <extracomment>Failure detail for a managed output directory path that already exists as a regular file or another non-directory entry.</extracomment>
        <translation>Der Pfad ist bereits durch einen Nicht-Verzeichnis-Dateisystemeintrag belegt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="427"/>
        <source>creating the directory failed</source>
        <extracomment>Failure detail for a managed output directory that Qt could not create on disk.</extracomment>
        <translation>Das Erstellen des Verzeichnisses ist fehlgeschlagen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="434"/>
        <source>the directory is still missing after creation</source>
        <extracomment>Failure detail for a managed output directory that still does not exist after a reported creation attempt.</extracomment>
        <translation>Das Verzeichnis fehlt nach der Erstellung noch</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="452"/>
        <source>No current image is available to move.</source>
        <extracomment>Error shown when the user tries to save or trash an image but no current image is loaded.</extracomment>
        <translation>Es ist kein aktuelles Bild zum Verschieben verfÃ¼gbar.</translation>
    </message>
</context>
<context>
    <name>CullendulaMainWindow</name>
    <message>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <translation type="vanished">Cullendula â€“ Ihr kleiner Helfer bei der Auswahl der besten Aufnahmen</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot;font-size:10pt;&quot;&gt;Diese Beschriftung zeigt das aktuelle Foto (Bilddatei) an, falls eines geladen ist.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot;font-size:10pt;&quot;&gt;Bitte ziehen Sie ein Verzeichnis oder eine Datei per Drag &amp; Drop in diesen Bereich.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <translation type="vanished">Ziehen Sie den Ordner oder die Datei per Drag&amp;Drop zum Starten :) 
(lÃ¤dt die aktivierten Erweiterungen von â€Hauptâ€œ -&gt; â€Erweiterungenâ€œ, zum Beispiel *.jpg, *.jpeg, *.png, *.webp)</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Wechseln Sie zum linken Nachbarn (basierend auf der Dateiliste des aktuellen Verzeichnisses).&lt;/p&gt;&lt;p&gt;Als Tastenkombination drÃ¼cken Sie die Taste â€linksâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†</source>
        <translation type="vanished">â†</translation>
    </message>
    <message>
        <source>Left</source>
        <translation type="vanished">Links</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Verschieben Sie das aktuelle Bild in das angegebene Ausgabe-Unterverzeichnis. Wechselt automatisch zum nÃ¤chsten Foto.&lt;/p&gt;&lt;p&gt;DrÃ¼cken Sie als VerknÃ¼pfung die Taste â€Nach obenâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>save â†‘</source>
        <translation type="vanished">speichern â†‘</translation>
    </message>
    <message>
        <source>Up</source>
        <translation type="vanished">Hoch</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Verschiebt das aktuelle Bild in das angegebene Trash-Unterverzeichnis. Wechselt automatisch zum nÃ¤chsten Foto.&lt;/p&gt;&lt;p&gt;DrÃ¼cken Sie als VerknÃ¼pfung die Taste â€Nach untenâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>trash â†“</source>
        <translation type="vanished">MÃ¼ll â†“</translation>
    </message>
    <message>
        <source>Down</source>
        <translation type="vanished">Runter</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Wechseln Sie zum rechten Nachbarn (basierend auf der Dateiliste des aktuellen Verzeichnisses).&lt;/p&gt;&lt;p&gt;Als Tastenkombination drÃ¼cken Sie die â€rechteâ€œ Taste. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†’ </source>
        <translation type="vanished">â†’</translation>
    </message>
    <message>
        <source>Right</source>
        <translation type="vanished">Rechts</translation>
    </message>
    <message>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <translation type="vanished">Dies ist die Statusleiste. Es werden alle Arten von Informationen wie die aktuelle Position, Fehlermeldungen usw. angezeigt.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="202"/>
        <source>system is up and running :)</source>
        <extracomment>Status bar message shown once after the main window is fully initialized.</extracomment>
        <translation>System ist betriebsbereit :)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="231"/>
        <source>drop current load and let&apos;s see what you dragged?</source>
        <extracomment>Status bar prompt during drag-and-drop after the payload was recognized as file-system URLs.</extracomment>
        <translation>Lass die aktuelle Last fallen und lass uns sehen, was du gezogen hast?</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="271"/>
        <source>The load was not usable! :(</source>
        <extracomment>Status bar error after a drop payload was rejected because it did not contain usable local file URLs.</extracomment>
        <translation>Die Ladung war nicht nutzbar! :(</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="326"/>
        <source>Could not save the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;output&quot; folder failed without a more specific message.</extracomment>
        <translation>Die aktuelle Datei konnte nicht gespeichert werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="345"/>
        <source>Could not trash the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;trash&quot; folder failed without a more specific message.</extracomment>
        <translation>Die aktuelle Datei konnte nicht in den Papierkorb verschoben werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="417"/>
        <source>no more valid images found: work maybe finished? :)
drag&amp;drop the next folder or files if you want!</source>
        <extracomment>Center label placeholder when no further images match the current extension filter in the active directory.</extracomment>
        <translation>Keine gÃ¼ltigen Bilder mehr gefunden: Arbeit vielleicht fertig? :) :) 
Ziehen Sie den nÃ¤chsten Ordner oder die nÃ¤chsten Dateien per Drag &amp; Drop, wenn Sie mÃ¶chten!</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="423"/>
        <source>no more files</source>
        <extracomment>Status bar message when the current directory no longer contains any matching images to show.</extracomment>
        <translation>keine Dateien mehr</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="430"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="432"/>
        <source>could not load the current image preview</source>
        <extracomment>Error shown both in the center label and the status bar when Qt cannot render the current image preview.</extracomment>
        <translation>Die aktuelle Bildvorschau konnte nicht geladen werden</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="478"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="640"/>
        <source>Enable loading of *.%1 files when opening the next directory</source>
        <extracomment>Tooltip for a checkable menu entry that enables a filename extension such as jpg, png, or webp for future directory scans.</extracomment>
        <translation>Aktivieren Sie das Laden von *.%1-Dateien beim Ã–ffnen des nÃ¤chsten Verzeichnisses</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="484"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="646"/>
        <source>Light</source>
        <extracomment>Menu label for the light visual theme.</extracomment>
        <translation>Licht</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="488"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="648"/>
        <source>Use the light application theme</source>
        <extracomment>Tooltip for switching the whole application to the light theme.</extracomment>
        <translation>Verwenden Sie das Lichtanwendungsthema</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="492"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="653"/>
        <source>Dark</source>
        <extracomment>Menu label for the dark visual theme.</extracomment>
        <translation>Dunkel</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="496"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="655"/>
        <source>Use the high-contrast dark application theme</source>
        <extracomment>Tooltip for switching the whole application to the dark theme.</extracomment>
        <translation>Verwenden Sie das kontrastreiche dunkle Anwendungsthema</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="503"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="660"/>
        <source>English</source>
        <extracomment>Language menu entry naming the English user-interface language.</extracomment>
        <translation>Englisch</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="510"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="667"/>
        <source>Deutsch</source>
        <extracomment>Language menu entry naming the German user-interface language in German.</extracomment>
        <translation>Deutsch</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="517"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="674"/>
        <source>Hrvatski</source>
        <extracomment>Language menu entry naming the Croatian user-interface language in Croatian.</extracomment>
        <translation>Hrvatski</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="524"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="681"/>
        <source>ä¸­æ–‡</source>
        <extracomment>Language menu entry naming the Chinese user-interface language in Chinese.</extracomment>
        <translation>ä¸­æ–‡</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="532"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="693"/>
        <source>Undo</source>
        <extracomment>Edit menu action label that reverses the most recent file move.</extracomment>
        <translation>RÃ¼ckgÃ¤ngig machen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="534"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="695"/>
        <source>Revert the last file-move-operation</source>
        <extracomment>Tooltip for the Undo action that moves the previously moved image back to its original location.</extracomment>
        <translation>Machen Sie den letzten Dateiverschiebungsvorgang rÃ¼ckgÃ¤ngig</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="543"/>
        <source>Could not undo the last file move.</source>
        <extracomment>Fallback status bar error after an undo request failed without a more specific message.</extracomment>
        <translation>Die letzte Dateiverschiebung konnte nicht rÃ¼ckgÃ¤ngig gemacht werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="549"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="700"/>
        <source>Redo</source>
        <extracomment>Edit menu action label that reapplies the most recently undone file move.</extracomment>
        <translation>Wiederholen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="551"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="702"/>
        <source>Redo the last file-move-operation (means: undo undo)</source>
        <extracomment>Tooltip for the Redo action. &quot;undo undo&quot; here means reapplied after an Undo.</extracomment>
        <translation>Den letzten Dateiverschiebungsvorgang wiederholen (bedeutet: rÃ¼ckgÃ¤ngig machen und rÃ¼ckgÃ¤ngig machen)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="560"/>
        <source>Could not redo the last file move.</source>
        <extracomment>Fallback status bar error after a redo request failed without a more specific message.</extracomment>
        <translation>Die letzte Dateiverschiebung konnte nicht wiederholt werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="567"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="712"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="803"/>
        <source>About Cullendula</source>
        <extracomment>Help menu action label that opens the application&apos;s About dialog.
----------
Title of the application&apos;s About dialog.</extracomment>
        <translation>Ãœber Cullendula</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="569"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="714"/>
        <source>Show the application&apos;s About box</source>
        <extracomment>Tooltip for opening the application&apos;s About dialog.</extracomment>
        <translation>Zeigt das Info-Feld der Anwendung an</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="574"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="719"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>About Qt</source>
        <extracomment>Help menu action label that opens Qt&apos;s built-in About dialog.
----------
Title of the Qt runtime information dialog. Rich-text body of the Qt runtime information dialog. %1 is the Qt version, %2 is the Qt installation prefix path.</extracomment>
        <translation>Ãœber Qt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="576"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="721"/>
        <source>Show the Qt library&apos;s About box</source>
        <extracomment>Tooltip for opening Qt&apos;s built-in About dialog.</extracomment>
        <translation>Zeigt das Info-Feld der Qt-Bibliothek an</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="614"/>
        <source>Cullendula</source>
        <extracomment>Main window title; the version suffix is appended separately in code.</extracomment>
        <translation>Cullendula</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="618"/>
        <source>Main</source>
        <extracomment>Top-level menu containing application settings such as extensions, style, and language.</extracomment>
        <translation>HauptsÃ¤chlich</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="623"/>
        <source>Extensions</source>
        <extracomment>Submenu listing the enabled image filename extensions for directory scanning.</extracomment>
        <translation>Erweiterungen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="628"/>
        <source>Style</source>
        <extracomment>Submenu for switching between visual themes.</extracomment>
        <translation>Stil</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="633"/>
        <source>Language</source>
        <extracomment>Submenu for switching the user-interface language.</extracomment>
        <translation>Sprache</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="662"/>
        <source>Use the default English source texts</source>
        <extracomment>Tooltip for switching back to the original English source texts.</extracomment>
        <translation>Verwenden Sie die standardmÃ¤ÃŸigen englischen Quelltexte</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="669"/>
        <source>Load the German user-interface translation</source>
        <extracomment>Tooltip for loading the German translation file.</extracomment>
        <translation>Laden Sie die deutsche Ãœbersetzung der BenutzeroberflÃ¤che</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="676"/>
        <source>Load the Croatian user-interface translation</source>
        <extracomment>Tooltip for loading the Croatian translation file.</extracomment>
        <translation>Laden Sie die kroatische Ãœbersetzung der BenutzeroberflÃ¤che</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="683"/>
        <source>Load the Chinese user-interface translation</source>
        <extracomment>Tooltip for loading the Simplified Chinese translation file.</extracomment>
        <translation>Laden Sie die chinesische Ãœbersetzung der BenutzeroberflÃ¤che</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="688"/>
        <source>Edit</source>
        <extracomment>Top-level menu for undo and redo actions.</extracomment>
        <translation>Bearbeiten</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="707"/>
        <source>Help</source>
        <extracomment>Top-level menu for About dialogs and other help-related actions.</extracomment>
        <translation>Helfen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="743"/>
        <source>Could not load the selected language.</source>
        <extracomment>Status bar error when loading the requested translation catalog failed.</extracomment>
        <translation>Die ausgewÃ¤hlte Sprache konnte nicht geladen werden.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="801"/>
        <source>Invoked Help|About</source>
        <extracomment>Status bar trace shown when the user opens the application&apos;s About dialog from the Help menu.</extracomment>
        <translation>Hilfe|Info aufgerufen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="805"/>
        <source>Helper program to sort out (&quot;cull&quot;) a collection of pictures in a directory after a nice photo-walk or event.&lt;br&gt;Should work cross-platform.&lt;br&gt;&lt;br&gt;Developed by &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;Source code can be found inside the repository at &lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;Feel free to use and share: GPL v3 :3</source>
        <extracomment>Rich-text body of the application&apos;s About dialog.</extracomment>
        <translation>Hilfsprogramm zum Sortieren (â€Aussortierenâ€œ) einer Sammlung von Bildern in einem Verzeichnis nach einem schÃ¶nen Foto-Spaziergang oder einer Veranstaltung.&lt;br&gt;Sollte plattformÃ¼bergreifend funktionieren.&lt;br&gt;&lt;br&gt;Entwickelt von &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;Der Quellcode befindet sich im Repository unter &lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;Sie kÃ¶nnen es gerne verwenden und teilen: GPL v3 :3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="818"/>
        <source>Invoked Help|About Qt</source>
        <extracomment>Status bar trace shown when the user opens Qt&apos;s About dialog from the Help menu.</extracomment>
        <translation>Aufgerufene Hilfe|Ãœber Qt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>This application currently runs with Qt %1.&lt;br&gt;Qt installation prefix: %2&lt;br&gt;&lt;br&gt;Qt is a cross-platform application framework for building desktop and embedded applications.</source>
        <translation>Diese Anwendung wird derzeit mit Qt %1 ausgefÃ¼hrt.&lt;br&gt;Qt-InstallationsprÃ¤fix: %2&lt;br&gt;&lt;br&gt;Qt ist ein plattformÃ¼bergreifendes Anwendungsframework zum Erstellen von Desktop- und eingebetteten Anwendungen.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="23"/>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <comment>Main window title shown before the runtime version suffix is applied from C++ code.</comment>
        <translation>Cullendula â€“ Ihr kleiner Helfer bei der Auswahl der besten Aufnahmen</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="55"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the large central preview area. It accepts a dropped image file or a directory containing images.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot;font-size:10pt;&quot;&gt;Diese Beschriftung zeigt das aktuelle Foto (Bilddatei) an, falls eines geladen ist.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot;font-size:10pt;&quot;&gt;Bitte ziehen Sie ein Verzeichnis oder eine Datei per Drag &amp; Drop in diesen Bereich.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="64"/>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <comment>Placeholder text in the central preview area before any image is loaded.</comment>
        <translation>Ziehen Sie den Ordner oder die Datei per Drag&amp;Drop zum Starten :) 
(lÃ¤dt die aktivierten Erweiterungen von â€Hauptâ€œ -&gt; â€Erweiterungenâ€œ, zum Beispiel *.jpg, *.jpeg, *.png, *.webp)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="131"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the left navigation button; it shows the previous image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Wechseln Sie zum linken Nachbarn (basierend auf der Dateiliste des aktuellen Verzeichnisses).&lt;/p&gt;&lt;p&gt;Als Tastenkombination drÃ¼cken Sie die Taste â€linksâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="134"/>
        <source>â†</source>
        <comment>Label of the previous-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="137"/>
        <source>Left</source>
        <comment>Keyboard shortcut for the previous-image navigation action; use the standard Left Arrow key sequence.</comment>
        <translation>Links</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="164"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Save button. This moves the current image into the app-managed &apos;output&apos; subdirectory, it does not write image edits.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Verschieben Sie das aktuelle Bild in das angegebene Ausgabe-Unterverzeichnis. Wechselt automatisch zum nÃ¤chsten Foto.&lt;/p&gt;&lt;p&gt;DrÃ¼cken Sie als VerknÃ¼pfung die Taste â€Nach obenâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="167"/>
        <source>save â†‘</source>
        <comment>Label of the button that keeps the current image by moving it into the &apos;output&apos; subdirectory.</comment>
        <translation>speichern â†‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="170"/>
        <source>Up</source>
        <comment>Keyboard shortcut for the Save action; use the standard Up Arrow key sequence.</comment>
        <translation>Hoch</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="197"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Trash button. This moves the current image into the app-managed &apos;trash&apos; subdirectory, it does not delete it permanently.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Verschiebt das aktuelle Bild in das angegebene Trash-Unterverzeichnis. Wechselt automatisch zum nÃ¤chsten Foto.&lt;/p&gt;&lt;p&gt;DrÃ¼cken Sie als VerknÃ¼pfung die Taste â€Nach untenâ€œ. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="200"/>
        <source>trash â†“</source>
        <comment>Label of the button that rejects the current image by moving it into the &apos;trash&apos; subdirectory.</comment>
        <translation>MÃ¼ll â†“</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="203"/>
        <source>Down</source>
        <comment>Keyboard shortcut for the Trash action; use the standard Down Arrow key sequence.</comment>
        <translation>Runter</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="232"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the right navigation button; it shows the next image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Wechseln Sie zum rechten Nachbarn (basierend auf der Dateiliste des aktuellen Verzeichnisses).&lt;/p&gt;&lt;p&gt;Als Tastenkombination drÃ¼cken Sie die â€rechteâ€œ Taste. Pfeiltaste.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="235"/>
        <source>â†’ </source>
        <comment>Label of the next-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†’</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="238"/>
        <source>Right</source>
        <comment>Keyboard shortcut for the next-image navigation action; use the standard Right Arrow key sequence.</comment>
        <translation>Rechts</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="277"/>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <comment>Tooltip for the status bar at the bottom of the main window.</comment>
        <translation>Dies ist die Statusleiste. Es werden alle Arten von Informationen wie die aktuelle Position, Fehlermeldungen usw. angezeigt.</translation>
    </message>
</context>
</TS>
---------- end ----------
-------------------- ./translations/Cullendula_hr.ts --------------------
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="hr_HR">
<context>
    <name>CullendulaFileSystemHandler</name>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="53"/>
        <source>Could not move &apos;%1&apos; to &apos;%2&apos;: %3</source>
        <extracomment>Error message after moving a file into a named subdirectory such as &quot;output&quot;, &quot;trash&quot;, &quot;undo&quot;, or &quot;redo&quot; failed.</extracomment>
        <translation>Nije moguÄ‡e premjestiti &apos;%1&apos; u &apos;%2&apos;: %3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="58"/>
        <source>Could not prepare &apos;%1&apos; directory at &apos;%2&apos;: %3</source>
        <extracomment>Error message after preparing an application-managed subdirectory such as &quot;output&quot; or &quot;trash&quot; failed.</extracomment>
        <translation>Nije moguÄ‡e pripremiti direktorij &apos;%1&apos; na &apos;%2&apos;: %3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="206"/>
        <source>showing %1 of %2</source>
        <extracomment>Status bar message showing the current 1-based image position and the total number of loaded images.</extracomment>
        <translation>prikazuje %1 od %2</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="231"/>
        <source>No undo step is currently available.</source>
        <extracomment>Error shown when the user requests Undo but the undo history is empty.</extracomment>
        <translation>Trenutno nije dostupan nijedan korak poniÅ¡tavanja.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="248"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="285"/>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="474"/>
        <source>the filesystem rename operation failed</source>
        <extracomment>Low-level filesystem failure detail inserted into a larger user-visible move error message.</extracomment>
        <translation>operacija preimenovanja datoteÄnog sustava nije uspjela</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="262"/>
        <source>No redo step is currently available.</source>
        <extracomment>Error shown when the user requests Redo but the redo history is empty.</extracomment>
        <translation>Trenutno nije dostupan nijedan korak ponavljanja.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="346"/>
        <source>The path &apos;%1&apos; could not be resolved to an existing directory.</source>
        <extracomment>Error after a dropped path or selected path does not resolve to an existing directory on disk.</extracomment>
        <translation>Put &apos;%1&apos; ne moÅ¾e se razrijeÅ¡iti na postojeÄ‡i direktorij.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="415"/>
        <source>the path is already occupied by a non-directory filesystem entry</source>
        <extracomment>Failure detail for a managed output directory path that already exists as a regular file or another non-directory entry.</extracomment>
        <translation>staza je veÄ‡ zauzeta unosom datoteÄnog sustava koji nije direktorij</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="427"/>
        <source>creating the directory failed</source>
        <extracomment>Failure detail for a managed output directory that Qt could not create on disk.</extracomment>
        <translation>stvaranje imenika nije uspjelo</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="434"/>
        <source>the directory is still missing after creation</source>
        <extracomment>Failure detail for a managed output directory that still does not exist after a reported creation attempt.</extracomment>
        <translation>imenik joÅ¡ uvijek nedostaje nakon izrade</translation>
    </message>
    <message>
        <location filename="../src/CullendulaFileSystemHandler.cpp" line="452"/>
        <source>No current image is available to move.</source>
        <extracomment>Error shown when the user tries to save or trash an image but no current image is loaded.</extracomment>
        <translation>Trenutna slika nije dostupna za premjeÅ¡tanje.</translation>
    </message>
</context>
<context>
    <name>CullendulaMainWindow</name>
    <message>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <translation type="vanished">Cullendula - vaÅ¡ smol pomoÄ‡nik u odabiru najboljih kadrova</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Ova oznaka Ä‡e prikazati trenutnu fotografiju (datoteku-slike) u sluÄaju da je ona uÄitana.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Molimo vas da povuÄete i ispustite direktorij ili datoteku na ovo podruÄje.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <translation type="vanished">povucite i ispustite mapu ili datoteku za poÄetak :) 
(uÄitava omoguÄ‡ena proÅ¡irenja iz Main -&gt; Extensions, na primjer *.jpg, *.jpeg, *.png, *.webp)</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Prebaci se na lijevog susjeda (na temelju popisa datoteka trenutnog direktorija).&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;lijevu&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†</source>
        <translation type="vanished">â†</translation>
    </message>
    <message>
        <source>Left</source>
        <translation type="vanished">Lijevo</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Premjesti trenutnu sliku u navedeni izlazni poddirektorij. Automatski Ä‡e se prebaciti na fotografiju koja je sljedeÄ‡a&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;gore&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>save â†‘</source>
        <translation type="vanished">spremiti â†‘</translation>
    </message>
    <message>
        <source>Up</source>
        <translation type="vanished">Gore</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Premjesti trenutnu sliku u navedeni poddirektorij smeÄ‡a. Automatski Ä‡e se prebaciti na fotografiju koja je sljedeÄ‡a&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;dolje&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>trash â†“</source>
        <translation type="vanished">smeÄ‡e â†“</translation>
    </message>
    <message>
        <source>Down</source>
        <translation type="vanished">dolje</translation>
    </message>
    <message>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="vanished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Prebaci se na desni susjed (na temelju popisa datoteka trenutnog direktorija).&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;desno&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <source>â†’ </source>
        <translation type="vanished">â†’</translation>
    </message>
    <message>
        <source>Right</source>
        <translation type="vanished">Pravo</translation>
    </message>
    <message>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <translation type="vanished">Ovo je statusna traka. Prikazat Ä‡e bilo koju vrstu informacija poput trenutne pozicije, poruka o neuspjehu, ..</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="202"/>
        <source>system is up and running :)</source>
        <extracomment>Status bar message shown once after the main window is fully initialized.</extracomment>
        <translation>sustav radi :)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="231"/>
        <source>drop current load and let&apos;s see what you dragged?</source>
        <extracomment>Status bar prompt during drag-and-drop after the payload was recognized as file-system URLs.</extracomment>
        <translation>ispusti trenutno optereÄ‡enje i da vidimo Å¡to si dovukao?</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="271"/>
        <source>The load was not usable! :(</source>
        <extracomment>Status bar error after a drop payload was rejected because it did not contain usable local file URLs.</extracomment>
        <translation>Teret nije bio upotrebljiv! :(</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="326"/>
        <source>Could not save the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;output&quot; folder failed without a more specific message.</extracomment>
        <translation>Nije moguÄ‡e spremiti trenutnu datoteku.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="345"/>
        <source>Could not trash the current file.</source>
        <extracomment>Fallback status bar error after moving the current image to the &quot;trash&quot; folder failed without a more specific message.</extracomment>
        <translation>Nije moguÄ‡e baciti trenutnu datoteku u smeÄ‡e.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="417"/>
        <source>no more valid images found: work maybe finished? :)
drag&amp;drop the next folder or files if you want!</source>
        <extracomment>Center label placeholder when no further images match the current extension filter in the active directory.</extracomment>
        <translation>viÅ¡e nije pronaÄ‘ena vaÅ¾eÄ‡a slika: rad je moÅ¾da zavrÅ¡en? :) 
povucite i ispustite sljedeÄ‡u mapu ili datoteke ako Å¾elite!</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="423"/>
        <source>no more files</source>
        <extracomment>Status bar message when the current directory no longer contains any matching images to show.</extracomment>
        <translation>nema viÅ¡e datoteka</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="430"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="432"/>
        <source>could not load the current image preview</source>
        <extracomment>Error shown both in the center label and the status bar when Qt cannot render the current image preview.</extracomment>
        <translation>nije mogao uÄitati trenutni pregled slike</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="478"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="640"/>
        <source>Enable loading of *.%1 files when opening the next directory</source>
        <extracomment>Tooltip for a checkable menu entry that enables a filename extension such as jpg, png, or webp for future directory scans.</extracomment>
        <translation>OmoguÄ‡i uÄitavanje *.%1 datoteka prilikom otvaranja sljedeÄ‡eg direktorija</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="484"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="646"/>
        <source>Light</source>
        <extracomment>Menu label for the light visual theme.</extracomment>
        <translation>Svjetlo</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="488"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="648"/>
        <source>Use the light application theme</source>
        <extracomment>Tooltip for switching the whole application to the light theme.</extracomment>
        <translation>Koristite svijetlu temu aplikacije</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="492"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="653"/>
        <source>Dark</source>
        <extracomment>Menu label for the dark visual theme.</extracomment>
        <translation>tamno</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="496"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="655"/>
        <source>Use the high-contrast dark application theme</source>
        <extracomment>Tooltip for switching the whole application to the dark theme.</extracomment>
        <translation>Koristite tamnu temu aplikacije visokog kontrasta</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="503"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="660"/>
        <source>English</source>
        <extracomment>Language menu entry naming the English user-interface language.</extracomment>
        <translation>engleski</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="510"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="667"/>
        <source>Deutsch</source>
        <extracomment>Language menu entry naming the German user-interface language in German.</extracomment>
        <translation>Deutsch</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="517"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="674"/>
        <source>Hrvatski</source>
        <extracomment>Language menu entry naming the Croatian user-interface language in Croatian.</extracomment>
        <translation>Hrvatski</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="524"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="681"/>
        <source>ä¸­æ–‡</source>
        <extracomment>Language menu entry naming the Chinese user-interface language in Chinese.</extracomment>
        <translation>ä¸­æ–‡</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="532"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="693"/>
        <source>Undo</source>
        <extracomment>Edit menu action label that reverses the most recent file move.</extracomment>
        <translation>PoniÅ¡ti</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="534"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="695"/>
        <source>Revert the last file-move-operation</source>
        <extracomment>Tooltip for the Undo action that moves the previously moved image back to its original location.</extracomment>
        <translation>VraÄ‡anje zadnje operacije premjeÅ¡tanja datoteke</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="543"/>
        <source>Could not undo the last file move.</source>
        <extracomment>Fallback status bar error after an undo request failed without a more specific message.</extracomment>
        <translation>Nije moguÄ‡e poniÅ¡titi zadnje premjeÅ¡tanje datoteke.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="549"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="700"/>
        <source>Redo</source>
        <extracomment>Edit menu action label that reapplies the most recently undone file move.</extracomment>
        <translation>Ponovi</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="551"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="702"/>
        <source>Redo the last file-move-operation (means: undo undo)</source>
        <extracomment>Tooltip for the Redo action. &quot;undo undo&quot; here means reapplied after an Undo.</extracomment>
        <translation>Ponovi posljednju operaciju premjeÅ¡tanja datoteke (znaÄi: poniÅ¡ti poniÅ¡tavanje)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="560"/>
        <source>Could not redo the last file move.</source>
        <extracomment>Fallback status bar error after a redo request failed without a more specific message.</extracomment>
        <translation>Nije moguÄ‡e ponoviti zadnje premjeÅ¡tanje datoteke.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="567"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="712"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="803"/>
        <source>About Cullendula</source>
        <extracomment>Help menu action label that opens the application&apos;s About dialog.
----------
Title of the application&apos;s About dialog.</extracomment>
        <translation>O Cullenduli</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="569"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="714"/>
        <source>Show the application&apos;s About box</source>
        <extracomment>Tooltip for opening the application&apos;s About dialog.</extracomment>
        <translation>PrikaÅ¾i okvir O aplikaciji</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="574"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="719"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>About Qt</source>
        <extracomment>Help menu action label that opens Qt&apos;s built-in About dialog.
----------
Title of the Qt runtime information dialog. Rich-text body of the Qt runtime information dialog. %1 is the Qt version, %2 is the Qt installation prefix path.</extracomment>
        <translation>O Qt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="576"/>
        <location filename="../src/CullendulaMainWindow.cpp" line="721"/>
        <source>Show the Qt library&apos;s About box</source>
        <extracomment>Tooltip for opening Qt&apos;s built-in About dialog.</extracomment>
        <translation>PrikaÅ¾i okvir O Qt biblioteci</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="614"/>
        <source>Cullendula</source>
        <extracomment>Main window title; the version suffix is appended separately in code.</extracomment>
        <translation>Cullendula</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="618"/>
        <source>Main</source>
        <extracomment>Top-level menu containing application settings such as extensions, style, and language.</extracomment>
        <translation>Glavni</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="623"/>
        <source>Extensions</source>
        <extracomment>Submenu listing the enabled image filename extensions for directory scanning.</extracomment>
        <translation>Ekstenzije</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="628"/>
        <source>Style</source>
        <extracomment>Submenu for switching between visual themes.</extracomment>
        <translation>Stil</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="633"/>
        <source>Language</source>
        <extracomment>Submenu for switching the user-interface language.</extracomment>
        <translation>Jezik</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="662"/>
        <source>Use the default English source texts</source>
        <extracomment>Tooltip for switching back to the original English source texts.</extracomment>
        <translation>Koristite zadani engleski izvorni tekst</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="669"/>
        <source>Load the German user-interface translation</source>
        <extracomment>Tooltip for loading the German translation file.</extracomment>
        <translation>UÄitajte prijevod njemaÄkog korisniÄkog suÄelja</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="676"/>
        <source>Load the Croatian user-interface translation</source>
        <extracomment>Tooltip for loading the Croatian translation file.</extracomment>
        <translation>UÄitajte prijevod hrvatskog korisniÄkog suÄelja</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="683"/>
        <source>Load the Chinese user-interface translation</source>
        <extracomment>Tooltip for loading the Simplified Chinese translation file.</extracomment>
        <translation>UÄitajte prijevod kineskog korisniÄkog suÄelja</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="688"/>
        <source>Edit</source>
        <extracomment>Top-level menu for undo and redo actions.</extracomment>
        <translation>Uredi</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="707"/>
        <source>Help</source>
        <extracomment>Top-level menu for About dialogs and other help-related actions.</extracomment>
        <translation>PomoÄ‡</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="743"/>
        <source>Could not load the selected language.</source>
        <extracomment>Status bar error when loading the requested translation catalog failed.</extracomment>
        <translation>Nije moguÄ‡e uÄitati odabrani jezik.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="801"/>
        <source>Invoked Help|About</source>
        <extracomment>Status bar trace shown when the user opens the application&apos;s About dialog from the Help menu.</extracomment>
        <translation>Pozvana pomoÄ‡|O</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="805"/>
        <source>Helper program to sort out (&quot;cull&quot;) a collection of pictures in a directory after a nice photo-walk or event.&lt;br&gt;Should work cross-platform.&lt;br&gt;&lt;br&gt;Developed by &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;Source code can be found inside the repository at &lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;Feel free to use and share: GPL v3 :3</source>
        <extracomment>Rich-text body of the application&apos;s About dialog.</extracomment>
        <translation>PomoÄ‡ni program za sortiranje (&quot;oduzimanje&quot;) kolekcije slika u direktoriju nakon lijepe foto-Å¡etnje ili dogaÄ‘aja.&lt;br&gt;Trebao bi raditi na viÅ¡e platformi.&lt;br&gt;&lt;br&gt;Razvio &lt;a href=&apos;mail@marcelpetrick.it&apos;&gt;mail@marcelpetrick.it&lt;/a&gt;&lt;br&gt;Izvorni kod moÅ¾e se pronaÄ‡i unutar repozitorija na &lt;a href=&apos;https://github.com/marcelpetrick/Cullendula/&apos;&gt;https://github.com/marcelpetrick/Cullendula&lt;/a&gt;&lt;br&gt;Slobodno koristite i dijelite: GPL v3 :3</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="818"/>
        <source>Invoked Help|About Qt</source>
        <extracomment>Status bar trace shown when the user opens Qt&apos;s About dialog from the Help menu.</extracomment>
        <translation>Pozvana pomoÄ‡|O Qt</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.cpp" line="821"/>
        <source>This application currently runs with Qt %1.&lt;br&gt;Qt installation prefix: %2&lt;br&gt;&lt;br&gt;Qt is a cross-platform application framework for building desktop and embedded applications.</source>
        <translation>Ova aplikacija trenutno radi s Qt-om %1.&lt;br&gt;Instalacijski prefiks Qt-a: %2&lt;br&gt;&lt;br&gt;Qt je meÄ‘uplatformski aplikacijski okvir za izradu desktop i ugraÄ‘enih aplikacija.</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="23"/>
        <source>Cullendula - your smol helper to pick the best shots</source>
        <comment>Main window title shown before the runtime version suffix is applied from C++ code.</comment>
        <translation>Cullendula - vaÅ¡ smol pomoÄ‡nik u odabiru najboljih kadrova</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="55"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;This label will show the current photo (image-file) in case one is loaded.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Please drag and drop a directory or file on this area.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the large central preview area. It accepts a dropped image file or a directory containing images.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Ova oznaka Ä‡e prikazati trenutnu fotografiju (datoteku-slike) u sluÄaju da je ona uÄitana.&lt;/span&gt;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-size:10pt;&quot;&gt;Molimo vas da povuÄete i ispustite direktorij ili datoteku na ovo podruÄje.&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="64"/>
        <source>drag&amp;drop folder or file to start :)
(loads the enabled extensions from Main -&gt; Extensions, for example *.jpg, *.jpeg, *.png, *.webp)</source>
        <comment>Placeholder text in the central preview area before any image is loaded.</comment>
        <translation>povucite i ispustite mapu ili datoteku za poÄetak :) 
(uÄitava omoguÄ‡ena proÅ¡irenja iz Main -&gt; Extensions, na primjer *.jpg, *.jpeg, *.png, *.webp)</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="131"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the left neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;left&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the left navigation button; it shows the previous image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Prebaci se na lijevog susjeda (na temelju popisa datoteka trenutnog direktorija).&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;lijevu&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="134"/>
        <source>â†</source>
        <comment>Label of the previous-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="137"/>
        <source>Left</source>
        <comment>Keyboard shortcut for the previous-image navigation action; use the standard Left Arrow key sequence.</comment>
        <translation>Lijevo</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="164"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified output-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;up&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Save button. This moves the current image into the app-managed &apos;output&apos; subdirectory, it does not write image edits.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Premjesti trenutnu sliku u navedeni izlazni poddirektorij. Automatski Ä‡e se prebaciti na fotografiju koja je sljedeÄ‡a&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;gore&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="167"/>
        <source>save â†‘</source>
        <comment>Label of the button that keeps the current image by moving it into the &apos;output&apos; subdirectory.</comment>
        <translation>spremiti â†‘</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="170"/>
        <source>Up</source>
        <comment>Keyboard shortcut for the Save action; use the standard Up Arrow key sequence.</comment>
        <translation>Gore</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="197"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Move the current picture into the specified trash-subdirectory. Will automatically switch to the photo which is next&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;down&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the Trash button. This moves the current image into the app-managed &apos;trash&apos; subdirectory, it does not delete it permanently.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Premjesti trenutnu sliku u navedeni poddirektorij smeÄ‡a. Automatski Ä‡e se prebaciti na fotografiju koja je sljedeÄ‡a&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;dolje&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="200"/>
        <source>trash â†“</source>
        <comment>Label of the button that rejects the current image by moving it into the &apos;trash&apos; subdirectory.</comment>
        <translation>smeÄ‡e â†“</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="203"/>
        <source>Down</source>
        <comment>Keyboard shortcut for the Trash action; use the standard Down Arrow key sequence.</comment>
        <translation>dolje</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="232"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Switch to the right neighbour (based on the file-list of the current directory).&lt;/p&gt;&lt;p&gt;As shortcut press the &amp;quot;right&amp;quot; arrow key.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <comment>Tooltip for the right navigation button; it shows the next image in the current directory order.</comment>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Prebaci se na desni susjed (na temelju popisa datoteka trenutnog direktorija).&lt;/p&gt;&lt;p&gt;Kao preÄac pritisnite &amp;quot;desno&amp;quot; tipka sa strelicom.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="235"/>
        <source>â†’ </source>
        <comment>Label of the next-image navigation button. Keep the arrow symbol if possible.</comment>
        <translation>â†’</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="238"/>
        <source>Right</source>
        <comment>Keyboard shortcut for the next-image navigation action; use the standard Right Arrow key sequence.</comment>
        <translation>Pravo</translation>
    </message>
    <message>
        <location filename="../src/CullendulaMainWindow.ui" line="277"/>
        <source>This is the status bar. It will display any kind of information like current position, failure messages, ..</source>
        <comment>Tooltip for the status bar at the bottom of the main window.</comment>
        <translation>Ovo je statusna traka. Prikazat Ä‡e bilo koju vrstu informacija poput trenutne pozicije, poruka o neuspjehu, ..</translation>
    </message>
</context>
</TS>
---------- end ----------
-------------------- ./Doxyfile.in --------------------
PROJECT_NAME           = "@PROJECT_NAME@"
PROJECT_NUMBER         = "@PROJECT_VERSION@"
PROJECT_BRIEF          = "A widget-based photo culling helper"
OUTPUT_DIRECTORY       = "@CULLENDULA_DOXYGEN_OUTPUT_DIRECTORY@"
CREATE_SUBDIRS         = NO
ALLOW_UNICODE_NAMES    = YES
OUTPUT_LANGUAGE        = English
USE_MDFILE_AS_MAINPAGE = "@CMAKE_SOURCE_DIR@/README.md"

INPUT                  = "@CMAKE_SOURCE_DIR@/README.md" \
                         "@CMAKE_SOURCE_DIR@/src"
FILE_PATTERNS          = *.md \
                         *.h \
                         *.cpp
RECURSIVE              = YES
EXCLUDE_PATTERNS       = */build/* \
                         */build-coverage/* \
                         */build-qt6/*

EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = NO
EXTRACT_STATIC         = YES
EXTRACT_LOCAL_CLASSES  = YES
HIDE_UNDOC_MEMBERS     = NO
HIDE_UNDOC_CLASSES     = NO
INLINE_INFO            = YES
SORT_MEMBER_DOCS       = YES
SORT_BRIEF_DOCS        = YES

QUIET                  = YES
WARN_IF_UNDOCUMENTED   = NO
WARN_IF_DOC_ERROR      = YES
WARN_LOGFILE           = "@CULLENDULA_DOXYGEN_OUTPUT_DIRECTORY@/warnings.txt"

GENERATE_HTML          = YES
HTML_OUTPUT            = html
HTML_FILE_EXTENSION    = .html
GENERATE_TREEVIEW      = YES
FULL_SIDEBAR           = YES

GENERATE_LATEX         = NO
GENERATE_MAN           = NO
GENERATE_RTF           = NO
GENERATE_XML           = NO

SOURCE_BROWSER         = YES
INLINE_SOURCES         = NO
STRIP_CODE_COMMENTS    = NO
REFERENCED_BY_RELATION = YES
REFERENCES_RELATION    = YES
VERBATIM_HEADERS       = YES

HAVE_DOT               = YES
DOT_IMAGE_FORMAT       = svg
CLASS_GRAPH            = YES
COLLABORATION_GRAPH    = YES
GROUP_GRAPHS           = YES
INCLUDE_GRAPH          = YES
INCLUDED_BY_GRAPH      = YES
CALL_GRAPH             = NO
CALLER_GRAPH           = NO
GRAPHICAL_HIERARCHY    = YES
DIRECTORY_GRAPH        = YES
DOT_CLEANUP            = YES
---------- end ----------
