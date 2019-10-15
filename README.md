# Rick Sanchez’s travel guide problem

Rick Sanchez's travel schedule problem is a scenario where we have a list of planets to visit, each with their own name and time to visit, and we also have a maximum time allocated to visit planets on a month. From this information, we need to organize an agenda with the planets to be visited each month so that:

* The number of planets visited in a month is always greater than or equal to the number of planets visited in a month later.
* Planets are visited within a month following the alphabetical order of their names.

The objective of this work is to implement an algorithm capable of organizing such a schedule in a timely manner for large lists of planets. The following algorithm architecture is built using a vector of planets, a month row, and merge sort ordering.

### Project

```
ds_travel_guide
├── build
├── docs
|   ├── relatorio.pdf
|   └── spec.pdf
├── include
├── src
├── tests
├── .gitignore
├── LICENSE
├── main.cpp
├── makefile
└── README.md
```

### Make options

- `$ make`: Compile source code
- `$ make run`: Execute aplication
- `$ make mem`: Execute aplication and show memory allocation logs
- `$ make clean`: Clean build output
- `$ make test`: Run tests
