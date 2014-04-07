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
    1 | qnikst           | undebugq2        | ***************** |     96.79 ms |      0.00 %
    2 | qnikst           | undebugq3        | ***************** |     98.22 ms |      1.47 %
    3 | wota             | remove_word      | ***************** |    113.86 ms |     17.64 %
    4 | beastie          | cutout           | ***************** |    127.67 ms |     31.90 %
    5 | anonymous        | anon_strcut      | ***************** |    138.32 ms |     42.91 %
    6 | puzan            | str_mask_str     | ***************** |    144.84 ms |     49.65 %
    7 | beastie          | undebug          | ***************** |    162.05 ms |     67.42 %
    8 | qulinxao         | wordstrings      | ***************** |    168.14 ms |     73.72 %
    9 | mix-mix          | strcut           | ***************** |    207.23 ms |    114.10 %
   10 | puzan            | str_drop_str     | ***************** |    224.81 ms |    132.26 %
   11 | beastie          | wipeout          | ***************** |    313.29 ms |    223.68 %
   12 | qnikst           | undebugq uspace  | *_*************** |     97.77 ms |      1.01 %
   13 | qnikst           | undebugq         | *_*************** |    106.10 ms |      9.62 %
   14 | beastie          | split            | __****_********** |    388.87 ms |    301.77 %
   15 | anonymous        | anon_wipedebug   | ******_*****___*_ |     70.17 ms |    -27.50 %
   16 | wota             | undebug_wota     | ******_*****___*_ |     70.23 ms |    -27.45 %
   17 | Carb             | debugdel         | *_****_*****___*_ |     74.27 ms |    -23.26 %
   18 | nokachi          | remove           | **_*******___**__ |    240.12 ms |    148.08 %
   19 | beastie          | cutout_orig      | ***___**____***_* |    153.37 ms |     58.45 %
   20 | KennyMinigun     | strdel           | ***___**____***_* |    166.07 ms |     71.58 %
   21 | anonymous        | strcut           | ***___**____***_* |    175.38 ms |     81.20 %
   22 | true_admin       | cut              | ***___**____***_* |    206.77 ms |    113.63 %
   23 | wota             | strremove        | ***___**____***_* |    704.76 ms |    628.14 %
   24 | Gvidon           | process          | ***___**____***_* |    857.14 ms |    785.56 %
   25 | true_admin       | cut2             | ***___**____***_* |   1507.19 ms |   1457.18 %
   26 | Eddy_Em          | delsubstr        | _**__*_*____*_*_* |    298.53 ms |    208.43 %
   27 | nop              | nop              | __****_________** |     36.51 ms |    -62.28 %
