rm -rf build
mkdir build
cd build || exit
# CMAKE_INSTALL_PREFIX 的默认定义是 /usr/local
cmake -DCMAKE_INSTALL_PREFIX=/tmp/cmake/02-better/usr ..
make
sudo make install