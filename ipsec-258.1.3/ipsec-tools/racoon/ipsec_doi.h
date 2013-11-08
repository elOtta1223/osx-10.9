/* $Id: ipsec_doi.h,v 1.9.2.2 2005/10/17 16:23:50 monas Exp $ */

/*
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _IPSEC_DOI_H
#define _IPSEC_DOI_H

#include "isakmp.h"

/* refered to RFC2407 */

#define IPSEC_DOI 1

/* 4.2 IPSEC Situation Definition */
#define IPSECDOI_SIT_IDENTITY_ONLY           0x00000001
#define IPSECDOI_SIT_SECRECY                 0x00000002
#define IPSECDOI_SIT_INTEGRITY               0x00000004

/* 4.4.1 IPSEC Security Protocol Identifiers */
  /* 4.4.2 IPSEC ISAKMP Transform Values */
#define IPSECDOI_PROTO_ISAKMP                        1
#define   IPSECDOI_KEY_IKE                             1

/* 4.4.1 IPSEC Security Protocol Identifiers */
#define IPSECDOI_PROTO_IPSEC_AH                      2
  /* 4.4.3 IPSEC AH Transform Values */
#define   IPSECDOI_AH_MD5                              2
#define   IPSECDOI_AH_SHA                              3
#define   IPSECDOI_AH_DES                              4
#define   IPSECDOI_AH_SHA256                           5
#define   IPSECDOI_AH_SHA384                           6
#define   IPSECDOI_AH_SHA512                           7

/* 4.4.1 IPSEC Security Protocol Identifiers */
#define IPSECDOI_PROTO_IPSEC_ESP                     3
  /* 4.4.4 IPSEC ESP Transform Identifiers */
#define   IPSECDOI_ESP_DES_IV64				1
#define   IPSECDOI_ESP_DES				2
#define   IPSECDOI_ESP_3DES				3
#define   IPSECDOI_ESP_RC5				4
#define   IPSECDOI_ESP_IDEA				5
#define   IPSECDOI_ESP_CAST				6
#define   IPSECDOI_ESP_BLOWFISH				7
#define   IPSECDOI_ESP_3IDEA				8
#define   IPSECDOI_ESP_DES_IV32				9
#define   IPSECDOI_ESP_RC4				10
#define   IPSECDOI_ESP_NULL				11
#define   IPSECDOI_ESP_AES				12
#if 1
  /* draft-ietf-ipsec-ciph-aes-cbc-00.txt */
#define   IPSECDOI_ESP_TWOFISH				253
#else
  /* SSH uses these value for now */
#define   IPSECDOI_ESP_TWOFISH				250
#endif

/* 4.4.1 IPSEC Security Protocol Identifiers */
#define IPSECDOI_PROTO_IPCOMP                        4
  /* 4.4.5 IPSEC IPCOMP Transform Identifiers */
#define   IPSECDOI_IPCOMP_OUI				1
#define   IPSECDOI_IPCOMP_DEFLATE			2
#define   IPSECDOI_IPCOMP_LZS				3

/* 4.5 IPSEC Security Association Attributes */
/* NOTE: default value is not included in a packet. */
#define IPSECDOI_ATTR_SA_LD_TYPE              1 /* B */
#define   IPSECDOI_ATTR_SA_LD_TYPE_DEFAULT      1
#define   IPSECDOI_ATTR_SA_LD_TYPE_SEC          1
#define   IPSECDOI_ATTR_SA_LD_TYPE_KB           2
#define   IPSECDOI_ATTR_SA_LD_TYPE_MAX          3
#define IPSECDOI_ATTR_SA_LD                   2 /* V */
#define   IPSECDOI_ATTR_SA_LD_SEC_DEFAULT      28800 /* 8 hours */
#define   IPSECDOI_ATTR_SA_LD_KB_MAX  (~(1 << ((sizeof(int) << 3) - 1)))
#define IPSECDOI_ATTR_GRP_DESC                3 /* B */
#define IPSECDOI_ATTR_ENC_MODE                4 /* B */
	/* default value: host dependent */
