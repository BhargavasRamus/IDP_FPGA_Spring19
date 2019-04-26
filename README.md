# IDP_FPGA_Spring19
Fixed point matrix multiplication

prerequists:
  -properly flashed RaspberryPi, icoboard, Arduino installed properly.
  
  -download RaspberryPi from: https://www.raspberrypi.org/downloads/raspbian/ 
  and flash in the SD card following the instructions from :https://www.raspberrypi.org/documentation/installation/installing-images/README.md
  
  -download Arduino linux arm version from:https://www.arduino.cc/en/Main/Software
  -follow the steps provided in the website to install arduino in the RaspberryPi.
  
  -use the below commands in the terminal of the RaspberryPi to download the required setup:
  
cd
git clone git://git.drogon.net/ wiringPi
cd wiringPi && ./build

cd 
sudo apt-get install subversion
svn co http://svn.clifford.at/handicraft/2015/icoprog
cd icoprog && make install

sudo apt-get install build-essential clang bison flex libreadline-dev
sudo apt-get install gawk tcl-dev libffi-dev git mercurial graphviz
sudo apt-get install xdot pkg-config python python3 libftdi-dev

cd
git clone https://github.com/cliffordwolf/icestorm.git icestorm
cd icestorm && make && sudo make install

cd 
git clone https://github.com/cseed/arachne-pnr.git arachne-pnr
cd arachne-pnr && make && sudo make install

cd
git clone https://github.com/cliffordwolf/yosys.git yosys
cd yosys && make && sudo make install


  code compiling and executing:
  
  -after installing the required setup, compile Makefile in the terminal as follows:
  -make v_fname = <file_name>
  
  -the verilog file will be flashed in the icoboard (using icestorm).
  
  -dump the arduino codes in different ports of the RaspberryPi.
  
  -provide input from Arduino serial monitor and then change the arduino port (tools->ports-><change_port_to_output>). open the  serial monitor to read output of the matrix multiplication. 
