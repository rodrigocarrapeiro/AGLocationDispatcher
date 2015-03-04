//
//  LDRouteDispatch.h
//  Pods
//
//  Created by Vermillion on 20.02.15.
//
//

#import "LDLocationDispatch.h"
#import "LDRoute.h"

@interface LDRouteDispatch : LDLocationDispatch {
    NSString *internalDocPath;
}

@property (strong, nonatomic) NSString *docPath;

- (instancetype)init;

- (instancetype)initWithUpdatingInterval:(NSTimeInterval)interval andDesiredAccuracy:(CLLocationAccuracy)horizontalAccuracy;

- (LDRoute *)loadRouteWithName:(NSString *)fileName;

- (void)saveRoute:(LDRoute *)route name:(NSString *)fileName;

- (void)deleteDocWithName:(NSString *)name;

- (void)setDocPath:(NSString *)docPath;

@end