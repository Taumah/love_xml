
# INSTALL UBUNTU ALONGSIDE WITH WINDOWS 10

#### Tutorial inspired from [korben.info](https://korben.info/linux-wsl-gui-interface-graphique-windows-10.html)

- Open a Windows Powershell as admin and type :
    ```PowerShell
    * Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```
- download and install any version of Linux on the microsoft store:
    * latest ubuntu [20.04 TLS](https://www.microsoft.com/store/productId/9N6SVWS3RX71)
    * type WSL in the microsoft's store searchbar

- create a new user ;  username : your_name  password : root    are the most usual credentials used

- update packages with `sudo apt update && sudo apt upgrade`
> You can close you WSL for now

- Install a Visual server software on your computer
    * [VcXsrv](https://sourceforge.net/projects/vcxsrv/)
> You can leave the default settings 

- launch app Xlaunch from desktop of start shortcut
    * choose one large window 
    * let all other configuration as default

- get back to your wsl 
    * type `sudo apt-get install vim-gtk` (make sure you updated your system well)
> it might take up some time :grimacing:

- go to your .bashrc (nano /home/YOUR_USERNAME/.bashrc) and write at the very bottom 
    * export DISPLAY=:0
    * save your file , quit Linux and restart it. 
> It should work now

- On your WSL ; install a desktop environement : 

    * `sudo apt-get install xfce4` is the software we'll use

> might take up **more** time :grimacing::grimacing::grimacing:

- then,  type `xfce4-session` , a desktop should appear on Xlaunch's window



now, every time you need a graphical desktop , just type xfce4-session with Xlaunch oppened (launch the Xserver first)
and you'll be able to use graphical applications with this linux
