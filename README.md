LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Rules
-----

Allowed API: http://www.cs.bham.ac.uk/~exr/teaching/lectures/systems/08_09/docs/kernelAPI/x1820.html

Test cases: https://www.linux.org.ru/forum/development/10349962?cid=10352344

Style note: please use indent with provided config

Gros Relults
------------

place | name             | func name        | passed            | gros time    | slower
  --- | ---              | ---              | ---               | ---          | ---
    1 | qnikst           | undebugq2        | ***************** |    467.25 ms |      0.00 %
    2 | qnikst           | undebugq3        | ***************** |    473.51 ms |      1.34 %
    3 | wota             | remove_word      | ***************** |    560.28 ms |     19.91 %
    4 | beastie          | cutout           | ***************** |    602.05 ms |     28.85 %
    5 | anonymous        | anon_strcut      | ***************** |    721.56 ms |     54.43 %
    6 | puzan            | str_mask_str     | ***************** |    739.18 ms |     58.20 %
    7 | beastie          | undebug          | ***************** |    784.89 ms |     67.98 %
    8 | qulinxao         | wordstrings      | ***************** |    839.61 ms |     79.69 %
    9 | mix-mix          | strcut           | ***************** |    996.95 ms |    113.37 %
   10 | puzan            | str_drop_str     | ***************** |   1168.18 ms |    150.01 %
   11 | beastie          | wipeout          | ***************** |   1660.81 ms |    255.45 %
   12 | nop              | nop              |   ****         ** |    180.83 ms |    -61.30 %
   13 | anonymous        | anon_wipedebug   | ****** *****   *  |    350.27 ms |    -25.04 %
   14 | wota             | undebug_wota     | ****** *****   *  |    350.68 ms |    -24.95 %
   15 | Carb             | debugdel         | * **** *****   *  |    374.02 ms |    -19.95 %
   16 | qnikst           | undebugq uspace  | * *************** |    517.30 ms |     10.71 %
   17 | qnikst           | undebugq         | * *************** |    525.08 ms |     12.38 %
   18 | KennyMinigun     | strdel           | ***   **    *** * |    647.08 ms |     38.49 %
   19 | beastie          | cutout_orig      | ***   **    *** * |    746.96 ms |     59.86 %
   20 | anonymous        | strcut           | ***   **    *** * |    819.65 ms |     75.42 %
   21 | true_admin       | cut              | ***   **    *** * |    979.20 ms |    109.57 %
   22 | nokachi          | remove           | ** *******   **   |   1111.31 ms |    137.84 %
   23 | Eddy_Em          | delsubstr        |  **  * *    * * * |   1447.85 ms |    209.87 %
   24 | beastie          | split            |   **** ********** |   1889.15 ms |    304.31 %
   25 | wota             | strremove        | ***   **    *** * |   2306.30 ms |    393.59 %
   26 | Gvidon           | process          | ***   **    *** * |   3171.09 ms |    578.67 %
   27 | true_admin       | cut2             | ***   **    *** * |   7334.57 ms |   1469.74 %

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
