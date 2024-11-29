def optimal_page_replacement(frames, reference_string):
    frame_set = set()
    page_faults = 0
    memory_accesses = len(reference_string)
    for i, page in enumerate(reference_string):
        if page in frame_set:
            continue
        page_faults += 1
        if len(frame_set) < len(frames):
            frame_set.add(page)
        else:
            farthest_index = i
            page_to_replace = None
            for frame in frame_set:
                try:
                    next_index = reference_string[i+1:].index(frame) + i + 1
                except ValueError:
                    next_index = float('inf')
                
                if next_index > farthest_index:
                    farthest_index = next_index
                    page_to_replace = frame
            frame_set.remove(page_to_replace)
            frame_set.add(page)
    page_fault_rate = page_faults / memory_accesses    
    return page_fault_rate, frame_set
frames = [0, 1, 2]  
reference_string = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2] 
page_fault_rate, final_frames = optimal_page_replacement(frames, reference_string)
print(f"缺页率: {page_fault_rate:.2f}")
print(f"最终内存中的页面: {final_frames}")
