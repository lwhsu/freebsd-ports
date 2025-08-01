PORTNAME=	love
PORTVERSION=	0.8.0
PORTREVISION=	20
CATEGORIES=	devel games
MASTER_SITES=	http://cdn.bitbucket.org/rude/love/downloads/ \
		https://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	08
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open-source 2D game engine
WWW=		https://www.love2d.org/

LIB_DEPENDS=	libIL.so:graphics/devil \
		libmodplug.so:audio/libmodplug \
		libmpg123.so:audio/mpg123 \
		libvorbisfile.so:audio/libvorbis \
		libphysfs.so:devel/physfs \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

PORTSCOUT=	limit:^0\.8\.

USES=		compiler:c++11-lang gl gmake openal dos2unix lua:51 sdl
USE_SDL=	sdl mixer
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 \
		-I${LUA_INCDIR} `${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}
LDFLAGS_i386=	-Wl,-znotext
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --libdir=${PREFIX}/lib \
		--program-suffix=08
WRKSRC=		${WRKDIR}/love-${PORTVERSION}
DOS2UNIX_FILES=	src/modules/graphics/opengl/GLee.h

PLIST_FILES=	bin/love08

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^prefix=/ d; /^bindir=/ d; /^libdir=/ d; \
		/test/ s|==|=|' \
		-e "s/lua5.1/lua-${LUA_VER}/g" \
		${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changes.txt readme.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
