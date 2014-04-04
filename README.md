LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Results
-------

Average time of 5 passes each:

<pre>
DATA

input  "debug debugfs debug debug=1 systemd.debug debug"
expect "debugfs debug=1 systemd.debug"

EXECUTING

beastie cutout       clobber           - fails   "systemd."
beastie whiteout     clobber           - fails   "           fs            =1 systemd.           "
beastie undebug      clobber           - passes  "debugfs debug=1 systemd.debug "
beastie split        clobber           - passes  "debugfs debug=1 systemd.debug"
Eddy_Em                    -  needs free fails   " fs  =1 systemd. "
Gvidon               clobber           - fails   " fs  =1 systemd. "
KennyMinigun         clobber           - fails   "s 1 systemd."
nokachi                    -  needs free passes  " debugfs  debug=1 systemd.debug "
qulinxao             clobber           - fails   "      debugfs            =1 systemd.           "
true_admin #1              -  needs free fails   " fs  =1 systemd. "
true_admin #2              -  needs free fails   " fs  =1 systemd. "
wota #1              clobber           - fails   " fs  =1 systemd. "
wota #2              clobber           - passes  "      debugfs       debug=1 systemd.debug      "
anonymous            clobber           - fails   " fs  =1 systemd. "

TIMING

beastie cutout      230.68 ms  fails     110.5 % slower than best
beastie whiteout     96.62 ms  fails     -11.8 % slower than best
beastie undebug     116.77 ms passes       6.6 % slower than best
beastie split       236.49 ms passes     115.8 % slower than best
Eddy_Em             249.73 ms  fails     127.9 % slower than best
Gvidon              291.68 ms  fails     166.2 % slower than best
KennyMinigun        111.75 ms  fails       2.0 % slower than best
nokachi             113.84 ms passes       3.9 % slower than best
qulinxao            154.87 ms  fails      41.4 % slower than best
true_admin #1        79.79 ms  fails     -27.2 % slower than best
true_admin #2       198.71 ms  fails      81.4 % slower than best
wota #1             322.62 ms  fails     194.5 % slower than best
wota #2             109.56 ms passes       0.0 % slower than best
anonymous           147.95 ms  fails      35.0 % slower than best
</pre>

test cases
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
