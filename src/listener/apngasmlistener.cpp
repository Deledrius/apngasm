#include "apngasmlistener.h"
#include <sstream>

namespace apngasm {
  namespace listener {

    // Called before add frame.
    // Return true if can add.
    bool APNGAsmListener::onPreAddFrame(const std::string& filePath, unsigned int delayNum, unsigned int delayDen) const
    {
      return true;
    }

    // Called before add frame.
    // Return true if can add.
    bool APNGAsmListener::onPreAddFrame(const APNGFrame& frame) const
    {
      return true;
    }

    // Called after add frame.
    void APNGAsmListener::onPostAddFrame(const std::string& filePath, unsigned int delayNum, unsigned int delayDen) const
    {
      // nop
    }

    // Called after add frame.
    void APNGAsmListener::onPostAddFrame(const APNGFrame& frame) const
    {
      // nop
    }

    // Called before save.
    // Return true if can save.
    bool APNGAsmListener::onPreSave(const std::string& filePath) const
    {
      return true;
    }

    // Called after save.
    void APNGAsmListener::onPostSave(const std::string& filePath) const
    {
      // nop
    }

    // Called when create output path of png file.
    // Return output path.
    const std::string APNGAsmListener::onCreatePngPath(const std::string& outputDir, int index) const
    {
      std::ostringstream result;
      result  << outputDir
              << ( (outputDir.empty() || *outputDir.rbegin() == '/') ? "" : "/" )
              << index
              << ".png"
              ;
      return result.str();
    }

  } // namespace listener
} // namespace apngasm
