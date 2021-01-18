# end-to-end-GCN-acceleration

## Requirement
- Install Xilinx Runtime (XRT)
- Install Vitis 2020.1 or above
- Install link [here](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis.html)
- Clone this project
- Download the graph datasets [here](https://drive.google.com/drive/folders/1a1-5ziftuYrNVHshaEoizR76u2Udq0Mg?usp=sharing)

## Usasge
1. Source Xilinx Runtime by running `source /opt/xilinx/xrt/setup.sh`
(directory may be different based on where your Runtime is installed)
2. Change directory to "run" `cd ./run `
3. Run the following command to build FPGA binary `make build TARGET=hw`
(this would take up to 10 hours)
4. Run the following command to test the program `make run TARGET=hw`

## Modification
To implement your own dataset, you need to do some modification in host.cpp:
1. Prepare adjacency matrix in CSR format and change file directory in line 75-88
2. Update row_size to the number of nodes in your graph, i.e. dimesion of adjacency matrix (line 94)
3. Update meta-data in line 39-40 to the dimension of layer 1 and layer 2