#define   IPSECDOI_ATTR_ENC_MODE_ANY            0	/* NOTE:internal use */
#define   IPSECDOI_ATTR_ENC_MODE_TUNNEL         1
#define   IPSECDOI_ATTR_ENC_MODE_TRNS           2

/* NAT-T draft-ietf-ipsec-nat-t-ike-05 and later */
#define   IPSECDOI_ATTR_ENC_MODE_UDPTUNNEL_RFC	3
#define   IPSECDOI_ATTR_ENC_MODE_UDPTRNS_RFC	4

/* NAT-T up to draft-ietf-ipsec-nat-t-ike-04 */
#define   IPSECDOI_ATTR_ENC_MODE_UDPTUNNEL_DRAFT	61443
#define   IPSECDOI_ATTR_ENC_MODE_UDPTRNS_DRAFT		61444

#define IPSECDOI_ATTR_AUTH                    5 /* B */
	/* 0 means not to use authentication. */
#define   IPSECDOI_ATTR_AUTH_HMAC_MD5           1
#define   IPSECDOI_ATTR_AUTH_HMAC_SHA1          2
#define   IPSECDOI_ATTR_AUTH_DES_MAC            3
#define   IPSECDOI_ATTR_AUTH_KPDK               4 /*RFC-1826(Key/Pad/Data/Key)*/
#define   IPSECDOI_ATTR_AUTH_HMAC_SHA2_256      5
#define   IPSECDOI_ATTR_AUTH_HMAC_SHA2_384      6
#define   IPSECDOI_ATTR_AUTH_HMAC_SHA2_512      7
#define   IPSECDOI_ATTR_AUTH_HMAC_MD5_96        252 /* NOTE:internal use */
#define   IPSECDOI_ATTR_AUTH_HMAC_SHA1_96       253 /* NOTE:internal use */
#define   IPSECDOI_ATTR_AUTH_NONE               254	/* NOTE:internal use */
	/*
	 * When negotiating ESP without authentication, the Auth
	 * Algorithm attribute MUST NOT be included in the proposal.
	 * When negotiating ESP without confidentiality, the Auth
	 * Algorithm attribute MUST be included in the proposal and
	 * the ESP transform ID must be ESP_NULL.
	*/
#define IPSECDOI_ATTR_KEY_LENGTH              6 /* B */
#define IPSECDOI_ATTR_KEY_ROUNDS              7 /* B */
#define IPSECDOI_ATTR_COMP_DICT_SIZE          8 /* B */
#define IPSECDOI_ATTR_COMP_PRIVALG            9 /* V */

/* 4.6.1 Security Association Payload */
struct ipsecdoi_pl_sa {
	struct isakmp_gen h;
	struct ipsecdoi_sa_b {
		u_int32_t doi; /* Domain of Interpretation */
		u_int32_t sit; /* Situation */
	} b;
	/* followed by Leveled Domain Identifier and so on. */
} __attribute__((__packed__));

struct ipsecdoi_secrecy_h {
	u_int16_t len;
	u_int16_t reserved;
	/* followed by the value */
} __attribute__((__packed__));

/* 4.6.2 Identification Payload Content */
struct ipsecdoi_pl_id {
	struct isakmp_gen h;
	struct ipsecdoi_id_b {
		u_int8_t type;		/* ID Type */
		u_int8_t proto_id;	/* Protocol ID */
		u_int16_t port;		/* Port */
	} b;
	/* followed by Identification Data */
} __attribute__((__packed__));

#define IPSECDOI_ID_IPV4_ADDR                        1
#define IPSECDOI_ID_FQDN                             2
#define IPSECDOI_ID_USER_FQDN                        3
#define IPSECDOI_ID_IPV4_ADDR_SUBNET                 4
#define IPSECDOI_ID_IPV6_ADDR                        5
#define IPSECDOI_ID_IPV6_ADDR_SUBNET                 6
#define IPSECDOI_ID_IPV4_ADDR_RANGE                  7
#define IPSECDOI_ID_IPV6_ADDR_RANGE                  8
#define IPSECDOI_ID_DER_ASN1_DN                      9
#define IPSECDOI_ID_DER_ASN1_GN                      10
#define IPSECDOI_ID_KEY_ID                           11

