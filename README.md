# BollingerBands

This project allow you to calculate the bollinger bands regarding indexes contained in a file.

## Install

Run `make`then `make clean`

## Usage


    `./bollinger [-h] period standard_dev indexes_file index_number`

    period		period number of indexes for the moving average
    standard_dev	standard deviation coefficient to apply
    indexes_file	file containing daily indexes
    index_number	index number to compute moving average and Bollinger bands

    -h			print usage and quit.
