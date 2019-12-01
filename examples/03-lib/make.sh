rm -rf build
mkdir build
cd build || exit
cmake -DCMAKE_INSTALL_PREFIX=/tmp/cmake/03-lib/usr ..
make
sudo make install