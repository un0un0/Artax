                   _____ __________________________  ____  ___
                  /  _  \\______   \__    ___/  _  \ \   \/  /
                 /  /_\  \|       _/ |    | /  /_\  \ \     /  2018 Artax/ARTX
                /    |    \    |   \ |    |/    |    \/     \ 
                \____|____/____|___/ |____|\____|____/___/\__\
                                     

Artax is a Powerful Node-Based PoW + PoS-based cryptocurrency.

## Artax Specifications

| Specification | Value |
|:-----------|:-----------|
| Block Spacing | `65 seconds` |
| Stake Minimum Age | `10 hours` |
| Masternode Minimum Age | `24 hours` |
| Stake Reward | `20% PoS / 180% Masternode per annum` |
| Port | `21526` |
| RPC Port | `21527` |

## Social Channels

| Site | link |
|:-----------|:-----------|
| Bitcointalk | https://bitcointalk.org/index.php?topic=2702901 |
| Facebook | https://www.facebook.com/artaxtech/ |
| Twitter | http://twitter.com/artaxtech |
| Telegram | http://t.me/artax |
| Discord | https://discord.gg/btMYs43 |
| Website | http://www.artax.one |



BUILD LINUX
-----------
1) git clone https://github.com/Artax-Project/Artax

2) cd Artax/src

3) mkdir obj/crypto

4) chmod +x leveldb/build_detect_platform

5) cd leveldb && make libleveldb.a libmemenv.a

6) cd ..

7) sudo make -f makefile.unix USE_UPNP=    # Headless Artax Node

8) strip artaxd

9) sudo cp artaxd /usr/local/bin




BUILD WINDOWS
-------------

1) Download Qt.zip from https://github.com/Artax-Project/Artax/releases/tag/v1.0 and unpack to C:/

2) Download Artax source from https://github.com/Artax-Project/Artax/archive/master.zip 

2.1) Unpack to C:/Artax

3) Install Perl for windows from the homepage http://www.activestate.com/activeperl/downloads

4) Download Python 2.7 https://www.python.org/downloads/windows/

4.1) While installing python make sure to add python.exe to the path.

5) Run msys.bat located in C:\MinGW49-32\msys\1.0

6) cd /C/Artax/src/leveldb

7) Type "TARGET_OS=NATIVE_WINDOWS make libleveldb.a libmemenv.a" and hit enter to build leveldb

8) Exit msys shell

9) Open windows command prompt

10) cd C:/dev

11) Type "49-32-qt5.bat" and hit enter to run

12) cd ../Artax

13) Type "qmake USE_UPNP=0" and hit enter to run

14) Type "mingw32-make" and hit enter to start building. When it's finished you can find your .exe in the release folder


Masternode Setup guide here:
Linux - http://artax.one/dl/AM.pdf
Windows - http://artax.one/dl/WAM.pdf


For more information please visit the website:

http://artax.one
