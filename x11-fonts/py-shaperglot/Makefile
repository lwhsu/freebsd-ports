PORTNAME=	shaperglot
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	shaperglot-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test font files for OpenType language support
WWW=		https://github.com/googlefonts/shaperglot

LICENSE=	APACHE20

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}maturin>=1.8.3<2.0:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517

CARGO_BUILD=	no
CARGO_CARGOLOCK=${WRKSRC}/shaperglot-py/Cargo.lock
CARGO_CARGOTOML=${WRKSRC}/shaperglot-py/Cargo.toml
CARGO_INSTALL=	no

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/cargo-crates/google-fonts-languages-0.7.3/build.rs

.include <bsd.port.mk>
