///**********************************************************************************************************************************
///  DKDistortionTransform.h
///  DrawKit ©2005-2008 Apptree.net
///
///  Created by Graham Cox on 27/10/2006.
///
///	 This software is released subject to licensing conditions as detailed in DRAWKIT-LICENSING.TXT, which must accompany this source file. 
///
///**********************************************************************************************************************************

#import <Cocoa/Cocoa.h>


@interface DKDistortionTransform : NSObject <NSCoding, NSCopying>
{
	NSPoint		m_q[4];
	BOOL		m_inverted;
}

+ (DKDistortionTransform*)	transformWithInitialRect:(NSRect) rect;

- (id)				initWithRect:(NSRect) rect;
- (id)				initWithEnvelope:(NSPoint*) points;

- (void)			setEnvelopePoints:(NSPoint*) points;
- (void)			getEnvelopePoints:(NSPoint*) points;
- (NSRect)			bounds;

- (void)			offsetByX:(CGFloat) dx byY:(CGFloat) dy;
- (void)			shearHorizontallyBy:(CGFloat) dx;
- (void)			shearVerticallyBy:(CGFloat) dy;
- (void)			differentialPerspectiveBy:(CGFloat) delta;

- (void)			invert;

- (NSPoint)			transformPoint:(NSPoint) p fromRect:(NSRect) rect;
- (NSBezierPath*)	transformBezierPath:(NSBezierPath*) path;

@end



/*

This objects performs distortion transformations on points and paths. The four envelope points define a
quadrilateral in a clockwise direction starting at top,left. A point is mapped from its position relative
to a given rectangle to this quadrilateral.

This is a non-affine transformation which is why it's not a subclass of NSAffineTransform. However it
can be used in a similar way.


*/
