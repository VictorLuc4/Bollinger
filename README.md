# BollingerBands

This project allow you to calculate the bollinger bands regarding indexes contained in a file.

## Install

To compile the project, run : `make`
To run the tests : `make coverage`

**Warning** : To be able to run the tests, make sure you installed the lib `criterion`

## Usage

To run :  

```text
./bollinger [-h] period standard_dev indexes_file index_number

period		    period number of indexes for the moving average
standard_dev	standard deviation coefficient to apply
indexes_file	file containing daily indexes
index_number	index number to compute moving average and Bollinger bands

-h			print usage and quit.
```
