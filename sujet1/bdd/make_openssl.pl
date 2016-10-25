use v5.10;

opendir(my $dir, 'openssl');
chdir $dir;
my @files = readdir $dir;

for my $file (@files) {
    if ($file =~ /.*\.tar\.gz/){}
    else{
        if ($file =~ /openssl/){
            `rm -rf $file`;
        }
    }
}

my $args;
my $hid = "> /dev/null 2> /dev/null";
for my $file (@files) {
    if ($file =~ /.*\.tar\.gz/) {

        say "Compiling $file...";
        $args = ("tar xzf $file"); 
        say $args;
        system($args) == 0 or say 'Tar error !';

        my $mfile = substr $file, 0, (length ($file) - 7); 

        opendir(my $openssldir, $mfile) or die "Failed to open $file";
        chdir $openssldir;

        $args = "./config shared $hid";
        say $args;
        system($args) == 0 or say 'Config error !';
        $args = "make -j4 $hid";
        say $args;
        system($args) == 0 or say 'Compilation error !';

        closedir $openssldir;
        chdir $dir;
    }
}

