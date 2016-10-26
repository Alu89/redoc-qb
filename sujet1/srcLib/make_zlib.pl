use v5.10;
use Data::Dumper;
my $NBPROC = 8;
my $lib = "zlib";
my $strconfig = "configure";
opendir(my $dir, $lib);

chdir $dir;


my @files = readdir $dir;
opendir(my $dir, './');
my @files = readdir $dir;
for my $file (@files) {	
	say $file;
	
    if (-d $file) {
        say "Compiling $file...";
		$mfile=$file;
        opendir(my $openssldir, $mfile) or die "Failed to open $mfile $!";
        chdir $openssldir;

        $args = "./$strconfig $hid";
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


say "cp all";
for my $line (@findOUTArray){	

	my @version = split /\//, $line;
	my $pathToCp = "../../bdd/$lib/$version[1]/so/";
	
	
	if (!(-d $pathToCp)) {
		`mkdir $pathToCp`;
	}
	`cp $line $pathToCp`
}
