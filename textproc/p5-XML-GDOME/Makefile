PORTNAME=	XML-GDOME
PORTVERSION=	0.86
PORTREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module that provides the DOM Level 2 Core API for XML documents
WWW=		https://metacpan.org/release/XML-GDOME

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN=		Fails to build with libxml2 2.14, error: unknown type name 'xmlChar'

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:textproc/p5-XML-SAX
LIB_DEPENDS=	libgdome.so:textproc/gdome2

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
