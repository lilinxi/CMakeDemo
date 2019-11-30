cmake_minimum_required(VERSION 3.14)
PROJECT(HELLO)

# ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# 这个指令用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存 放的位置。EXCLUDE_FROM_ALL 参数的含义是将这个目录从编译过程中排除，比如，工程的 example。
ADD_SUBDIRECTORY(src bin)

# CMAKE_INSTALL_PREFIX 的默认定义是 /usr/local

# 普通文件的安装：
# 可用于安装一般文件，并可以指定访问权限，文件名是此指令所在路径下的相对路径。
# 如果默认不定义权限 PERMISSIONS，安装后的权限为: OWNER_WRITE, OWNER_READ, GROUP_READ, WORLD_READ，即 644 权限。
INSTALL(FILES COPYRIGHT README.md DESTINATION share/doc/cmake/02-better)

# 非目标文件的可执行程序安装（比如脚本之类）：
# 跟上面的 FILES 指令使用方法一样，唯一的不同是安装后权限为: OWNER_EXECUTE, GROUP_EXECUTE, 和WORLD_EXECUTE，即 755 权限。
INSTALL(PROGRAMS run.sh DESTINATION bin)

# 目录的安装：
# 这里主要使用其中的 DIRECTORY、PATTERN 以及 PERMISSIONS 参数。
# DIRECTORY 后面连接的是所在 Source 目录的相对路径，但务必注意:
#   abc 和 abc/有很大的区别。
#   如果目录名不以/结尾，那么这个目录将被安装为目标路径下的 abc，如果目录名以/结尾，代表将这个目录中的内容安装到目标路径，但不包括这个目录本身。
# PATTERN 用于使用正则表达式进行过滤，PERMISSIONS 用于指定 PATTERN 过滤后的文件权限。
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake/02-better)

# INSTALL([[SCRIPT <file>] [CODE <code>]] [...])
# SCRIPT 参数用于在安装时调用 cmake 脚本文件（也就是<abc>.cmake 文件）

# CODE 参数用于执行 CMAKE 指令，必须以双引号括起来。
INSTALL(CODE "MESSAGE(\"Sample install message.\")")
