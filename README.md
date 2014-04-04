LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Gros Relults
----

name            | func name       | passed  | gros time   | slower      
---             | ---             | ---     | ---         | ---         
anonymous       | nop             |       4 |    21.60 ms |      0.00 % 
beastie         | cutout          |       7 |    47.44 ms |    119.65 % 
beastie         | undebug         |       7 |    41.16 ms |     90.55 % 
beastie         | split           |       6 |    75.38 ms |    248.99 % 
Eddy_Em         | delsubstr       |       3 |    91.82 ms |    325.14 % 
Gvidon          | process         |       3 |    92.67 ms |    329.04 % 
KennyMinigun    | strdel          |       3 |    40.17 ms |     86.01 % 
nokachi         | remove          |       6 |    60.27 ms |    179.03 % 
qulinxao        | wordstrings     |       4 |    48.11 ms |    122.74 % 
true_admin      | cut             |       3 |    55.79 ms |    158.31 % 
true_admin      | cut2            |       3 |    85.94 ms |    297.92 % 
wota            | strremove       |       3 |    84.62 ms |    291.77 % 
wota            | remove_word     |       7 |    46.21 ms |    113.95 % 
anonymous       | strcut          |       3 |    46.77 ms |    116.56 % 
puzan           | str_drop_str    |       7 |    41.21 ms |     90.80 % 
qnikst          | undebugq        |       5 |    37.90 ms |     75.46 % 
mix-mix         | strcut          |       7 |    48.18 ms |    123.09 % 


Test Cases
----------

name | debug | debugfs | debug=1 | systemd.debug | debug 123 debug 456 | debug debugfs debug debug=1 systemd.debug debug
---- | ---- | ---- | ---- | ---- | ---- | ----
expect | | debugfs | debug=1 | systemd.debug | 123 456 | debugfs debug=1 systemd.debug
beastie cutout  | ok   | ok   | ok   | ok   | ok   | ok
beastie undebug | ok   | ok   | ok   | ok   | ok   | ok
beastie split   | fail | ok   | ok   | ok   | ok   | ok
Eddy_Em         | fail | fail | fail | ok   | ok   | fail
Gvidon          | ok   | fail | fail | fail | ok   | fail
KennyMinigun    | ok   | fail | fail | fail | ok   | fail
nokachi         | ok   | ok   | ok   | ok   | ok   | ok
qulinxao        | ok   | ok   | fail | fail | ok   | fail
true_admin      | ok   | fail | fail | fail | ok   | fail
true_admin 2    | ok   | fail | fail | fail | ok   | fail
wota            | ok   | fail | fail | fail | ok   | fail
wota whiteout   | ok   | ok   | ok   | ok   | ok   | ok
anonymous       | ok   | fail | fail | fail | ok   | fail
