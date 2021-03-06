//
//  ASLayoutSpec+Subclasses.h
//  AsyncDisplayKit
//
//  Created by Michael Schneider on 9/15/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#import <AsyncDisplayKit/AsyncDisplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ASLayoutSpec (Subclassing)

/**
 * Helper method for finalLayoutable support
 *
 * @warning If you are getting recursion crashes here after implementing finalLayoutable, make sure
 * that you are setting isFinalLayoutable flag to YES. This must be one BEFORE adding a child
 * to the new ASLayoutable.
 *
 * For example:
 * - (id<ASLayoutable>)finalLayoutable
 * {
 *   ASInsetLayoutSpec *insetSpec = [[ASInsetLayoutSpec alloc] init];
 *   insetSpec.insets = UIEdgeInsetsMake(10,10,10,10);
 *   insetSpec.isFinalLayoutable = YES;
 *   [insetSpec setChild:self];
 *   return insetSpec;
 * }
 *
 * @see finalLayoutable
 */
- (id<ASLayoutable>)layoutableToAddFromLayoutable:(id<ASLayoutable>)child;

/**
 * Adds a child with the given identifier to this layout spec.
 *
 * @param child A child to be added.
 *
 * @param index An index associated with the child.
 *
 * @discussion Every ASLayoutSpec must act on at least one child. The ASLayoutSpec base class takes the
 * responsibility of holding on to the spec children. Some layout specs, like ASInsetLayoutSpec,
 * only require a single child.
 *
 * For layout specs that require a known number of children (ASBackgroundLayoutSpec, for example)
 * a subclass can use the setChild method to set the "primary" child. It should then use this method
 * to set any other required children. Ideally a subclass would hide this from the user, and use the
 * setChild:forIndex: internally. For example, ASBackgroundLayoutSpec exposes a backgroundChild
 * property that behind the scenes is calling setChild:forIndex:.
 */
- (void)setChild:(id<ASLayoutable>)child atIndex:(NSUInteger)index;

/**
 * Returns the child added to this layout spec using the given index.
 *
 * @param index An identifier associated with the the child.
 */
- (nullable id<ASLayoutable>)childAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
