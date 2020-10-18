# COSC1114 Assignemnt 1 2020 Semester 2

|            |             |
|------------|-------------|
| Author     | Arone Susau |
| Student #  | s3728977    |
| Course     | COSC1114    |
| Assignment | 2           |

### Please Note
This project is intended to be run using the automatic run commands as the `Makefile` creates all required result files for the aggregation of data.

# How To Automatically Run

1. To compile all schedulers please first run:
```
make
```
2. To run all allocators:
```
make run
```

3. To clean out the current build and data:
```
make clean
```

# How To Manually Run

1. To compile all schedulers please first run:
```
make
```
2. To run a allocator please enter:
```
./Main <INPUT_FILE> <ALLOCATOR_TYPE> <NAME_LIST_SIZE>
```
Example
```
./Main data/first-names-1.txt FIRST 4945
```

# Directory Descriptions

- `out`: Contains compiled binary files.
- `data`: Contains original names fiels.
- `results`: Contains csv files with data from the allocators seperated into first-names and middle-names directories.

There is also the contents of the jyputer notebook in the results directory, if you'd like to view the code used to generate the charts and analytics.

# Results Structure

As mentioned above, the individual results of each allocators freeMBList and allocMBList has been input to seperate files if you would like to reference each result on its own. The `combined.csv` file contains an aggregate of all the data from each allocator and will be primarily used for data analysis. The `totals.csv` file contains the memory usage totals.