function [bv_dcmp] = bv_decomp(FP_embed_out, Firstpass_embed_debug_signal)

   for x = 1:FP_embed_out.numDetected
      bv_mode6_mod_bv = reshape(Firstpass_embed_debug_signal.bv_u16(1:32, x), 4, []);
      bv_mode6_mod_bv_axi = uint16([bv_mode6_mod_bv; zeros(4, size(bv_mode6_mod_bv, 2))]);
      [data_r, data_i, shft] = dcmp_unpack(bv_mode6_mod_bv_axi, int16(1), int16(6));
      [bv, ~, ~] = decompression (2^-15 * complex(double(data_r), double(data_i)), double(shft), 0, 0, 6, 0, 0, 0);
      bv_dcmp(1:32, x) = reshape(bv, 1, []) ./ 2^15;
   end

end
