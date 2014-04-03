LOR-Contest
===========

LOR Contest for a Medal of Lennart

https://www.linux.org.ru/forum/development/10349962

Results
-------

Average time of 5 passes each:

<pre>
         beastie   pass   clobber input                              113.39 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         Eddy_Em   pass                    potential memory leaks    148.67 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

          Gvidon   pass   clobber input                             1205.80 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

    KennyMinigun   pass   clobber input                              135.87 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         nokachi   pass                    potential memory leaks    141.27 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

        qulinxao   pass   clobber input                              183.02 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64       root=UUID=who-ever-cares-about-uid ro      '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

   true_admin #1   pass                    potential memory leaks    121.01 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

   true_admin #2   pass                    potential memory leaks    944.89 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         wota #1   pass   clobber input                             1002.16 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64  root=UUID=who-ever-cares-about-uid ro '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'

         wota #2   pass   clobber input                               90.48 ms
           input 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 debug root=UUID=who-ever-cares-about-uid ro debug'
          output 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64       root=UUID=who-ever-cares-about-uid ro      '
        expected 'BOOT_IMAGE=/boot/vmlinuz-3.2.0-amd64 root=UUID=who-ever-cares-about-uid ro'
</pre>
