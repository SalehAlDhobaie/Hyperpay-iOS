Pod::Spec.new do |spec|
  spec.name         = "HyperpaySDK"
  spec.version      = "1.8.0"
  spec.summary      = "unoffical SDK "
  spec.homepage     = "https://saleh.im"
  spec.author       = "SalehAlDhobaie"
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/SalehAlDhobaie/Hyperpay-iOS.git" }
  spec.requires_arc = true
  spec.default_subspec = "Core"
  s.resource_bundle = { 'OPPWAMobile-Resources' => '/*' }

  spec.subspec "Core" do |core|
    core.vendored_frameworks = "OPPWAMobile.framework"
    core.public_header_files = "OPPWAMobile.framework/Versions/1.8.0/Headers/*.h"
  end

end