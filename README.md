LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Gros Relults
----

name            | func name       | passed  | gros time   | slower      
---             | ---             | ---     | ---         | ---         
anonymous       | nop             |       4 |   122.12 ms |    -37.83 % 
beastie         | cutout          |       8 |   259.51 ms |     32.10 % 
beastie         | cutout_orig     |       3 |   333.16 ms |     69.59 % 
beastie         | undebug         |       8 |   282.05 ms |     43.58 % 
beastie         | split           |       7 |   505.40 ms |    157.27 % 
Eddy_Em         | delsubstr       |       3 |   631.74 ms |    221.58 % 
Gvidon          | process         |       3 |   713.79 ms |    263.35 % 
KennyMinigun    | strdel          |       3 |   258.54 ms |     31.61 % 
nokachi         | remove          |       7 |   383.76 ms |     95.35 % 
qulinxao        | wordstrings     |       8 |   239.00 ms |     21.66 % 
true_admin      | cut             |       3 |   379.67 ms |     93.27 % 
true_admin      | cut2            |       3 |   699.92 ms |    256.29 % 
wota            | strremove       |       3 |   667.68 ms |    239.88 % 
wota            | remove_word     |       8 |   286.61 ms |     45.90 % 
anonymous       | strcut          |       3 |   327.97 ms |     66.95 % 
anonymous       | anon_strcut     |       8 |   222.85 ms |     13.44 % 
puzan           | str_drop_str    |       8 |   327.03 ms |     66.47 % 
qnikst          | undebugq        |       8 |   235.13 ms |     19.69 % 
mix-mix         | strcut          |       8 |   312.42 ms |     59.03 % 
Carb            | debugdel        |       8 |   196.45 ms |      0.00 % 

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
