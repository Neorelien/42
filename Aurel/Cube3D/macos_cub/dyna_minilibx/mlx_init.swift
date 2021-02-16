
import Cocoa
import Metal
import mlx_window
import mlx_image


func _mlx_bridge<T : AnyObject>(obj : T) -> UnsafeMutableRawPointer? {
    return UnsafeMutableRawPointer(Unmanaged.passUnretained(obj).toOpaque())
}

func _mlx_bridge<T : AnyObject>(ptr : UnsafeRawPointer) -> T {
    return Unmanaged<T>.fromOpaque(ptr).takeUnretainedValue()
}

