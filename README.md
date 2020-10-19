# love_xml
3A - XML files' validator in C , and Graphical XML generator from DTD 


## GET STARTED

OS prefered : Linux  (can choose any distro~, or directly on a Linux boot)

also through VMs like : 

- [VirtualBox](https://www.virtualbox.org/)
- [VMware Workstation](https://www.vmware.com/)
- [ESGI students](https://e5.onthehub.com/WebStore/ProductsByMajorVersionList.aspx?ws=d2aba3ff-f1ad-e711-80f7-000d3af41938)
    * [linux ubuntu 20.04 iso] (https://releases.ubuntu.com/20.04/)

A great alternative is the window's WSL.

Get [Ubuntu 20.04](https://www.microsoft.com/store/productId/9N6SVWS3RX71) (latest stable version as of 19/10/2020)

You can also follow [this link](https://github.com/Taumah/love_xml/blob/main/WSL.md) 
to learn how to get your WSL set up :v:


##### CLONE THE PROJECT

cd to you working directory.
Then

- `git clone git@github.com:Taumah/love_xml.git`  for SSH
    
    **OR**

- `git clone https://github.com/Taumah/love_xml.git` for HTTPS


## COMPILATION

packages needed : :lock:

| Package Name  |          with root           |             without root              |
| ------------- | ---------------------------- | ------------------------------------- |
|     gcc-8     |  `apt install gcc-8`         |  `sudo apt install gcc-8`             |
|     gtk3+     |  `apt install libgtk-3-dev`  |  `sudo apt-get install libgtk-3-dev`  |
|     make      |  `apt install make`          |  `sudo apt install make`              |

## COMPILE AND LAUNCH

Everything you need to launch the project is available in the Makefile

1. `make all`       both builds and runs the program.
2. `make build`     creates an exe in bin/ folder
3. `make launch`    is a shortcut for ./bin/name_of_exe.exe

>I assume we will mostly use `make all`

### Contributors
- @Taumah :green_heart:
- 
- 