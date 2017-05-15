# gz-log-analyser - Analize data stored in gzip compressed text files 

Gather stats on a fly from compressed .gz files without extracting these file.

**Build**
```g++ report.cpp -o report```

**Examples**
To analize a single `.gz` file
```zcat search1.log.gz | grep -E '^results |^indices ' | ./report```

To analize all `search*.log.gz` files in a current folder
```zcat search*.log.gz | grep -E '^results |^indices ' | ./report```

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
