# NBlib 

## Intro.

🐂🍺NBlib: 基于 **Boost.Asio** 的 C++ 网络库，专注于并发编程、线程池管理和网络通信。该库提供了基础的服务器和客户端实现，支持多线程任务调度与管理，学习使用；

## Cat.

- [功能特性](#功能特性)
- [依赖项](#依赖项)
- [编译与安装](#编译与安装)
- [文件结构](#文件结构)
- [贡献](#贡献)

## Features.

- **多线程支持**：包括简单线程池和任务窃取线程池（`SimpleThreadPool` 和 `StealThreadPool`），用于高效的任务调度和并行处理。
- **并发队列**：提供并发队列 (`concurrentqueue.h`)，支持高效的数据传输和任务分发。
- **网络通信**：基于 `Boost.Asio` 的服务器和客户端实现 (`BaseServer` 和 `BaseClient`)，支持异步 I/O 和高并发连接处理。
- **线程管理**：线程池管理（如 `ioservicepool.h`、`parrallenThreadPool.h` 等），支持多线程环境下的资源管理和调度。
- **日志系统**：提供基础的日志记录工具 (`log.h`)。
- **配置管理**：支持配置文件的加载和解析 (`config.h`)工具，方便管理应用的配置选项。
- **单例模式**：提供单例模式模板 (`singleton.h`)，用于全局对象的管理。

## Dep.

该项目基于 [Boost.Asio](https://www.boost.org/doc/libs/1_81_0/doc/html/boost_asio.html) 实现，并需要以下依赖项：

- **Boost C++ 库**：特别是 `Boost.Asio`，用于网络通信和异步 I/O 操作。你可以从 [Boost 官方网站](https://www.boost.org/) 下载并安装 Boost 库。
- **C++11 或以上**：项目使用了 C++11 特性，确保你的编译器支持 C++11 或更高版本。

## Make.

### Visual Studio

该项目包含 `NBlib.vcxproj` 文件，可以通过 Visual Studio 直接打开并构建：

1. 打开 Visual Studio。
2. 选择 "打开项目/解决方案"。
3. 选择 `NBlib.vcxproj` 文件。
4. 在项目属性中设置 Boost 库的路径。
5. 生成解决方案即可。

###  CMake

你也可以通过创建一个适配的 `CMakeLists.txt` 文件来编译此项目，确保包含 Boost 库：

1. 创建 `CMakeLists.txt` 文件：

   ```cmake
   cmake_minimum_required(VERSION 3.10)
   project(NBlib)
   
   set(CMAKE_CXX_STANDARD 11)
   
   find_package(Boost REQUIRED COMPONENTS system thread)
   
   include_directories(${Boost_INCLUDE_DIRS})
   
   file(GLOB SOURCES
       "*.cpp"
       "*.h"
   )
   
   add_executable(NBlib ${SOURCES})
   
   target_link_libraries(NBlib ${Boost_LIBRARIES})
   ```
   
2. 在项目根目录执行以下命令：

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## File Stru.

- `BaseClient.cpp` / `BaseClient.h`：基于 Boost.Asio 的基础客户端实现，支持异步 I/O 操作。
- `BaseServer.cpp` / `BaseServer.h`：基于 Boost.Asio 的基础服务器实现，支持并发的客户端连接处理。
- `concurrentqueue.h`：并发队列的实现，支持多线程环境下的高效数据交换。
- `simplethreadpool.cpp` / `simplethreadpool.h`：简单线程池实现，用于基本的任务并行处理。
- `stealThreadPool.cpp` / `stealThreadPool.h`：任务窃取线程池实现，支持负载均衡和多线程任务窃取。
- `ioservicepool.cpp` / `ioservicepool.h`：基于 Boost.Asio 的 IO 服务线程池，用于管理多个 I/O 操作。
- `config.cpp` / `config.h`：配置管理模块，支持从配置文件加载和解析应用的配置项。
- `log.cpp` / `log.h`：日志系统，提供简单的日志记录功能。
- `packet.cpp` / `packet.h`：网络数据包类
- `session.cpp` / `session.h`：会话管理类，用于管理与客户端的连接。
- `singleton.h`：单例模式模板，用于全局对象的管理。
- `test.h`：测试相关的头文件，可能包含一些测试用例或测试框架的设置。

## Ref.

- [sylar](https://github.com/sylar-yin/sylar)

