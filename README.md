LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Rules
-----

Allowed API: http://www.cs.bham.ac.uk/~exr/teaching/lectures/systems/08_09/docs/kernelAPI/x1820.html

Test cases: https://www.linux.org.ru/forum/development/10349962?cid=10352344

Gros Relults
------------

name            | func name       | passed    | gros time   | slower      
---             | ---             | ---       | ---         | ---         
anonymous       | nop             |  ***  *   |   136.12 ms |    -39.02 % 
beastie         | cutout          | ********* |   335.27 ms |     50.18 % 
beastie         | cutout_orig     | *   * *   |   405.59 ms |     81.68 % 
beastie         | undebug         | ********* |   338.16 ms |     51.47 % 
beastie         | split           |  ******** |   681.69 ms |    205.36 % 
Eddy_Em         | delsubstr       |    ** *   |   785.19 ms |    251.72 % 
Gvidon          | process         | *   * *   |  1006.85 ms |    351.00 % 
KennyMinigun    | strdel          | *   * *   |   349.09 ms |     56.37 % 
nokachi         | remove          | ****** *  |   488.56 ms |    118.85 % 
qulinxao        | wordstrings     | ********* |   312.89 ms |     40.15 % 
true_admin      | cut             | *   * *   |   455.05 ms |    103.83 % 
true_admin      | cut2            | *   * *   |  1062.44 ms |    375.91 % 
wota            | strremove       | *   * *   |   835.42 ms |    274.21 % 
wota            | remove_word     | ********* |   352.17 ms |     57.75 % 
anonymous       | strcut          | *   * *   |   424.82 ms |     90.29 % 
anonymous       | anon_strcut     | ********* |   295.01 ms |     32.15 % 
puzan           | str_drop_str    | ********* |   463.46 ms |    107.60 % 
qnikst          | undebugq        | ********* |   344.70 ms |     54.40 % 
mix-mix         | strcut          | ********* |   402.85 ms |     80.45 % 
Carb            | debugdel        | ********* |   223.25 ms |      0.00 % 

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
