LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Results
-------

Average time of 5 passes each:

<pre>
         beastie   pass   clobber input                              108.98 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         Eddy_Em   pass                    potential memory leaks    145.59 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

          Gvidon   pass   clobber input                             1192.48 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

    KennyMinigun   pass   clobber input                              165.24 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         nokachi   pass                    potential memory leaks    148.62 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

        qulinxao   pass   clobber input                              206.31 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64       root=UUID=who-ever-cares-about-uid ro      '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

   true_admin #1  fails                    potential memory leaks    128.98 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro d ro      '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

   true_admin #2  fails                    potential memory leaks    946.64 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro d ro debug'
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         wota #1   pass   clobber input                              996.23 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         wota #2   pass   clobber input                               89.33 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64       root=UUID=who-ever-cares-about-uid ro      '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'
</pre>
