# gz-log-analyser

## Analize data stored in gzip compressed text files 

Gather stats on a fly from compressed .gz files without extracting these file.

**Build**

```bash
g++ report.cpp -o report
```

**Examples**

To analize a single `.gz` file open a bash terminal, and run the following

```bash
zcat search1.log.gz | grep -E '^results |^indices ' | ./report
```

To analize all `search*.log.gz` files in a current folder

```bash
zcat search*.log.gz | grep -E '^results |^indices ' | ./report
```

```
results
----------------
  size   5
  sum    42
  mean   8.4
  median 5
  75%    12
  90%    20
  99.9%  20

indices
----------------
  size   2
  sum    51
  mean   25.5
  median 25.5
  75%    34
  90%    34
  99.9%  34
```

### Wrapping with a Bash script

```bash
#!/bin/bash
	
  # List .log.gz files, supress ls error message if empty
  LIST_OF_FILES=`ls *.log.gz 2>/dev/null`
  echo "list:" $LIST_OF_FILES

  # Exit if list is empty
  if [ -z "$LIST_OF_FILES" ]; then
	echo "EMPTY LIST. EXIT.";
	exit 0;
  fi

  zcat $LIST_OF_FILES | egrep '^results|^indices' | ./report
```
