# **love_xml**
3A - XML files' validator in C , and Graphical XML generator from DTD 


## GET STARTED

OS prefered : Linux  (distribution choice is up to you)

If you are on a Linux Boot , you can skip this section

Else, you could fancy using hypervisors such as : 

- [VirtualBox](https://www.virtualbox.org/)
- [VMware Workstation](https://www.vmware.com/)
- [ESGI students](https://e5.onthehub.com/WebStore/ProductsByMajorVersionList.aspx?ws=d2aba3ff-f1ad-e711-80f7-000d3af41938)

And mount [linux ubuntu 20.04 iso](https://releases.ubuntu.com/20.04/)

A great alternative is the window's WSL.

Get [Ubuntu 20.04](https://www.microsoft.com/store/productId/9N6SVWS3RX71) (latest stable version as of 19/10/2020)

You can also follow [this link](https://github.com/Taumah/love_xml/blob/main/WSL.md) 
to learn how to get your WSL set up :v:


##### CLONE THE PROJECT

cd to you working directory.
Then

- `git clone git@github.com:Taumah/love_xml.git`  for __SSH__
    
    **OR**

- `git clone https://github.com/Taumah/love_xml.git` for __HTTPS__


## COMPILATION

packages needed : :lock:

| Package Name  |          with root           |             without root           |
| ------------- | ---------------------------- | ---------------------------------- |
|     gcc-8     |  `apt install gcc-8`         |  `sudo apt install gcc-8`          |
|     gtk3+     |  `apt install libgtk-3-dev`  |  `sudo apt install libgtk-3-dev`   |
|     make      |  `apt install make`          |  `sudo apt install make`           |

## COMPILE AND LAUNCH

Everything you need to launch the project is available in the Makefile

1. `make all`       both builds and runs the program.
2. `make build`     creates an exe in bin/ folder
3. `make launch`    is a shortcut for ./bin/name_of_exe.exe

>I assume we will mostly use `make all`


## GENERATE TEMPLATES

in order to create XML files for our app, we decided to use glade.

You can download it [here](http://gemmei.ftp.acc.umu.se/pub/GNOME/binaries/win32/glade/3.14/glade-3-14-2-installer.exe)!

Also see a great [GLADE Tutorial](https://zestedesavoir.com/tutoriels/870/des-interfaces-graphiques-en-python-et-gtk/1456_utilisation-avancee/5778_prise-en-main-de-glade/)
 in French :open_mouth:

For further learning , see [this blog](http://blog.borovsak.si/) (English)


### Contributors
- @Taumah :green_heart:
- 
- 