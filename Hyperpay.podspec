Pod::Spec.new do |spec|
  spec.name         = "HyperpaySDK"
  spec.version      = "1.8.0"
  spec.summary      = "unoffical SDK "
  spec.homepage     = "https://saleh.im"
  spec.author       = "SalehAlDhobaie"
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/SalehAlDhobaie/Hyperpay-iOS.git" }
  spec.requires_arc = true
  spec.vendored_frameworks = "OPPWAMobile.framework"
  spec.public_header_files = "OPPWAMobile.framework/Versions/1.8.0/Headers/*.h"
  spec.resource_bundle = { 'OPPWAMobile-Resources' => '/*' }


end