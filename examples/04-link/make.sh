rm -rf build
mkdir build
cd build || exit
cmake -DCMAKE_INSTALL_PREFIX=/tmp/cmake/04-link/usr ..
make
#sudo make install