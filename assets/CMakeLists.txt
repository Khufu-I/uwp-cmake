set(ASSET_FILES
  assets/LargeTile.scale-100.png
  assets/LargeTile.scale-200.png
  assets/SmallTile.scale-100.png
  assets/SmallTile.scale-200.png
  assets/SplashScreen.scale-100.png
  assets/SplashScreen.scale-200.png
  assets/Square150x150Logo.scale-100.png
  assets/Square150x150Logo.scale-200.png
  assets/Square44x44Logo.altform-lightunplated_targetsize-16.png
  assets/Square44x44Logo.altform-lightunplated_targetsize-48.png
  assets/Square44x44Logo.altform-unplated_targetsize-16.png
  assets/Square44x44Logo.altform-unplated_targetsize-48.png
  assets/Square44x44Logo.scale-100.png
  assets/Square44x44Logo.scale-200.png
  assets/Square44x44Logo.targetsize-16.png
  assets/Square44x44Logo.targetsize-48.png
  assets/StoreLogo.scale-100.png
  assets/StoreLogo.scale-200.png
  assets/Wide310x150Logo.scale-100.png
  assets/Wide310x150Logo.scale-200.png)

set_source_files_properties(${ASSET_FILES} PROPERTIES VS_DEPLOYMENT_CONTENT 1)
set_source_files_properties(${ASSET_FILES} PROPERTIES VS_DEPLOYMENT_LOCATION "assets")
