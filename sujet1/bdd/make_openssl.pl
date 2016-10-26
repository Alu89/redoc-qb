use v5.10;
use Data::Dumper;
my $NBPROC = 8;
opendir(my $dir, 'openssl');

chdir $dir;


my @files = readdir $dir;

for my $file (@files) {
    if ($file =~ /.*\.tar\.gz/){}
    else{
        if ($file =~ /openssl/){
            `rm -rf $file`;
        }
        if ($file =~ /so/){
            `rm -rf $file`;
        }
    }
}



my $args;
my $hid = "> /dev/null 2> /dev/null";
for my $file (@files) {

    if ($file =~ /.*\.tar\.gz/) {
        $args = ("tar xzf $file"); 
        say $args;
        system($args) == 0 or say 'Tar error !';
        }
    }
    
closedir $dir;
opendir(my $dir, './');
my @files = readdir $dir;
for my $file (@files) {	
	say $file;
	
    if (-d $file) {
        say "Compiling $file...";
		$mfile=$file;
        opendir(my $openssldir, $mfile) or die "Failed to open $mfile $!";
        chdir $openssldir;

        $args = "./config shared $hid";
        say $args;
        system($args) == 0 or say "Config error ! $!";
        $args = "make -j$NBPROC $hid";
        say $args;
        system($args) == 0 or say 'Compilation error !';
        
        closedir $openssldir;
        chdir $dir;
    }
}


closedir $dir;



$findCMD = "find ./ | grep -e \"\\.so\$\"";

my $findOUT = `$findCMD`;
my @findOUTArray = split /\s/, $findOUT;

if (!(-d "./so")) {
	`mkdir ./so`;
}

say "cp all";
for my $line (@findOUTArray){	

	my @version = split /\//, $line;
	if (!(-d "./so/$version[1]")) {
		`mkdir ./so/$version[1]`;
	}
	`cp $line ./so/$version[1]`
}
