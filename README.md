LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Gros Relults
----

sorted by success and time

name            | func name       | passed      | gros time   | slower
---             | ---             | ---         | ---         | ---
wota            | remove_word     |       6 |   75.64 ms |      0.00 %
beastie         | undebug         |       6 |   76.34 ms |      0.92 %
beastie         | cutout          |       6 |   78.26 ms |      3.46 %
nokachi         | remove          |       6 |  157.40 ms |    108.09 %
beastie         | split           |       5 |  182.92 ms |    141.83 %
qulinxao        | wordstrings     |       3 |   69.81 ms |     -7.70 %
wota            | strremove       |       2 |   70.27 ms |     -7.10 %
Gvidon          | process         |       2 |   74.87 ms |     -1.02 %
KennyMinigun    | strdel          |       2 |   63.98 ms |    -15.41 %
anonymous       | strcut          |       2 |   81.30 ms |      7.48 %
true_admin      | cut             |       2 |  164.18 ms |    117.05 %
true_admin      | cut2            |       2 |  230.41 ms |    204.62 %
Eddy_Em         | delsubstr       |       2 |  258.54 ms |    241.80 %

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
