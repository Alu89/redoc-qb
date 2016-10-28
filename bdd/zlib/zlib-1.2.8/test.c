#include "zlib.h"
#include "gzguts.h"
#include "zutil.h"
#include "inftrees.h"
#include "zconf.h"

main(){
inflateBackEnd(NULL);
gzclose(NULL);
zError(NULL);
gzrewind(NULL);
compressBound(NULL);
gzclearerr(NULL);
inflateSync(NULL);
deflateReset(NULL);
gzdirect(NULL);
gzclose_r(NULL);
gzeof(NULL);
inflateEnd(NULL);
deflateEnd(NULL);
inflateReset(NULL);
gzgetc_(NULL);
inflateMark(NULL);
gzclose_w(NULL);

}
