//
//  ViewController.m
//  FTPopOverMenu
//
//  Created by liufengting on 16/4/5.
//  Copyright © 2016年 liufengting ( https://github.com/liufengting ). All rights reserved.
//

#import "ViewController.h"
#import "FTPopOverMenu.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    

}

- (IBAction)showMenuFromButton:(UIButton *)sender
{
    
    // Do any of the following setting to set the style (Only set what you want to change)
    // Maybe do this when app starts (in AppDelegate) or anywhere you wanna change the style.

    
    // uncomment the following line to use custom settings.
    
//#define USE_CUSTOM_SETTINGS

#ifdef USE_CUSTOM_SETTINGS
    FTPopOverMenuConfiguration *configuration = [FTPopOverMenuConfiguration defaultConfiguration];
    configuration.menuRowHeight = 80;
    configuration.menuWidth = 120;
    configuration.textColor = [UIColor orangeColor];
    configuration.textFont = [UIFont boldSystemFontOfSize:14];
    configuration.tintColor = [UIColor whiteColor];
    configuration.borderColor = [UIColor blackColor];
    configuration.borderWidth = 0.5;
//    configuration.textAlignment = NSTextAlignmentCenter;
//    configuration.ignoreImageOriginalColor = YES;// set 'ignoreImageOriginalColor' to YES, images color will be same as textColor

#endif
    
    
    
    // supports image name, UIImage, image remote URL (NSURL), image remote URL string
    
    NSString *icomImageURLString = @"https://avatars1.githubusercontent.com/u/4414522?v=3&s=40";
    
    NSURL *icomImageURL = [NSURL URLWithString:icomImageURLString];

    //[FTPopOverMenuConfiguration defaultConfiguration].customArrowImage = [UIImage imageNamed:@"bj_sanjiao"];
    FTPopOverMenuConfiguration *configuration = [FTPopOverMenuConfiguration defaultConfiguration];
    configuration.customArrowImage = [UIImage imageNamed:@"bj_sanjiao"];
    configuration.borderColor = [[UIColor whiteColor] colorWithAlphaComponent:0.95];
    configuration.tintColor = [[UIColor whiteColor] colorWithAlphaComponent:0.95];
    configuration.textFont = [UIFont systemFontOfSize:15 weight:UIFontWeightLight];
    configuration.textColor = [UIColor blackColor];
    configuration.menuIconMargin = 13;
    configuration.menuTextTrailMargin = 20;
    configuration.menuTextMargin = 20;
    configuration.menuIconSize = 30;
    configuration.separatorColor = [UIColor clearColor];
    configuration.highlightedTextColor = [UIColor redColor];
    configuration.selectionStyle = UITableViewCellSelectionStyleNone;
    configuration.maxMenuWidth = 280;
    configuration.adaptiveMenuWidth = YES;
  
    [FTPopOverMenu showForSender:sender
                   withMenuArray:@[@"MenuOne", @"MenuTwo", @"MenuThreeMenuThree", @"MenuFour"]
     defaultSelectedIndex:2
                      imageArray:@[icomImageURLString, icomImageURL, [UIImage imageNamed:@"Pokemon_Go_03"], @"Pokemon_Go_04"]
       highlightedMenuImageArray:@[icomImageURLString, icomImageURL, [UIImage imageNamed:@"Pokemon_Go_04"], @"Pokemon_Go_03"]
                       doneBlock:^(NSInteger selectedIndex) {
                           
                           NSLog(@"done block. do something. selectedIndex : %ld", (long)selectedIndex);
                           
                       } dismissBlock:^{
                           
                           NSLog(@"user canceled. do nothing.");
                           
//                           FTPopOverMenuConfiguration *configuration = [FTPopOverMenuConfiguration defaultConfiguration];
//                           configuration.allowRoundedArrow = !configuration.allowRoundedArrow;
                           
                       } configuration:nil];
    
    
    
}



@end
