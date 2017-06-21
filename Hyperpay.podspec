Pod::Spec.new do |spec|
  spec.name         = "FabricOSX"
  spec.version      = "1.2.6"
  spec.summary      = "Fabric by Twitter, Inc."
  spec.homepage     = "https://fabric.io"
  spec.author       = "Twitter"
  spec.license      = { :type => "Copyright", :file => "LICENSE.md" } # from http://fabric.io/terms
  spec.platform     = :osx, "10.8"
  spec.source       = { :git => "https://github.com/IngmarStein/FabricOSX.git", :tag => "#{spec.version}" }
  spec.requires_arc = true
  spec.default_subspec = "Core"

  spec.subspec "Core" do |core|
    core.vendored_frameworks = "Fabric.framework"
    core.public_header_files = "Fabric.framework/Versions/A/Headers/*.h"
  end

  spec.subspec "Crashlytics" do |crashlytics|
    crashlytics.vendored_frameworks = "Crashlytics.framework"
    crashlytics.public_header_files = "Crashlytics.framework/Versions/A/Headers/*.h"
  end
end