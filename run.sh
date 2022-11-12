# shell script to maintain build system

mkdir -p build
cd build


# cmake commands run in such a way that we dont need 
# build files in the repository.
cmake ../
cmake --build ./

mv ./build/* ../