/* compressing doi type, it's internal use. */
#define IDTYPE_UNDEFINED	0
#define IDTYPE_FQDN		1
#define IDTYPE_USERFQDN		2
#define IDTYPE_KEYID		3
#define IDTYPE_ADDRESS		4
#define IDTYPE_ASN1DN		5
#define IDTYPE_LOGIN		6
#define IDTYPE_SUBNET		7
#define IDTYPE_KEYIDUSE     8
#define IDTYPE_MAX          IDTYPE_KEYIDUSE

/* shared secret type, it's internal use. */
#define SECRETTYPE_USE				0
#define SECRETTYPE_KEY				1
#define SECRETTYPE_KEYCHAIN			2
#define SECRETTYPE_KEYCHAIN_BY_ID	3

/* verification modules */
#define VERIFICATION_MODULE_OPENSSL			0
#define VERIFICATION_MODULE_SEC_FRAMEWORK	1

/* verification options */
#define VERIFICATION_OPTION_NONE				0
#define VERIFICATION_OPTION_PEERS_IDENTIFIER	1
#define VERIFICATION_OPTION_OPEN_DIR			2

/* qualifiers for KEYID (and maybe others) */
#define IDQUAL_UNSPEC		0
#define IDQUAL_FILE		1
#define IDQUAL_TAG		2


/* The use for checking proposal payload. This is not exchange type. */
#define IPSECDOI_TYPE_PH1		0
#define IPSECDOI_TYPE_PH2		1

struct isakmpsa;
struct ipsecdoi_pl_sa;
struct saprop;
struct saproto;
struct satrns;
struct prop_pair;

extern struct isakmpsa *get_ph1approvalx (struct prop_pair *,
										  struct isakmpsa *, struct isakmpsa *, int);
extern int ipsecdoi_checkph1proposal (vchar_t *, phase1_handle_t *);
extern int ipsecdoi_selectph2proposal (phase2_handle_t *);
extern int ipsecdoi_checkph2proposal (phase2_handle_t *);

extern struct prop_pair **get_proppair (vchar_t *, int);
extern vchar_t *get_sabyproppair (struct prop_pair *, phase1_handle_t *);
extern int ipsecdoi_updatespi (phase2_handle_t *iph2);
extern vchar_t *get_sabysaprop (struct saprop *, vchar_t *);
extern int ipsecdoi_chkcmpids (const vchar_t *, const vchar_t *, int );
extern int ipsecdoi_checkid1 (phase1_handle_t *);
extern int ipsecdoi_setid1 (phase1_handle_t *);
extern int set_identifier (vchar_t **, int, vchar_t *);
extern int set_identifier_qual (vchar_t **, int, vchar_t *, int);
extern int ipsecdoi_setid2 (phase2_handle_t *);
extern vchar_t *ipsecdoi_sockaddr2id (struct sockaddr_storage *, u_int, u_int);
extern int ipsecdoi_id2sockaddr (vchar_t *, struct sockaddr_storage *,
	u_int8_t *, u_int16_t *, int);
extern char *ipsecdoi_id2str (const vchar_t *);
extern vchar_t *ipsecdoi_sockrange2id (struct sockaddr_storage *,
	struct sockaddr_storage *, u_int);

extern vchar_t *ipsecdoi_setph1proposal (phase1_handle_t *);
extern int ipsecdoi_setph2proposal (phase2_handle_t *, int);
extern int ipsecdoi_transportmode (struct saprop *);
extern int ipsecdoi_tunnelmode (phase2_handle_t *);
extern int ipsecdoi_any_transportmode (struct saprop *);
extern int ipsecdoi_get_defaultlifetime (void);
extern int ipsecdoi_checkalgtypes (int, int, int, int);
extern int ipproto2doi (int);
extern int doi2ipproto (int);

extern int ipsecdoi_t2satrns (struct isakmp_pl_t *,
	struct saprop *, struct saproto *, struct satrns *);
extern int ipsecdoi_authalg2trnsid (int);
extern int idtype2doi (int);
extern int doi2idtype (int);
extern int check_spi_size (int, int);
extern void print_ph1mismatched (struct prop_pair *, struct isakmpsa *);


#endif /* _IPSEC_DOI_H */