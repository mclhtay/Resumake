# Resumake is the simplest Resumé maker you can find!

Resumake takes some very basic details about you and turns them into a well formatted resume that you can use to apply to jobs right away!

## Current Version Features:

- Supports adding name, email and phone number
- Supports adding one experience and one education

# Run a already compiled version of Resumake:

1. There should be an executable, compiled version of resumake inside Resumake/
2. Make sure you give it executable permission, `chmod u+x ./Resumake/Resumake`
3. run `./Resumake/Resumake`

# Instructions on how to set up on Raspeberry Pi

1. We need to install Qt on Pi and the easiest way is to download the entire Qt creator application. It will serve as both an IDE and a compiler at the same time to make our lives easier.
2. First open your terminal, and check for any Pi updates: `sudo apt-get update`
3. Install any updates: `sudo apt-get install build-essential`, say yes to all installs
4. Install Qt creator: `sudo apt-get install qtcreator`, and use version 5 as the default (version 5 is latest): `sudo apt install qt5-default`
5. Install the examples just in case `sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html`

## Open Resumake

1. From the upper left corner of the menu (the raspberry pi icon), go to programming, and there should be a program called <strong> Qt Creator </strong>, open it.
2. Find the location of your project. Because it is probably imported from your own OS, it will give you a warning message, just confirm, and then in the next screen, click configure. This will configure the project into linux compatible automatically.
3. You can now make changes to the program in the Qt Creator IDE
4. To run the project in Qt Creator, the keyboard short-cut is `ctrl-r`

## Compile and build an executable for delivery

### You can run the script `./run.sh`

### or manually compile :

1. `cd` inside Resumake/
2. `qmake Resumake.pro` to build for linux specific
3. `make clean` to clean any previously built object files
4. `make` will create the executable automatically
5. `./Resumake` will execute the program

## Install and Generate:

### Installing:

- To install:
  sudo apt install doxygen
  sudo apt-get install graphviz

Note: The config file 'dconfig' has been created in the Resumake folder and configured (don't touch).

### Generating Documentation

- In /Resumake run 'doxygen dconfig'. This will generate/update the documentation as HTML and PDFs in the /docs folder next to /Resumake.

- Open docs/HTML/index.html to view the HTML documentation.

### Comments:

Comments are made directly above the class/function. Here is an example of a function from driver.h:

    /*!
     * \brief This function does something (brief)
     * \param r - This parameter does something
     * \returns This function returns something
     */
    void convertToPDF(Resume * r);

Qt will automatically suggest comment fields such as \brief, \param, \return.

See driver.h for more examples of Doxygen comments.
Again, run 'doxygen dconfig' in /Resumake to update/generate the documentation in /docs.
