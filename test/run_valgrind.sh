#/usr/bin/env bash
cd ../cmake-build-debug/test/ && ls && valgrind --leak-check=full ./full_test
