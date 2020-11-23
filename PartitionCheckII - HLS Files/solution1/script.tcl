############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PartitionCheckII
set_top PartitionCheckII
add_files C:/Users/16167/Downloads/axi4_burst/axi4_sqrt.hpp
add_files C:/Users/16167/Downloads/axi4_burst/axi4_sqrt.cpp
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./PartitionCheckII/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
