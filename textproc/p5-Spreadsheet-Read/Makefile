PORTNAME=	Spreadsheet-Read
PORTVERSION=	0.83
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read the data from a spreadsheet

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Spreadsheet-ParseExcel>=0.13:textproc/p5-Spreadsheet-ParseExcel \
		p5-Spreadsheet-ReadSXC>=0.26:textproc/p5-Spreadsheet-ReadSXC \
		p5-Text-CSV>=1.33:textproc/p5-Text-CSV \
		p5-Text-CSV_XS>=0.71:textproc/p5-Text-CSV_XS
TEST_DEPENDS=	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
