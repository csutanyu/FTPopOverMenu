//
//  FTPopOverMenu.h
//  FTPopOverMenu
//
//  Created by liufengting on 16/4/5.
//  Copyright © 2016年 liufengting ( https://github.com/liufengting ). All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  FTPopOverMenuDoneBlock
 *
 *  @param index SlectedIndex
 */
typedef void (^FTPopOverMenuDoneBlock)(NSInteger selectedIndex);
/**
 *  FTPopOverMenuDismissBlock
 */
typedef void (^FTPopOverMenuDismissBlock)();

/**
 *  -----------------------FTPopOverMenuConfiguration-----------------------
 */
@interface FTPopOverMenuConfiguration : NSObject

@property (nonatomic, assign)CGFloat menuTextMargin;// Default is 6.
@property (nonatomic, assign)CGFloat menuTextTrailMargin; // Default is 6.
@property (nonatomic, assign)CGFloat menuIconMargin;// Default is 6.
@property (nonatomic, assign)CGFloat menuIconSize;// Default is 24
@property (nonatomic, assign)CGFloat menuRowHeight;
@property (nonatomic, assign)CGFloat menuWidth;
@property (nonatomic, assign)CGFloat menuOffset; // Default is 0
@property (nonatomic, assign)BOOL adaptiveMenuWidth; // Default is NO
@property (nonatomic, assign)CGFloat maxMenuWidth; // Default is [UIScreen mainScreen].bounds.width - menuTextMargin - menuTextTrailMargin. Just meaningful when adaptiveMenuWidth == YES
@property (nonatomic, strong)UIColor *textColor;
@property (nonatomic, strong)UIColor *highlightedTextColor; // Default is nil
@property (nonatomic, strong)UIColor *tintColor;
@property (nonatomic, strong)UIColor *borderColor;
@property (nonatomic, assign)CGFloat borderWidth;
@property (nonatomic, strong)UIFont *textFont;
@property (nonatomic, assign)NSTextAlignment textAlignment;
@property (nonatomic, strong)UIColor *separatorColor;
@property (nonatomic, assign)BOOL ignoreImageOriginalColor;// Default is 'NO', if sets to 'YES', images color will be same as textColor.
@property (nonatomic, assign)BOOL allowRoundedArrow;// Default is 'NO', if sets to 'YES', the arrow will be drawn with round corner.
@property (nonatomic, assign)NSTimeInterval animationDuration;
@property (nonatomic, strong)UIImage *customArrowImage; // Default image
@property (nonatomic, assign)UITableViewCellSelectionStyle selectionStyle; // Default is equal to UITableViewCell's selectionStyle property
/**
 *  defaultConfiguration
 *
 *  @return curren configuration
 */
+ (FTPopOverMenuConfiguration *)defaultConfiguration;

@end

/**
 *  -----------------------FTPopOverMenuCell-----------------------
 */
@interface FTPopOverMenuCell : UITableViewCell

@end
/**
 *  -----------------------FTPopOverMenuView-----------------------
 */
@interface FTPopOverMenuView : UIControl

@end

/**
 *  -----------------------FTPopOverMenu-----------------------
 */
@interface FTPopOverMenu : NSObject


/**
 show method with sender without images

 @param sender sender
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray<NSString*> *)menuArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with sender and image resouce Array
 
 @param sender sender
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray<NSString*> *)menuArray
            imageArray:(NSArray *)imageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with sender and image resouce Array
 
 @param sender sender
 @param menuArray menuArray
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray<NSString*> *)menuArray
            imageArray:(NSArray *)imageArray
highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
         configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 show method with sender and image resouce Array
 
 @param sender sender
 @param menuArray menuArray
 @param defaultSelectedIndex defaultSelectedIndex
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showForSender:(UIView *)sender
         withMenuArray:(NSArray<NSString*> *)menuArray
  defaultSelectedIndex:(NSInteger)defaultSelectedIndex
            imageArray:(NSArray *)imageArray
highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
         configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 show method for barbuttonitems with event without images

 @param event event
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray<NSString*> *)menuArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method for barbuttonitems with event and imageArray

 @param event event
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray<NSString*> *)menuArray
            imageArray:(NSArray *)imageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method for barbuttonitems with event and imageArray
 
 @param event event
 @param menuArray menuArray
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray<NSString*> *)menuArray
            imageArray:(NSArray *)imageArray
highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
         configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 show method for barbuttonitems with event and imageArray
 
 @param event event
 @param menuArray menuArray
 @param defaultSelectedIndex defaultSelectedIndex
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showFromEvent:(UIEvent *)event
         withMenuArray:(NSArray<NSString*> *)menuArray
  defaultSelectedIndex:(NSInteger)defaultSelectedIndex
            imageArray:(NSArray *)imageArray
highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
             doneBlock:(FTPopOverMenuDoneBlock)doneBlock
          dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
         configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 show method with SenderFrame without images

 @param senderFrame senderFrame
 @param menuArray menuArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray<NSString*> *)menuArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with SenderFrame and image resouce Array

 @param senderFrame senderFrame
 @param menuArray menuArray
 @param imageArray imageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray<NSString*> *)menuArray
                  imageArray:(NSArray *)imageArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock;

/**
 show method with SenderFrame and image resouce Array
 
 @param senderFrame senderFrame
 @param menuArray menuArray
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray<NSString*> *)menuArray
                  imageArray:(NSArray *)imageArray
   highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
               configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 show method with SenderFrame and image resouce Array
 
 @param senderFrame senderFrame
 @param menuArray menuArray
 @param defaultSelectedIndex defaultSelectedIndex
 @param imageArray imageArray
 @param highlightedMenuImageArray highlightedMenuImageArray
 @param doneBlock doneBlock
 @param dismissBlock dismissBlock
 @param configuration configuration
 */
+ (void) showFromSenderFrame:(CGRect )senderFrame
               withMenuArray:(NSArray<NSString*> *)menuArray
        defaultSelectedIndex:(NSInteger)defaultSelectedIndex
                  imageArray:(NSArray *)imageArray
       highlightedMenuImageArray:(NSArray *)highlightedMenuImageArray
                   doneBlock:(FTPopOverMenuDoneBlock)doneBlock
                dismissBlock:(FTPopOverMenuDismissBlock)dismissBlock
               configuration:(FTPopOverMenuConfiguration *)configuration;

/**
 *  dismiss method
 */
+ (void) dismiss;

@end
