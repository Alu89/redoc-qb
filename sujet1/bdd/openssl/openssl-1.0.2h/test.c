#include "conf_api.h"
#include "engine.h"
#include "lhash.h"
#include "rand.h"
#include "blowfish.h"
#include "pqueue.h"
#include "ecdh.h"
#include "ssl2.h"
#include "evp.h"
#include "comp.h"
#include "hmac.h"
#include "whrlpool.h"
#include "ossl_typ.h"
#include "opensslv.h"
#include "cmac.h"
#include "rc4.h"
#include "sha.h"
#include "objects.h"
#include "conf.h"
#include "ssl23.h"
#include "srp.h"
#include "md4.h"
#include "dh.h"
#include "ssl.h"
#include "ui.h"
#include "asn1.h"
#include "ec.h"
#include "err.h"
#include "ecdsa.h"
#include "bn.h"
#include "obj_mac.h"
#include "bio.h"
#include "x509v3.h"
#include "dso.h"
#include "pkcs7.h"
#include "ui_compat.h"
#include "x509.h"
#include "ts.h"
#include "pkcs12.h"
#include "aes.h"
#include "md5.h"
#include "srtp.h"
#include "des.h"
#include "safestack.h"
#include "x509_vfy.h"
#include "ripemd.h"
#include "opensslconf.h"
#include "asn1_mac.h"
#include "buffer.h"
#include "rsa.h"
#include "krb5_asn.h"
#include "ocsp.h"
#include "tls1.h"
#include "seed.h"
#include "cast.h"
#include "ssl3.h"
#include "modes.h"
#include "pem2.h"
#include "e_os2.h"
#include "rc2.h"
#include "cms.h"
#include "symhacks.h"
#include "txt_db.h"
#include "crypto.h"
#include "stack.h"
#include "dsa.h"
#include "camellia.h"
#include "asn1t.h"
#include "ebcdic.h"
#include "kssl.h"
#include "pem.h"
int main(){
CRYPTO_mem_ctrl(0);
CRYPTO_is_mem_check_on();
SSLeay_version(0);
SSLeay();
OPENSSL_issetugid();
CRYPTO_get_ex_data_implementation();
CRYPTO_set_ex_data_implementation(NULL);
CRYPTO_ex_data_new_class();
CRYPTO_get_ex_new_index(0,0,NULL,NULL,NULL,NULL);
CRYPTO_new_ex_data(0,NULL,NULL);
CRYPTO_dup_ex_data(0,NULL,NULL);
CRYPTO_free_ex_data(0,NULL,NULL);
CRYPTO_set_ex_data(NULL,0,NULL);
CRYPTO_get_ex_data(NULL,0);
CRYPTO_cleanup_all_ex_data();
CRYPTO_get_new_lockid(NULL);
CRYPTO_num_locks();
CRYPTO_lock(0,0,NULL,0);
CRYPTO_set_locking_callback(NULL);
CRYPTO_get_locking_callback();
CRYPTO_set_add_lock_callback(NULL);
CRYPTO_get_add_lock_callback();
CRYPTO_THREADID_set_numeric(NULL,0);
CRYPTO_THREADID_set_pointer(NULL,NULL);
CRYPTO_THREADID_set_callback(NULL);
CRYPTO_THREADID_get_callback();
CRYPTO_THREADID_current(NULL);
CRYPTO_THREADID_cmp(NULL,NULL);
CRYPTO_THREADID_cpy(NULL,NULL);
CRYPTO_THREADID_hash(NULL);
CRYPTO_set_id_callback(NULL);
CRYPTO_get_id_callback();
CRYPTO_thread_id();
CRYPTO_get_lock_name(0);
CRYPTO_add_lock(NULL,0,0,NULL,0);
CRYPTO_get_new_dynlockid();
CRYPTO_destroy_dynlockid(0);
CRYPTO_get_dynlock_value(0);
CRYPTO_set_dynlock_create_callback(NULL);
CRYPTO_set_dynlock_lock_callback(NULL);
CRYPTO_set_dynlock_destroy_callback(NULL);
CRYPTO_get_dynlock_create_callback();
CRYPTO_get_dynlock_lock_callback();
CRYPTO_get_dynlock_destroy_callback();
CRYPTO_set_mem_functions(NULL,NULL,NULL);
CRYPTO_set_locked_mem_functions(NULL,NULL);
CRYPTO_set_mem_ex_functions(NULL,NULL,NULL);
CRYPTO_set_locked_mem_ex_functions(NULL,NULL);
CRYPTO_set_mem_debug_functions(NULL,NULL,NULL,NULL,NULL);
CRYPTO_get_mem_functions(NULL,NULL,NULL);
CRYPTO_get_locked_mem_functions(NULL,NULL);
CRYPTO_get_mem_ex_functions(NULL,NULL,NULL);
CRYPTO_get_locked_mem_ex_functions(NULL,NULL);
CRYPTO_get_mem_debug_functions(NULL,NULL,NULL,NULL,NULL);
CRYPTO_malloc_locked(0,NULL,0);
CRYPTO_free_locked(NULL);
CRYPTO_malloc(0,NULL,0);
CRYPTO_strdup(NULL,NULL,0);
CRYPTO_free(NULL);
CRYPTO_realloc(NULL,0,NULL,0);
CRYPTO_realloc_clean(NULL,0,0,NULL,0);
CRYPTO_remalloc(NULL,0,NULL,0);
OPENSSL_cleanse(NULL,0);
CRYPTO_set_mem_debug_options(0);
CRYPTO_get_mem_debug_options();
CRYPTO_push_info_(NULL,NULL,0);
CRYPTO_pop_info();
CRYPTO_remove_all_info();
CRYPTO_dbg_malloc(NULL,0,NULL,0,0);
CRYPTO_dbg_realloc(NULL,NULL,0,NULL,0,0);
CRYPTO_dbg_free(NULL,0);
CRYPTO_dbg_set_options(0);
CRYPTO_dbg_get_options();
//CRYPTO_mem_leaks_fp();
CRYPTO_mem_leaks(NULL);
//CRYPTO_MEM_LEAK_CB();
CRYPTO_mem_leaks_cb(NULL);
OpenSSLDie(NULL,0,NULL);
OPENSSL_ia32cap_loc();
OPENSSL_isservice();
FIPS_mode();
FIPS_mode_set(0);
OPENSSL_init();
CRYPTO_memcmp(NULL,NULL,0);
ERR_load_CRYPTO_strings();
}
