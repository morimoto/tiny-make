#! /bin/sh
#===============================
#
#          cpulist.sh
#
# 2008/11 morimoto
#===============================

grep -h INSTALL_CPU $* | sed -e "s/INSTALL_CPU/CPU_EXTERN/g"
echo "const static struct lss2_cpu *cpulist[] = {"
grep -h INSTALL_CPU $* | sed -e "s/INSTALL_CPU/CPU_DEFINE/g"
echo "};"
echo "CPU_LIST_SIZE;"
